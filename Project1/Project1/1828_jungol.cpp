#include <iostream>
#include <algorithm>
#include <vector>
#define x first
#define y second
using namespace std;

int main(void) {
    int N;
    cin >> N;
    int cnt = 0;
    vector<pair<int, int>> vec;
    vec.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> vec[i].first >> vec[i].second;
    }
    //i = 화학물질 x y
    sort(vec.begin(), vec.end(), [](auto a, auto b) {if (a.y == b.y) return a.x < b.x; else return a.y < b.y; });
    int last = -271;
    for (auto i : vec) {
        if (i.x > last) {
            last = i.y;
            cnt++;
        }
    }
    cout << cnt;

    return 0;
}