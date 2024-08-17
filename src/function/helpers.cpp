/**
 * @file helpers.cpp
 * @author nenamaxi
 * @brief helpers function
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
 * @brief function to check the correctness of the matrix size
 *
 * @return true or false
 */
bool S21Matrix::checkSize() const { return (rows_ > 0 && cols_ > 0); }

/**
 * @brief Checking that the indices are included in the matrix size
 *
 * @param i index for rows_
 * @param j index for cols_
 * @return true or false
 */
bool S21Matrix::checkIndex(const int i, const int j) const {
  bool i_ = (i >= 0 && i < rows_);
  bool j_ = (j >= 0 && j < cols_);
  return (i_ && j_);
}

/**
 * @brief Checking the equality of matrix sizes
 *
 * @param other comparison matrix
 * @return true or false
 */
bool S21Matrix::EqSizeMatrix(const S21Matrix &other) const {
  return (other.cols_ == this->cols_) && (other.rows_ == this->rows_);
}

/**
 * @brief Initializing a matrix to zeros
 */
void S21Matrix::initMatrixZero() {
  MATRIX_DOUBLE_LOOP(rows_, cols_) { matrix_[i][j] = 0; }
}

/**
 * @brief Copying matrix `other` to matrix `this->matrix_`
 *
 * @param other matrix for copy
 */
void S21Matrix::copyMatrix(const S21Matrix &other) {
  MATRIX_DOUBLE_LOOP(other.rows_, other.cols_) {
    this->matrix_[i][j] = other(i, j);
  }
}

/**
 * @brief Function to get matrix minor
 *
 * @param rows_del exception rows
 * @param cols_del exception cols
 * @return matrix of minors
 */
S21Matrix S21Matrix::getMatrixMinor(const int rows_del, const int cols_del) {
  int res_rows = 0;
  int res_cols = 0;
  S21Matrix result(rows_ - 1, cols_ - 1);
  for (int i = 0; i < rows_; i++) {
    if (i == rows_del) continue;
    res_cols = 0;
    for (int j = 0; j < cols_; j++) {
      if (j == cols_del) continue;
      result(res_rows, res_cols) = this->matrix_[i][j];
      res_cols++;
    }
    res_rows++;
  }
  return result;
}

/**
 * @brief Accessor method to get the value of a private variable rows
 *
 * @return size rows
 */
int S21Matrix::getRows_() const { return this->rows_; }

/**
 * @brief Accessor method to get the value of a private variable cols
 *
 * @return size cols
 */
int S21Matrix::getCols_() const { return this->cols_; }

/**
 * @brief Helper function for setting a new matrix size. When the size
 * increases, the matrix is supplemented with zero elements; when decreased, the
 * excess is simply discarded
 *
 * @param Nrows new size rows
 * @param Ncols new size cols
 */
void S21Matrix::setNewSize(int Nrows, int Ncols) {
  S21Matrix tmp(Nrows, Ncols);
  MATRIX_DOUBLE_LOOP(std::min(rows_, Nrows), std::min(cols_, Ncols))
  tmp.setMatrixValue(i, j, matrix_[i][j]);

  deleteMatrix();
  *this = std::move(tmp);
}

/**
 * @brief Mutator method for setting the value of a private variable rows
 *
 * @param newRows new size rows
 */
void S21Matrix::setRows_(int newRows) {
  if (newRows <= 0) errors_(CODE_SET_ROWS);
  setNewSize(newRows, cols_);
}

/**
 * @brief Mutator method for setting the value of a private variable cols
 *
 * @param newCols new size cols
 */
void S21Matrix::setCols_(int newCols) {
  if (newCols <= 0) errors_(CODE_SET_COLS);
  setNewSize(rows_, newCols);
}

/**
 * @brief Function to get value by indexes
 *
 * @param i index for rows
 * @param j index for cols
 * @return values `matrix[i][j]`
 */
double S21Matrix::getMatrixValue(int i, int j) {
  return this->operator()(i, j);
}

/**
 * @brief Setting a value to a matrix
 *
 * @param i index for rows
 * @param j index for cols
 * @param value set value
 */
void S21Matrix::setMatrixValue(int i, int j, double value) {
  this->operator()(i, j) = value;
}

/**
 * @brief Setting values from a vector(values) to a matrix
 *
 * @param values vector of values
 */
void S21Matrix::setMatrixValue(std::vector<double> &values) {
  if ((rows_ * cols_) != (int)values.size()) errors_(CODE_DIFF_DIMENSIONS);

  int count = 0;
  MATRIX_DOUBLE_LOOP(rows_, cols_) { matrix_[i][j] = values[count++]; }
}
