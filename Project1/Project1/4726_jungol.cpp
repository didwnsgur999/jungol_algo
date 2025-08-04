#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int N;
    cin >> N;
    vector<int> arr(N, 0);
    vector<int> sums(N, 0);

    cin >> arr[0];
    sums[0] = arr[0];
    for (int i = 1; i < N; i++) {
        cin >> arr[i];
        sums[i] = sums[i - 1] + arr[i];
    }

    int ans = 0;
    int total = sums[N - 1];
    //맨 오른쪽 끝, 벌 한마리만 결정
    for (int i = 1; i < N - 1; i++) {
        int temp = (total - arr[0] - arr[i]) + (total - sums[i]);
        ans = max(ans, temp);
    }
    //맨 왼쪽 끝, 벌 한마리만 결정
    for (int i = N - 2; i > 0; i--) {
        int temp = total - arr[N - 1] - arr[i] + sums[i - 1];
        ans = max(ans, temp);
    }
    //중간, 벌통 위치만 변경
    for (int i = 1; i < N - 1; i++) {
        int temp = total - arr[0] - arr[N - 1] + arr[i];
        ans = max(ans, temp);
    }
    cout << ans;

    return 0;
}