#include <iostream>
#include <vector>
#include <set>
using namespace std;

long long gcd(long long a, long long b) {
    return b ? gcd(b, a % b) : a;
}
long long lcm(long long a, long long b) {
    return a  / gcd(a, b) * b;
}

int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int N;
    cin >> N;
    vector<long long> v(N + 1);
    vector<int> vis(N + 1);
    set<long long> ret;
    for (int i = 1; i <= N; i++) {
        cin >> v[i];
    }
    for (int i = 1; i <= N; i++) {
        if (vis[i]) continue;
        vis[i] = 1;
        long long start = v[i];
        long long cnt = 1;
        while (i != start) {
            vis[start] = 1;
            start = v[start];
            cnt++;
        }
        ret.insert(cnt);
    }
    long long ans = 1;
    for (auto i : ret) {
        ans = lcm(ans, i);
    }
    cout << ans;

    return 0;
}