
#include "PhysicalNumber.h"
#include <stdexcept>
namespace ariel 
{

        PhysicalNumber::PhysicalNumber()
        {

        }
        PhysicalNumber::PhysicalNumber(double number,Unit unit)
        {

        }
        PhysicalNumber::~PhysicalNumber(){

        }
        PhysicalNumber PhysicalNumber::operator+(const PhysicalNumber & pn) const
        {
            PhysicalNumber a;
            return a;
        }
        PhysicalNumber& PhysicalNumber::operator+=(PhysicalNumber const & pn)
        {
            return *this;
        }
        PhysicalNumber  PhysicalNumber::operator+()
        {
            PhysicalNumber a;
            return a;
        }
        PhysicalNumber& PhysicalNumber::operator++()
        {

            return *this;
        }
        const PhysicalNumber PhysicalNumber::operator++(int)
        {
            PhysicalNumber a;
            return a;
        }
        PhysicalNumber PhysicalNumber::operator-(const PhysicalNumber& pn) const
        {
            PhysicalNumber a;
            return a;
        }
        PhysicalNumber& PhysicalNumber::operator-=(PhysicalNumber& pn)
        {
            return *this;
        }
        PhysicalNumber PhysicalNumber::operator-()
        {
            PhysicalNumber a;
            return a;
        }
        PhysicalNumber& PhysicalNumber::operator--()
        {
            return *this;
        }
        const PhysicalNumber PhysicalNumber::operator--(int)
        {
            PhysicalNumber a;
            return a;
                    }
        
        bool  PhysicalNumber::operator<(const PhysicalNumber& PhysicalNumber) const
        {
              return false;
        }
        bool  PhysicalNumber::operator>(const PhysicalNumber& PhysicalNumber) const
        {
            return false;
        }
        bool  PhysicalNumber::operator<=(const PhysicalNumber& PhysicalNumber) const
        {
        return false;
        }
        bool  PhysicalNumber::operator>=(const PhysicalNumber& PhysicalNumber) const

        {
            return false;
        }
        bool  PhysicalNumber::operator==(const PhysicalNumber& PhysicalNumber) const
        {
                return false;
        }
        bool  PhysicalNumber::operator!=(const PhysicalNumber& PhysicalNumber) const
        {
             return false;
        }

        ostream& operator << (ostream& os, PhysicalNumber const & x){
	    return os;
        }

        istream& operator >> (istream & is, PhysicalNumber& x){
	    return is;
        }
 


}