//Speed.hh

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

#ifndef Speed_HH_
#define Speed_HH_

namespace stb
{



//=============================================================================
//=============================================================================
// UNITS CLASS ================================================================
//=============================================================================
//=============================================================================



// Speed DEFINITION ===========================================================



template<typename Rep, typename Period = std::ratio<1>>
class Speed
{
public:

  typedef Rep rep;
  typedef Period period;


  Speed(Rep const& count):
  _count(count)
  {
  }


  Rep count() const
  {
    return _count;
  }


  static Speed zero()
  {
    return Speed(0);
  }


  Speed& operator++()
  {
    ++_count;
    return *this;
  }


  Speed operator++(int)
  {
    return Speed(_count++);
  }


  Speed& operator--()
  {
    --_count;
    return *this;
  }


  Speed operator--(int)
  {
    return Speed(_count--);
  }


  Speed& operator+=(Speed const& Obj)
  {
    _count += Obj.count();
    return *this;
  }


  Speed& operator-=(Speed const& Obj)
  {
    _count -= Obj.count();
    return *this;
  }


  Speed& operator*=(Rep coef)
  {
    _count *= coef;
    return *this;
  }


  Speed& operator/=(Rep coef)
  {
    _count /= coef;
    return *this;
  }


  Speed& operator%=(Rep coef)
  {
    _count %= coef;
    return *this;
  }


  Speed& operator%=(const Speed& Obj)
  {
    _count %= Obj.count();
    return *this;
  }

protected:

  Rep _count;

};

template<typename toUnit, typename Rep, typename Period>
constexpr toUnit speed_cast(Speed<Rep, Period> const& Speed)
{
  typedef typename std::ratio_divide<Period, typename toUnit::period>::type ratio;
  typedef typename std::common_type<typename toUnit::rep, Rep, intmax_t>::type type;

  type coef = static_cast<type>(ratio::num) / static_cast<type>(ratio::den);
  type value = static_cast<type>(Speed.count()) * coef;

  return toUnit(static_cast<typename toUnit::rep>(value));
}


template <typename Rep1, typename Period1, typename Rep2, typename Period2>
constexpr typename std::common_type<Speed<Rep1,Period1>, Speed<Rep2,Period2>>::type
operator+ (Speed<Rep1,Period1> const& Obj1, Speed<Rep2,Period2> const& Obj2)
{
  typedef typename std::common_type<Speed<Rep1,Period1>, Speed<Rep2,Period2>>::type type;
  return type(speed_cast<type>(Obj1).count() + speed_cast<type>(Obj2).count());
}


template <typename Rep1, typename Period1, typename Rep2, typename Period2>
constexpr typename std::common_type<Speed<Rep1,Period1>, Speed<Rep2,Period2>>::type
operator- (Speed<Rep1,Period1> const& Obj1, Speed<Rep2,Period2> const& Obj2)
{
  typedef typename std::common_type<Speed<Rep1,Period1>, Speed<Rep2,Period2>>::type type;
  return type(speed_cast<type>(Obj1).count() - speed_cast<type>(Obj1).count());
}


template <typename Rep, typename Period, typename coefType>
constexpr Speed<typename std::common_type<Rep, coefType>::type, Period>
operator* (Speed<Rep, Period> const& Obj, coefType coef)
{
  typedef Speed<typename std::common_type<Rep, coefType>::type, Period> type;
  return type(speed_cast<type>(Obj).count() * coef);
}


template <typename Rep, typename Period, typename coefType>
constexpr Speed<typename std::common_type<Rep, coefType>::type, Period>
operator* (coefType coef, Speed<Rep, Period> const& Obj)
{
  typedef Speed<typename std::common_type<Rep, coefType>::type, Period> type;
  return type(speed_cast<type>(Obj).count() * coef);
}


template <typename Rep, typename Period, typename coefType>
constexpr Speed<typename std::common_type<Rep, coefType>::type, Period>
operator/ (Speed<Rep, Period> const& Obj, coefType coef)
{
  typedef Speed<typename std::common_type<Rep, coefType>::type, Period> type;
  return type(speed_cast<type>(Obj).count() / coef);
}


template <typename Rep, typename Period, typename coefType>
constexpr Speed<typename std::common_type<Rep, coefType>::type, Period>
operator/ (coefType coef, Speed<Rep, Period> const& Obj)
{
  typedef Speed<typename std::common_type<Rep, coefType>::type, Period> type;
  return type(speed_cast<type>(Obj).count() / coef);
}


template <typename Rep1, typename Period1, typename Rep2, typename Period2>
constexpr typename std::common_type<Rep1, Rep2>::type
operator/ (Speed<Rep1,Period1> const& Obj1, Speed<Rep2,Period2> const& Obj2)
{
  typedef typename std::common_type<Speed<Rep1,Period1>, Speed<Rep2,Period2>>::type common_type;
  return speed_cast<common_type>(Obj1).count() / speed_cast<common_type>(Obj2).count();
}


template <typename Rep, typename Period, typename coefType>
constexpr Speed<typename std::common_type<Rep, coefType>::type, Period>
operator% (coefType coef, Speed<Rep, Period> const& Obj)
{
  typedef Speed<typename std::common_type<Rep, coefType>::type, Period> type;
  return type(speed_cast<type>(Obj).count() % coef);
}


template <typename Rep1, typename Period1, typename Rep2, typename Period2>
constexpr typename std::common_type<Speed<Rep1,Period1>, Speed<Rep2,Period2>>::type
operator% (Speed<Rep1,Period1> const& Obj1, Speed<Rep2,Period2> const& Obj2)
{
  typedef typename std::common_type<Speed<Rep1,Period1>, Speed<Rep2,Period2>>::type type;
  return type(speed_cast<type>(Obj1).count() % speed_cast<type>(Obj2).count());
}


template <typename Rep1, typename Period1, typename Rep2, typename Period2>
constexpr bool operator== (Speed<Rep1,Period1> const& Obj1, Speed<Rep2,Period2> const& Obj2)
{
  typedef typename std::common_type<Speed<Rep1,Period1>, Speed<Rep2,Period2>>::type type;
  return speed_cast<type>(Obj1).count() == speed_cast<type>(Obj2).count() ? true : false;
}


template <typename Rep1, typename Period1, typename Rep2, typename Period2>
constexpr bool operator!= (Speed<Rep1,Period1> const& Obj1, Speed<Rep2,Period2> const& Obj2)
{
  typedef typename std::common_type<Speed<Rep1,Period1>, Speed<Rep2,Period2>>::type type;
  return speed_cast<type>(Obj1).count() != speed_cast<type>(Obj2).count() ? true : false;
}


template <typename Rep1, typename Period1, typename Rep2, typename Period2>
constexpr bool operator>= (Speed<Rep1,Period1> const& Obj1, Speed<Rep2,Period2> const& Obj2)
{
  typedef typename std::common_type<Speed<Rep1,Period1>, Speed<Rep2,Period2>>::type type;
  return speed_cast<type>(Obj1).count() >= speed_cast<type>(Obj2).count() ? true : false;
}


template <typename Rep1, typename Period1, typename Rep2, typename Period2>
constexpr bool operator<= (Speed<Rep1,Period1> const& Obj1, Speed<Rep2,Period2> const& Obj2)
{
  typedef typename std::common_type<Speed<Rep1,Period1>, Speed<Rep2,Period2>>::type type;
  return speed_cast<type>(Obj1).count() <= speed_cast<type>(Obj2).count() ? true : false;
}


template <typename Rep1, typename Period1, typename Rep2, typename Period2>
constexpr bool operator> (Speed<Rep1,Period1> const& Obj1, Speed<Rep2,Period2> const& Obj2)
{
  typedef typename std::common_type<Speed<Rep1,Period1>, Speed<Rep2,Period2>>::type type;
  return speed_cast<type>(Obj1).count() > speed_cast<type>(Obj2).count() ? true : false;
}


template <typename Rep1, typename Period1, typename Rep2, typename Period2>
constexpr bool operator< (Speed<Rep1,Period1> const& Obj1, Speed<Rep2,Period2> const& Obj2)
{
  typedef typename std::common_type<Speed<Rep1,Period1>, Speed<Rep2,Period2>>::type type;
  return speed_cast<type>(Obj1).count() < speed_cast<type>(Obj2).count() ? true : false;
}





//=============================================================================
//=============================================================================
// Speed TYPEDEF ==============================================================
//=============================================================================
//=============================================================================


typedef Speed<long long, std::ratio<1, 1>>          meterPerSecond;
typedef Speed<long long, std::ratio<1000, 1>>       kilometerPerSecond;
typedef Speed<long long, std::ratio<1000, 3600>>    kilometerPerHour;

typedef Speed<float, std::ratio<1, 1>>          meterPerSecond_f;
typedef Speed<float, std::ratio<1000, 1>>       kilometerPerSecond_f;
typedef Speed<float, std::ratio<1000, 3600>>    kilometerPerHour_f;





//=============================================================================
//=============================================================================
// Speed CONSTANT =============================================================
//=============================================================================
//=============================================================================



//Speed of lux through void
const Speed<bool, std::ratio<300*1000*1000, 1>> cRounded(1);
const meterPerSecond c(299792458);

//Speed of sound, in normal pressure and temperature conditions
const meterPerSecond cAir(340);
const meterPerSecond cWater(1480);
const meterPerSecond cIce(3200);
const meterPerSecond cGlass(5300);
const meterPerSecond cSteel(5700);
const meterPerSecond cLead(1200);
const meterPerSecond cTitanium(4950);
const meterPerSecond cConcrete(3100);
const meterPerSecond cGranite(6200);
const meterPerSecond cPeridotite(7700);

//Speed at the earth's equator
const kilometerPerHour vEquator(1670);

//Speeds in the sun system
const kilometerPerHour vMercury(172800);
const kilometerPerHour vVenus(126000);
const kilometerPerHour vEarth(104400);
const kilometerPerHour vMars(86400);
const kilometerPerHour vJupiter(46400);
const kilometerPerHour vSaturn(36000);
const kilometerPerHour vUranus(25200);
const kilometerPerHour vNeptune(18000);

//intestellar Speeds
//const kilometerPerHour vSun_aCentauri(828000);
//const kilometerPerHour vSun_Sirius(828000);
//const kilometerPerHour vSun_Eridiani(828000);
const kilometerPerSecond vSun_MilkyWay(230);

//intergalactic Speeds
const kilometerPerSecond vMilkyWay_Andromeda(120);
const kilometerPerSecond vMilkyWay_LocalGoup(65);
const kilometerPerSecond vLocalGroup_LocalSuperCluster(627);
const kilometerPerSecond vLocalSuperCluster_GreatAttractor(368);
const kilometerPerSecond vLocalSuperCluster_Laniakea = vLocalSuperCluster_GreatAttractor;




//=============================================================================
//=============================================================================
// TYPEDEF ====================================================================
//=============================================================================
//=============================================================================



}//namespace stb





//specialization of std::common_type for stb::Speed
namespace std
{
//note that std:: qualification is provided even if not needed in order
//to know where types/functions come from



template<typename CT, typename Period1, typename Period2>
struct Speed_common_type_wrapper
{
private:

  typedef std::__static_gcd<Period1::num, Period2::num> gcd_num;
  typedef std::__static_gcd<Period1::den, Period2::den> gcd_den;
  typedef typename CT::type cr;
  typedef std::ratio<gcd_num::value,
    (Period1::den / gcd_den::value) * Period2::den> r;

public:

  typedef std::__success_type<stb::Speed<cr, r>> type;
};

template<typename Period1, typename Period2>
struct Speed_common_type_wrapper<std::__failure_type, Period1, Period2>
{
   typedef std::__failure_type type;
};

template<typename Rep1, typename Period1, typename Rep2, typename Period2>
struct common_type<stb::Speed<Rep1, Period1>, stb::Speed<Rep2, Period2>>
        : public Speed_common_type_wrapper<typename std::__member_type_wrapper<
        std::common_type<Rep1, Rep2>>::type, Period1, Period2>::type
{
};



}//namespace std

#endif //UNIT_HH_
