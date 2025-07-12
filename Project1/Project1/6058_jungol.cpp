#include <iostream>
#include <vector>
#include <string>
using namespace std;

char board[10][10];
unsigned short vis;
int cnt;
int N;
void dfs(int n) {
    if (n == N) {
        cnt++;
        return;
    }
    for (int i = 0; i < N; i++) {
        unsigned short cur = 1 << i;
        if (vis & cur || board[n][i] == '#') continue;
        vis |= cur;
        dfs(n + 1);
        vis &= ~cur;
    }
}

int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin >> N;
    string input;
    for (int i = 0; i < N; i++) {
        cin >> input;
        for (int j = 0; j < N; j++) {
            board[i][j] = input[j];
        }
    }
    dfs(0);
    cout << cnt;
    return 0;
}