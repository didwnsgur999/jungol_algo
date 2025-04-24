#include <bits/stdc++.h>
using namespace std;

int main(void) {
    long long P, V, K;
    long long A, B, C, D;
    cin >> P >> V >> K;
    long long a = P + 1;
    long long b = V + 1;
    long long gcd = 0;
    while (1) {
        if (a < b) {
            int tmp = a;
            a = b;
            b = tmp;
        }
        a %= b;
        if (a == 0) {
            gcd = b;
            break;
        }
    }
    B = K / ((P + 1) / gcd * (V + 1));
    C = K / (V + 1) - B;
    D = K / (P + 1) - B;
    A = K - D - C - B;
    printf("%lld %lld %lld %lld", A, B, C, D);
    return 0;
}