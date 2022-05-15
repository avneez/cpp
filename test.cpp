#include <bits/stdc++.h>
using namespace std;

// class Base{
//     public:
//     virtual void show() { cout<<" In Base \n";}
// };

// class Derived: public Base{
//     public:
//     void show() { cout<<" In Derived \n";}
// };

// int main(void){
//     // Base *bp = new Derived;
//     // bp->show();

//     // Base &br = *bp;
//     // br.show();

//     Base *bp, b;
//     Derived d;
//     bp = &d;
//     bp->show();

//     bp = &b;
//     bp->show();

//     return 0;
// }

class Base{};
class Derived: public Base{};
int main(){
    Derived d;
    try {
        throw d;
    }
    catch(Base b){
        cout<<"Caught Base Exception";
    }
    catch(Derived d){
        cout<<"Caught Derived Exception";
    }
    return 0;
}