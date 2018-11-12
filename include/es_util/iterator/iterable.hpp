#pragma once
#include <utility>

namespace es_util
{
template<class Iterator_begin, class Iterator_end = Iterator_begin>
class Iterable
{
public:
	Iterable(Iterator_begin begin, Iterator_end end) :
		begin_(std::move(begin)), end_(std::move(end))
	{}

	Iterator_begin begin() const
	{
		return begin_;
	}

	Iterator_end end() const
	{
		return end_;
	}

	bool empty() const
	{
		return begin_ == end_;
	}

private:
	const Iterator_begin begin_;
	const Iterator_end end_;
};
} // namespace es_util
