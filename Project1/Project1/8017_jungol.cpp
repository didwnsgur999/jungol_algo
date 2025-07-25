#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(0);
    long long L;
    int N, K;
    cin >> L >> N >> K;
    vector<long long> A(N);
    unordered_map<long long, long long> vis;
    vector<long long> ans;
    long long dx[2] = { -1,1 };
    queue<pair<long long, long long>> q;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        q.push({ A[i],0 });
        vis[A[i]] = 1;
    }
    while (!q.empty() && ans.size() < K) {
        auto [cur, light] = q.front();
        q.pop();
        //answer 넣기.
        ans.push_back(light);

        for (int i = 0; i < 2; i++) {
            long long nx = cur + dx[i];
            if (nx<0 || nx>L) continue;
            if (vis.find(nx) == vis.end()) {
                vis[nx] = 1;
                q.push({ nx,light + 1 });
            }
        }
    }

    for (const auto& i : ans) {
        cout << i << "\n";
    }

    return 0;
}