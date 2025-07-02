#include <iostream>

using namespace std;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int G, L;
    cin >> G >> L;
    int k = L / G;
    int a, b;
    int x = 0, y = 0;
    for (int i = 1; i * i <= k; i++) {
        if (k % i == 0) {
            x = i;
            y = k / x;
            if (gcd(x, y) == 1) {
                a = x * G;
                b = y * G;
            }
        }
    }
    cout << a << " " << b;

    return 0;
}