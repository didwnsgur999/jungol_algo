#include <iostream>
using namespace std;

int main(void) {
    int a, b, c, d, e, N;
    cin >> a >> b >> c >> d >> e >> N;
    int cnt = 0;
    while (e != 0 && N >= 16) { N -= 16; cnt++; e--; }
    while (d != 0 && N >= 8) { N -= 8; cnt++; d--; }
    while (c != 0 && N >= 4) { N -= 4; cnt++; c--; }
    while (b != 0 && N >= 2) { N -= 2; cnt++; b--; }
    while (a != 0 && N >= 1) { N -= 1; cnt++; a--; }
    if (N != 0)
        cout << "impossible";
    else
        cout << cnt;
    return 0;
}