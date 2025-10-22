#include "segment.hpp"
#include <cmath>
#include "math.hpp"
float sdc::segment::len() const {
	return (c1 - c2).len();
}
