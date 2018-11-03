#pragma once
#include <utility>

namespace es_util
{
template<class Iter_begin, class Iter_end = Iter_begin>
class Iterable
{
public:
	Iterable(Iter_begin begin, Iter_end end) :
		begin_(std::move(begin)), end_(std::move(end))
	{ }

	Iter_begin begin() const
	{
		return begin_;
	}

	Iter_end end() const
	{
		return end_;
	}

	bool empty() const
	{
		return begin_ == end_;
	}

private:
	const Iter_begin begin_;
	const Iter_end end_;
};
}