#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, M;
vector<long long> vec;
vector<int> point;
vector<long long> ans;

bool isright(long long param) {
    int idx = 0;
    int cnt = 1; long long tempsum = 0;
    for (int i = 0; i < N; i++) {
        if (tempsum + vec[i] <= param) {
            tempsum += vec[i];
        }
        else {
            tempsum = 0;
            cnt++;
            i--;
        }
        if (cnt > M) return 0;
    }
    return 1;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin >> N >> M;
    vec.resize(N);
    long long sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> vec[i];
        sum += vec[i];
    }
    long long fir = sum / M, las = sum;
    long long ans = 0;
    while (fir <= las) {
        long long mid = (fir + las) / 2;
        if (isright(mid)) {
            ans = mid;
            las = mid - 1;
        }
        else {
            fir = mid + 1;
        }
    }
    cout << ans;
    return 0;
}