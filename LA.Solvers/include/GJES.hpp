#ifndef GJES_H
#define GJES_H

#include "Matrix.hpp"
#include <vector>

/*
* ---------------------------------------------------------------------------------------------------- 
* GJES
*  Summary: Gauss-Jordan Elimination Solver
* ---------------------------------------------------------------------------------------------------- 
*/

namespace LA {
	namespace Solvers {
		template <typename T>
		class GJES {
		public:
			GJES();
			//static Matrix<T> solveWithFullPivoting(const Matrix<T>& A, const Matrix<T>& b);
			static Core::Matrix<T> solveWithPartialPivoting(const Core::Matrix<T>& A, const Core::Matrix<T>& b);
			//static Matrix<T> solveWithImplicitPivoting(const Matrix<T>& A, const Matrix<T>& b);
		private:
			//static void performElimination(Matrix<T>& A, Matrix>& b);
			//static void performBackSubstitution(const Matrix<T>& A, const Matrix<T>& b);
		protected:
		};
	}
}

#endif // GJES_H
