#pragma once
#include <es_util/type_traits.hpp>

TEST(type_traits_all_test, main)
{
	EXPECT_TRUE(es_util::all<>);

	EXPECT_FALSE(es_util::all<false>);
	EXPECT_TRUE(es_util::all<true>);

	EXPECT_FALSE((es_util::all<false, false, false>));
	EXPECT_FALSE((es_util::all<false, true, true>));
	EXPECT_FALSE((es_util::all<true, false, true>));
	EXPECT_TRUE((es_util::all<true, true, true>));
}

TEST(type_traits_any_test, main)
{
	EXPECT_FALSE(es_util::any<>);

	EXPECT_FALSE(es_util::any<false>);
	EXPECT_TRUE(es_util::any<true>);

	EXPECT_FALSE((es_util::any<false, false, false>));
	EXPECT_TRUE((es_util::any<false, true, true>));
	EXPECT_TRUE((es_util::any<true, false, true>));
	EXPECT_TRUE((es_util::any<true, true, true>));
}

TEST(type_traits_none_test, main)
{
	EXPECT_TRUE(es_util::none<>);

	EXPECT_TRUE(es_util::none<false>);
	EXPECT_FALSE(es_util::none<true>);

	EXPECT_TRUE((es_util::none<false, false, false>));
	EXPECT_FALSE((es_util::none<false, true, true>));
	EXPECT_FALSE((es_util::none<true, false, true>));
	EXPECT_FALSE((es_util::none<true, true, true>));
}
