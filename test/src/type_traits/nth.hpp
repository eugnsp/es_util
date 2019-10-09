#pragma once
#include <esu/type_traits.hpp>

TEST(type_traits_nth_test, main)
{
	testing::StaticAssertTypeEq<esu::Nth<0, int>, int>();

	testing::StaticAssertTypeEq<esu::Nth<0, int, double, float>, int>();
	testing::StaticAssertTypeEq<esu::Nth<1, int, double, float>, double>();
	testing::StaticAssertTypeEq<esu::Nth<2, int, double, float>, float>();

	testing::StaticAssertTypeEq<esu::Head<int>, int>();
	testing::StaticAssertTypeEq<esu::Head<int, double, float>, int>();

	SUCCEED();
}
