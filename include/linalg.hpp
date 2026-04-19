#pragma once

# include "vector.hpp"
# include "matrix.hpp"

namespace numc {
	template <typename T>
	Matrix<T> outer_product(const Vector<T>& vecA, const Vector<T>& vecB) {
		if (vecA.shape != vecB.shape)
			throw std::invalid_argument("Incompatible Vector Dimensions");

		Matrix<T> matC(vecA.shape.cols, vecB.shape.cols);

		for (size_t i = 0; i < matC.shape.rows; ++i) {
			auto vecA_i = vecA.elements[i];
			for (size_t j = 0; j < matC.shape.cols; ++j) {
				matC.elements[i * matC.shape.cols + j] = vecA_i * vecB.elements[j];
			}
		}

		return matC;
	}

	template <typename T>
	Matrix<T> add_bias(const Matrix<T>& matA, const Vector<T>& vecB) {
	    Matrix<T> matC(matA.shape.rows, matA.shape.cols);
	    for (size_t i = 0; i < matA.shape.rows; ++i)
		for (size_t j = 0; j < matA.shape.cols; ++j)
		    matC[i][j] = matA.elements[i * matA.shape.cols + j] + vecB.elements[j];
	    return matC; 
	}

	// 

	template <typename T>
	Vector<T> sum(const Matrix<T>& mat, uint8_t axis) {
		if (axis == 0) {
			Vector<T> vecSum(mat.shape.cols);

			for (size_t i = 0; i < mat.shape.rows; ++i) {
				for (size_t j = 0; j < mat.shape.cols; ++j) {
					vecSum.elements[j] += mat.elements[i * mat.shape.cols + j];
				}
			}
			return vecSum;
		}

		Vector<T> vecSum(mat.shape.rows);

		for (size_t i = 0; i < mat.shape.rows; ++i) {
			for (size_t j = 0; j < mat.shape.cols; ++j) {
				vecSum.elements[i] += mat.elements[i * mat.shape.cols + j];
			}
		}
		return vecSum;
	}

	template <typename T, typename R = double>
	Vector<R> mean(const Matrix<T>& mat, uint8_t axis) {
	    Vector<T> vecSum = sum(mat, axis);
	    Vector<R> vecMean(vecSum.shape.size);

	    R divisor = (axis == 0) ? mat.shape.rows : mat.shape.cols;

	    for (size_t i = 0; i < vecMean.shape.size; ++i)
		    vecMean.elements[i] = static_cast<R>(vecSum.elements[i]) / divisor;	    
	    return vecMean;
	}
}
