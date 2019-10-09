#include <esu/algorithm.hpp>

#include <cassert>
#include <iostream>
#include <vector>

void circ_permutation_empty()
{
	std::vector<int> v1;
	std::vector<int> v2;

	assert(esu::is_circ_permutation(v1.begin(), v1.end(), v2.begin()));
}

void circ_permutation_true()
{
	std::vector<int> v1{1, 2, 3, 4, 5, 6, 7};
	std::vector<int> v2{3, 4, 5, 6, 7, 1, 2};
	std::vector<int> v3{5, 6, 7, 1, 2, 3, 4};

	assert(esu::is_circ_permutation(v1.begin(), v1.end(), v2.begin()));
	assert(esu::is_circ_permutation(v1.begin(), v1.end(), v3.begin()));
}

void circ_permutation_false()
{
	std::vector<int> v1{1, 2, 3, 4, 5, 6, 7};
	std::vector<int> v2{4, 3, 5, 6, 7, 1, 2};
	std::vector<int> v3{6, 5, 7, 1, 2, 3, 4};
	std::vector<int> v4{9, 5, 7, 1, 2, 3, 4};

	assert(!esu::is_circ_permutation(v1.begin(), v1.end(), v2.begin()));
	assert(!esu::is_circ_permutation(v1.begin(), v1.end(), v3.begin()));
	assert(!esu::is_circ_permutation(v1.begin(), v1.end(), v4.begin()));
}

int main()
{
	circ_permutation_empty();
	circ_permutation_true();
	circ_permutation_false();

	std::cout << "OK.\n";
	return EXIT_SUCCESS;
}
