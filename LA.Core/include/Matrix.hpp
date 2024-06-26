#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <initializer_list>

namespace LA {
	namespace Core {
		template <typename T>
		class Matrix {
		public:
			// Constructors
			Matrix();
			Matrix(int rows, int cols);
			Matrix(const std::vector< std::vector<T> >& input);
			Matrix(std::initializer_list< std::initializer_list<T> > list);

			// Destructors
			//~Matrix();

			// Size
			std::vector<int> size() const;

			// Data
			std::vector< std::vector<T> > getData() const;

			// Unit 
			static Matrix<T> unit(int n);

			// Zeros
			static Matrix<T> zeros(int n, int m);

			// Matrix Operations
			const std::vector<T>& operator[](int index) const;
			std::vector<T>& operator[](int index);
			Matrix<T> operator+(const Matrix<T>& other) const;
			Matrix<T> operator*(const Matrix<T>& other) const;
			bool operator==(const Matrix<T>& other) const;
			//Matrix<T> inverse() const;
		private:
			int nrows;
			int mcols;
			// Matrix data
			std::vector< std::vector<T> > data;
			// Helper
			void checkDimensions(int n, int m) const;
		protected:
		};
	}
}

#endif // MATRIX_H
