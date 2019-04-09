
#include <iostream>
#include "Unit.h"
namespace ariel
{
    using namespace std;
    class PhysicalNumber
    {
        public:
        
        //members (variables)
        double number; // the amount of the units
        Unit unit; // can be  seconds,minutes,hours,tons,m and so on...

        //constructor
        PhysicalNumber(double ,Unit);
        PhysicalNumber();
        ~PhysicalNumber();

        PhysicalNumber operator+(const PhysicalNumber& pn) const;
        PhysicalNumber& operator+=(PhysicalNumber const & pn);
        PhysicalNumber operator+();
        const PhysicalNumber operator++(int);
        PhysicalNumber& operator++();
        
        PhysicalNumber operator-(const PhysicalNumber& pn) const;
        PhysicalNumber& operator-=(PhysicalNumber& pn);
        PhysicalNumber operator-();
        PhysicalNumber& operator--();
        const PhysicalNumber operator--(int);
    
        bool operator<(const PhysicalNumber& PhysicalNumber) const;
        bool operator>(const PhysicalNumber& PhysicalNumber) const;
        bool operator<=(const PhysicalNumber& PhysicalNumber) const;
        bool operator>=(const PhysicalNumber& PhysicalNumber) const;
        bool operator==(const PhysicalNumber& PhysicalNumber) const;
        bool operator!=(const PhysicalNumber& PhysicalNumber) const;
        /*
        friend bool operator<(const PhysicalNumber& PhysicalNumber);
        friend bool operator>(const PhysicalNumber& PhysicalNumber);
        friend bool operator<=(const PhysicalNumber& PhysicalNumber);
        friend bool operator>=(const PhysicalNumber& PhysicalNumber);
        friend bool operator==(const PhysicalNumber& PhysicalNumber);
        friend bool operator!=(const PhysicalNumber& PhysicalNumber);
        */
        };
        
        ostream& operator << (ostream &, PhysicalNumber const &);
        istream& operator >> (istream & ,PhysicalNumber &);
}