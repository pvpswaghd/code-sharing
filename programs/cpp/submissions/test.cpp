#include <iostream> 
#include <string> 
using namespace std;
void f(int &a) { 
    cout << "function address: " << &a << endl;
    {
        int a = 0;
        cout << "declaring same name address: " << &a << endl;
    }
}
int main() { 
    int a = 2; //constructing
    {
        int a = 3; //destructing and reconstructing -> new  
        f(a);
        cout << &a << " " << endl;
    }
    cout << "Outside of loop: " << &a << endl;
    f(a);
    cout << a << " "; 
    return 0;
}
