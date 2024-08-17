/**
 * @file operations.cpp
 * @author nenamaxi
 * @brief operations implementation
 * @version 0.1
 * @date 2024-02-18
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <cmath>
#include <functional>
#include <iostream>

#include "../s21_matrix_oop.h"
#include "Errors.h"

/**
 * @brief accuracy for compere value
 *
 */
constexpr double ACCURACY = 0.0000001;

/**
 * @brief Checks matrices for equality with each other.
 *
 * @param other comparison matrix
 * @return true or false
 */
bool S21Matrix::EqMatrix(const S21Matrix &other) const {
  bool code = true;
  if (EqSizeMatrix(other)) {
    for (int i = 0; (i < this->rows_) && code; i++)
      for (int j = 0; (j < this->cols_) && code; j++)
        if (fabs(this->matrix_[i][j] - other.matrix_[i][j]) > ACCURACY)
          code = false;
  } else
    code = false;
  return code;
}

/**
 * @brief Performs an operation on matrices.
 *
 * This method performs a specified operation on the elements of the current
 * matrix and corresponding elements of another matrix. The operation is defined
 * by a function, passed as an argument.
 *
 * @param code_ Error code that will be thrown if an error occurs
 * when performing an operation.
 * @param other Another matrix to perform the operation on.
 * @param op A function representing the operation to be performed on
 * matrix elements.
 *
 * @throws std::logic_error or std::invalid_argument  If an error occurs during
 * the operation, specified in the code_ argument.
 *
 * @see ChecksError
 */
void S21Matrix::PerformMatrixOperation(Code code_, const S21Matrix &other,
                                       MatrixOperation op) {
  ChecksError(code_, *this, &other);
  MATRIX_DOUBLE_LOOP(this->rows_, this->cols_) {
    op(this->matrix_[i][j], other(i, j));
  }
}

/**
 * @brief Adds the second matrix to the current one.
 * @throw Different matrix dimensions.
 * @param other Another matrix with which addition is performed.
 * @see PerformMatrixOperation
 */
void S21Matrix::SumMatrix(const S21Matrix &other) {
  auto sum_ = [](double &a, double b) { a += b; };
  PerformMatrixOperation(CODE_DIFF_DIMENSIONS, other, sum_);
}

/**
 * @brief Subtracts another matrix from the current one.
 * @throw Different matrix dimensions.
 * @param other Matrix to be subtracted.
 * @see PerformMatrixOperation
 */
void S21Matrix::SubMatrix(const S21Matrix &other) {
  auto sub_ = [](double &a, double b) { a -= b; };
  PerformMatrixOperation(CODE_DIFF_DIMENSIONS, other, sub_);
}

/**
 * @brief Multiplies the current matrix by a number.
 * @param num number.
 */
void S21Matrix::MulNumber(const double num) {
  MATRIX_DOUBLE_LOOP(rows_, cols_) { this->matrix_[i][j] *= num; }
}

/**
 * @brief Multiplies the current matrix by the second matrix.
 * @throw The number of columns of the first matrix is not equal to the number
 * of rows of the second matrix.
 * @param other Matrix for multiplication.
 * @see ChecksError
 * @see deleteMAtrix
 */
void S21Matrix::MulMatrix(const S21Matrix &other) {
  ChecksError(CODE_MISTMATCH_SIZE, *this, &other);

  S21Matrix resultMatrix(this->rows_, other.cols_);
  MATRIX_DOUBLE_LOOP(this->rows_, other.cols_) {
    for (int k = 0; k < this->cols_; ++k)
      resultMatrix.matrix_[i][j] += this->matrix_[i][k] * other.matrix_[k][j];
  }
  this->deleteMatrix();
  *this = std::move(resultMatrix);
}

/**
 * @brief Creates a new transposed matrix from the current one and returns it.
 * @return Transposed matrix.
 */
S21Matrix S21Matrix::Transpose() {
  S21Matrix resultMatrix(cols_, rows_);
  MATRIX_DOUBLE_LOOP(this->rows_, this->cols_) {
    resultMatrix.matrix_[j][i] = matrix_[i][j];
  }
  return resultMatrix;
}

/**
 * @brief Calculates the algebraic addition matrix of the current one and
 * returns it.
 * @throw The matrix is not square.
 * @throw The matrix size < 2x2.
 * @return Algebraic addition matrix.
 * @see ChecksError
 * @see getMatrixMinor
 * @see Determinant
 */
S21Matrix S21Matrix::CalcComplements() {
  ChecksError(CODE_NO_SQUERE, *this, NULL);
  ChecksError(CODE_CALC_COMPLEMENT, *this, NULL);
  S21Matrix resultMatrix(cols_, rows_);
  MATRIX_DOUBLE_LOOP(rows_, cols_) {
    S21Matrix minor = this->getMatrixMinor(i, j);
    double determinant = 0.0;
    determinant = minor.Determinant();
    resultMatrix.matrix_[i][j] = pow(-1, (i + j)) * determinant;
  }
  return resultMatrix;
}

/**
 * @brief Calculates and returns the determinant of the current matrix.
 * @throw The matrix is not square.
 * @return Determinant.
 * @see ChecksError
 * @see getMatrixMinor
 * @see Determinant
 */
double S21Matrix::Determinant() const {
  ChecksError(CODE_NO_SQUERE, *this, NULL);

  double det = matrix_[0][0];
  if (rows_ != 1) {
    det = 0.0;
    int sign = 1;
    S21Matrix tmp = *this;
    for (int i = 0; i < cols_; ++i) {
      S21Matrix minor = tmp.getMatrixMinor(0, i);
      det += sign * matrix_[0][i] * minor.Determinant();
      sign = -sign;
    }
  }
  return det;
}

/**
 * @brief Calculates the inverse matrix.
 * @throw Matrix determinant is 0.
 * @return inverse matrix.
 * @see ChecksError
 * @see Determinant
 * @see Transpose
 * @see CalcComplements
 * @see MulNumber
 */
S21Matrix S21Matrix::InverseMatrix() {
  ChecksError(CODE_ZERO_DETERMINANT, *this, NULL);
  double determinant = this->Determinant();
  S21Matrix resultMatrix = *this;
  if (rows_ == 1) {
    resultMatrix.matrix_[0][0] = 1.0 / determinant;
  } else {
    resultMatrix = this->Transpose().CalcComplements();
    resultMatrix.MulNumber(1.0 / determinant);
  }
  return resultMatrix;
}