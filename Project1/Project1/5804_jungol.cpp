#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<long long> point;
int N, C;
long long ans;
bool isright(long long param) {
    int cnt = 1; long long last = point[0];
    for (int i = 1; i < N; i++) {
        if (point[i] - last >= param) {
            cnt++;
            last = point[i];
        }
        if (cnt >= C)
            return 1;
    }
    return 0;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin >> N >> C;
    point.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> point[i];
    }
    sort(point.begin(), point.end());
    long long las = point[N - 1], fir = 0;
    while (fir <= las) {
        long long mid = (fir + las) / 2;
        if (isright(mid)) {
            ans = mid;
            fir = mid + 1;
        }
        else {
            las = mid - 1;
        }
    }
    cout << ans;
    return 0;
}