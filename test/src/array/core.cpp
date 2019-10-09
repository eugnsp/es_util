#include <esu/array.hpp>
#include <esu/type_traits.hpp>

#include <array>
#include <cassert>
#include <iostream>
#include <memory>
#include <type_traits>

struct B
{
	virtual int foo()
	{
		return 1;
	}
};

struct D : B
{
	virtual int foo()
	{
		return 2;
	}
};

void array_size()
{
	using A0 = std::array<int, 0>;
	using A1 = std::array<int, 1>;

	static_assert(esu::array_size<A0> == 0);
	static_assert(esu::array_size<const A0> == 0);
	static_assert(esu::array_size<A0&> == 0);
	static_assert(esu::array_size<const A0&> == 0);

	static_assert(esu::array_size<A1> == 1);
	static_assert(esu::array_size<const A1> == 1);
	static_assert(esu::array_size<A1&> == 1);
	static_assert(esu::array_size<const A1&> == 1);
}

void make_array()
{
	constexpr auto a1 = esu::make_array(1, 2);
	static_assert(std::is_same_v<esu::Remove_cvref<decltype(a1)>::value_type, int>);

	static_assert(a1[0] == 1);
	static_assert(a1[1] == 2);

	constexpr auto a2 = esu::make_array(1, 3.0);
	static_assert(std::is_same_v<esu::Remove_cvref<decltype(a2)>::value_type, double>);

	static_assert(a2[0] == 1.0);
	static_assert(a2[1] == 3.0);
}

void make_array_move()
{
	auto ptr1 = std::make_unique<int>(1);
	auto ptr2 = std::make_unique<int>(2);

	auto a = esu::make_array(std::move(ptr1), std::move(ptr2));
	assert(!!a[0]);
	assert(!!a[1]);

	assert(*a[0] == 1);
	assert(*a[1] == 2);

	auto ptr_b = std::make_unique<B>();
	auto ptr_d = std::make_unique<D>();

	auto b = esu::make_array(std::move(ptr_b), std::move(ptr_d));
	static_assert(
		std::is_same_v<esu::Remove_cvref<decltype(b)>::value_type, std::unique_ptr<B>>);

	assert(!!b[0]);
	assert(!!b[1]);

	assert(b[0]->foo() == 1);
	assert(b[1]->foo() == 2);
}

int main()
{
	array_size();
	make_array();
	make_array_move();

	std::cout << "OK.\n";
	return 0;
}
