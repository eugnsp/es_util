#include <es_util/algorithm.hpp>

#include <cassert>
#include <iostream>
#include <vector>

void for_each_pair_empty()
{
	std::vector<int> v{};

	int n = 0;
	es_util::for_each_pair(v.begin(), v.end(), [&n](...) { ++n; });
	assert(n == 0);
}

void for_each_pair_one()
{
	std::vector<int> v{1};

	int n = 0;
	es_util::for_each_pair(v.begin(), v.end(), [&n](...) { ++n; });
	assert(n == 0);
}

void for_each_pair_two()
{
	std::vector<int> v{1, 2};
	std::vector<std::pair<int, int>> o;

	es_util::for_each_pair(v.begin(), v.end(), [&o](int x, int y) { o.push_back({x, y}); });

	assert(o.size() == 1);
	assert(o.front() == std::make_pair(1, 2));
}

void for_each_pair_main()
{
	std::vector<int> v{1, 2, 3, 4, 5};
	std::vector<std::pair<int, int>> o;

	es_util::for_each_pair(v.begin(), v.end(), [&o](int x, int y) { o.push_back({x, y}); });

	assert(o.size() == 4);
	assert(o[0] == std::make_pair(1, 2));
	assert(o[1] == std::make_pair(2, 3));
	assert(o[2] == std::make_pair(3, 4));
	assert(o[3] == std::make_pair(4, 5));
}

void for_each_pair_n_negative_zero()
{
	std::vector<int> v{1, 2, 3, 4, 5};

	int n = 0;
	es_util::for_each_pair_n(v.begin(), -1, [&n](...) { ++n; });
	assert(n == 0);
}

void for_each_pair_n_zero()
{
	std::vector<int> v{1, 2, 3, 4, 5};

	int n = 0;
	es_util::for_each_pair_n(v.begin(), 0, [&n](...) { ++n; });
	assert(n == 0);
}

void for_each_pair_n_main()
{
	std::vector<int> v{1, 2, 3, 4, 5};
	std::vector<std::pair<int, int>> o;

	es_util::for_each_pair_n(v.begin(), 4, [&o](int x, int y) { o.push_back({x, y}); });

	assert(o.size() == 4);
	assert(o[0] == std::make_pair(1, 2));
	assert(o[1] == std::make_pair(2, 3));
	assert(o[2] == std::make_pair(3, 4));
	assert(o[3] == std::make_pair(4, 5));

	o.clear();
	es_util::for_each_pair_n(v.begin() + 1, 3, [&o](int x, int y) { o.push_back({x, y}); });

	assert(o.size() == 3);
	assert(o[0] == std::make_pair(2, 3));
	assert(o[1] == std::make_pair(3, 4));
	assert(o[2] == std::make_pair(4, 5));
}

int main()
{
	for_each_pair_empty();
	for_each_pair_one();
	for_each_pair_two();
	for_each_pair_main();
	for_each_pair_n_negative_zero();
	for_each_pair_n_zero();
	for_each_pair_n_main();

	std::cout << "OK.\n";
	return EXIT_SUCCESS;
}