#include "include/numc.hpp"
#include "include/vector.hpp"
#include <iostream>
#include <memory>

int main(void) {
		
	// auto vec1 = numc::Vector<int>(3);
	// auto vec2 = numc::Vector<int>(3);

	// for (int i = 0; i < 3; ++i) {
	// 	vec1[i] = i + 1;
	// }
	//
	// for (int i = 0; i < 3; ++i) {
	// 	vec2[i] = i + 1;
	// }
	//
	// auto matC = numc::outer_product(vec1, vec2);
	//
	// std::cout << matC << "\n";

	// auto vec3 = numc::hadamard(vec1, vec2);
	//
	// std::cout << vec1 << "\n";
	// std::cout << vec2 << "\n";
	// std::cout << matC << "\n";
	//
	//
	// std::cout << vec3 << "\n";
	//
	// std::cout << "------------------\n";
	//
	// auto vec4 = numc::normalize(vec3);
	//
	// std::cout << vec4 << "\n";
	//
	// std::cout << numc::argmax(vec4) << "\n";

	//
	// double similarity = numc::cosine_similarity(vec1, vec2);
	//
	// std::cout << similarity << "\n";
	
	// MATRIX TEST STARTS HERE:
	
	numc::Shape square = numc::Shape(3, 3); 
	auto matrixA = numc::Matrix<int>(square);
	auto matrixB = numc::Matrix<int>(square);

	int valA = 1;

	for (int i = 0; i < matrixA.shape.rows; ++i) {
		for (int j = 0; j < matrixA.shape.cols; ++j) {
			matrixA[i][j] = valA;
			++valA;
		}
	}

	int valB = 9;

	for (int i = 0; i < matrixB.shape.rows; ++i) {
		for (int j = 0; j < matrixB.shape.rows; ++j) {
			matrixB[i][j] = valB;
			--valB;
		}
	}

	std::cout << matrixA << "\n";
	std::cout << matrixB << "\n";
	//
	numc::Matrix<int> matrixC = numc::mat_mult(matrixA, matrixB);

	std::cout << matrixC << "\n";

	numc::Matrix<int> matrixD = numc::hadamard(matrixA, matrixB);

	std::cout << matrixD << "\n";
	
	auto matrixT = numc::transpose(matrixA);

	std::cout << matrixT << "\n";
	
	auto vecSumCol = numc::sum(matrixT, 0);
	auto vecSumRow = numc::sum(matrixT, 1);

	std::cout << vecSumCol << "\n";
	std::cout << vecSumRow << "\n";

	std::cout << numc::mean(matrixT, 0) << "\n";
	std::cout << numc::mean<int, double>(matrixT, 1) << "\n";

	return 0;
}
