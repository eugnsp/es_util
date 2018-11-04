#pragma once
#include <es_util/array.hpp>
#include <es_util/type_traits.hpp>
#include <array>
#include <memory>

TEST(array_core_test, array_size)
{
	using A0 = std::array<int, 0>;
	using A1 = std::array<int, 1>;

	static_assert(es_util::array_size<A0> == 0);
	static_assert(es_util::array_size<const A0> == 0);
	static_assert(es_util::array_size<A0&> == 0);
	static_assert(es_util::array_size<const A0&> == 0);

	static_assert(es_util::array_size<A1> == 1);
	static_assert(es_util::array_size<const A1> == 1);
	static_assert(es_util::array_size<A1&> == 1);
	static_assert(es_util::array_size<const A1&> == 1);

	SUCCEED();
}

TEST(array_core_test, make_array)
{
	auto a1 = es_util::make_array(1, 2);
	testing::StaticAssertTypeEq<es_util::Remove_cvref<decltype(a1)>::value_type, int>();

	EXPECT_EQ(a1[0], 1);	
	EXPECT_EQ(a1[1], 2);	

	auto a2 = es_util::make_array(1, 3.0);
	testing::StaticAssertTypeEq<es_util::Remove_cvref<decltype(a2)>::value_type, double>();

	EXPECT_EQ(a2[0], 1.0);	
	EXPECT_EQ(a2[1], 3.0);
}

TEST(array_core_test, make_array_move)
{
	auto ptr1 = std::make_unique<int>(1);
	auto ptr2 = std::make_unique<int>(2);
	
	auto a = es_util::make_array(std::move(ptr1), std::move(ptr2));
	ASSERT_TRUE(!!a[0]);
	ASSERT_TRUE(!!a[1]);

	EXPECT_EQ(*a[0], 1);	
	EXPECT_EQ(*a[1], 2);	
	
	struct B { virtual int foo() { return 1; } };
	struct D : B { virtual int foo() { return 2; } };
	
	auto ptr_b = std::make_unique<B>();
	auto ptr_d = std::make_unique<D>();
	
	auto b = es_util::make_array(std::move(ptr_b), std::move(ptr_d));
	testing::StaticAssertTypeEq<es_util::Remove_cvref<decltype(b)>::value_type, std::unique_ptr<B>>();

	ASSERT_TRUE(!!b[0]);
	ASSERT_TRUE(!!b[1]);

	EXPECT_EQ(b[0]->foo(), 1);	
	EXPECT_EQ(b[1]->foo(), 2);	
}
