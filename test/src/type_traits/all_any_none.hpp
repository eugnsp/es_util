#pragma once
#include <esu/type_traits.hpp>

TEST(type_traits_all_test, main)
{
	EXPECT_TRUE(esu::all<>);

	EXPECT_FALSE(esu::all<false>);
	EXPECT_TRUE(esu::all<true>);

	EXPECT_FALSE((esu::all<false, false, false>));
	EXPECT_FALSE((esu::all<false, true, true>));
	EXPECT_FALSE((esu::all<true, false, true>));
	EXPECT_TRUE((esu::all<true, true, true>));
}

TEST(type_traits_any_test, main)
{
	EXPECT_FALSE(esu::any<>);

	EXPECT_FALSE(esu::any<false>);
	EXPECT_TRUE(esu::any<true>);

	EXPECT_FALSE((esu::any<false, false, false>));
	EXPECT_TRUE((esu::any<false, true, true>));
	EXPECT_TRUE((esu::any<true, false, true>));
	EXPECT_TRUE((esu::any<true, true, true>));
}

TEST(type_traits_none_test, main)
{
	EXPECT_TRUE(esu::none<>);

	EXPECT_TRUE(esu::none<false>);
	EXPECT_FALSE(esu::none<true>);

	EXPECT_TRUE((esu::none<false, false, false>));
	EXPECT_FALSE((esu::none<false, true, true>));
	EXPECT_FALSE((esu::none<true, false, true>));
	EXPECT_FALSE((esu::none<true, true, true>));
}
