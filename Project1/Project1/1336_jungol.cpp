#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;
//prime -> 소수 아니면 0 소수면 1
vector<bool> prime(10000, 1);
//방문기록
vector<bool> vis(10000, 0);

int strtoi(string str) {
    int sum = 0;
    for (int i = 0; i < 4; i++) {
        sum *= 10;
        sum += str[i] - '0';
    }
    return sum;
}

int main(void) {
    //for speed
    cin.tie(0); ios_base::sync_with_stdio(0);
    string st, ed;
    cin >> st >> ed;
    //prime
    for (int i = 2; i < 10000; i++) {
        if (prime[i] == 1) {
            for (int j = 2 * i; j < 10000; j += i) {
                prime[j] = 0;
            }
        }
    }
    queue<pair<string, int>> q;
    q.push({ st,0 });
    vis[strtoi(st)] = 1;
    while (!q.empty()) {
        auto [cur, cnt] = q.front();
        q.pop();
        if (cur == ed) {
            cout << cnt;
            return 0;
        }
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j <= 9; j++) {
                if (i == 0 && j == 0) continue;
                string nxt = cur;
                nxt[i] = j + '0';
                int nxtI = strtoi(nxt);
                if (vis[nxtI] == 1 || prime[nxtI] == 0)
                    continue;
                vis[nxtI] = 1;
                q.push({ nxt, cnt + 1 });
            }
        }
    }

    return 0;
}