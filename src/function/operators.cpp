/**
 * @file operators.cpp
 * @author nenamaxi
 * @brief operator implementation
 * @version 0.1
 * @date 2024-02-18
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <iostream>
#include <type_traits>

#include "../s21_matrix_oop.h"

/**
 * @brief Performs an operation on two matrices using the specified method.
 *
 * This method creates a new matrix, copies the current matrix into it, then
 * applies the specified method to the elements of the new matrix using
 * corresponding elements of another matrix.
 *
 * @param other Another matrix on which the operation is performed.
 * @param oper Pointer to the method that will be applied to the matrix
 * elements.
 *
 * @return A new matrix containing the result of the operation.
 *
 * @see MatrixMethod
 */
S21Matrix S21Matrix::operator_calculate(const S21Matrix &other,
                                        MatrixMethod oper) const {
  S21Matrix resultMatrix(*this);
  (resultMatrix.*oper)(other);
  return resultMatrix;
}

/**
 * @brief Overloaded matrix addition operator.
 *
 * Creates a new matrix that is the result of adding the current matrix to
 * another matrix.
 *
 * @param other Another matrix that adds to the current one.
 *
 * @return A new matrix containing the result of the addition.
 */
S21Matrix S21Matrix::operator+(const S21Matrix &other) const {
  return operator_calculate(other, &S21Matrix::SumMatrix);
}

/**
 * @brief Overloaded matrix subtraction operator.
 *
 * Creates a new matrix that is the result of subtracting another matrix from
 * the current one.
 *
 * @param other Another matrix that is subtracted from the current one.
 *
 * @return A new matrix containing the result of the subtraction.
 */
S21Matrix S21Matrix::operator-(const S21Matrix &other) const {
  return operator_calculate(other, &S21Matrix::SubMatrix);
}

/**
 * @brief Overloaded matrix multiplication operator.
 *
 * Creates a new matrix that is the result of multiplying the current matrix by
 * another matrix.
 *
 * @param other Another matrix by which the current one is multiplied.
 *
 * @return A new matrix containing the result of the multiplication.
 */
S21Matrix S21Matrix::operator*(const S21Matrix &other) const {
  return operator_calculate(other, &S21Matrix::MulMatrix);
}

/**
 * @brief Overloaded operator for multiplying a matrix by a number.
 *
 * Creates a new matrix that is the result of multiplying the current matrix by
 * the specified number.
 *
 * @param number The number by which each element of the current matrix is
 * multiplied.
 *
 * @return A new matrix containing the result of multiplication by a number.
 */
S21Matrix S21Matrix::operator*(const double &number) const {
  S21Matrix resultMatrix(*this);
  resultMatrix.MulNumber(number);
  return resultMatrix;
}
/**
 * @brief Overloaded operator for comparing two matrices for equality.
 *
 * @param other Another matrix with which the current one is compared.
 *
 * @return true if the matrices are equal, false otherwise.
 */
bool S21Matrix::operator==(const S21Matrix &other) const {
  return EqMatrix(other);
}

/**
 * @brief Overloaded matrix addition operator.
 *
 * Adds another matrix to the current one and stores the result in the current
 * matrix.
 *
 * @param other Another matrix that adds to the current one.
 *
 * @return A reference to the current matrix after the addition is performed.
 */
S21Matrix &S21Matrix::operator+=(const S21Matrix &other) {
  SumMatrix(other);
  return *this;
}

/**
 * @brief Overloaded matrix subtraction operator.
 *
 * Subtracts another matrix from the current one and stores the result in the
 * current matrix.
 *
 * @param other Another matrix that is subtracted from the current one.
 *
 * @return A reference to the current matrix after subtraction is performed.
 */
S21Matrix &S21Matrix::operator-=(const S21Matrix &other) {
  SubMatrix(other);
  return *this;
}

/**
 * @brief Overloaded matrix multiplication operator.
 *
 * Multiplies the current matrix by another matrix and stores the result in the
 * current matrix.
 *
 * @param other Another matrix by which the current one is multiplied.
 *
 * @return A reference to the current matrix after performing the
 * multiplication.
 */
S21Matrix &S21Matrix::operator*=(const S21Matrix &other) {
  MulMatrix(other);
  return *this;
}

/**
 * @brief Overloaded operator for multiplying a matrix by a number.
 *
 * Multiplies each element of the current matrix by the specified number and
 * stores the result in the current matrix.
 *
 * @param number The number by which each element of the current matrix is
 * multiplied.
 *
 * @return A reference to the current matrix after multiplying by a number.
 */
S21Matrix &S21Matrix::operator*=(const double &number) {
  MulNumber(number);
  return *this;
}

/**
 * @brief Overloaded assignment operator for copying a matrix.
 *
 * Copies the contents of another matrix into the current matrix.
 *
 * @param other Another matrix from which the data is copied.
 *
 * @return A reference to the current matrix after the assignment has been
 * performed.
 */
S21Matrix &S21Matrix::operator=(const S21Matrix &other) {
  if (this != &other) {
    help_move_and_copy(other);
    this->creater_();
    this->copyMatrix(other);
  }

  return *this;
}

/**
 * @brief Moves the contents of a matrix from another object to the current
 * object.
 *
 * @param other The matrix from which to move.
 * @return A reference to the current object after the move.
 */
S21Matrix &S21Matrix::operator=(S21Matrix &&other) noexcept {
  if (this != &other) {
    help_move_and_copy(other);
    this->matrix_ = other.matrix_;
    other.zeroing();
  }

  return *this;
}

/**
 * @brief Returns a reference to a matrix element at the given indices.
 *
 * @param i The index of the string.
 * @param j Column index.
 * @return A reference to a matrix element.
 * @throws std::out_of_range if indexes are outside the matrix size.
 */
double &S21Matrix::operator()(int i, int j) {
  if (!checkIndex(i, j)) errors_(CODE_INDEX_OUT_OF_RANGE);
  return matrix_[i][j];
}

/**
 * @brief Returns a constant reference to the matrix element at the given
 * indices.
 *
 * @param i The index of the string.
 * @param j Column index.
 * @return A constant reference to a matrix element.
 * @throws std::out_of_range if indexes are outside the matrix size.
 */
const double &S21Matrix::operator()(int i, int j) const {
  if (!checkIndex(i, j)) errors_(CODE_INDEX_OUT_OF_RANGE);
  return matrix_[i][j];
}