#include <iostream>
#define long long ll;

long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

//the fundamental idea of this algorithm:
//for 3^8, it makes the computation faster by
//(3*4)^2 = (((3^2)^2)^2)
