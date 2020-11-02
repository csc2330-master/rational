#include "rational.h"

#include <cassert>
#include <iostream>

using std::cout;
using std::endl;

int main(int argc, char* argv[]){
	Rational a;
	assert(a.ToString() == "0");
	cout << "Passed Test 1" << endl;
	Rational b(2);
	assert(b.ToString() == "2");
	cout << "Passed Test 2" << endl;
	Rational c(1,3);
	assert(c.ToString() == "1 / 3");
	cout << "Passed Test 3" << endl;
	Rational d(4, -3);
	assert(d.ToString() == "-4 / 3");
	cout << "Passed Test 4" << endl;
	Rational e(c.Sum(d));
	assert(e.ToString() == "-1");
	cout << "Passed Test 5" << endl;
	assert(c.ToString() == "1 / 3");
	cout << "Passed Test 6" << endl;
	assert(d.ToString() == "-4 / 3");
	cout << "Passed Test 7" << endl;




	return 0;
}
