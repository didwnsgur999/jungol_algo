#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int N;
    cin >> N;
    vector<int> v[N];
    vector<int> arr(N);
    int cnt;
    for (int i = 0; i < N; i++) {
        cin >> cnt;
        v[i].resize(cnt);
        for (int j = 0; j < cnt; j++) {
            cin >> v[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    for (auto i : arr) {
        for (auto j : v[i]) {
            cout << j << " ";
        }
        cout << "\n";
    }

    return 0;
}