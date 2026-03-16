#pragma once

#include <cstdint>
#include <ostream>

namespace numc {
	
	struct Shape {
		uint32_t rows;
		uint32_t cols;

		friend std::ostream& operator<<(std::ostream& os, const Shape& shape) {	
			os << "(" << shape.rows << ", " << shape.cols << ")";
			return os;
	
		}
	};
}
