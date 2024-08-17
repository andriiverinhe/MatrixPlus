#pragma once
#include <iostream>
#include <stdexcept>
#include <string>

#define ERROR_MESSAGES                                                        \
  ERROR_MESSAGE("Different matrix sizes.") /* 0 LOG_ERR */                    \
  ERROR_MESSAGE(                                                              \
      "The number of columns of the first matrix is not equal to the number " \
      "of rows of the second matrix.")          /* 1 LOG_ERR */               \
  ERROR_MESSAGE("The matrix is not square.")    /* 2 LOG_ERR */               \
  ERROR_MESSAGE("The matrix determinant is 0.") /* 3 LOG_ERR */               \
  ERROR_MESSAGE(                                                              \
      "The matrix size for a compute algebraic complement matrix should"      \
      "be at least 2.")                              /* 4 LOG_ERR */          \
  ERROR_MESSAGE("Index outside the matrix.")         /* 5 INV_ARG */          \
  ERROR_MESSAGE("The matrix size is incorrect.")     /* 6 INV_ARG */          \
  ERROR_MESSAGE("The new row size is incorrect.")    /* 7 INV_ARG */          \
  ERROR_MESSAGE("The new column size is incorrect.") /* 8 INV_ARG */

#define ERROR_MESSAGE(message) message,

#define LOG_ERR(index) throw std::logic_error(getErrorMessage(index))
#define INV_ARG(index) throw std::invalid_argument(getErrorMessage(index))

const char* getErrorMessage(size_t index);
