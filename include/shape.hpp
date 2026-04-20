#pragma once

#include <cstdint>
#include <ostream>

namespace numc {
	
	struct Shape {
		size_t rows;
		size_t cols;
		size_t size;
		bool square;
		
		Shape(uint32_t rows, uint32_t cols) : rows(rows), cols(cols), size(rows * cols), square(rows == cols) {}

		friend bool operator==(const Shape shapeA, const Shape shapeB) {
			return shapeA.rows == shapeB.rows && shapeA.cols == shapeB.cols;
		}

		friend bool operator!=(const Shape shapeA, const Shape shapeB) {
			return shapeA.rows != shapeB.rows || shapeA.cols != shapeB.cols;
		}

		friend std::ostream& operator<<(std::ostream& os, const Shape& shape) {	
			os << "(" << shape.rows << ", " << shape.cols << ")";
			return os;
	
		}
	};
}
