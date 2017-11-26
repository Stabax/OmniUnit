//Length.hh

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

#ifndef LENGTH_HH_
#define LENGTH_HH_

#include "Unit.hpp" // Unit

namespace stb
{



//previous declaration needed to define cast
template<typename Rep, typename Period>
class Length;



//=============================================================================
//=============================================================================
// CAST =======================================================================
//=============================================================================
//=============================================================================



template<typename toUnit, typename new_ratio, typename common_rep,
bool NumIsOne = false, bool DenIsOne = false>
class length_cast_impl : public casting_type_trait
{
public:

  template<typename Rep, typename Period>
  static constexpr toUnit cast(Length<Rep, Period> const& Obj)
  {
    typedef typename toUnit::rep rep;

    return toUnit(static_cast<rep>(static_cast<common_rep>(Obj.count())
      * static_cast<common_rep>(new_ratio::num) / static_cast<common_rep>(new_ratio::den)));
  }
};


template<typename toUnit, typename new_ratio, typename common_rep>
class length_cast_impl<toUnit, new_ratio, common_rep, true, true> : public casting_type_trait
{
public:

  template<typename Rep, typename Period>
  static constexpr toUnit cast(Length<Rep, Period> const& Obj)
  {
    typedef typename toUnit::rep rep;
    return toUnit(static_cast<rep>(Obj.count()));
  }
};


template<typename toUnit, typename new_ratio, typename common_rep>
class length_cast_impl<toUnit, new_ratio, common_rep, true, false> : public casting_type_trait
{
public:

  template<typename Rep, typename Period>
  static constexpr toUnit cast(Length<Rep, Period> const& Obj)
  {
    typedef typename toUnit::rep rep;
    return toUnit(static_cast<rep>(
    static_cast<common_rep>(Obj.count()) / static_cast<common_rep>(new_ratio::den)));
  }
};


template<typename toUnit, typename new_ratio, typename common_rep>
class length_cast_impl<toUnit, new_ratio, common_rep, false, true> : public casting_type_trait
{
public:

  template<typename Rep, typename Period>
  static constexpr toUnit
  cast(Length<Rep, Period> const& Obj)
  {
    typedef typename toUnit::rep rep;
    return toUnit(static_cast<rep>(
    static_cast<common_rep>(Obj.count()) * static_cast<common_rep>(new_ratio::num)));
  }
};


template<typename falseType>
class is_Length : public std::false_type
{
};


template<typename Rep, typename Period>
class is_Length<Length<Rep, Period>> : public std::true_type
{
};


template<typename toUnit, typename Rep, typename Period>
constexpr typename std::enable_if<is_Length<toUnit>::value, toUnit>::type
length_cast(const Length<Rep, Period>& Obj)
{
  typedef typename toUnit::period period;
  typedef typename toUnit::rep rep;
  typedef std::ratio_divide<Period, period> new_ratio;
  typedef typename std::common_type<rep, Rep, intmax_t>::type common_rep;
  typedef  length_cast_impl<toUnit, new_ratio,
  common_rep, new_ratio::num == 1, new_ratio::den == 1> type;
  return type::cast(Obj);
}





//=============================================================================
//=============================================================================
// DEFINITION =================================================================
//=============================================================================
//=============================================================================



template<typename Rep, typename Period = std::ratio<1>>
class Length : public Unit<Rep, Period>
{
public:

  typedef Rep    rep;
  typedef Period period;


  static_assert(! is_Length<Rep>::value, "rep cannot be a Length");
  static_assert(std::chrono::__is_ratio<Period>::value,
  "period must be a specialization of ratio");
  static_assert(Period::num > 0, "period must be positive");


  constexpr Length() = default;
  Length(Length const&) = default;


  template<typename _Rep, typename = typename std::enable_if<std::is_convertible<_Rep, Rep>::value
  && (std::chrono::treat_as_floating_point<Rep>::value || !std::chrono::treat_as_floating_point<_Rep>::value)>::type>
  constexpr explicit Length(_Rep const& countArg):
  Unit<Rep, Period>(static_cast<Rep>(countArg))
  {
  }


  template<typename _Rep, typename _Period, typename = typename std::enable_if<std::chrono::treat_as_floating_point<Rep>::value
  || (std::ratio_divide<_Period, Period>::den == 1 && !std::chrono::treat_as_floating_point<_Rep>::value)>::type>
  constexpr Length(Length<_Rep, _Period> const& Obj):
  Unit<Rep, Period>(length_cast<Length>(Obj).count())
  {
  }


  ~Length() = default;
  Length& operator=(Length const&) = default;


  static constexpr Length zero()
  {
    return Length(0);
  }


  Length& operator++()
  {
    ++Unit<Rep, Period>::_count;
    return *this;
  }


  Length operator++(int)
  {
    return Length(Unit<Rep, Period>::_count++);
  }


  Length& operator--()
  {
    --Unit<Rep, Period>::_count;
    return *this;
  }


  Length operator--(int)
  {
    return Length(Unit<Rep, Period>::_count--);
  }


  Length& operator+=(Length const& Obj)
  {
    Unit<Rep, Period>::_count += Obj.count();
    return *this;
  }


  Length& operator-=(Length const& Obj)
  {
    Unit<Rep, Period>::_count -= Obj.count();
    return *this;
  }


  Length& operator*=(Rep coef)
  {
    Unit<Rep, Period>::_count *= coef;
    return *this;
  }


  Length& operator/=(Rep coef)
  {
    if(coef == 0)
      throw Unit_exception("Divide by 0.");
    Unit<Rep, Period>::_count /= coef;
    return *this;
  }


  template <typename _Rep = Rep>
  typename std::enable_if<!std::chrono::treat_as_floating_point<_Rep>::value, Length&>::type
  operator%=(Rep const& coef)
  {
    if(coef == 0)
      throw Unit_exception("Divide by 0.");
    Unit<Rep, Period>::_count %= coef;
    return *this;
  }


  template <typename _Rep = Rep>
  typename std::enable_if<!std::chrono::treat_as_floating_point<_Rep>::value, Length&>::type
  operator%=(Length const& Obj)
  {
    if(Obj.count() == 0)
      throw Unit_exception("Divide by 0.");
    Unit<Rep, Period>::_count %= Obj.count();
    return *this;
  }
};





//=============================================================================
//=============================================================================
// OPERATORS ==================================================================
//=============================================================================
//=============================================================================



template <typename Rep1, typename Period1, typename Rep2, typename Period2>
constexpr typename std::common_type<Length<Rep1,Period1>, Length<Rep2,Period2>>::type
operator+ (Length<Rep1,Period1> const& Obj1, Length<Rep2,Period2> const& Obj2)
{
  typedef typename std::common_type<Length<Rep1,Period1>, Length<Rep2,Period2>>::type type;
  return type(type(Obj1).count() + type(Obj2).count());
}


template <typename Rep1, typename Period1, typename Rep2, typename Period2>
constexpr typename std::common_type<Length<Rep1,Period1>, Length<Rep2,Period2>>::type
operator- (Length<Rep1,Period1> const& Obj1, Length<Rep2,Period2> const& Obj2)
{
  typedef typename std::common_type<Length<Rep1,Period1>, Length<Rep2,Period2>>::type type;
  return type(type(Obj1).count() - type(Obj2).count());
}


template <typename Rep, typename Period, typename coefType>
constexpr Length<typename std::chrono::__common_rep_type<Rep, coefType>::type, Period>
operator* (Length<Rep, Period> const& Obj, coefType const& coef)
{
  typedef typename std::common_type<Rep, coefType>::type common;
  typedef Length<common, Period> type;
  return type(type(Obj).count() * coef);
}


template <typename Rep, typename Period, typename coefType>
constexpr Length<typename std::chrono::__common_rep_type<Rep, coefType>::type, Period>
operator* (coefType const& coef, Length<Rep, Period> const& Obj)
{
  return Obj * coef;
}


template <typename Rep, typename Period, typename coefType>
constexpr Length<typename std::chrono::__common_rep_type<Rep, typename
std::enable_if<!is_Length<coefType>::value, coefType>::type>::type, Period>
operator/ (Length<Rep, Period> const& Obj, coefType const& coef)
{
  if(coef == 0)
    throw Unit_exception("Divide by 0.");
  typedef typename std::common_type<Rep, coefType>::type common;
  typedef Length<common, Period> type;
  return type(type(Obj).count() / coef);
}


template <typename Rep1, typename Period1, typename Rep2, typename Period2>
constexpr typename std::common_type<Rep1, Rep2>::type
operator/ (Length<Rep1,Period1> const& Obj1, Length<Rep2,Period2> const& Obj2)
{
  if(Obj2.count() == 0)
    throw Unit_exception("Divide by 0.");
  typedef typename std::common_type<Length<Rep1,Period1>, Length<Rep2,Period2>>::type type;
  return type(Obj1).count() / type(Obj2).count();
}


template <typename Rep, typename Period, typename coefType>
constexpr Length<typename std::chrono::__common_rep_type<Rep, typename
std::enable_if<!is_Length<coefType>::value, coefType>::type>::type, Period>
operator% (Length<Rep, Period> const& Obj, coefType const& coef)
{
  if(coef == 0)
    throw Unit_exception("Divide by 0.");
  typedef Length<typename std::common_type<Rep, coefType>::type, Period> type;
  return type(type(Obj).count() % coef);
}


template <typename Rep1, typename Period1, typename Rep2, typename Period2>
constexpr typename std::common_type<Length<Rep1,Period1>, Length<Rep2,Period2>>::type
operator% (Length<Rep1,Period1> const& Obj1, Length<Rep2,Period2> const& Obj2)
{
  if(Obj2.count() == 0)
    throw Unit_exception("Divide by 0.");
  typedef typename std::common_type<Length<Rep1,Period1>, Length<Rep2,Period2>>::type type;
  return type(type(Obj1).count() % type(Obj2).count());
}


template <typename Rep1, typename Period1, typename Rep2, typename Period2>
constexpr bool operator==(Length<Rep1,Period1> const& Obj1, Length<Rep2,Period2> const& Obj2)
{
  typedef typename std::common_type<Length<Rep1,Period1>, Length<Rep2,Period2>>::type type;
  return type(Obj1).count() == type(Obj2).count();
}


template <typename Rep1, typename Period1, typename Rep2, typename Period2>
constexpr bool operator!=(Length<Rep1,Period1> const& Obj1, Length<Rep2,Period2> const& Obj2)
{
  return !(Obj1 == Obj2);
}


template <typename Rep1, typename Period1, typename Rep2, typename Period2>
constexpr bool operator<(Length<Rep1,Period1> const& Obj1, Length<Rep2,Period2> const& Obj2)
{
  typedef typename std::common_type<Length<Rep1,Period1>, Length<Rep2,Period2>>::type type;
  return type(Obj1).count() < type(Obj2).count();
}


template <typename Rep1, typename Period1, typename Rep2, typename Period2>
constexpr bool operator<=(Length<Rep1,Period1> const& Obj1, Length<Rep2,Period2> const& Obj2)
{
  return !(Obj2 < Obj1);
}


template <typename Rep1, typename Period1, typename Rep2, typename Period2>
constexpr bool operator>(Length<Rep1,Period1> const& Obj1, Length<Rep2,Period2> const& Obj2)
{
  return Obj2 < Obj1;
}


template <typename Rep1, typename Period1, typename Rep2, typename Period2>
constexpr bool operator>=(Length<Rep1,Period1> const& Obj1, Length<Rep2,Period2> const& Obj2)
{
  return ! (Obj1 < Obj2);
}





//=============================================================================
//=============================================================================
// TYPEDEF ====================================================================
//=============================================================================
//=============================================================================



template<typename Rep, typename period = std::ratio<1>>
using Ray = Length<Rep, period>;





typedef Length<float, std::atto>                            attometer;
typedef Length<float, std::femto>                           femtometer;
typedef Length<float, std::pico>                            picometer;
typedef Length<float,
std::__ratio_multiply<std::nano, std::ratio<1, 10>>::type>  angstrom;
typedef Length<float, std::nano>                            nanometer;
typedef Length<float, std::micro>                           micrometer;
typedef Length<float, std::milli>                           millimeter;
typedef Length<float, std::centi>                           centimeter;
typedef Length<float, std::ratio<1, 1>>                     meter;
typedef Length<float, std::kilo>                            kilometer;
typedef Length<float, std::mega>                            megameter;
typedef Length<float, std::ratio<299792458, 1>>             lightsecond;
typedef Length<float, std::giga>                            gigameter;
typedef Length<float,
std::__ratio_multiply<std::ratio<299792458, 1>,
std::ratio<60, 1>>::type>                                   lightminute;
typedef Length<float, std::ratio<149597870700, 1>>          astronomical_unit;
typedef Length<float, std::tera>                            terameter;
typedef Length<float, std::peta>                            petameter;
typedef Length<float,
std::__ratio_multiply<lightminute::period,
std::ratio<60*24*36525, 100>>::type>                        lightyear;
//value of parsec is approximated because of pi...
typedef Length<float,
std::__ratio_multiply<lightyear::period,
std::ratio<32616, 10000>>::type>                            parsec;
typedef Length<float, std::exa>                             exameter;
//these units involve overflow error
/*
typedef Length<float,
std::__ratio_multiply<parsec::period, std::kilo>::type>     kiloparsec;
typedef Length<float,
std::__ratio_multiply<parsec::period, std::mega>::type>     megaparsec;
typedef Length<float,
std::__ratio_multiply<parsec::period, std::giga>::type>     gigaparsec;
*/





//=============================================================================
//=============================================================================
// CONSTANT ===================================================================
//=============================================================================
//=============================================================================



namespace constant
{

//Planck Lenght
const attometer Lp(0.00000000000000001616299); //+-38

//Bohr ray
const angstrom Rb(0.52917721092); //+-17

//planets ray
const kilometer Rsun(695700);
const kilometer Rmercury(695700);
const kilometer Rvenus(695700);
const kilometer Rearth(6371);
const kilometer Rmoon(1737);
const kilometer Rmars(3390);
const kilometer Rjupiter(69911);
const kilometer Rsaturn(58232);
const kilometer Ruranus(25362);
const kilometer Rneptune(24622);

//distance with the sun
const kilometer Lmercury(57910000);
const kilometer Lvenus(108200000);
const kilometer Learth(149600000);
const kilometer Lmars(227900000);
const kilometer Ljupiter(778500000);
const kilometer Lsaturn(1429000000);
const kilometer Luranus(2871000000);
const kilometer Lneptune(4498000000);

//distance earth-moon
const lightsecond Lmoon(1.25);

//distance sun-milkyway
const lightyear Lsun(30000);

//ray of the milkyway
const lightyear Rmilkyway(60000);

//thickness of the milky way
const lightyear Dmilkyway(1000);

//distance milkyway-andromeda
const parsec Landromeda(778000); //+-17000



}//namespace constant



}//namespace stb





//=============================================================================
//=============================================================================
// COMMON_TYPE ================================================================
//=============================================================================
//=============================================================================



namespace std _GLIBCXX_VISIBILITY(default)
{
//std:: qualification is provided even if not needed in order
//to know where types/functions come from



template<typename CT, typename Period1, typename Period2>
class Length_common_type_wrapper
{
private:

  typedef std::__static_gcd<Period1::num, Period2::num> gcd_num;
  typedef std::__static_gcd<Period1::den, Period2::den> gcd_den;
  typedef typename CT::type common_rep;
  typedef std::ratio<gcd_num::value,
    (Period1::den / gcd_den::value) * Period2::den> new_ratio;

public:

  typedef std::__success_type<stb::Length<common_rep, new_ratio>> type;
};


template<typename Period1, typename Period2>
class Length_common_type_wrapper<std::__failure_type, Period1, Period2>
{
public:

  typedef std::__failure_type type;
};


template<typename Rep1, typename Period1, typename Rep2, typename Period2>
class common_type<stb::Length<Rep1, Period1>, stb::Length<Rep2, Period2>>
        : public Length_common_type_wrapper<typename std::__member_type_wrapper<
        std::common_type<Rep1, Rep2>>::type, Period1, Period2>::type
{
};



}//namespace std






#endif //LENGTH_HH_
