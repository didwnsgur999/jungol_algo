#include <iostream>
using namespace std;

int dp[100001];
int main(void) {
    int N;
    cin >> N;
    dp[1] = 1;
    dp[2] = 3;
    //dp[3]= 2*dp1+dp2;
    for (int i = 3; i <= N; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2] * 2) % 20100529;
    }
    cout << dp[N];
    return 0;
}