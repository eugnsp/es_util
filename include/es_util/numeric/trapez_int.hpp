#pragma once
#include <cassert>

namespace es_util
{
template<typename N, class Xs, class Fn, typename T>
auto trapez_int(N n_points, Xs&& xs, Fn&& fn, const T init)
{
	auto value = init;

	N i{};
	assert(i != n_points && i + 1 != n_points);

	value += (xs(i + 1) - xs(i)) * fn(i);

	--n_points;
	while (++i < n_points)
		value += (xs(i + 1) - xs(i - 1)) * fn(i);

	value += (xs(n_points) - xs(n_points - 1)) * fn(n_points);
	value *= .5;

	return value;
}
}
