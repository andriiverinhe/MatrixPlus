CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++17
TESTFLAGS = -lgtest -lgtest_main -pthread
CFLAGS_COVERAGE = -fprofile-arcs -ftest-coverage

FUNC_SOURCES = $(wildcard ./src/function/*.cpp)
FUNC_OBJECTS = $(patsubst ./src/function/%.cpp, OBJ/function/%.o, $(FUNC_SOURCES))
TEST_SOURCES = $(wildcard ./src/test/*.cpp)
TEST_OBJECTS = $(patsubst ./src/test/%.cpp, OBJ/test/%.o, $(TEST_SOURCES))

LIBRARY = s21_matrix_oop.a

all:
	@make $(LIBRARY)
	@make test
	@make clean
	@make gcov_report

$(LIBRARY): $(FUNC_OBJECTS)
	ar rcs $@ $^

test: $(LIBRARY) $(TEST_OBJECTS)
	$(CC) -o test_executable $(TEST_OBJECTS) -L. -l:$(LIBRARY) $(TESTFLAGS)
	./test_executable

peer: gcov_report gcov_show

gcov_report: CFLAGS += $(CFLAGS_COVERAGE)
gcov_report: clean $(TEST_OBJECTS) $(FUNC_OBJECTS)
	$(CC) $(CFLAGS) -o test_executable $(TEST_OBJECTS) $(FUNC_OBJECTS) $(TESTFLAGS)
	./test_executable
	@mkdir -p OBJ_gcov
	gcovr -r ./src/function/ ./OBJ/function/ --html-details -o ./OBJ_gcov/coverage_report.html

gcov_show:
	xdg-open ./OBJ_gcov/coverage_report.html
 
clang-check:
	clang-format -n src/**/*h
	clang-format -n src/**/*cpp

clang-fix: 
	clang-format -i src/**/*h
	clang-format -i src/**/*cpp

cppcheck:
	cppcheck --enable=all --check-config --suppress=missingIncludeSystem src/**/*h src/**/*cpp

valgrind: clean test
	valgrind --tool=memcheck --leak-check=yes --log-file="valgrind.log" ./test_executable

clean_gcov:
	rm -rf *.gcno *.gcda *.gcov coverage_report.html *.html *.css OBJ_gcov

docs:
	doxygen Doxyfile

dvi: 
	xdg-open refman.pdf

clean: clean_gcov
	rm -rf OBJ/ $(LIBRARY) *.log *.o test_executable
	rm -rf Docs

OBJ/function/%.o: ./src/function/%.cpp
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@ -lm

OBJ/test/%.o: ./src/test/%.cpp
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@ -L. -l$(LIBRARY) $(TESTFLAGS)