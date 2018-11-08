#pragma once
#include <es_util/string.hpp>
#include <string>

TEST(algorithm_ends_with_test, main)
{
	const std::string str{"string"};

	EXPECT_TRUE(es_util::ends_with(str, std::string{"ing"}));
	EXPECT_TRUE(es_util::ends_with(str, std::string{""}));
	EXPECT_FALSE(es_util::ends_with(str, std::string{"xxx"}));
	EXPECT_FALSE(es_util::ends_with(str, std::string{"long_string"}));

	EXPECT_TRUE(es_util::ends_with(str, "ing"));
	EXPECT_TRUE(es_util::ends_with(str, ""));
	EXPECT_FALSE(es_util::ends_with(str, "xxx"));
	EXPECT_FALSE(es_util::ends_with(str, "long_string"));
}
