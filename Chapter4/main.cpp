import std;
using namespace std;

constexpr int frame_width = 2;
int area(int length, int width) { return length * width; }
int framed_area(int x, int y) { return area(x - frame_width, y - frame_width); }
void TryThis3_1() {
	//int s1 = area(7, 2;
	//int s2 = area(7,2)
	//Int s3 = area(7, 2);
	//int s4 = area('7,2);
}
//error s1
	//error C2143: syntax error: missing ')' before ';'
	//error C3861: 'area': identifier not found
//error s2
	//error C3861: 'area': identifier not found
	//error C2143: syntax error: missing ';' before '}'
//error s3
	//error C2065: 'Int': undeclared identifier
	//error C2146: syntax error: missing ';' before identifier 's3'
	//error C2065: 's3': undeclared identifier
	//error C3861: 'area': identifier not found
//error s4
	//error C2001: newline in constant
	//error C2015: too many characters in constant
	//error C2143: syntax error: missing ')' before '}'
	//error C3861: 'area': identifier not found
	//error C2143: syntax error: missing ';' before '}'
void TryThis3_2() {
	//int x0 = arena(7, 2);
	//int x1 = area(7);
	//int x2 = area("seven", 2);
}
//errors x0
	//error C3861: 'arena': identifier not found
//errors x1
	//error C2660: 'area': function does not take 1 arguments
//errors x2
	//error C2664: 'int area(int,int)': cannot convert argument 1 from 'const char [6]' to 'int'
void TryThis() {
	//pick up at 4.5.3 pg.157
}

///Drill

///Review

/// Name four major types of errors and briefly define each one.
//
/// What kinds of errors can we ignore in student programs ?
//
/// What guarantees should every completed project offer ?
//
/// List three approaches we can take to eliminate errors in programs and produce acceptable software.
//
/// Why do we hate debugging ?
//
/// What is a syntax error ? Give five examples.
//
/// What is a type error ? Give five examples.
//
/// What is a linker error ? Give three examples.
//
/// What is a logic error ? Give three examples.
//
/// List four potential sources of program errors discussed in the text.
//
/// How do you know if a result is plausible ? What techniques do you have to answer such questions ?
//
/// How do you test if an input operation succeeded ?
//
/// Compare and contrast having the caller of a function handle a run - time error vs.having the called function handle the run - time error.
//
/// When is throwing an exception preferable to returning an “error value” ?
//
/// When is returning an “error value” preferable to throwing an exception ?
//
/// Describe the process of how exceptions are thrown and caught.
//
/// Why, with a vector called v, is v[v.size()] a range error ? What would be the result of calling this ?
//
/// What is an assertion ?
//
/// Define precondition and postcondition; give an example(that is not the area() function from this chapter), preferably a computation that requires a loop.
//
/// When would you not test a precondition ?
//
/// When would you not test a postcondition ?
//
/// What are the steps in debugging a program ?
//
/// Why does commenting help when debugging ?
//
/// How does testing differ from debugging ?
//
/// What is a random number ?
//
/// How do we use random_int() and seed() ?
//


///Exercises

int main() {
	TryThis3_1();
	return 0;
}