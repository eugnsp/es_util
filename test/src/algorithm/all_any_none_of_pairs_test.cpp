#include <es_util/algorithm.hpp>

#include <cassert>
#include <iostream>
#include <vector>

void all_of_pairs_less_than_two()
{
	std::vector<int> v{1};

	assert(es_util::all_of_pairs(v.begin(), v.begin(), [](...) { return false; }));
	assert(es_util::all_of_pairs(v.begin(), v.end(), [](...) { return false; }));
}

void all_of_pairs_main()
{
	std::vector<int> v{1, 2, 3, 4, 5};

	assert(es_util::all_of_pairs(v.begin(), v.end(), [](int x, int y) { return x + y > 2; }));
	assert(!es_util::all_of_pairs(v.begin(), v.end(), [](int x, int y) { return x + y > 3; }));
}

void any_of_pairs_less_than_two()
{
	std::vector<int> v{1};

	assert(!es_util::any_of_pairs(v.begin(), v.begin(), [](...) { return true; }));
	assert(!es_util::any_of_pairs(v.begin(), v.end(), [](...) { return true; }));
}

void any_of_pairs_main()
{
	std::vector<int> v{1, 2, 3, 4, 5};

	assert(es_util::any_of_pairs(v.begin(), v.end(), [](int x, int y) { return x + y > 8; }));
	assert(!es_util::any_of_pairs(v.begin(), v.end(), [](int x, int y) { return x + y > 9; }));
}

void none_of_pairs_less_than_two()
{
	std::vector<int> v{1};

	assert(es_util::none_of_pairs(v.begin(), v.begin(), [](...) { return false; }));
	assert(es_util::none_of_pairs(v.begin(), v.end(), [](...) { return false; }));
}

void none_of_pairs_main()
{
	std::vector<int> v{1, 2, 3, 4, 5};

	assert(es_util::none_of_pairs(v.begin(), v.end(), [](int x, int y) { return x + y > 9; }));
	assert(!es_util::none_of_pairs(v.begin(), v.end(), [](int x, int y) { return x + y > 8; }));
}

int main()
{
	all_of_pairs_less_than_two();
	all_of_pairs_main();

	any_of_pairs_less_than_two();
	any_of_pairs_main();

	none_of_pairs_less_than_two();
	none_of_pairs_main();

	std::cout << "OK.\n";
	return 0;
}