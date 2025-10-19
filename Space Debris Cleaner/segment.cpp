#include "segment.hpp"
#include <cmath>

float sdc::segment::len() const {
	float dx = c2.x - c1.x;
	float dy = c2.y - c1.y;
	return std::sqrt(dx * dx + dy * dy);
}
