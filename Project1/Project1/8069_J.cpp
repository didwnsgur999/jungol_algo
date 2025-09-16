#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(0);

    int N, Q;
    cin >> N >> Q;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < Q; i++) {
        int temp = 0;
        cin >> temp;
        int idx = lower_bound(a.begin(), a.end(), temp) - a.begin();
        if (idx == N) cout << a[idx - 1] << "\n";
        else if (idx == 0) cout << a[0] << "\n";
        else cout << (abs(a[idx - 1] - temp) <= a[idx] - temp ? a[idx - 1] : a[idx]) << "\n";
    }

    return 0;
}