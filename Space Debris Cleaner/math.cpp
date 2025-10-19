#include "definitions.hpp"
#include "math.hpp"
#include <cmath>

// math

bool sdc::math::is_intersected(
	const sdc::segment s1, 
	const sdc::segment s2
) noexcept {
	using namespace sdc;

	const coord& A = s1.c1;
	const coord& B = s1.c2;
	const coord& C = s2.c1;
	const coord& D = s2.c2;

	float c1 = math::cross_product(B - A, C - A);
	float c2 = math::cross_product(B - A, D - A);
	float c3 = math::cross_product(D - C, A - C);
	float c4 = math::cross_product(D - C, B - C);

	if ((c1 * c2 < 0.0f) && (c3 * c4 < 0.0f))
		return true;

	if (std::fabs(c1) < math::EPS && math::in_range(A.x, B.x, C.x) && math::in_range(A.y, B.y, C.y))
		return true;
	if (std::fabs(c2) < math::EPS && math::in_range(A.x, B.x, D.x) && math::in_range(A.y, B.y, D.y))
		return true;
	if (std::fabs(c3) < math::EPS && math::in_range(C.x, D.x, A.x) && math::in_range(C.y, D.y, A.y))
		return true;
	if (std::fabs(c4) < math::EPS && math::in_range(C.x, D.x, B.x) && math::in_range(C.y, D.y, B.y))
		return true;

	return false;
}


bool sdc::math::is_intersected(
	const sdc::polygon& p1,
	const sdc::polygon& p2
) noexcept{
	const auto& A = p1.get_coords();
	const auto& B = p2.get_coords();

	constexpr float EPS = 1e-6f;

	auto test_axes_from = [&](const std::vector<sdc::coord>& polyA,
		const std::vector<sdc::coord>& polyB) -> bool {
			const size_t n = polyA.size();
			for (size_t i = 0; i < n; ++i) {
				const sdc::coord& p = polyA[i];
				const sdc::coord& q = polyA[(i + 1) % n];

				sdc::coord edge = q - p;
				sdc::coord axis(-edge.y, edge.x);

				float minA = sdc::math::inner_product(polyA[0], axis);
				float maxA = minA;
				for (const auto& v : polyA) {
					float proj = sdc::math::inner_product(v, axis);
					if (proj < minA) minA = proj;
					if (proj > maxA) maxA = proj;
				}

				float minB = sdc::math::inner_product(polyB[0], axis);
				float maxB = minB;
				for (const auto& v : polyB) {
					float proj = sdc::math::inner_product(v, axis);
					if (proj < minB) minB = proj;
					if (proj > maxB) maxB = proj;
				}

				if (maxA < minB - EPS || maxB < minA - EPS) {
					return false;
				}
			}
			return true;
		};

	if (!test_axes_from(A, B)) return false;
	if (!test_axes_from(B, A)) return false;

	return true;
}

