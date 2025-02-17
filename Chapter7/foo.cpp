#include "foo.h"
#include<iostream>

namespace fooh { //prevent name clashes
	int foo = -1;
	void print_foo() { std::cout << "foo.h=" << foo << std::endl; }
	void print(int a) { std::cout << "foo.h_int=" << a << std::endl; }
}