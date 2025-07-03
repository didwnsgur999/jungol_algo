#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(0);
    //물건값
    int W;
    cin >> W;
    //500, 100, 50, 10, 5, 1
    int coin[6] = { 1,5,10,50,100,500 };
    int max[6] = { 0 };
    int sum[6] = { 0 };
    int cnt[6] = { 0 };
    int ans[6] = { 0 };
    for (int i = 5; i >= 0; i--) {
        cin >> cnt[i];
        max[i] = cnt[i] * coin[i];
        cout << max[i] << " ";
    }
    sum[0] = max[0];
    for (int i = 1; i < 6;i++) {
        sum[i] = max[i] + sum[i - 1];
    }
    int idx = 5;
    for (int i = 0; i < 6; i++) {
        if (sum[i] >= W) {
            idx = i;
            break;
        }
    }
    cnt[idx] = 1 + (W - sum[idx-1]) / coin[idx];
    W -= sum[idx-1];


    return 0;
}