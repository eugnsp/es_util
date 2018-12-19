#include <es_util/algorithm.hpp>

#include <cassert>
#include <iostream>
#include <vector>

struct S
{
	int x;
	int y;

	bool operator<(S s) const
	{
		return x < s.x;
	}
};

void sort2_main()
{
	int x1 = 1;
	int x2 = 2;
	es_util::sort2(x1, x2);

	assert(x1 == 1);
	assert(x2 == 2);

	int x3 = 2;
	int x4 = 1;
	es_util::sort2(x3, x4);

	assert(x3 == 1);
	assert(x4 == 2);
}

void sort2_stability()
{
	S s1{0, 1};
	S s2{0, 2};

	es_util::sort2(s1, s2);

	assert(s1.y == 1);
	assert(s2.y == 2);
}

int main()
{
	sort2_main();
	sort2_stability();

	std::cout << "OK.\n";
	return EXIT_SUCCESS;
}