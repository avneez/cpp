// C++ program for function overloading
#include <bits/stdc++.h>

using namespace std;
class Geeks
{
	public:

	// function with 1 int parameter
	void func(int x)
	{
		cout << "value of x is " << x << endl;
	}

	// function with same name but 1 double parameter
	void func(double x)
	{
		cout << "value of x is " << x << endl;
	}

	// function with same name and 2 int parameters
	void func(int x, int y)
	{
		cout << "value of x and y is " << x << ", " << y << endl;
	}
};

int main() {

	Geeks obj1;

	// Which function is called will depend on the parameters passed
	// The first 'func' is called
	obj1.func(7);

	// The second 'func' is called
	obj1.func(9.132);

	// The third 'func' is called
	obj1.func(85,64);
	return 0;
}


// Types of Polymorphism

// A. Compile-time polymorphism: This type of polymorphism is achieved by function overloading or operator overloading.
// Function Overloading: When there are multiple functions with the same name but different parameters, then the functions are said to be overloaded.
// Functions can be overloaded by changing the number of arguments or/and changing the type of arguments.

// Rules of Function Overloading:
// In C++, following function declarations cannot be overloaded.

// 1) Function declarations that differ only in the return type.


// 2) Member function declarations with the same name and the name parameter-type-list cannot be overloaded if any of them is a static member function declaration.

// 3) Parameter declarations that differ only in a pointer * versus an array [] are equivalent. That is, the array declaration is adjusted to become a pointer declaration.
// Only the second and subsequent array dimensions are significant in parameter types. For example, following two function declarations are equivalent.

// int fun(int *ptr);
// int fun(int ptr[]); // redeclaration of fun(int *ptr)

// 4) Parameter declarations that differ only in that one is a function type and the other is a pointer to the same function type are equivalent.

// void h(int ());
// void h(int (*)()); // redeclaration of h(int())

// 5) Parameter declarations that differ only in the presence or absence of const and/or volatile are equivalent. That is, the const and volatile type-specifiers for each parameter type are ignored when determining which function is being declared, defined, or called. For example, following program fails in compilation with error “redefinition of `int f(int)’ “ Example:


// #include<iostream>
// #include<stdio.h>

// using namespace std;

// int f ( int x) {
//     return x+10;
// }

// int f ( const int x) {
//     return x+10;
// }

// int main() {
//   getchar();
//   return 0;
// }
// Only the const and volatile type-specifiers at the outermost level of the parameter type specification are ignored in this fashion; const and volatile type-specifiers buried within a parameter type specification are significant and can be used to distinguish overloaded function declarations. In particular, for any type T, “pointer to T,” “pointer to const T,” and “pointer to volatile T” are considered distinct parameter types, as are “reference to T,” “reference to const T,” and “reference to volatile T.” For example, see the example in this comment posted by Venki.

// 6) Two parameter declarations that differ only in their default arguments are equivalent. For example, following program fails in compilation with error “redefinition of `int f(int, int)’ “


// #include<iostream>
// #include<stdio.h>

// using namespace std;

// int f ( int x, int y) {
//     return x+10;
// }

// int f ( int x, int y = 10) {
//     return x+y;
// }

// int main() {
//   getchar();
//   return 0;
// }


/* B. Runtime polymorphism: This type of polymorphism is achieved by Function Overriding.
Function overriding occurs when a derived class has a definition for one of the member functions of the base class. That base function is said to be overridden. */

// C++ program for function overriding

class base
{
public:
	virtual void print ()
	{ cout<< "print base class" <<endl; }

	void show ()
	{ cout<< "show base class" <<endl; }
};

class derived:public base
{
public:
	void print () //print () is already virtual function in derived class, we could also declared as virtual void print () explicitly
	{ cout<< "print derived class" <<endl; }

	void show ()
	{ cout<< "show derived class" <<endl; }
};

//main function
int main()
{
	base *bptr;
	derived d;
	bptr = &d;

	//virtual function, binded at runtime (Runtime polymorphism)
	bptr->print();

	// Non-virtual function, binded at compile time
	bptr->show();

	return 0;
}
