import foo;
import std;

#include "foo.h"

void d3test() {
	foomod::print_foo();
	foomod::set_foo(1);
	std::cout << foomod::get_foo() << std::endl;
}

void d4test() {
	fooh::print_foo();
	fooh::print(2);
}