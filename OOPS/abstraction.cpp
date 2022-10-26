// In OOPs, Abstraction is the method of getting information where the information needed will be taken in such a simplest way
// that solely the required components are extracted, and also the ones that are considered less significant are unnoticed.
// The concept of abstraction only shows necessary information to the users.
// It reduces the complexity of the program by hiding the implementation complexities of programs.

#include <iostream>
using namespace std;

class Summation {
private:
	// private variables
	int a, b, c;
public:
	void sum(int x, int y)
	{
		a = x;
		b = y;
		c = a + b;
		cout<<"Sum of the two number is : "<<c<<endl;
	}
};
int main()
{
	Summation s;
	s.sum(5, 4);
	return 0;
}
