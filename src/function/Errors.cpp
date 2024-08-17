
/**
 * @file Errors.cpp
 * @author nenamaxi
 * @brief File for checking errors and throwing them
 * @version 0.1
 * @date 2024-02-18
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "Errors.h"

#include <cmath>

#include "../s21_matrix_oop.h"

/**
 * @brief Function for throwing an error based on a specific code
 *
 * @param code_  error code
 */
void errors_(const Code code_) {
  if (code_ == CODE_NO) return;

  if (code_ < CODE_INDEX_OUT_OF_RANGE)
    LOG_ERR((long unsigned int)code_);
  else
    INV_ARG((long unsigned int)code_);
}

/**
 * @brief Function for checking errors in the code between the first and second
 * matrices, or only the first
 *
 * @param code_ error code
 * @param first first matrix, main
 * @param second second matrix to check
 */
void ChecksError(Code code_, const S21Matrix& first, const S21Matrix* second) {
  bool c_ = false;

  switch (code_) {
    case CODE_DIFF_DIMENSIONS:
      if (!first.EqSizeMatrix(*second)) c_ = true;
      break;
    case CODE_MISTMATCH_SIZE:
      if (first.getCols_() != second->getRows_()) c_ = true;
      break;
    case CODE_NO_SQUERE:
      if (first.getCols_() != first.getRows_()) c_ = true;
      break;
    case CODE_ZERO_DETERMINANT:
      if (fabs(first.Determinant()) < 1e-7) c_ = true;
      break;
    case CODE_CALC_COMPLEMENT:
      if (first.getCols_() < 2) c_ = true;
      break;
    case CODE_INCORRECT_SIZE:
      if (!first.checkSize()) c_ = true;
      break;

    case CODE_NO:
    default:
      break;
  }
  if (c_) errors_(code_);
}
/**
 * @brief Get the Error Message object
 *
 * @param index index by which the error is selected
 * @return const char*
 */
const char* getErrorMessage(size_t index) {
  const char* const errorMessages[] = {ERROR_MESSAGES};
  return (index < sizeof(errorMessages) / sizeof(errorMessages[0]))
             ? errorMessages[index]
             : "Unknown error";
}