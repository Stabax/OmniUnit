//duration.hh

/*
Copyright (c) 1998, Regents of the University of California All rights
reserved. Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

  Redistributions of source code must retain the above copyright notice,
  this list of conditions and the following disclaimer.
  Redistributions in binary form must reproduce the above copyright notice,
  this list of conditions and the following disclaimer in the documentation
  and/or other materials provided with the distribution.
  Neither the name of the University of California, Berkeley nor the names
  of its contributors may be used to endorse or promote products derived
  from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS "AS IS" AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE REGENTS AND CONTRIBUTORS BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef DURATION_HH_
#define DURATION_HH_

#include"constants_for_units.hh"

namespace stb
{



namespace omni
{



typedef Dimension<0, 0, 1, 0, 0, 0, 0> Duration;



//cast stb::duration to another stb::duration
template <typename toRep, typename toPeriod, typename Rep, typename Period,
typename = typename std::enable_if<is_stb_Ratio<toPeriod>::value, toPeriod>::type>
constexpr Unit<Duration, toRep, toPeriod>
duration_cast(Unit<Duration, Rep, Period> const& Obj)
{
  return unit_cast<Unit<Duration, toRep, toPeriod>>(Obj);
}


//cast stb::duration to std::chrono::duration
template <typename toRep, typename toPeriod, typename Rep, typename Period,
typename = typename std::enable_if<is_std_Ratio<toPeriod>::value, toPeriod>::type>
constexpr std::chrono::duration<toRep, toPeriod>
duration_cast(Unit<Duration, Rep, Period> const& Obj)
{
  return std::chrono::duration<toRep, toPeriod>(Obj);
}


//cast stb::duration to toUnit
template <typename toUnit, typename Rep, typename Period>
toUnit duration_cast(Unit<Duration, Rep, Period> const& Obj)
{
  return unit_cast<toUnit>(Obj);
}


//cast std::chrono::duration to toUnit
template <typename toUnit, typename Rep, typename Period>
toUnit duration_cast(std::chrono::duration<Rep, Period> const& Obj)
{
  return unit_cast<toUnit>(Obj);
}



template <typename Rep = OMNI_DEFAULT_TYPE>
using yoctosecond = Unit<Duration, Rep, yocto>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using zeptosecond = Unit<Duration, Rep, zepto>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using attosecond = Unit<Duration, Rep, atto>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using femtosecond = Unit<Duration, Rep, femto>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using picosecond = Unit<Duration, Rep, pico>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using nanosecond = Unit<Duration, Rep, nano>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using microsecond = Unit<Duration, Rep, micro>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using millisecond = Unit<Duration, Rep, milli>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using centisecond = Unit<Duration, Rep, centi>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using decisecond = Unit<Duration, Rep, deci>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using second = Unit<Duration, Rep, base>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using decasecond = Unit<Duration, Rep, deca>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using hectosecond = Unit<Duration, Rep, hecto>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using kilosecond = Unit<Duration, Rep, kilo>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using megasecond = Unit<Duration, Rep, mega>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using gigasecond = Unit<Duration, Rep, giga>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using terasecond = Unit<Duration, Rep, tera>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using petasecond = Unit<Duration, Rep, peta>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using exasecond = Unit<Duration, Rep, exa>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using zettasecond = Unit<Duration, Rep, zetta>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using yottasecond = Unit<Duration, Rep, yotta>;





template <typename Rep = OMNI_DEFAULT_TYPE>
using minute = Unit<Duration, Rep, Ratio<secondsIn1Min, E0>>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using hour = Unit<Duration, Rep, Ratio<secondsIn1Hour, E0>>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using day = Unit<Duration, Rep, Ratio<secondsIn1Day, E0>>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using week = Unit<Duration, Rep, Ratio<secondsIn1Week, E0>>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using month = Unit<Duration, Rep, secondsIn1Month>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using year = Unit<Duration, Rep, secondsIn1Year>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using kiloyear = Unit<Duration, Rep, typename Ratio_multiply<
typename year<Rep>::period, kilo>::type>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using megayear = Unit<Duration, Rep, typename Ratio_multiply<
typename year<Rep>::period, mega>::type>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using gigayear = Unit<Duration, Rep, typename Ratio_multiply<
typename year<Rep>::period, giga>::type>;



namespace def
{



typedef zeptosecond<> zeptosecond;
typedef femtosecond<>  femtosecond;
typedef picosecond<> picosecond;
typedef nanosecond<> nanosecond;
typedef microsecond<> microsecond;
typedef millisecond<> millisecond;
typedef centisecond<> centisecond;
typedef decisecond<> decisecond;
typedef second<> second;
typedef decasecond<> decasecond;
typedef hectosecond<> hectosecond;
typedef kilosecond<> kilosecond;
typedef megasecond<> megasecond;
typedef gigasecond<> gigasecond;
typedef terasecond<> terasecond;
typedef petasecond<> petasecond;
typedef exasecond<> exasecond;
typedef zettasecond<> zettasecond;
typedef yottasecond<> yottasecond;

typedef minute<> minute;
typedef hour<> hour;
typedef day<> day;
typedef week<> week;
typedef month<> month;
typedef year<> year;
typedef kiloyear<> kiloyear;
typedef megayear<> megayear;
typedef gigayear<> gigayear;



}



} //namespace omni



} //namespace stb

#endif //DURATION_HH_
