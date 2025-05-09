#include <iostream>
using namespace std;
int arr[41];
//¾Õ, µÚ
int dp[41];
int main(void) {
    int N, M, temp, ans = 1;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> temp;
        arr[temp] = 1;
    }
    dp[1] = 1; dp[2] = 2;
    for (int i = 3; i <= N; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        if (arr[i] == 1) {
            if (cnt) {
                ans *= dp[cnt];
            }
            cnt = 0;
        }
        else {
            cnt++;
        }
    }
    if (cnt) ans *= dp[cnt];
    cout << ans;
}