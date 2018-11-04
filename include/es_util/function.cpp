#include "function.hpp"
#if __has_include(<mkl_version.h>)
#include <mkl_version.h>
#endif
#include <cctype>
#include <sstream>
#include <iomanip>

namespace es_util
{
// Returns size in bytes in a human readable form
std::string size_string(std::size_t size)
{
	std::stringstream str;

	if (size < 1'024U)
		str << size << " B";
	else
	{
		str << std::fixed << std::setprecision(1);
		if (size < 1'048'576U)
			str << size / 1'024. << " KB";
		else
			str << size / 1'048'576. << " MB";
	}
	return str.str();
}

std::string compiler_and_mkl_info()
{
	std::stringstream info;

#if defined(_WIN32) || defined(_WIN64)
	info << "Win";
#else
	info << "Unix";
#endif

	info << ' ';

#if defined(_WIN64) || defined(__x86_64)
	info << "64-bit";
#else
	info << "32-bit";
#endif

#ifdef _DEBUG
	info << " Debug";
#else
	info << " Release";
#endif

#ifdef __INTEL_COMPILER
	info << '\n' << "Intel C++ Compiler Version " << __INTEL_COMPILER << " (" << __INTEL_COMPILER_BUILD_DATE << ')';
#else
#ifdef _MSC_VER
	info << '\n' << "Microsoft C/C++ Compiler Version " << _MSC_FULL_VER;
#endif
#endif

#ifdef __INTEL_MKL__
	info << '\n' << "Intel MKL Version " << __INTEL_MKL__ << '.' << __INTEL_MKL_MINOR__ << '.' << __INTEL_MKL_UPDATE__
		<< " (" << __INTEL_MKL_BUILD_DATE << ')';
#endif

	return info.str();
}
}