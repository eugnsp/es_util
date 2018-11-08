#include <es_util/algorithm.hpp>

#include <cassert>
#include <iostream>
#include <vector>

void find_empty()
{
	std::vector<int> v;

	const auto p1 = es_util::find(v.begin(), v.end(), 1);
	const auto p2 = es_util::find_if(v.begin(), v.end(), [](int) { return true; });
		
	assert(p1 == v.end());
	assert(p2 == v.end());	
}

void find_not_found()
{
	std::vector<int> v{1, 2, 2, 4};

	const auto p1 = es_util::find(v.begin(), v.end(), 3);
	const auto p2 = es_util::find_if(v.begin(), v.end(), [](int x) { return x == 3; });
		
	assert(p1 == v.end());
	assert(p2 == v.end());	
}

void find_found()
{
	std::vector<int> v{1, 2, 2, 4};

	const auto p1 = es_util::find(v.begin(), v.end(), 2);
	const auto p2 = es_util::find_if(v.begin(), v.end(), [](int x) { return x == 2; });
		
	assert(p1 == v.begin() + 1);
	assert(p2 == v.begin() + 1);	
}

int main()
{
	find_empty();
	find_not_found();
	find_found();

	std::cout << "OK.\n";
	return 0;
}