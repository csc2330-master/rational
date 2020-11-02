//
// Created by Arias Arevalo, Carlos on 11/2/20.
//

#ifndef RATIONAL_RATIONAL_H
#define RATIONAL_RATIONAL_H
#include <string>
using std::string;

class Rational { //SnakeCase
private:
	int _numerator;
	int _denominator;
	void Simplify();
public:
	Rational(int numerator = 0, int denominator = 1);
	string ToString()const;
	double ToDouble()const;
	const Rational Minus()const;
	const Rational Sum(const Rational& rhs)const;
	const Rational Difference(const Rational& rhs) const;

	const Rational& Assignment(const Rational& rhs);
	const Rational& Addition(const Rational& rhs);
	const Rational& Subtraction(const Rational& rhs);
};


#endif //RATIONAL_RATIONAL_H
