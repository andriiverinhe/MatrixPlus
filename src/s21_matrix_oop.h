#pragma once

#include <functional>  // для std::function
#include <vector>

/**
 * @brief Macro for double loop through a matrix.
 *
 * This macro allows you to go through all the elements of a matrix with given
 * sizes.
 *
 * @param rows Number of rows in the matrix.
 * @param cols The number of columns in the matrix.
 */
#define MATRIX_DOUBLE_LOOP(rows, cols) \
  for (int i = 0; i < (rows); i++)     \
    for (int j = 0; j < (cols); j++)

/**
 * @brief Function for allocating memory for an array of a given type.
 *
 * Allocates dynamic memory for an array of a given type and size.
 *
 * @tparam T The type of array elements.
 * @param size The size of the array.
 * @return A pointer to the allocated memory.
 */
template <typename T>
T* allocate_(const size_t size) {
  return new T[size];
}

/**
 * @brief Function to free memory allocated for the array.
 *
 * Frees dynamic memory allocated for the array.
 *
 * @tparam T The type of array elements.
 * @param element Pointer to an array.
 */
template <typename T>
void delete_(T& element) {
  delete[] element;
  element = nullptr;
}

/**
 * @brief Enumeration for error codes.
 *
 * This listing contains error codes that may occur when performing matrix
 * operations. Each error code has its own description indicating the cause of
 * the error.
 */
enum Code {
  CODE_NO = -1,             /**< No error. */
  CODE_DIFF_DIMENSIONS = 0, /**< Different matrix dimensions. */
  CODE_MISTMATCH_SIZE =
      1, /**< The number of columns of the first matrix is not equal to the
            number of rows of the second matrix. */
  CODE_NO_SQUERE = 2,        /**< The matrix is not square. */
  CODE_ZERO_DETERMINANT = 3, /**< Matrix determinant is 0. */
  CODE_CALC_COMPLEMENT =
      4, /**< Error when calculating algebraic complements. */
  CODE_INDEX_OUT_OF_RANGE = 5, /**< Index out of matrix. */
  CODE_INCORRECT_SIZE = 6,     /**< The matrix size specified is incorrect. */
  CODE_SET_ROWS = 7,           /**< The new row size is incorrect. */
  CODE_SET_COLS = 8,           /**< The new column size is incorrect. */
};

/**
 * @brief Class representing a matrix in a mathematical context.
 */
class S21Matrix {
 private:
  int rows_;        /**< Number of rows in the matrix. */
  int cols_;        /**< Number of columns in the matrix. */
  double** matrix_; /**< Pointer to the memory where the matrix is allocated. */

 public:
  // constructors and destructors
  S21Matrix();
  S21Matrix(int rows, int cols);
  S21Matrix(const S21Matrix& other);
  S21Matrix(S21Matrix&& other) noexcept;
  ~S21Matrix();

  bool EqSizeMatrix(const S21Matrix& other) const;
  bool checkSize() const;

  // OPERATIONS
  bool EqMatrix(const S21Matrix& other) const;

  void SumMatrix(const S21Matrix& other);
  void SubMatrix(const S21Matrix& other);

  void MulNumber(const double num);
  void MulMatrix(const S21Matrix& other);

  S21Matrix Transpose();
  S21Matrix CalcComplements();
  double Determinant() const;
  S21Matrix InverseMatrix();

  // OPERATORS
  S21Matrix& operator=(S21Matrix&& other) noexcept;
  S21Matrix& operator=(const S21Matrix& other);
  S21Matrix operator+(const S21Matrix& other) const;
  S21Matrix operator-(const S21Matrix& other) const;
  S21Matrix operator*(const S21Matrix& other) const;
  S21Matrix operator*(const double& number) const;

  bool operator==(const S21Matrix& other) const;
  S21Matrix& operator+=(const S21Matrix& other);
  S21Matrix& operator-=(const S21Matrix& other);
  S21Matrix& operator*=(const S21Matrix& other);
  S21Matrix& operator*=(const double& number);

  double& operator()(int i, int j);
  const double& operator()(int i, int j) const;

  // GETTERS
  int getRows_() const;
  int getCols_() const;
  double getMatrixValue(int i, int j);
  // setNewSize
  void setRows_(int newRows);
  void setCols_(int newCols);
  void setMatrixValue(int i, int j, double value);
  void setMatrixValue(std::vector<double>& values);

 private:
  using MatrixOperation = std::function<void(double&, double)>;
  using MatrixMethod = void (S21Matrix::*)(const S21Matrix&);

  inline void zeroing() {
    cols_ = 0;
    rows_ = 0;
    matrix_ = nullptr;
  }
  inline void help_move_and_copy(const S21Matrix& other) {
    this->deleteMatrix();
    this->rows_ = other.rows_;
    this->cols_ = other.cols_;
  }
  // Helpers function struct
  void createMatrix();
  void deleteMatrix();
  inline void creater_() {
    createMatrix();
    initMatrixZero();
  }
  void initMatrixZero();
  void copyMatrix(const S21Matrix& other);
  bool checkIndex(const int i, const int j) const;
  void setNewSize(int Nrows, int Ncols);

  // Helpers function operations
  S21Matrix operator_calculate(const S21Matrix& other, MatrixMethod oper) const;
  void PerformMatrixOperation(Code code_, const S21Matrix& other,
                              MatrixOperation op);
  S21Matrix getMatrixMinor(const int rows_del, const int cols_del);
};

void ChecksError(Code code_, const S21Matrix& first, const S21Matrix* second);
void errors_(const Code code_);