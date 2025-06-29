#include <iostream>
#include <algorithm>
#include <vector>
#define x first
#define y second
using namespace std;

int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int N;
    vector<pair<int, pair<int, int>>> v;
    vector<int> ans;
    cin >> N;
    v.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i].x >> v[i].y.x >> v[i].y.y;
    }
    sort(v.begin(), v.end(), [=](auto a, auto b) { if (a.y.y == b.y.y)
        return (a.y.x < b.y.x);
    else
        return (a.y.y < b.y.y); });
    int cnt = 0;
    int last = -1;
    for (auto i : v) {
        if (last <= i.y.x) {
            cnt++;
            last = i.y.y;
            ans.push_back(i.x);
        }
    }
    cout << cnt << "\n";
    for (auto i : ans) {
        cout << i << " ";
    }
    return 0;
}