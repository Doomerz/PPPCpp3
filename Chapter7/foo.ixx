module;
export module foo;
import std;

namespace foomod { //so we don't have name clashes with foo.h
	int foo = 0;
	export void print_foo() { std::cout << foo << std::endl; }
	export void set_foo(int x) { foo = x; }
	export int get_foo() { return foo; }
}