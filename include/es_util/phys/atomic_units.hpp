#pragma once
#include <es_util/phys/const.hpp>

namespace es_util::au
{
#define ES_PHYS_DEFINE_AU_UNIT(Name, Factor)                                                       \
	inline constexpr double from_##Name(double x)                                                  \
	{                                                                                              \
		constexpr auto factor = (Factor);                                                          \
		return factor * x;                                                                         \
	}                                                                                              \
                                                                                                   \
	inline constexpr double to_##Name(double x)                                                    \
	{                                                                                              \
		constexpr auto factor = 1. / (Factor);                                                     \
		return factor * x;                                                                         \
	}                                                                                              \
                                                                                                   \
	inline namespace literals                                                                      \
	{                                                                                              \
	inline constexpr double operator"" _##Name(long double x)                                      \
	{                                                                                              \
		return from_##Name(static_cast<double>(x));                                                \
	}                                                                                              \
                                                                                                   \
	inline constexpr double operator"" _##Name(unsigned long long x)                               \
	{                                                                                              \
		return from_##Name(static_cast<double>(x));                                                \
	}                                                                                              \
	} // namespace literals

// Units of length

ES_PHYS_DEFINE_AU_UNIT(m, metre)
ES_PHYS_DEFINE_AU_UNIT(cm, cmetre)
ES_PHYS_DEFINE_AU_UNIT(nm, nmetre)
ES_PHYS_DEFINE_AU_UNIT(ang, angstrom)

// Units of time

ES_PHYS_DEFINE_AU_UNIT(sec, second)
ES_PHYS_DEFINE_AU_UNIT(msec, 1e-3 * second)
ES_PHYS_DEFINE_AU_UNIT(usec, 1e-6 * second)
ES_PHYS_DEFINE_AU_UNIT(nsec, 1e-9 * second)
ES_PHYS_DEFINE_AU_UNIT(psec, 1e-12 * second)

// Units of velocity

ES_PHYS_DEFINE_AU_UNIT(m_per_sec, metre / second)
ES_PHYS_DEFINE_AU_UNIT(cm_per_sec, cmetre / second)

// Units of concentration

ES_PHYS_DEFINE_AU_UNIT(per_cm2, 1 / (cmetre * cmetre))
ES_PHYS_DEFINE_AU_UNIT(per_cm3, 1 / (cmetre * cmetre * cmetre))

// Units of mass density

ES_PHYS_DEFINE_AU_UNIT(g_per_cm2, gram / (cmetre * cmetre))
ES_PHYS_DEFINE_AU_UNIT(ng_per_cm2, 1e-9 * gram / (cmetre * cmetre))

// Units of energy

ES_PHYS_DEFINE_AU_UNIT(ry, rydberg)
ES_PHYS_DEFINE_AU_UNIT(evolt, evolt)
ES_PHYS_DEFINE_AU_UNIT(mevolt, 1e-3 * evolt)
ES_PHYS_DEFINE_AU_UNIT(kelvin, kelvin)
ES_PHYS_DEFINE_AU_UNIT(joule, joule)

// Units of power

ES_PHYS_DEFINE_AU_UNIT(watt, joule / second)

// Units of potential

ES_PHYS_DEFINE_AU_UNIT(volt, volt)

// Units of current

ES_PHYS_DEFINE_AU_UNIT(amp, coulomb / second)
ES_PHYS_DEFINE_AU_UNIT(mamp, 1e-3 * coulomb / second)

// Units of electric field

ES_PHYS_DEFINE_AU_UNIT(volt_per_m, volt / metre)
ES_PHYS_DEFINE_AU_UNIT(volt_per_cm, volt / cmetre)
ES_PHYS_DEFINE_AU_UNIT(kvolt_per_m, 1e3 * volt / metre)
ES_PHYS_DEFINE_AU_UNIT(kvolt_per_cm, 1e3 * volt / cmetre)

// Units of mobility

ES_PHYS_DEFINE_AU_UNIT(cm2_per_volt_sec, cmetre * cmetre / (evolt * second))

// Unit of resistance

ES_PHYS_DEFINE_AU_UNIT(ohm, volt * second / coulomb)
ES_PHYS_DEFINE_AU_UNIT(mohm, 1e-3 * volt * second / coulomb)
ES_PHYS_DEFINE_AU_UNIT(kohm, 1e3 * volt * second / coulomb)

} // namespace phys::au
