#include "Matrix.hpp"
#include <stdexcept>

namespace LA {
	namespace Core {
		// Empty Constructor
		template<typename T>
		Matrix<T>::Matrix() : data() {}

		/*
		* ---------------------------------------------------------------------------------------- 
		* Matrix
		*  Summary: Constructor for the Matrix, provided the number of rows and columns.
		* ---------------------------------------------------------------------------------------- 
		*/
		template<typename T>
		Matrix<T>::Matrix(const int nrows, const int mcols) : nrows(nrows), mcols(mcols), 
			data(nrows, std::vector<T>(mcols)) {}

		/*
		* ---------------------------------------------------------------------------------------- 
		* Matrix
		*  Summary: Constructor for the Matrix, provided the input data.
		* ---------------------------------------------------------------------------------------- 
		*/
		template<typename T>
		Matrix<T>::Matrix(const std::vector< std::vector<T> >& input) : data(input) {
			nrows = input.size();
			mcols = (nrows > 0) ? input.begin()->size() : 0;
		}

		/*
		* ---------------------------------------------------------------------------------------- 
		* Matrix
		*  Summary: Constructor for the Matrix, provided the input data.
		* ---------------------------------------------------------------------------------------- 
		*/
		template<typename T>
		Matrix<T>::Matrix(std::initializer_list< std::initializer_list<T> > list) {
			nrows = list.size();
			mcols = (nrows > 0) ? list.begin()->size() : 0;
			data.resize(nrows);
			int i = 0;
			for (const auto& row : list) {
				data[i].assign(row.begin(), row.end());
				++i;
			}
		}

		/*
		* ---------------------------------------------------------------------------------------- 
		* ~Matrix
		*  Summary: Deconstructor for the Matrix.
		* ---------------------------------------------------------------------------------------- 
		*/
		//template<typename T>
		//Matrix<T>::~Matrix() {}

		/*
		* ---------------------------------------------------------------------------------------- 
		* Size
		*  Summary: Obtain the size of the Matrix instance.
		* ---------------------------------------------------------------------------------------- 
		*/
		template<typename T>
		std::vector<int> Matrix<T>::size() const {
			std::vector<int> size = {0, 0};
			if (data.empty()) {
				return size;
			}
			size[0] = nrows;
			size[1] = mcols;
			return size;
		}

		/*
		* ---------------------------------------------------------------------------------------- 
		* getData
		*  Retrieve the data from a matrix.
		* ---------------------------------------------------------------------------------------- 
		*/
		template <typename T>
		std::vector< std::vector<T> > Matrix<T>::getData() const {
			return data;
		}

		/*
		* ---------------------------------------------------------------------------------------- 
		* unit
		*  Summary: Static method to obtain a unit Matrix of size n x n.
		* ---------------------------------------------------------------------------------------- 
		*/
		template<typename T>
		Matrix<T> Matrix<T>::unit(int n) {
			Matrix<T> result(n, n);
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (i == j) {
						result[i][j] = 1;
					}
					else {
						result[i][j] = 0;
					}
				}
			}
			return result;
		}

		/*
		* ---------------------------------------------------------------------------------------- 
		* zeros
		*  Summary: Static method to obtain a zero Matrix of size n x m.
		* ---------------------------------------------------------------------------------------- 
		*/
		template<typename T>
		Matrix<T> Matrix<T>::zeros(int n, int m) {
			Matrix<T> result(n, m);
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					result[i][j] = 0;
				}
			}
			return result;
		}

		/*
		* ---------------------------------------------------------------------------------------- 
		* []
		*  Summary: Obtain the ith row.
		* ---------------------------------------------------------------------------------------- 
		*/
		template<typename T>
		const std::vector<T>& Matrix<T>::operator[](int index) const {
			return data[index];
		}

		/*
		* ---------------------------------------------------------------------------------------- 
		* []
		*  Summary: Obtain the ith row.
		* ---------------------------------------------------------------------------------------- 
		*/
		template<typename T>
		std::vector<T>& Matrix<T>::operator[](int index) {
			return data[index];
		}

		/*
		* ---------------------------------------------------------------------------------------- 
		* +
		*  Summary: Add two Matrix instances together.
		* ---------------------------------------------------------------------------------------- 
		*/
		template <typename T>
		Matrix<T> Matrix<T>::operator+(const Matrix<T>& other) const {
			// Ensure the two Matrices share the same dimensions.
			other.checkDimensions(nrows, mcols);
			// Add the two together.
			Matrix<T> result(nrows, mcols);
			for (int i = 0; i < nrows; i++) {
				for (int j = 0; j < mcols; j++) {
					result[i][j] = data[i][j] + other[i][j];
				}
			}
			return result;
		}

		/*
		* ---------------------------------------------------------------------------------------- 
		* * 
		*  Summary: Multiply two Matrices together.
		* ---------------------------------------------------------------------------------------- 
		*/
		template <typename T>
		Matrix<T> Matrix<T>::operator*(const Matrix<T>& other) const {
			int n = nrows;
			int m = mcols;
			int p = other.size()[1];
			if (mcols != p) {
				throw std::invalid_argument("Matrix dimensions for multiplication are incompatible");
			}
			
			Matrix<T> result(n, p);
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < p; j++) {
					T sum = 0;
					for (int k = 0; k < m; k++) {
						sum += data[i][k] * other[k][j];
					}
					result[i][j] = sum;
				}
			}
			return result;
		}

		/*
		* ---------------------------------------------------------------------------------------- 
		* ==
		*  Summary: Compare equality of two Matrix iinstances.
		* ---------------------------------------------------------------------------------------- 
		*/
		template <typename T>
		bool Matrix<T>::operator==(const Matrix<T>& other) const {
			return data == other.getData();
		}
		
		/*
		* ---------------------------------------------------------------------------------------- 
		* checkDimensions
		*  Summary: Helper function to check if a Matrix has the correct dimensions.
		* ---------------------------------------------------------------------------------------- 
		*/
		template <typename T>
		void Matrix<T>::checkDimensions(int n, int m) const {
			if (nrows != n || mcols != m) {
				throw std::invalid_argument("Matrix dimensions are invalid.");
			}
		}

	}
}
template class LA::Core::Matrix<int>;
template class LA::Core::Matrix<double>;
