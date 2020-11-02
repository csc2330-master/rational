#include "rational.h"

#include <cmath>
#include <string>
#include <sstream>
using std::string;
using std::stringstream;

int GreatestCommonDivisor(int a, int b){
	int temp;
	while (b != 0)	{
		temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}
void Rational::Simplify(){
	int gcd = GreatestCommonDivisor(abs(_numerator), abs(_denominator));
	_numerator /= gcd;
	_denominator /= gcd;
}
Rational::Rational(int numerator, int denominator){
	if (denominator == 0){
		// Should throw an exception or set error flag?
		_numerator = 0;
		_denominator = 1;
	}else if (denominator < 0){
		_numerator = -numerator;
		_denominator = -denominator;
	}else{
		_numerator = numerator;
		_denominator = denominator;
	}

	Simplify();
}
string Rational::ToString()const{
	stringstream retVal;
	if (_denominator == 1){
		retVal << _numerator;
	}else if (_numerator == 0){
		retVal << 0;
	}else{
		retVal << _numerator << " / " << _denominator;
	}
	return retVal.str();
}
double Rational::ToDouble()const{
	return static_cast<double>(_numerator) / static_cast<double>(_denominator);
}
const Rational Rational::Minus()const{
	return Rational(-_numerator, _denominator);
}
const Rational Rational::Sum(const Rational& rhs)const{
	Rational retVal;
	retVal._numerator = _numerator * rhs._denominator + _denominator * rhs._numerator;
	retVal._denominator = _denominator * rhs._denominator;
	retVal.Simplify();
	return retVal;
}
const Rational Rational::Difference(const Rational& rhs) const{
	Rational retVal;
	retVal._numerator = _numerator * rhs._denominator - _denominator * rhs._numerator;
	retVal._denominator = _denominator * rhs._denominator;
	retVal.Simplify();
	return retVal;
}

const Rational& Rational::Assignment(const Rational& rhs){
	_numerator= rhs._numerator;
	_denominator = rhs._denominator;
	return *this; // return the same caller NOT A COPY
}
const Rational& Rational::Addition(const Rational& rhs){
	_numerator = _numerator * rhs._denominator + _denominator * rhs._numerator;
	_denominator = _denominator * rhs._denominator;
	Simplify();
	return *this;
}
const Rational& Rational::Subtraction(const Rational& rhs){
	_numerator = _numerator * rhs._denominator - _denominator * rhs._numerator;
	_denominator = _denominator * rhs._denominator;
	Simplify();
	return *this;
}
