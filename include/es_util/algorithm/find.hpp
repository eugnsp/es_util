#pragma once

namespace es_util
{
template<class Input_iterator1, class Input_iterator2, class Predicate>
Input_iterator1 find_if(Input_iterator1 first, Input_iterator2 last, Predicate pred)
{
	for (; first != last; ++first)
		if (pred(*first))
			break;

	return first;
}

template<class Input_iterator1, class Input_iterator2, typename T>
Input_iterator1 find(Input_iterator1 first, Input_iterator2 last, const T& value)
{
	return ::es_util::find_if(first, last, [&value](const auto& v) { return v == value; });
}
}