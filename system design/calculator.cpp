#include <bits/stdc++.h>
using namespace std;

class Calculator{
    float a,b;
public:
    void input(){
        cout<<"Enter 1st Number: ";
        cin>>a;
        cout<<"Enter 2nd Number: ";
        cin>>b;
    }
    float add(){
        return a+b;
    }
    float sub(){
        return a-b;
    }
    float mul(){
        return a*b;
    }
    float div(){
        if(b==0){
            cout<<"Undefined"<<endl;
            return INFINITY;
        }
        else return a/b;
    }
};

int main(){
    int ch;
    Calculator c;
    cout<<"Enter 1 to Add"<<"\nEnter 2 to Subtract"<<"\nEnter 3 to Multiply"<<"\nEnter 4 to Divide"<<"\nEnter 5 to Exit";
    do{
        cout<<"\nEnter Choice: ";
        cin>>ch;
        switch(ch){
            case 1:
            c.input();
            cout<<"Result: "<<c.add()<<endl;
            break;
            case 2:
            c.input();
            cout<<"Result: "<<c.sub()<<endl;
            break;
            case 3:
            c.input();
            cout<<"Result: "<<c.mul()<<endl;
            break;
            case 4:
            c.input();
            cout<<"Result: "<<c.div()<<endl;
            break;

            default:
            exit(0);
        }
    } while(ch>=1 and ch<=4);
    return 0;
}

