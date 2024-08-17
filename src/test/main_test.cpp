#include <gtest/gtest.h>

// Точка входа для запуска всех тестов
int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
