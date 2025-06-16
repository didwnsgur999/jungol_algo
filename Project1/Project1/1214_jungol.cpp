#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int N;
    long long temp;
    cin >> N;
    //height / first found height
    stack<pair<long long, long long>> s;
    long long ans = 0;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        long long idx = i;
        while (!s.empty() && s.top().first >= temp) {
            ans = max(ans, (i - s.top().second) * s.top().first);
            idx = s.top().second;
            s.pop();
        }
        s.push({ temp,idx });
    }
    //
    while (!s.empty()) {
        ans = max(ans, (N - s.top().second) * s.top().first);
        s.pop();
    }
    cout << ans;

    return 0;
}