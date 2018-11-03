#pragma once
#include <es_util/algorithm.hpp>
#include <vector>

TEST(find_test, empty)
{
	std::vector<int> v;

	const auto p1 = es_util::find(v.begin(), v.end(), 1);
	const auto p2 = es_util::find_if(v.begin(), v.end(), [](int) { return true; });
		
	EXPECT_EQ(p1, (v.end()));
	EXPECT_EQ(p2, (v.end()));	
}

TEST(find_test, not_found)
{
	std::vector<int> v{1, 2, 2, 4};

	const auto p1 = es_util::find(v.begin(), v.end(), 3);
	const auto p2 = es_util::find_if(v.begin(), v.end(), [](int x) { return x == 3; });
		
	EXPECT_EQ(p1, (v.end()));
	EXPECT_EQ(p2, (v.end()));	
}

TEST(find_test, found)
{
	std::vector<int> v{1, 2, 2, 4};

	const auto p1 = es_util::find(v.begin(), v.end(), 2);
	const auto p2 = es_util::find_if(v.begin(), v.end(), [](int x) { return x == 2; });
		
	EXPECT_EQ(p1, (v.begin() + 1));
	EXPECT_EQ(p2, (v.begin() + 1));	
}

