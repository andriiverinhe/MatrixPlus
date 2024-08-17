#pragma once
#include <gtest/gtest.h>

#include "../s21_matrix_oop.h"
class CORECT_TEST : public ::testing::Test {
 protected:
  void SetUp() override { epsilon = 1e-6; }

  double epsilon;
};
class INCORRECT_TEST : public ::testing::Test {};