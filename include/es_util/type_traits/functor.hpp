#pragma once

namespace es_util
{
struct Nop_fn
{
	template<class... Args>
	void operator()(const Args&...)
	{}
};
}
