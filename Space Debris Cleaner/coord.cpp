#include "coord.hpp"
#include <cmath>
float sdc::coord::len() const {
	return std::sqrt(x * x + y * y);
}
