#pragma once
#include <es_util/type_traits.hpp>

TEST(type_traits_nth_test, main)
{
	testing::StaticAssertTypeEq<es_util::Nth<0, int>, int>();

	testing::StaticAssertTypeEq<es_util::Nth<0, int, double, float>, int>();
	testing::StaticAssertTypeEq<es_util::Nth<1, int, double, float>, double>();
	testing::StaticAssertTypeEq<es_util::Nth<2, int, double, float>, float>();

	testing::StaticAssertTypeEq<es_util::Head<int>, int>();
	testing::StaticAssertTypeEq<es_util::Head<int, double, float>, int>();

	SUCCEED();
}
