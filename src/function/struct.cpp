/**
 * @file struct.cpp
 * @author nenamaxi
 * @brief structur fanction in this file
 * @version 0.1
 * @date 2024-02-18
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <iostream>

#include "../s21_matrix_oop.h"
#include "Errors.h"

/**
 * @brief Creates a matrix with the dimensions specified in the constructor.
 *
 * Allocates memory for a two-dimensional array and fills it with zeros.
 *
 * @throw std::invalid_argument If the matrix dimensions are set incorrectly.
 */
void S21Matrix::createMatrix() {
  ChecksError(CODE_INCORRECT_SIZE, *this, NULL);
  matrix_ = allocate_<double *>(rows_);
  for (int i = 0; i < rows_; ++i) matrix_[i] = allocate_<double>(cols_);
}

/**
 * @brief Removes allocated memory for a matrix.
 *
 * Frees memory allocated for a two-dimensional array of matrix elements.
 *
 * If the matrix was not created (the pointer is nullptr), the method exits
 * without action.
 */
void S21Matrix::deleteMatrix() {
  if (nullptr != matrix_) {
    for (int i = 0; i < rows_; ++i)
      if (nullptr != matrix_[i]) delete_(matrix_[i]);
    delete_(matrix_);
    zeroing();
  }
}

/**
 * @brief Default constructor.
 *
 * Creates a 3x3 square matrix and fills it with zeros.
 */
S21Matrix::S21Matrix() : rows_(3), cols_(3), matrix_(nullptr) { creater_(); }

/**
 * @brief Constructor with given dimensions.
 *
 * Creates a matrix with the specified number of rows and columns and fills it
 * with zeros.
 *
 * @param rows Number of rows in the matrix.
 * @param cols The number of columns in the matrix.
 */
S21Matrix::S21Matrix(int rows, int cols)
    : rows_(rows), cols_(cols), matrix_(nullptr) {
  creater_();
}

/**
 * @brief Copy constructor.
 *
 * Creates a copy of the matrix using deep copy.
 *
 * @param other Link to the matrix to be copied.
 */
S21Matrix::S21Matrix(const S21Matrix &other)
    : rows_(other.rows_), cols_(other.cols_), matrix_(nullptr) {
  creater_();
  copyMatrix(other);
}

/**
 * @brief Move constructor.
 *
 * Moves resources from another object to a new object.
 *
 * @param other R-value reference to the object being moved.
 */
S21Matrix::S21Matrix(S21Matrix &&other) noexcept {
  rows_ = other.rows_;
  cols_ = other.cols_;
  matrix_ = other.matrix_;

  other.zeroing();
}

/**
 * @brief Destructor.
 *
 * Frees memory allocated for the matrix.
 */
S21Matrix::~S21Matrix() { deleteMatrix(); }