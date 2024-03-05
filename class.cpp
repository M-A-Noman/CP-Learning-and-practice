#include <bits/stdc++.h>
using namespace std;
class A
{
public:
    A()
    {
        cout << "A\n";
    }
    // A(B obj)
    // {
    //     cout << "Passing object of B\n";
    // }
    void fun(){
        cout << "Method of A\n";
    }
};
class B : public A
{
public:
    B()
    {
        cout << "B\n";
    }
    void fun(){
        cout << "Method of B\n";
    }
};
int main()
{
    B obj1;
    A  obj2;
    // obj2 = obj1;
    obj2.fun();
    obj1.fun();
}