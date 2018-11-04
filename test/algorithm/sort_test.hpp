#pragma once
#include <es_util/algorithm.hpp>
#include <vector>

TEST(algorithm_sort2_test, main)
{
	int x1 = 1;
	int x2 = 2;
	es_util::sort2(x1, x2);
	
	EXPECT_EQ(x1, 1);	
	EXPECT_EQ(x2, 2);

	int x3 = 2;
	int x4 = 1;
	es_util::sort2(x3, x4);
	
	EXPECT_EQ(x3, 1);	
	EXPECT_EQ(x4, 2);
}

TEST(algorithm_sort2_test, stability)
{
	struct S
	{
		int x;
		int y;
		
		bool operator<(S s) const
		{
			return x < s.x;
		}
	};
	
	S s1{0, 1};
	S s2{0, 2};
	
	es_util::sort2(s1, s2);
	
	EXPECT_EQ(s1.y, 1);
	EXPECT_EQ(s2.y, 2);
}
