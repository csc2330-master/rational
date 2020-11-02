#include "rational.h"

#include <iostream>
using std::cout;
using std::endl;

// Third reason to use const at the end of a method
int main() {
	Rational a(1, 3);
	Rational b(a.Minus());
	cout << a.ToString() << endl;
	cout << b.ToString() << endl;

	std::cout << "Hello, World!" << std::endl;
	return 0;
}
