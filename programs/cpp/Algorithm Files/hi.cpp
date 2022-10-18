#include <iostream>
#include <cmath>

using namespace std;

int solve(int n){
    if(n==1) return 0;
    if(n==2) return 4;
    if(n==3) return 10;
    return 2*n + solve(floor(n/2)) + solve(ceil(n/2));
}



int main(){

    cout << solve(5);

    return 0;


}
