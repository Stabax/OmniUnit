#define GOPNIK blyat
#define OMNI_TRUE_ZERO false
#define OMNI_DISABLE_UNCERTAINTIES

#include "omniunit/omniunit.hh"
#include "omniunit/chronoscale.hh"

#include <iostream>
#include <thread>
#include <typeinfo>
#include <iomanip>


#if OMNI_TRUE_ZERO == true

#define VAR1 100
#define VAR2 100
#define VAR3 100
#define VAR4 1
#define VAR5 1
#define VAR6 0
#define VAR7 0

#define VAR8 2458.35
#define VAR9 2458.35
#define VAR10 2458.35
#define VAR11 -245.835
#define VAR12 -245.835
#define VAR13 -270
#define VAR14 -270

#define VAR15 2831.5
#define VAR16 2831.5
#define VAR17 10
#define VAR18 28.315
#define VAR19 10
#define VAR20 -273
#define VAR21 -273

#define VAR22 1
#define VAR23 0
#define VAR24 273.15
#define VAR25 -273.15
#define VAR26 0
#define VAR27 0
#define VAR28 2731.5
#define VAR29 0

#define VAR30 1

#else // non official zero

#define VAR1 100
#define VAR2 100
#define VAR3 100
#define VAR4 1
#define VAR5 1
#define VAR6 0
#define VAR7 0

#define VAR8 0
#define VAR9 0
#define VAR10 0
#define VAR11 0
#define VAR12 0
#define VAR13 0
#define VAR14 0

#define VAR15 -900
#define VAR16 -900
#define VAR17 -90
#define VAR18 10/9
#define VAR19 0
#define VAR20 -273
#define VAR21 -273

#define VAR22 1
#define VAR23 0
#define VAR24 273.15
#define VAR25 -273.15
#define VAR26 0
#define VAR27 0
#define VAR28 2731.5
#define VAR29 0

#define VAR30 4.53999e-005

#endif

struct faux
{
  static int value;
};

int faux::value = 0;


template <typename dim, typename rep, typename rat, double const& ori>
void show(int test, omniunit::Basic_Unit<dim, rep, rat, ori> const& var1, double ref = 0)
{
  bool a = (static_cast<float>(var1.count() - ref) <= std::numeric_limits<float>::epsilon());
  std::cout << std::left << std::setw(8) << "TEST " + std::to_string(test)
  << std::left << std::setw(8) << std::boolalpha << a
  << std::left << std::setw(10) << var1.count()
  << std::left << std::setw(13) << var1.dimension()
  << std::left << std::setw(2) << typeid(rep).name()
  << std::left << std::setw(0) << rat::num << std::left << std::setw(0) << "/" << std::left << std::setw(8) << rat::den
  << std::left << std::setw(8) << var1.origin << "\n";

  if(a == false)
    faux::value++;
}

template <typename T, typename = typename std::enable_if<std::is_arithmetic<T>::value, T>::type>
void show(int test, T const& var1, double ref = 0)
{
  bool a = (static_cast<float>(var1) - static_cast<float>(ref) <= std::numeric_limits<float>::epsilon());
  std::cout << std::left << std::setw(8) << "TEST " + std::to_string(test)
  << std::left << std::setw(8) << std::boolalpha << a
  << std::left << std::setw(10) << var1
  << std::left << std::setw(2) << typeid(T).name() << "\n";

  if(a == false)
    faux::value++;
}

int main()
{
  typedef omniunit::Unit<omniunit::Dimension<0,0,0,0,0,0,0,0,0>, float, omniunit::deci, omniunit::E1> scalar;



  omniunit::kelvin<double> temp1(10);
  auto var1 = temp1 * 10;
  show(1, var1, VAR1);

  omniunit::kelvin<double> temp2(10);
  auto var2 = 10 * temp2;
  show(2, var2, VAR2);

  omniunit::kelvin<double> temp3(10);
  auto var3 = temp3 *= 10;
  show(3, var3, VAR3);

  omniunit::kelvin<double> temp4(10);
  auto var4 = temp4 / 10;
  show(4, var4, VAR4);

  omniunit::kelvin<double> temp5(10);
  auto var5 = temp5 /= 10;
  show(5, var5, VAR5);

  omniunit::kelvin<double> temp6(10);
  auto var6 = temp6 % 10;
  show(6, var6, VAR6);

  omniunit::kelvin<double> temp7(10);
  auto var7 = temp7 %= 10;
  show(7, var7, VAR7);



  omniunit::celsius<double> temp8(0);
  auto var8 = temp8 * 10;
  show(8, var8, VAR8);

  omniunit::celsius<double> temp9(0);
  auto var9 = 10 * temp9;
  show(9, var9, VAR9);

  omniunit::celsius<double> temp10(0);
  auto var10 = temp10 *= 10;
  show(10, var10, VAR10);

  omniunit::celsius<double> temp11(0);
  auto var11 = temp11 / 10;
  show(11, var11, VAR11);

  omniunit::celsius<double> temp12(0);
  auto var12 = temp12 /= 10;
  show(12, var12, VAR12);

  omniunit::celsius<double> temp13(0);
  auto var13 = temp13 % 10;
  show(13, var13, VAR13);

  omniunit::celsius<double> temp14(0);
  auto var14 = temp14 %= 10;
  show(14, var14, VAR14);



  omniunit::celsius<double> temp15(10);
  scalar s15(-90); //1
  auto var15 = temp15 * s15;
  show(15, var15, VAR15);

  omniunit::celsius<double> temp16(10);
  scalar s16(-90); //1
  auto var16 = s16 * temp16;
  show(16, var16, VAR16);

  omniunit::celsius<double> temp17(10);
  scalar s17(-90); //1
  auto var17 = temp17 *= s17;
  show(17, var17, VAR17);

  omniunit::celsius<double> temp18(10);
  scalar s18(-90); //1
  auto var18 = temp18 / s18;
  show(18, var18, VAR18);

  omniunit::celsius<double> temp19(10);
  scalar s19(-90); //1
  auto var19 = temp19 /= s19;
  show(19, var19, VAR19);

  omniunit::celsius<double> temp20(10);
  scalar s20(-90); //1
  auto var20 = temp20 % s20;
  show(20, var20, VAR20);

  omniunit::celsius<double> temp21(10);
  scalar s21(-90); //1
  auto var21 = temp21 %= s21;
  show(21, var21, VAR21);



  omniunit::celsius<double> temp22(0);
  auto var22 = 273.15 / temp22;
  show(22, var22, VAR22);

  omniunit::celsius<double> temp23(0);
  auto var23 = 273.15 % temp23;
  show(23, var23, VAR23);

  omniunit::celsius<double> temp24(0);
  omniunit::kelvin<double> k24(0);
  auto var24 = k24 + temp24;
  show(24, var24, VAR24);

  omniunit::celsius<double> temp25(0);
  omniunit::kelvin<double> k25(0);
  auto var25 = k25 - temp25;
  show(25, var25, VAR25);

  omniunit::celsius<double> temp26(0);
  omniunit::kelvin<double> k26(0);
  auto var26 = temp26 += k26;
  show(26, var26, VAR26);

  omniunit::celsius<double> temp27(0);
  omniunit::kelvin<double> k27(0);
  auto var27 = temp27 -= k27;
  show(27, var27, VAR27);

  omniunit::celsius<double> temp28(0);
  omniunit::kelvin<double> k28(10);
  auto var28 = k28 * temp28;
  show(28, var28, VAR28);

  omniunit::celsius<double> temp29(0);
  omniunit::kelvin<double> k29(0);
  auto var29 = k29 / temp29;
  show(29, var29, VAR29);


  omniunit::Unit<omniunit::Dimension<0,0,0,0,0,0,0,0,0>, long double, omniunit::deci, omniunit::E1> temp30(-100); //1
  auto var30 = omniunit::exp(temp30);
  show(30, var30, VAR30);

  //constexpr scalar x(1);
  //constexpr scalar y(3);
  //constexpr scalar z = (x/y);

  std::cout << "nb de faux : " << faux::value << "\n";
  std::cout << omniunit::modulo(10, -9.f) << "\n"; //BUG
return 0;
}
