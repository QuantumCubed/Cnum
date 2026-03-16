#include "include/numc.hpp"
#include <iostream>
#include <memory>

int main(void) {
		
	auto vec = numc::Vector<int>(9);

	auto mat = numc::Matrix<int>(3, 3);
	
	std::cout << vec;

	std::cout << mat;

	return 0;
}
