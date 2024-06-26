#include <gtest/gtest.h>
//#include <pthread.h>
#include "Matrix.hpp"

// Test Fixture for the Matrix class tests
class MatrixTest : public ::testing::Test {
protected:
	// Optional setup code that runs before each test
	void SetUp() override {
		// Initialize common resources or prepare state
	}

	// Optional tear-down code that runs after each test
	void TearDown() override {
		// Clean up resources or reset state
	}

	// Define any member variables used by multiple tests
	LA::Core::Matrix<double> dmat; 
	LA::Core::Matrix<int> imat;
	//LA::Core::Matrix<std::complex> cmat;	
};

// Test for Matrix addition
TEST_F(MatrixTest, MatrixAddition) {
	// Setup matrices for test
	dmat = LA::Core::Matrix<double>{{1.0, 2.0}, {3.0, 4.0}};
	LA::Core::Matrix<double> expected{{2.0, 4.0}, {6.0, 8.0}};

	// Perform operation and assert the result
	LA::Core::Matrix<double> result = dmat + dmat;
	ASSERT_EQ(result, expected);
}

// Test for Matrix multiplication
TEST_F(MatrixTest, MatrixMultiplication) {
	// Setup the matrices for the test
	imat = LA::Core::Matrix<int>{{1, 2}, {3, 4}};
	LA::Core::Matrix<int> expected{{7, 10}, {15, 22}};

	// Perform the multiplication and assert the result
	LA::Core::Matrix<int> result = imat * imat;
	ASSERT_EQ(result, expected);
}

// Test for Matrix element access
TEST_F(MatrixTest, MatrixElementAccess) {
	// Setup the matrices for the test
	dmat = LA::Core::Matrix<double>{{1.0, 2.0}, {3.0, 4.0}};
	std::vector<double> expected_row = {1.0, 2.0};
	
	// Access elements and assert
	ASSERT_DOUBLE_EQ(dmat[0][0], 1.0);
	ASSERT_DOUBLE_EQ(dmat[1][1], 4.0);
	ASSERT_EQ(dmat[0], expected_row);
}

// Test for Matrix size
TEST_F(MatrixTest, MatrixSize) {
	// Setup the matrices for the test
	dmat = LA::Core::Matrix<double>{{1.0, 2.0, 0.0}, {3.0, 4.0, 0.0}};
	std::vector<int> expected_size = {2, 3};

	// Assert the size
	ASSERT_EQ(dmat.size(), expected_size);
}
