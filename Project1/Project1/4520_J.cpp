#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void) {
    int N, k;
    string s;
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin >> N >> k >> s;

    vector<bool> vis(N, 0);

    int cnt = 0;
    // ±×¸®µð
    for (int i = 0; i < N; i++) {
        if (s[i] == 'P') {
            for (int j = -k; j <= k; j++) {
                if (i + j < 0 || i + j >= N) continue;
                if ((s[i + j] == 'H') && (vis[i + j] != 1)) {
                    cnt++;
                    vis[i + j] = 1;
                    break;
                }
            }
        }
    }
    cout << cnt;

    return 0;
}