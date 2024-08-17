#include <cstdlib>  // Для использования функции rand()
#include <ctime>  // Для инициализации генератора случайных чисел
#include <iostream>
#include <random>
#include <vector>

#include "main_test.h"
void fillVectorWithRandomNumbers(std::vector<double>& vec, int count,
                                 double minValue, double maxValue) {
  // Используем генератор случайных чисел
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<double> distribution(minValue, maxValue);

  // Заполняем вектор случайными числами
  for (int i = 0; i < count; ++i) {
    double randomValue = distribution(gen);
    vec.push_back(randomValue);
  }
}

// Тестовые случаи используют фикстуру
TEST_F(CORECT_TEST, Test1) {
  std::vector<double> values = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  S21Matrix mat1(3, 3);
  S21Matrix mat2(3, 3);
  mat1.setMatrixValue(values);
  mat2.setMatrixValue(values);
  EXPECT_TRUE(mat1.EqMatrix(mat2));
}
TEST_F(CORECT_TEST, Test2) {
  std::vector<double> values = {
      1.123123, 231212312, -0.123123, -4123123123.123123, 4.213123, 6213.12,
      7.312,    8.123,     19};
  S21Matrix mat1(3, 3);
  S21Matrix mat2(3, 3);
  mat1.setMatrixValue(values);
  mat2.setMatrixValue(values);
  EXPECT_TRUE(mat1.EqMatrix(mat2));
}
TEST_F(CORECT_TEST, Test3) {
  std::vector<double> values;
  fillVectorWithRandomNumbers(values, 36, __DBL_MIN__, __DBL_MAX__);
  S21Matrix mat1(6, 6);
  S21Matrix mat2(6, 6);
  mat1.setMatrixValue(values);
  mat2.setMatrixValue(values);
  EXPECT_TRUE(mat1.EqMatrix(mat2));
}
TEST_F(CORECT_TEST, Test4) {
  std::vector<double> values;
  fillVectorWithRandomNumbers(values, 81, __DBL_MIN__, __DBL_MAX__);
  S21Matrix mat1(9, 9);
  S21Matrix mat2(9, 9);
  mat1.setMatrixValue(values);
  mat2.setMatrixValue(values);
  EXPECT_TRUE(mat1.EqMatrix(mat2));
}

TEST_F(CORECT_TEST, Test5) {
  std::vector<double> values;
  fillVectorWithRandomNumbers(values, 100, __DBL_MIN__, __DBL_MAX__);
  S21Matrix mat1(10, 10);
  S21Matrix mat2(10, 10);
  mat1.setMatrixValue(values);
  mat2.setMatrixValue(values);
  EXPECT_TRUE(mat1.EqMatrix(mat2));
}

// Cумма векторов
TEST_F(CORECT_TEST, Test6) {
  std::vector<double> values = {10, 11, 12, 13, 14, 15, 16, 17, 18};
  std::vector<double> trueVec = {20, 22, 24, 26, 28, 30, 32, 34, 36};
  S21Matrix trueMat(3, 3);
  S21Matrix res(3, 3);
  S21Matrix mat(3, 3);
  res.setMatrixValue(values);
  mat.setMatrixValue(values);
  trueMat.setMatrixValue(trueVec);
  res.SumMatrix(mat);
  EXPECT_TRUE(res.EqMatrix(trueMat));
}
TEST_F(CORECT_TEST, Test7) {
  std::vector<double> values1 = {10.32112, -1121.12,     0.122,
                                 1.313,    14.123123123, 0.12315,
                                 16.312,   17.123,       123.3218};
  std::vector<double> values2 = {-10.32112, 1121.12,       -0.122,
                                 -1.313,    -14.123123123, -0.12315,
                                 -16.312,   -17.123,       -123.3218};
  std::vector<double> trueVec;
  for (size_t i = 0; i < values1.size(); i++)
    trueVec.push_back(values1[i] + values2[i]);
  S21Matrix trueMat(3, 3);
  S21Matrix res(3, 3);
  S21Matrix mat(3, 3);
  res.setMatrixValue(values1);
  mat.setMatrixValue(values2);
  trueMat.setMatrixValue(trueVec);
  res.SumMatrix(mat);
  EXPECT_TRUE(res.EqMatrix(trueMat));
}
TEST_F(CORECT_TEST, Test8) {
  std::vector<double> values1 = {10213121231231312.32112};
  std::vector<double> values2 = {1231231231231.1231231232112};
  std::vector<double> trueVec;
  for (size_t i = 0; i < values1.size(); i++)
    trueVec.push_back(values1[i] + values2[i]);
  S21Matrix trueMat(1, 1);
  S21Matrix res(1, 1);
  S21Matrix mat(1, 1);
  res.setMatrixValue(values1);
  mat.setMatrixValue(values2);
  trueMat.setMatrixValue(trueVec);
  res.SumMatrix(mat);
  EXPECT_TRUE(res.EqMatrix(trueMat));
}
TEST_F(CORECT_TEST, Test9) {
  std::vector<double> values1;
  std::vector<double> values2;
  fillVectorWithRandomNumbers(values1, 81, __DBL_MIN__, __DBL_MAX__);
  fillVectorWithRandomNumbers(values2, 81, __DBL_MIN__, __DBL_MAX__);
  std::vector<double> trueVec;
  for (size_t i = 0; i < values1.size(); i++)
    trueVec.push_back(values1[i] + values2[i]);
  S21Matrix trueMat(9, 9);
  S21Matrix res(9, 9);
  S21Matrix mat(9, 9);
  res.setMatrixValue(values1);
  mat.setMatrixValue(values2);
  trueMat.setMatrixValue(trueVec);
  res.SumMatrix(mat);
  EXPECT_TRUE(res.EqMatrix(trueMat));
}

TEST_F(CORECT_TEST, Test10) {
  std::vector<double> values1;
  std::vector<double> values2;
  fillVectorWithRandomNumbers(values1, 400, -5000000, 5000000);
  fillVectorWithRandomNumbers(values2, 400, -5000000, 5000000);
  std::vector<double> trueVec;
  for (size_t i = 0; i < values1.size(); i++)
    trueVec.push_back(values1[i] + values2[i]);
  S21Matrix trueMat(20, 20);
  S21Matrix res(20, 20);
  S21Matrix mat(20, 20);
  res.setMatrixValue(values1);
  mat.setMatrixValue(values2);
  trueMat.setMatrixValue(trueVec);
  res.SumMatrix(mat);
  EXPECT_TRUE(res.EqMatrix(trueMat));
}

TEST_F(CORECT_TEST, Test11) {
  std::vector<double> values1;
  std::vector<double> values2;
  fillVectorWithRandomNumbers(values1, 40000, -5000000, 5000000);
  fillVectorWithRandomNumbers(values2, 40000, -5000000, 5000000);
  std::vector<double> trueVec;
  for (size_t i = 0; i < values1.size(); i++)
    trueVec.push_back(values1[i] + values2[i]);
  S21Matrix trueMat(200, 200);
  S21Matrix res(200, 200);
  S21Matrix mat(200, 200);
  res.setMatrixValue(values1);
  mat.setMatrixValue(values2);
  trueMat.setMatrixValue(trueVec);
  res.SumMatrix(mat);
  EXPECT_TRUE(res.EqMatrix(trueMat));
}

TEST_F(CORECT_TEST, Test12) {
  std::vector<double> values1;
  std::vector<double> values2;
  fillVectorWithRandomNumbers(values1, 400, -5000000, 5000000);
  fillVectorWithRandomNumbers(values2, 400, -5000000, 5000000);
  std::vector<double> trueVec;
  for (size_t i = 0; i < values1.size(); i++)
    trueVec.push_back(values1[i] + values2[i]);
  S21Matrix trueMat(10, 40);
  S21Matrix res(10, 40);
  S21Matrix mat(10, 40);
  res.setMatrixValue(values1);
  mat.setMatrixValue(values2);
  trueMat.setMatrixValue(trueVec);
  res.SumMatrix(mat);
  EXPECT_TRUE(res.EqMatrix(trueMat));
}

TEST_F(CORECT_TEST, Test13) {
  std::vector<double> values1;
  std::vector<double> values2;
  fillVectorWithRandomNumbers(values1, 200, -5000000, 5000000);
  fillVectorWithRandomNumbers(values2, 200, -5000000, 5000000);
  std::vector<double> trueVec;
  for (size_t i = 0; i < values1.size(); i++)
    trueVec.push_back(values1[i] + values2[i]);
  S21Matrix trueMat(5, 40);
  S21Matrix res(5, 40);
  S21Matrix mat(5, 40);
  res.setMatrixValue(values1);
  mat.setMatrixValue(values2);
  trueMat.setMatrixValue(trueVec);
  res.SumMatrix(mat);
  EXPECT_TRUE(res.EqMatrix(trueMat));
}

TEST_F(CORECT_TEST, Test14) {
  std::vector<double> values1;
  std::vector<double> values2;
  fillVectorWithRandomNumbers(values1, 42, -5000000, 5000000);
  fillVectorWithRandomNumbers(values2, 42, -5000000, 5000000);
  std::vector<double> trueVec;
  for (size_t i = 0; i < values1.size(); i++)
    trueVec.push_back(values1[i] + values2[i]);
  S21Matrix trueMat(7, 6);
  S21Matrix res(7, 6);
  S21Matrix mat(7, 6);
  res.setMatrixValue(values1);
  mat.setMatrixValue(values2);
  trueMat.setMatrixValue(trueVec);
  res.SumMatrix(mat);
  EXPECT_TRUE(res.EqMatrix(trueMat));
}

TEST_F(CORECT_TEST, Test15) {
  std::vector<double> values1;
  std::vector<double> values2;
  fillVectorWithRandomNumbers(values1, 352, __DBL_MIN__, __DBL_MAX__);
  fillVectorWithRandomNumbers(values2, 352, __DBL_MIN__, __DBL_MAX__);
  std::vector<double> trueVec;
  for (size_t i = 0; i < values1.size(); i++)
    trueVec.push_back(values1[i] + values2[i]);
  S21Matrix trueMat(32, 11);
  S21Matrix res(32, 11);
  S21Matrix mat(32, 11);
  res.setMatrixValue(values1);
  mat.setMatrixValue(values2);
  trueMat.setMatrixValue(trueVec);
  res.SumMatrix(mat);
  EXPECT_TRUE(res.EqMatrix(trueMat));
}

// SUM MATRIX
TEST_F(CORECT_TEST, Test16) {
  std::vector<double> values1;
  std::vector<double> values2;
  fillVectorWithRandomNumbers(values1, 352, __DBL_MIN__, __DBL_MAX__);
  fillVectorWithRandomNumbers(values2, 352, __DBL_MIN__, __DBL_MAX__);
  std::vector<double> trueVec;
  for (size_t i = 0; i < values1.size(); i++)
    trueVec.push_back(values1[i] - values2[i]);
  S21Matrix trueMat(32, 11);
  S21Matrix res(32, 11);
  S21Matrix mat(32, 11);
  res.setMatrixValue(values1);
  mat.setMatrixValue(values2);
  trueMat.setMatrixValue(trueVec);
  res.SubMatrix(mat);
  EXPECT_TRUE(res.EqMatrix(trueMat));
}
TEST_F(CORECT_TEST, Test17) {
  std::vector<double> values1;
  std::vector<double> values2;
  fillVectorWithRandomNumbers(values1, 378, __DBL_MIN__, __DBL_MAX__);
  fillVectorWithRandomNumbers(values2, 378, __DBL_MIN__, __DBL_MAX__);
  std::vector<double> trueVec;
  for (size_t i = 0; i < values1.size(); i++)
    trueVec.push_back(values1[i] - values2[i]);
  S21Matrix trueMat(9, 42);
  S21Matrix res(9, 42);
  S21Matrix mat(9, 42);
  res.setMatrixValue(values1);
  mat.setMatrixValue(values2);
  trueMat.setMatrixValue(trueVec);
  res.SubMatrix(mat);
  EXPECT_TRUE(res.EqMatrix(trueMat));
}

TEST_F(CORECT_TEST, Test18) {
  std::vector<double> values1;
  std::vector<double> values2;
  fillVectorWithRandomNumbers(values1, 1600, __DBL_MIN__, __DBL_MAX__);
  fillVectorWithRandomNumbers(values2, 1600, __DBL_MIN__, __DBL_MAX__);
  std::vector<double> trueVec;
  for (size_t i = 0; i < values1.size(); i++)
    trueVec.push_back(values1[i] - values2[i]);
  S21Matrix trueMat(40, 40);
  S21Matrix res(40, 40);
  S21Matrix mat(40, 40);
  res.setMatrixValue(values1);
  mat.setMatrixValue(values2);
  trueMat.setMatrixValue(trueVec);
  res.SubMatrix(mat);
  EXPECT_TRUE(res.EqMatrix(trueMat));
}

TEST_F(CORECT_TEST, Test19) {
  std::vector<double> values1;
  std::vector<double> values2;
  fillVectorWithRandomNumbers(values1, 16, __DBL_MIN__, __DBL_MAX__);
  fillVectorWithRandomNumbers(values2, 16, __DBL_MIN__, __DBL_MAX__);
  std::vector<double> trueVec;
  for (size_t i = 0; i < values1.size(); i++)
    trueVec.push_back(values1[i] - values2[i]);
  S21Matrix trueMat(4, 4);
  S21Matrix res(4, 4);
  S21Matrix mat(4, 4);
  res.setMatrixValue(values1);
  mat.setMatrixValue(values2);
  trueMat.setMatrixValue(trueVec);
  res.SubMatrix(mat);
  EXPECT_TRUE(res.EqMatrix(trueMat));
}
TEST_F(CORECT_TEST, Test20) {
  std::vector<double> values1;
  std::vector<double> values2;
  fillVectorWithRandomNumbers(values1, 1, __DBL_MIN__, __DBL_MAX__);
  fillVectorWithRandomNumbers(values2, 1, __DBL_MIN__, __DBL_MAX__);
  std::vector<double> trueVec;
  for (size_t i = 0; i < values1.size(); i++)
    trueVec.push_back(values1[i] - values2[i]);
  S21Matrix trueMat(1, 1);
  S21Matrix res(1, 1);
  S21Matrix mat(1, 1);
  res.setMatrixValue(values1);
  mat.setMatrixValue(values2);
  trueMat.setMatrixValue(trueVec);
  res.SubMatrix(mat);
  EXPECT_TRUE(res.EqMatrix(trueMat));
}

// MUL NUMBER

TEST_F(CORECT_TEST, Test21) {
  std::vector<double> values;
  double number = 0;
  fillVectorWithRandomNumbers(values, 1, __DBL_MIN__, __DBL_MAX__);
  std::vector<double> trueVec;
  for (size_t i = 0; i < values.size(); i++)
    trueVec.push_back(values[i] * number);
  S21Matrix trueMat(1, 1);
  S21Matrix res(1, 1);
  res.setMatrixValue(values);
  trueMat.setMatrixValue(trueVec);
  res.MulNumber(number);
  EXPECT_TRUE(res.EqMatrix(trueMat));
}

TEST_F(CORECT_TEST, Test22) {
  std::vector<double> values;
  double number = 21.34332432423432432;
  fillVectorWithRandomNumbers(values, 400, __DBL_MIN__, __DBL_MAX__);
  std::vector<double> trueVec;
  for (size_t i = 0; i < values.size(); i++)
    trueVec.push_back(values[i] * number);
  S21Matrix trueMat(20, 20);
  S21Matrix res(20, 20);
  res.setMatrixValue(values);
  trueMat.setMatrixValue(trueVec);
  res.MulNumber(number);
  EXPECT_TRUE(res.EqMatrix(trueMat));
}

TEST_F(CORECT_TEST, Test23) {
  std::vector<double> values;
  double number = -21.34332432423432432;
  fillVectorWithRandomNumbers(values, 400, __DBL_MIN__, __DBL_MAX__);
  std::vector<double> trueVec;
  for (size_t i = 0; i < values.size(); i++)
    trueVec.push_back(values[i] * number);
  S21Matrix trueMat(20, 20);
  S21Matrix res(20, 20);
  res.setMatrixValue(values);
  trueMat.setMatrixValue(trueVec);
  res.MulNumber(number);
  EXPECT_TRUE(res.EqMatrix(trueMat));
}

TEST_F(CORECT_TEST, Test24) {
  std::vector<double> values;
  double number = -0.000003432432;
  fillVectorWithRandomNumbers(values, 100, __DBL_MIN__, __DBL_MAX__);
  std::vector<double> trueVec;
  for (size_t i = 0; i < values.size(); i++)
    trueVec.push_back(values[i] * number);
  S21Matrix trueMat(5, 20);
  S21Matrix res(5, 20);
  res.setMatrixValue(values);
  trueMat.setMatrixValue(trueVec);
  res.MulNumber(number);
  EXPECT_TRUE(res.EqMatrix(trueMat));
}

TEST_F(CORECT_TEST, Test25) {
  std::vector<double> values;
  double number = 0.000003432432;
  fillVectorWithRandomNumbers(values, 100, __DBL_MIN__, __DBL_MAX__);
  std::vector<double> trueVec;
  for (size_t i = 0; i < values.size(); i++)
    trueVec.push_back(values[i] * number);
  S21Matrix trueMat(20, 5);
  S21Matrix res(20, 5);
  res.setMatrixValue(values);
  trueMat.setMatrixValue(trueVec);
  res.MulNumber(number);
  EXPECT_TRUE(res.EqMatrix(trueMat));
}

// MUL MATRIX

TEST_F(CORECT_TEST, Test26) {
  std::vector<double> values1 = {0.113,    -123.56,    23, 0.213,  -32.3232,
                                 7.453345, 56.1212132, 0,  100.123};
  std::vector<double> values2 = values1;
  std::vector<double> trueVec = {1264.4823926, 3979.892312,   1384.4926918,
                                 411.4299912,  1018.4709782,  510.2343003,
                                 5625.3659263, -6934.3371030, 11315.4030326};

  S21Matrix trueMat(3, 3);
  S21Matrix res(3, 3);
  S21Matrix mat(3, 3);
  res.setMatrixValue(values1);
  mat.setMatrixValue(values2);
  trueMat.setMatrixValue(trueVec);
  res.MulMatrix(mat);
  EXPECT_TRUE(res.EqMatrix(trueMat));
}

TEST_F(CORECT_TEST, Test27) {
  std::vector<double> values1 = {-0.113,    123.56,      -23, -0.213,  32.3232,
                                 -7.453345, -56.1212132, 0,   -100.123};
  std::vector<double> values2 = values1;
  std::vector<double> trueVec = {1264.4823926, 3979.892312,   1384.4926918,
                                 411.4299912,  1018.4709782,  510.2343003,
                                 5625.3659263, -6934.3371030, 11315.4030326};

  S21Matrix trueMat(3, 3);
  S21Matrix res(3, 3);
  S21Matrix mat(3, 3);
  res.setMatrixValue(values1);
  mat.setMatrixValue(values2);
  trueMat.setMatrixValue(trueVec);
  res.MulMatrix(mat);
  EXPECT_TRUE(res.EqMatrix(trueMat));
}

TEST_F(CORECT_TEST, Test28) {
  std::vector<double> values1 = {
      -0.113,   123.56,  -23,    -0.213, 32.3232,  -7.453345, -56.1212132, 0,
      -100.123, 1264.48, 4.2999, 5.6253, -6934.33, 315.4,     79.89};
  std::vector<double> values2 = {1.23456, 12.3456, 123.456, 34.56, 345.6, 1.23};
  std::vector<double> trueVec = {
      7305.2838547, 4240.5485472, 1414.3539859,  1105.2925649,  -34671.7938050,
      -816.0013397, 4036.0285632, 15766.2879510, 57987.1599552, -74609.9757480};

  S21Matrix trueMat(5, 2);
  S21Matrix res(5, 3);
  S21Matrix mat(3, 2);
  res.setMatrixValue(values1);
  mat.setMatrixValue(values2);
  trueMat.setMatrixValue(trueVec);
  res.MulMatrix(mat);
  EXPECT_TRUE(res.EqMatrix(trueMat));
}

TEST_F(CORECT_TEST, Test29) {
  std::vector<double> values1 = {
      -0.113,   123.56,  -23,    -0.213, 32.3232,  -7.453345, -56.1212132, 0,
      -100.123, 1264.48, 4.2999, 5.6253, -6934.33, 315.4,     79.89};
  std::vector<double> values2 = {
      75.2838547, 440.5485472, 14.3539859,  5.2925649,  -341.7938050,
      -8.0013397, 36.0285632,  157.2879510, 57.1599552, -46.9757480};
  std::vector<double> trueVec = {11466.2475172,   -763.7106850,
                                 67303.6526730,   -78728.6208237,
                                 2386445.4120036, 103263.7441230};

  S21Matrix trueMat(3, 2);
  S21Matrix res(3, 5);
  S21Matrix mat(5, 2);
  res.setMatrixValue(values1);
  mat.setMatrixValue(values2);
  trueMat.setMatrixValue(trueVec);
  res.MulMatrix(mat);
  EXPECT_TRUE(res.EqMatrix(trueMat));
}

TEST_F(CORECT_TEST, Test30) {
  std::vector<double> values1 = {0.1234567};
  std::vector<double> values2 = {123456789.0};
  std::vector<double> trueVec = {15241567.7625363};

  S21Matrix trueMat(1, 1);
  S21Matrix res(1, 1);
  S21Matrix mat(1, 1);
  res.setMatrixValue(values1);
  mat.setMatrixValue(values2);
  trueMat.setMatrixValue(trueVec);
  res.MulMatrix(mat);
  EXPECT_TRUE(res.EqMatrix(trueMat));
}

// TETST TRANSPOSE

TEST_F(CORECT_TEST, Test31) {
  std::vector<double> values = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::vector<double> trueVec = {1, 4, 7, 2, 5, 8, 3, 6, 9};

  S21Matrix trueMat(3, 3);
  S21Matrix res(3, 3);
  S21Matrix mat(3, 3);
  mat.setMatrixValue(values);
  res = mat.Transpose();
  trueMat.setMatrixValue(trueVec);
  EXPECT_TRUE(res.EqMatrix(trueMat));
}

TEST_F(CORECT_TEST, Test32) {
  std::vector<double> values = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::vector<double> trueVec = {1, 6, 2, 7, 3, 8, 4, 9, 5, 10};

  S21Matrix trueMat(5, 2);
  S21Matrix res(5, 2);
  S21Matrix mat(2, 5);
  mat.setMatrixValue(values);
  res = mat.Transpose();
  trueMat.setMatrixValue(trueVec);
  EXPECT_TRUE(res.EqMatrix(trueMat));
}

TEST_F(CORECT_TEST, Test33) {
  std::vector<double> values = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::vector<double> trueVec = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10};

  S21Matrix trueMat(2, 5);
  S21Matrix res(2, 5);
  S21Matrix mat(5, 2);
  mat.setMatrixValue(values);
  res = mat.Transpose();
  trueMat.setMatrixValue(trueVec);
  EXPECT_TRUE(res.EqMatrix(trueMat));
}

// TEST CALCCOMPLEMENTS

TEST_F(CORECT_TEST, Test34) {
  std::vector<double> values = {1.0, 2.0, 2.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0};
  std::vector<double> trueVec = {-3.0000000, 6.0000000,  -3.0000000,
                                 -2.0000000, -5.0000000, 6.0000000,
                                 2.0000000,  2.0000000,  -3.0000000};

  S21Matrix trueMat(3, 3);
  S21Matrix res(3, 3);
  S21Matrix mat(3, 3);
  mat.setMatrixValue(values);
  res = mat.CalcComplements();
  trueMat.setMatrixValue(trueVec);
  EXPECT_TRUE(res.EqMatrix(trueMat));
}

TEST_F(CORECT_TEST, Test35) {
  std::vector<double> values = {7812.312, 1123.312, 17.32, 212.32};
  std::vector<double> trueVec = {212.32, -17.32, -1123.312, 7812.312};

  S21Matrix trueMat(2, 2);
  S21Matrix res(2, 2);
  S21Matrix mat(2, 2);
  mat.setMatrixValue(values);
  res = mat.CalcComplements();
  trueMat.setMatrixValue(trueVec);

  EXPECT_TRUE(res.EqMatrix(trueMat));
}

TEST_F(CORECT_TEST, Test36) {
  std::vector<double> values = {17.123,  2.123, 2.54435, 4.534534, 5.534534,
                                6.53434, 73.0,  8.3545,  9.312};
  std::vector<double> trueVec = {-3.053562922,  434.781239392,   -366.137217697,
                                 1.487396075,   -26.288174,      11.9248965,
                                 -0.2093877629, -100.3500622371, 85.14101};

  S21Matrix trueMat(3, 3);
  S21Matrix res(3, 3);
  S21Matrix mat(3, 3);
  mat.setMatrixValue(values);
  res = mat.CalcComplements();
  trueMat.setMatrixValue(trueVec);
  EXPECT_TRUE(res.EqMatrix(trueMat));
}

// DETERINANT
TEST_F(CORECT_TEST, Test37) {
  std::vector<double> values = {17.123,  2.123, 2.54435, 4.534534, 5.534534,
                                6.53434, 73.0,  8.3545,  9.312};
  double result = 0.0;
  const double trueResult = -60.8268165316;
  S21Matrix mat(3, 3);
  mat.setMatrixValue(values);
  result = mat.Determinant();
  EXPECT_NEAR(trueResult, result, epsilon);
}

TEST_F(CORECT_TEST, Test38) {
  std::vector<double> values = {1,  2,  1,  4,  5,  6, 7,  8,
                                16, 15, 14, 13, 12, 1, 10, 9};
  double result = 0.0;
  const double trueResult = 1260;
  S21Matrix mat(4, 4);
  mat.setMatrixValue(values);
  result = mat.Determinant();
  EXPECT_NEAR(trueResult, result, epsilon);
}

TEST_F(CORECT_TEST, Test39) {
  std::vector<double> values = {1.1, 2.2, 1.1, 4.4, 5.5, 6.6, 7.7, 8.8,
                                16,  15,  14,  13,  12,  1.1, 10,  9.9};
  double result = 0.0;
  const double trueResult = 1555.092;
  S21Matrix mat(4, 4);
  mat.setMatrixValue(values);
  result = mat.Determinant();
  EXPECT_NEAR(trueResult, result, epsilon);
}

TEST_F(CORECT_TEST, Test40) {
  std::vector<double> values = {
      1.1, 2.2, 1.1, 4.4, 1234567.12345, 6.6, 7.7, 8.8, 16,
      15,  14,  13,  12,  1.1,           10,  9.9};
  double result = 0.0;
  const double trueResult = -572267139.842013;
  S21Matrix mat(4, 4);
  mat.setMatrixValue(values);
  result = mat.Determinant();
  EXPECT_NEAR(trueResult, result, epsilon);
}
// INVERSE MATRIX
TEST_F(CORECT_TEST, Test41) {
  std::vector<double> values = {
      1.1, 2.2, 1.1, 4.4, 1234567.12345, 6.6, 7.7, 8.8, 16,
      15,  14,  13,  12,  1.1,           10,  9.9};
  std::vector<double> trueVec = {-0.0000004, 0.0000008,  -0.0000003, -0.0000002,
                                 0.0185529,  0.0000000,  0.0714286,  -0.1020408,
                                 -0.2895107, -0.0000010, 0.0365452,  0.0806837,
                                 0.2903741,  0.0000000,  -0.0448505, 0.0308495};

  S21Matrix trueMat(4, 4);
  S21Matrix res(4, 4);
  S21Matrix mat(4, 4);
  mat.setMatrixValue(values);
  res = mat.InverseMatrix();
  trueMat.setMatrixValue(trueVec);
  EXPECT_TRUE(res.EqMatrix(trueMat));
}
TEST_F(CORECT_TEST, Test43) {
  std::vector<double> values = {17.123,  2.123, 2.54435, 4.534534, 5.534534,
                                6.53434, 73.0,  8.3545,  9.312};
  std::vector<double> trueVec = {0.0502009,  -0.0244530, 0.0034424,
                                 -7.1478546, 0.4321807,  1.6497668,
                                 6.0193388,  -0.1960467, -1.3997282};

  S21Matrix trueMat(3, 3);
  S21Matrix res(3, 3);
  S21Matrix mat(3, 3);
  mat.setMatrixValue(values);
  res = mat.InverseMatrix();
  trueMat.setMatrixValue(trueVec);
  EXPECT_TRUE(res.EqMatrix(trueMat));
}

TEST_F(CORECT_TEST, Test44) {
  std::vector<double> values = {2};
  std::vector<double> trueVec = {0.5};

  S21Matrix trueMat(1, 1);
  S21Matrix res(1, 1);
  S21Matrix mat(1, 1);
  mat.setMatrixValue(values);
  res = mat.InverseMatrix();
  trueMat.setMatrixValue(trueVec);
  EXPECT_TRUE(res.EqMatrix(trueMat));
}

TEST_F(CORECT_TEST, Test45) {
  std::vector<double> values = {2352.312321};
  std::vector<double> trueVec = {0.0004251};

  S21Matrix trueMat(1, 1);
  S21Matrix res(1, 1);
  S21Matrix mat(1, 1);
  mat.setMatrixValue(values);
  res = mat.InverseMatrix();
  trueMat.setMatrixValue(trueVec);
  EXPECT_TRUE(res.EqMatrix(trueMat));
}

// OPERATORS

// OPERATOR +

TEST_F(CORECT_TEST, OPERATOR_TEST_1) {
  std::vector<double> values1;
  std::vector<double> values2;
  fillVectorWithRandomNumbers(values1, 10000, __DBL_MIN__, __DBL_MAX__);
  fillVectorWithRandomNumbers(values2, 10000, __DBL_MIN__, __DBL_MAX__);
  std::vector<double> trueVec;
  for (size_t i = 0; i < values1.size(); i++)
    trueVec.push_back(values1[i] + values2[i]);

  S21Matrix trueMat(100, 100);
  S21Matrix mat1(100, 100);
  S21Matrix mat2(100, 100);
  mat1.setMatrixValue(values1);
  mat2.setMatrixValue(values2);
  trueMat.setMatrixValue(trueVec);
  S21Matrix res = mat1 + mat2;
  EXPECT_TRUE(res.EqMatrix(trueMat));
}

// OPERATOR -
TEST_F(CORECT_TEST, OPERATOR_TEST_2) {
  std::vector<double> values1;
  std::vector<double> values2;
  fillVectorWithRandomNumbers(values1, 10000, __DBL_MIN__, __DBL_MAX__);
  fillVectorWithRandomNumbers(values2, 10000, __DBL_MIN__, __DBL_MAX__);
  std::vector<double> trueVec;
  for (size_t i = 0; i < values1.size(); i++)
    trueVec.push_back(values1[i] - values2[i]);

  S21Matrix trueMat(100, 100);
  S21Matrix mat1(100, 100);
  S21Matrix mat2(100, 100);
  mat1.setMatrixValue(values1);
  mat2.setMatrixValue(values2);
  trueMat.setMatrixValue(trueVec);
  S21Matrix res = mat1 - mat2;
  EXPECT_TRUE(res.EqMatrix(trueMat));
}
// OPERATOR * number
TEST_F(CORECT_TEST, OPERATOR_TEST_3) {
  std::vector<double> values1;
  std::vector<double> values2;
  fillVectorWithRandomNumbers(values1, 10000, __DBL_MIN__, __DBL_MAX__);
  double number = 123.12312123;
  std::vector<double> trueVec;
  for (size_t i = 0; i < values1.size(); i++)
    trueVec.push_back(values1[i] * number);

  S21Matrix trueMat(100, 100);
  S21Matrix mat1(100, 100);
  mat1.setMatrixValue(values1);
  trueMat.setMatrixValue(trueVec);
  S21Matrix res = mat1 * number;
  EXPECT_TRUE(res.EqMatrix(trueMat));
}

TEST_F(CORECT_TEST, OPERATOR_TEST_4) {
  std::vector<double> values1;
  std::vector<double> values2;
  fillVectorWithRandomNumbers(values1, 10000, __DBL_MIN__, __DBL_MAX__);
  double number = -123.12312123;
  std::vector<double> trueVec;
  for (size_t i = 0; i < values1.size(); i++)
    trueVec.push_back(values1[i] * number);

  S21Matrix trueMat(100, 100);
  S21Matrix mat1(100, 100);
  mat1.setMatrixValue(values1);
  trueMat.setMatrixValue(trueVec);
  S21Matrix res = mat1 * number;
  EXPECT_TRUE(res.EqMatrix(trueMat));
}
TEST_F(CORECT_TEST, OPERATOR_TEST_5) {
  std::vector<double> values1;
  std::vector<double> values2;
  fillVectorWithRandomNumbers(values1, 10000, __DBL_MIN__, __DBL_MAX__);
  double number = __DBL_MIN__;
  std::vector<double> trueVec;
  for (size_t i = 0; i < values1.size(); i++)
    trueVec.push_back(values1[i] * number);

  S21Matrix trueMat(100, 100);
  S21Matrix mat1(100, 100);
  mat1.setMatrixValue(values1);
  trueMat.setMatrixValue(trueVec);
  S21Matrix res = mat1 * number;
  EXPECT_TRUE(res.EqMatrix(trueMat));
}

// OPERATOR * matrix
TEST_F(CORECT_TEST, OPERATOR_TEST_6) {
  std::vector<double> values1 = {0.113,    -123.56,    23, 0.213,  -32.3232,
                                 7.453345, 56.1212132, 0,  100.123};
  std::vector<double> values2 = values1;
  std::vector<double> trueVec = {1264.4823926, 3979.892312,   1384.4926918,
                                 411.4299912,  1018.4709782,  510.2343003,
                                 5625.3659263, -6934.3371030, 11315.4030326};

  S21Matrix trueMat(3, 3);
  S21Matrix mat1(3, 3);
  S21Matrix mat2(3, 3);
  mat1.setMatrixValue(values1);
  mat2.setMatrixValue(values2);
  trueMat.setMatrixValue(trueVec);
  S21Matrix res;
  res = mat1 * mat2;
  EXPECT_TRUE(res.EqMatrix(trueMat));
}

TEST_F(CORECT_TEST, OPERATOR_TEST_7) {
  std::vector<double> values1 = {-0.113,    123.56,      -23, -0.213,  32.3232,
                                 -7.453345, -56.1212132, 0,   -100.123};
  std::vector<double> values2 = values1;
  std::vector<double> trueVec = {1264.4823926, 3979.892312,   1384.4926918,
                                 411.4299912,  1018.4709782,  510.2343003,
                                 5625.3659263, -6934.3371030, 11315.4030326};

  S21Matrix trueMat(3, 3);
  S21Matrix mat1(3, 3);
  S21Matrix mat2(3, 3);
  mat1.setMatrixValue(values1);
  mat2.setMatrixValue(values2);
  trueMat.setMatrixValue(trueVec);
  S21Matrix res = mat1 * mat2;
  EXPECT_TRUE(res.EqMatrix(trueMat));
}

TEST_F(CORECT_TEST, OPERATOR_TEST_8) {
  std::vector<double> values1 = {
      -0.113,   123.56,  -23,    -0.213, 32.3232,  -7.453345, -56.1212132, 0,
      -100.123, 1264.48, 4.2999, 5.6253, -6934.33, 315.4,     79.89};
  std::vector<double> values2 = {1.23456, 12.3456, 123.456, 34.56, 345.6, 1.23};
  std::vector<double> trueVec = {
      7305.2838547, 4240.5485472, 1414.3539859,  1105.2925649,  -34671.7938050,
      -816.0013397, 4036.0285632, 15766.2879510, 57987.1599552, -74609.9757480};

  S21Matrix trueMat(5, 2);
  S21Matrix mat1(5, 3);
  S21Matrix mat2(3, 2);
  mat1.setMatrixValue(values1);
  mat2.setMatrixValue(values2);
  trueMat.setMatrixValue(trueVec);
  S21Matrix res = mat1 * mat2;
  EXPECT_TRUE(res.EqMatrix(trueMat));
}

TEST_F(CORECT_TEST, OPERATOR_TEST_9) {
  std::vector<double> values1 = {
      -0.113,   123.56,  -23,    -0.213, 32.3232,  -7.453345, -56.1212132, 0,
      -100.123, 1264.48, 4.2999, 5.6253, -6934.33, 315.4,     79.89};
  std::vector<double> values2 = {
      75.2838547, 440.5485472, 14.3539859,  5.2925649,  -341.7938050,
      -8.0013397, 36.0285632,  157.2879510, 57.1599552, -46.9757480};
  std::vector<double> trueVec = {11466.2475172,   -763.7106850,
                                 67303.6526730,   -78728.6208237,
                                 2386445.4120036, 103263.7441230};

  S21Matrix trueMat(3, 2);
  S21Matrix mat1(3, 5);
  S21Matrix mat2(5, 2);
  mat1.setMatrixValue(values1);
  mat2.setMatrixValue(values2);
  trueMat.setMatrixValue(trueVec);
  S21Matrix res = mat1 * mat2;
  EXPECT_TRUE(res.EqMatrix(trueMat));
}

TEST_F(CORECT_TEST, OPERATOR_TEST_10) {
  std::vector<double> values1 = {0.1234567};
  std::vector<double> values2 = {123456789.0};
  std::vector<double> trueVec = {15241567.7625363};

  S21Matrix trueMat(1, 1);
  S21Matrix mat1(1, 1);
  S21Matrix mat2(1, 1);
  mat1.setMatrixValue(values1);
  mat2.setMatrixValue(values2);
  trueMat.setMatrixValue(trueVec);
  S21Matrix res = mat1 * mat2;
  EXPECT_TRUE(res.EqMatrix(trueMat));
}
// OPERATOR ==
TEST_F(CORECT_TEST, OPERATOR_TEST_11) {
  std::vector<double> values = {
      1.123123, 231212312, -0.123123, -4123123123.123123, 4.213123, 6213.12,
      7.312,    8.123,     19};
  S21Matrix mat1(3, 3);
  S21Matrix mat2(3, 3);
  mat1.setMatrixValue(values);
  mat2.setMatrixValue(values);
  EXPECT_TRUE(mat1 == mat2);
}
TEST_F(CORECT_TEST, OPERATOR_TEST_12) {
  std::vector<double> values;
  fillVectorWithRandomNumbers(values, 36, __DBL_MIN__, __DBL_MAX__);
  S21Matrix mat1(6, 6);
  S21Matrix mat2(6, 6);
  mat1.setMatrixValue(values);
  mat2.setMatrixValue(values);
  EXPECT_TRUE(mat1 == mat2);
}
TEST_F(CORECT_TEST, OPERATOR_TEST_13) {
  std::vector<double> values;
  fillVectorWithRandomNumbers(values, 81, __DBL_MIN__, __DBL_MAX__);
  S21Matrix mat1(9, 9);
  S21Matrix mat2(9, 9);
  mat1.setMatrixValue(values);
  mat2.setMatrixValue(values);
  EXPECT_TRUE(mat1 == mat2);
}

TEST_F(CORECT_TEST, OPERATOR_TEST_14) {
  std::vector<double> values;
  fillVectorWithRandomNumbers(values, 100, __DBL_MIN__, __DBL_MAX__);
  S21Matrix mat1(10, 10);
  S21Matrix mat2(10, 10);
  mat1.setMatrixValue(values);
  mat2.setMatrixValue(values);
  EXPECT_TRUE(mat1 == mat2);
}

TEST_F(CORECT_TEST, OPERATOR_TEST_15) {
  std::vector<double> values = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  S21Matrix mat1(3, 3);
  S21Matrix mat2(3, 3);
  mat1.setMatrixValue(values);
  mat2.setMatrixValue(values);
  EXPECT_TRUE(mat1 == mat2);
}

// OPERATOR +=

TEST_F(CORECT_TEST, OPERATOR_TEST_16) {
  std::vector<double> values1;
  std::vector<double> values2;
  fillVectorWithRandomNumbers(values1, 10000, __DBL_MIN__, __DBL_MAX__);
  fillVectorWithRandomNumbers(values2, 10000, __DBL_MIN__, __DBL_MAX__);
  std::vector<double> trueVec;
  for (size_t i = 0; i < values1.size(); i++)
    trueVec.push_back(values1[i] + values2[i]);

  S21Matrix trueMat(100, 100);
  S21Matrix mat1(100, 100);
  S21Matrix mat2(100, 100);
  mat1.setMatrixValue(values1);
  mat2.setMatrixValue(values2);
  trueMat.setMatrixValue(trueVec);
  mat1 += mat2;
  EXPECT_TRUE(mat1.EqMatrix(trueMat));
}

// OPERATOR -
TEST_F(CORECT_TEST, OPERATOR_TEST_17) {
  std::vector<double> values1;
  std::vector<double> values2;
  fillVectorWithRandomNumbers(values1, 10000, __DBL_MIN__, __DBL_MAX__);
  fillVectorWithRandomNumbers(values2, 10000, __DBL_MIN__, __DBL_MAX__);
  std::vector<double> trueVec;
  for (size_t i = 0; i < values1.size(); i++)
    trueVec.push_back(values1[i] - values2[i]);

  S21Matrix trueMat(100, 100);
  S21Matrix mat1(100, 100);
  S21Matrix mat2(100, 100);
  mat1.setMatrixValue(values1);
  mat2.setMatrixValue(values2);
  trueMat.setMatrixValue(trueVec);
  mat1 -= mat2;
  EXPECT_TRUE(mat1.EqMatrix(trueMat));
}
// OPERATOR * number
TEST_F(CORECT_TEST, OPERATOR_TEST_18) {
  std::vector<double> values1;
  std::vector<double> values2;
  fillVectorWithRandomNumbers(values1, 10000, __DBL_MIN__, __DBL_MAX__);
  double number = 123.12312123;
  std::vector<double> trueVec;
  for (size_t i = 0; i < values1.size(); i++)
    trueVec.push_back(values1[i] * number);

  S21Matrix trueMat(100, 100);
  S21Matrix mat1(100, 100);
  mat1.setMatrixValue(values1);
  trueMat.setMatrixValue(trueVec);
  mat1 *= number;
  EXPECT_TRUE(mat1.EqMatrix(trueMat));
}

TEST_F(CORECT_TEST, OPERATOR_TEST_19) {
  std::vector<double> values1;
  std::vector<double> values2;
  fillVectorWithRandomNumbers(values1, 10000, __DBL_MIN__, __DBL_MAX__);
  double number = -123.12312123;
  std::vector<double> trueVec;
  for (size_t i = 0; i < values1.size(); i++)
    trueVec.push_back(values1[i] * number);

  S21Matrix trueMat(100, 100);
  S21Matrix mat1(100, 100);
  mat1.setMatrixValue(values1);
  trueMat.setMatrixValue(trueVec);
  mat1 *= number;
  EXPECT_TRUE(mat1.EqMatrix(trueMat));
}
TEST_F(CORECT_TEST, OPERATOR_TEST_20) {
  std::vector<double> values1;
  std::vector<double> values2;
  fillVectorWithRandomNumbers(values1, 10000, __DBL_MIN__, __DBL_MAX__);
  double number = __DBL_MIN__;
  std::vector<double> trueVec;
  for (size_t i = 0; i < values1.size(); i++)
    trueVec.push_back(values1[i] * number);

  S21Matrix trueMat(100, 100);
  S21Matrix mat1(100, 100);
  mat1.setMatrixValue(values1);
  trueMat.setMatrixValue(trueVec);
  mat1 *= number;
  EXPECT_TRUE(mat1.EqMatrix(trueMat));
}

// OPERATOR *= matrix
TEST_F(CORECT_TEST, OPERATOR_TEST_21) {
  std::vector<double> values1 = {0.113,    -123.56,    23, 0.213,  -32.3232,
                                 7.453345, 56.1212132, 0,  100.123};
  std::vector<double> values2 = values1;
  std::vector<double> trueVec = {1264.4823926, 3979.892312,   1384.4926918,
                                 411.4299912,  1018.4709782,  510.2343003,
                                 5625.3659263, -6934.3371030, 11315.4030326};

  S21Matrix trueMat(3, 3);
  S21Matrix mat1(3, 3);
  S21Matrix mat2(3, 3);
  mat1.setMatrixValue(values1);
  mat2.setMatrixValue(values2);
  trueMat.setMatrixValue(trueVec);
  mat1 *= mat2;
  EXPECT_TRUE(mat1.EqMatrix(trueMat));
}

TEST_F(CORECT_TEST, OPERATOR_TEST_22) {
  std::vector<double> values1 = {-0.113,    123.56,      -23, -0.213,  32.3232,
                                 -7.453345, -56.1212132, 0,   -100.123};
  std::vector<double> values2 = values1;
  std::vector<double> trueVec = {1264.4823926, 3979.892312,   1384.4926918,
                                 411.4299912,  1018.4709782,  510.2343003,
                                 5625.3659263, -6934.3371030, 11315.4030326};

  S21Matrix trueMat(3, 3);
  S21Matrix mat1(3, 3);
  S21Matrix mat2(3, 3);
  mat1.setMatrixValue(values1);
  mat2.setMatrixValue(values2);
  trueMat.setMatrixValue(trueVec);
  mat1 *= mat2;
  EXPECT_TRUE(mat1.EqMatrix(trueMat));
}

TEST_F(CORECT_TEST, OPERATOR_TEST_23) {
  std::vector<double> values1 = {
      -0.113,   123.56,  -23,    -0.213, 32.3232,  -7.453345, -56.1212132, 0,
      -100.123, 1264.48, 4.2999, 5.6253, -6934.33, 315.4,     79.89};
  std::vector<double> values2 = {1.23456, 12.3456, 123.456, 34.56, 345.6, 1.23};
  std::vector<double> trueVec = {
      7305.2838547, 4240.5485472, 1414.3539859,  1105.2925649,  -34671.7938050,
      -816.0013397, 4036.0285632, 15766.2879510, 57987.1599552, -74609.9757480};

  S21Matrix trueMat(5, 2);
  S21Matrix mat1(5, 3);
  S21Matrix mat2(3, 2);
  mat1.setMatrixValue(values1);
  mat2.setMatrixValue(values2);
  trueMat.setMatrixValue(trueVec);
  mat1 *= mat2;
  EXPECT_TRUE(mat1.EqMatrix(trueMat));
}

TEST_F(CORECT_TEST, OPERATOR_TEST_24) {
  std::vector<double> values1 = {
      -0.113,   123.56,  -23,    -0.213, 32.3232,  -7.453345, -56.1212132, 0,
      -100.123, 1264.48, 4.2999, 5.6253, -6934.33, 315.4,     79.89};
  std::vector<double> values2 = {
      75.2838547, 440.5485472, 14.3539859,  5.2925649,  -341.7938050,
      -8.0013397, 36.0285632,  157.2879510, 57.1599552, -46.9757480};
  std::vector<double> trueVec = {11466.2475172,   -763.7106850,
                                 67303.6526730,   -78728.6208237,
                                 2386445.4120036, 103263.7441230};

  S21Matrix trueMat(3, 2);
  S21Matrix mat1(3, 5);
  S21Matrix mat2(5, 2);
  mat1.setMatrixValue(values1);
  mat2.setMatrixValue(values2);
  trueMat.setMatrixValue(trueVec);
  mat1 *= mat2;
  EXPECT_TRUE(mat1.EqMatrix(trueMat));
}

TEST_F(CORECT_TEST, OPERATOR_TEST_25) {
  std::vector<double> values1 = {0.1234567};
  std::vector<double> values2 = {123456789.0};
  std::vector<double> trueVec = {15241567.7625363};

  S21Matrix trueMat(1, 1);
  S21Matrix mat1(1, 1);
  S21Matrix mat2(1, 1);
  mat1.setMatrixValue(values1);
  mat2.setMatrixValue(values2);
  trueMat.setMatrixValue(trueVec);
  mat1 *= mat2;
  EXPECT_TRUE(mat1.EqMatrix(trueMat));
}

TEST_F(CORECT_TEST, OPERATOR_TEST_26) {
  std::vector<double> values1;
  std::vector<double> values2;
  fillVectorWithRandomNumbers(values1, 400, -5000000, 5000000);
  fillVectorWithRandomNumbers(values2, 400, -5000000, 5000000);
  std::vector<double> trueVec;
  for (size_t i = 0; i < values1.size(); i++)
    trueVec.push_back(values1[i] + values2[i]);
  S21Matrix trueMat(10, 40);
  S21Matrix res(10, 40);
  S21Matrix mat(10, 40);
  res.setMatrixValue(values1);
  mat.setMatrixValue(values2);
  trueMat.setMatrixValue(trueVec);
  res.SumMatrix(mat);
  EXPECT_TRUE(res == trueMat);
}
TEST_F(CORECT_TEST, TEST_OPERATORS_27) {
  std::vector<double> values = {1, 2, 3, 4, 5, 6, 7, 8, 9};

  S21Matrix trueMat;
  S21Matrix mat1(3, 3);
  mat1.setMatrixValue(values);
  trueMat = mat1;
  EXPECT_TRUE(mat1 == trueMat);
}
TEST_F(CORECT_TEST, TEST_OPERATORS_28) {
  std::vector<double> values = {1, 2, 3, 4, 5, 6, 7, 8, 9};

  S21Matrix trueMat;
  S21Matrix mat1(3, 3);
  mat1.setMatrixValue(values);
  trueMat = std::move(mat1);
  EXPECT_FALSE(mat1 == trueMat);
}

TEST_F(CORECT_TEST, TEST_SETVALUE_1) {
  S21Matrix matrix(3, 3);
  MATRIX_DOUBLE_LOOP(matrix.getRows_(), matrix.getCols_())
  matrix.setMatrixValue(i, j, 9.0);
  MATRIX_DOUBLE_LOOP(matrix.getRows_(), matrix.getCols_())
  EXPECT_NEAR(matrix.getMatrixValue(i, j), 9.0, epsilon);
}

TEST_F(CORECT_TEST, TEST_SETVALUE_2) {
  S21Matrix matrix(3, 3);
  MATRIX_DOUBLE_LOOP(matrix.getRows_(), matrix.getCols_())
  matrix.setMatrixValue(i, j, __DBL_MAX__);

  MATRIX_DOUBLE_LOOP(matrix.getRows_(), matrix.getCols_())
  EXPECT_NEAR(matrix.getMatrixValue(i, j), __DBL_MAX__, epsilon);
}

TEST_F(CORECT_TEST, TEST_SETVALUE_3) {
  S21Matrix matrix(3, 3);
  MATRIX_DOUBLE_LOOP(matrix.getRows_(), matrix.getCols_())
  matrix.setMatrixValue(i, j, __DBL_MIN__);

  MATRIX_DOUBLE_LOOP(matrix.getRows_(), matrix.getCols_())
  EXPECT_NEAR(matrix.getMatrixValue(i, j), __DBL_MIN__, epsilon);
}

TEST_F(CORECT_TEST, TEST_SETVALUE_4) {
  S21Matrix matrix(2, 4);
  MATRIX_DOUBLE_LOOP(matrix.getRows_(), matrix.getCols_()) {
    matrix.setMatrixValue(i, j, 4.4353453453);
  }

  MATRIX_DOUBLE_LOOP(matrix.getRows_(), matrix.getCols_())
  EXPECT_NEAR(matrix.getMatrixValue(i, j), 4.4353453453, epsilon);
}
TEST_F(CORECT_TEST, TEST_SETVALUE_5) {
  S21Matrix matrix(5, 1);
  MATRIX_DOUBLE_LOOP(matrix.getRows_(), matrix.getCols_()) {
    matrix.setMatrixValue(i, j, 4.4353453453);
  }

  MATRIX_DOUBLE_LOOP(matrix.getRows_(), matrix.getCols_())
  EXPECT_NEAR(matrix.getMatrixValue(i, j), 4.4353453453, epsilon);
}

TEST_F(CORECT_TEST, STRUCT_TEST_1) {
  S21Matrix matrix(3, 3);
  S21Matrix res = matrix;
  S21Matrix mat(std::move(matrix));
  EXPECT_TRUE(mat.EqMatrix(res));
}