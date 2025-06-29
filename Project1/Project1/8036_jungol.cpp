#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    int N;
    cin.tie(0); ios_base::sync_with_stdio(0);
    vector<pair<int, int>> v;
    cin >> N;
    int x, y;
    long long cnt = 0, sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        v.push_back({ x,y });
    }
    sort(v.begin(), v.end());
    int last = -1000000001;
    for (auto i : v) {
        if (i.first != last) {
            last = i.first;
            cnt = 0;
        }
        else {
            cnt++;
            sum += cnt;
        }
    }
    //cout<<sum;
    sort(v.begin(), v.end(), [](auto a, auto b) {if (a.second == b.second) return a.first < b.first; else return a.second < b.second;});
    last = -1000000001;
    cnt = 0;
    for (auto i : v) {
        if (i.second != last) {
            last = i.second;
            cnt = 0;
        }
        else {
            cnt++;
            sum += cnt;

        }
    }
    cout << sum;

    return 0;
}