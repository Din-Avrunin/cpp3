/**
 * Examples of automatic tests for the exercise on physical numbers.
 *
 * @author Erel Segal-Halevi
 * @since 2019-02
 */

#include <iostream>
#include <sstream>
using std::cout, std::endl, std::istringstream;
#include "PhysicalNumber.h"
using ariel::PhysicalNumber, ariel::Unit;
#include "badkan.hpp"

int main() {
  badkan::TestCase testcase;
  int grade=0;
  int signal = setjmp(badkan::longjmp_buffer);
  if (signal == 0) {

    // BASIC TESTS - DO NOT CHANGE
    PhysicalNumber a(2, Unit::KM);
    PhysicalNumber b(300, Unit::M);
    PhysicalNumber c(2, Unit::HOUR);
    PhysicalNumber d(30, Unit::MIN);

    PhysicalNumber e(20, Unit::CM);
    PhysicalNumber f(45, Unit::SEC);
    PhysicalNumber g(15, Unit::G);
    PhysicalNumber h(20, Unit::KG);
    PhysicalNumber i(10, Unit::TON);
    testcase
    .setname("Basic output")
    .CHECK_OUTPUT(a, "2[km]")
    .CHECK_OUTPUT(b, "300[m]")

    .setname("Compatible dimensions")
    .CHECK_OUTPUT(b+a, "2300[m]")
    .CHECK_OUTPUT((a+=b), "2.3[km]")
    .CHECK_OUTPUT(a, "2.3[km]")
    .CHECK_OUTPUT(a+a, "4.6[km]")
    .CHECK_OUTPUT(b-b, "0[m]")
    .CHECK_OUTPUT(c, "2[hour]")
    .CHECK_OUTPUT(d, "30[min]")
    .CHECK_OUTPUT(d+c, "150[min]")

    .setname("Incompatible dimensions")
    .CHECK_THROWS(a+c)
    .CHECK_THROWS(a+d)
    .CHECK_THROWS(b+c)
    .CHECK_THROWS(b+d)

    .setname("Basic input")
    .CHECK_OK(istringstream("700[kg]") >> a)
    .CHECK_OUTPUT((a += PhysicalNumber(1, Unit::TON)), "1700[kg]")

    // YOUR TESTS - INSERT AS MANY AS YOU WANT
.CHECK_OUTPUT(e, "20[cm]")
    .CHECK_OUTPUT(f, "45[sec]")
    .CHECK_OUTPUT(g, "15[g]")
    .CHECK_OUTPUT(h, "20[km]")
    .CHECK_OUTPUT(i, "10[ton]")
    .CHECK_OK(istringstream("2[km]") >> a) // changing back. a = 2[km]
    .CHECK_OUTPUT(a, "2[km]")
    .CHECK_OUTPUT(a+b, "2.3[km]")
    .CHECK_OUTPUT(a, "2[km]")
    .CHECK_OUTPUT(a+e, "2.0002[km]")
    .CHECK_OUTPUT((b+=a), "2300[m]") /////////// b = 2300[m]
    .CHECK_OUTPUT(b, "2300[m]")
    .CHECK_OUTPUT((b+=e), "2300.2[m]") ///////// b = 2300.2[m]
    .CHECK_OUTPUT(-c, "-2[hour]") // put const on physical number so that plus c wont turn into minus c or put Math.abs
    .CHECK_OUTPUT(+c, "2[hour]") // positive
    .CHECK_OUTPUT(c-d, "1.5[hour]") // need to check negativity with all units not only hours (perhaps a helping function)
    .CHECK_OUTPUT((a-=e), "1.9998[m]")
    .CHECK_OUTPUT((b-=e), "2300[m]") // b shoud be now 2300[m]
    .CHECK_OUTPUT((f>c), "false") // false because f is smaller than c
    .CHECK_OUTPUT((f>d), "false") // same
    .CHECK_OUTPUT((f>f), "false")
    .CHECK_OUTPUT((f>=f), "true")
    .CHECK_OUTPUT((g>=g), "true")
    .CHECK_OUTPUT((g>=h), "false")
    .CHECK_OUTPUT((g>=i), "false")
    .CHECK_OUTPUT((h==h), "true")
    .CHECK_OUTPUT((h==g), "false")
    .CHECK_OUTPUT((h==i), "false")
    .CHECK_OK(istringstream("20000[g]") >> g)
    .CHECK_OUTPUT(g, "20000[g]") 
    .CHECK_OUTPUT((h==g), "true") // check that even when [g] and [kg] are different units but with equal input (needs to be true and not false due to defferent units!!)
    .CHECK_OK(istringstream("0.0220462262[ton]") >> i)
    .CHECK_OUTPUT(i, "0.0220462262[ton]")
    .CHECK_OUTPUT((h==i), "true") // check that even when [g] and [kg] are different units but with equal input (needs to be true and not false due to defferent units!!)
    .CHECK_OUTPUT((h!=h), "false")
    .CHECK_OUTPUT((h!=g), "true")
    .CHECK_OUTPUT((h!=i), "true")
    .CHECK_OUTPUT((f<c), "true") // false because f is bigger than c
    .CHECK_OUTPUT((f<d), "true") // same
    .CHECK_OUTPUT((f<f), "false")
    .CHECK_OUTPUT((g<=g), "true")
    .CHECK_OUTPUT((g<=h), "true")
    .CHECK_OUTPUT((g<=i), "true")
    .CHECK_OK((a++)) // still 2
    .CHECK_OUTPUT(a, "3[km]") // now is 3
    .CHECK_OK((a--)) // still 3
    .CHECK_OUTPUT(a, "2[km]") // now 2




//////////////////////////////////////////////

    .CHECK_THROWS(a+f)
    .CHECK_THROWS(a+g)
    .CHECK_THROWS(a+h)
    .CHECK_THROWS(a+i)
    .CHECK_THROWS(b+=c)
    .CHECK_THROWS(b+=d)
    .CHECK_THROWS(b+=f)
    .CHECK_THROWS(b+=g)
    .CHECK_THROWS(b+=h)
    .CHECK_THROWS(b+=i)
    .CHECK_THROWS(d-a)
    .CHECK_THROWS(d-b)
    .CHECK_THROWS(d-e)
    .CHECK_THROWS(d-g)
    .CHECK_THROWS(d-h)
    .CHECK_THROWS(d-i)
    .CHECK_THROWS(d-c)
    .CHECK_THROWS(e-a)
    .CHECK_THROWS(e-b)
    .CHECK_THROWS(e-c)
    .CHECK_THROWS(e-d)
    .CHECK_THROWS(e-f)
    .CHECK_THROWS(e-g)
    .CHECK_THROWS(e-h)
    .CHECK_THROWS(e-i)
    .CHECK_THROWS(e-=a) // throws because e<0
    .CHECK_THROWS(e-=b) // same
    .CHECK_THROWS(e-=c) // throws because of units
    .CHECK_THROWS(e-=d)
    .CHECK_THROWS(e-=f)
    .CHECK_THROWS(e-=g)
    .CHECK_THROWS(e-=h)
    .CHECK_THROWS(e-=i)
    .CHECK_THROWS(f>a)
    .CHECK_THROWS(f>b)
    .CHECK_THROWS(f>e)
    .CHECK_THROWS(f>g)
    .CHECK_THROWS(f>h)
    .CHECK_THROWS(f>i)
    .CHECK_THROWS(g>=a)
    .CHECK_THROWS(g>=b)
    .CHECK_THROWS(g>=c)
    .CHECK_THROWS(g>=d)
    .CHECK_THROWS(g>=e)
    .CHECK_THROWS(g>=f)
    .CHECK_THROWS(h==a)
    .CHECK_THROWS(h==b)
    .CHECK_THROWS(h==c)
    .CHECK_THROWS(h==d)
    .CHECK_THROWS(h==e)
    .CHECK_THROWS(h==f)
    .CHECK_THROWS(i!=a)
    .CHECK_THROWS(i!=b)
    .CHECK_THROWS(i!=c)
    .CHECK_THROWS(i!=d)
    .CHECK_THROWS(i!=e)
    .CHECK_THROWS(i!=f)
    .CHECK_THROWS(f<a)
    .CHECK_THROWS(f<b)
    .CHECK_THROWS(f<e)
    .CHECK_THROWS(f<g)
    .CHECK_THROWS(f<h)
    .CHECK_THROWS(f<i)
    .CHECK_THROWS(g<=a)
    .CHECK_THROWS(g<=b)
    .CHECK_THROWS(g<=c)
    .CHECK_THROWS(g<=d)
    .CHECK_THROWS(g<=e)
    .CHECK_THROWS(g<=f)
      .setname("...")

      .print(cout, /*show_grade=*/false);
      grade = testcase.grade();
    } else {
      testcase.print_signal(signal);
      grade = 0;
    }
    cout <<  "*** Grade: " << grade << " ***" << endl;
    return grade;
}