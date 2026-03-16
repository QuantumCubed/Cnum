#pragma once

#include "shape.hpp"
#include <memory>
#include <cstddef>
#include <ostream>

namespace numc {

	template <typename T>

	struct Matrix {
		std::unique_ptr<T[]> elements;
		std::size_t size;
		numc::Shape shape;

		Matrix(std::size_t rows, std::size_t cols) :
			shape({
				static_cast<uint32_t>(rows), 
				static_cast<uint32_t>(cols),
			}),
			size(rows * cols),
			elements(std::make_unique<T[]>(rows * cols)) {}
		
		~Matrix() = default;

		T get(std::uint32_t row_index, std::uint32_t col_index) const {	
			if (row_index >= shape.rows || col_index >= shape.cols) { throw std::out_of_range("index of of range!"); } 
			return elements[row_index * shape.cols + col_index];
		}
		
		friend std::ostream& operator<<(std::ostream& os, const Matrix<T>& mat) {
			os << "[";

			for (uint32_t i = 0; i < mat.shape.rows; ++i) {
				if(i == 0) { os << "[ "; } else { os << "\n [ "; }
				for (uint32_t j = 0; j < mat.shape.cols; ++j) {
					auto element = mat.elements[i * mat.shape.cols + j];
					if(j + 1 == mat.shape.cols) {
						os << element << " ]";
						break;
					}
					
					os << element << ", ";
				}
			}
			os << "]" << "\n";
			return os;
		}
	};
}
