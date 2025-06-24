#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int board[129][129];
int blcnt, whcnt;
void count(int rst, int red, int lst, int led) {
    if ((red - rst == 1) && (led - lst == 1)) {
        board[rst][lst] == 0 ? whcnt++ : blcnt++;
        return;
    }
    int rmid = (rst + red) / 2;
    int lmid = (lst + led) / 2;
    int clr = board[rst][lst];
    int flag = 0;
    for (int i = rst; i < red; i++) {
        for (int j = lst; j < led; j++) {
            if (board[i][j] != clr) {
                flag = 1;
                break;
            }
        }
        if (flag) break;
    }

    if (flag == 0) {
        if (clr)
            blcnt++;
        else
            whcnt++;
        return;
    }
    else {
        count(rst, rmid, lst, lmid);
        count(rst, rmid, lmid, led);
        count(rmid, red, lst, lmid);
        count(rmid, red, lmid, led);
    }
}

int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }
    count(0, N, 0, N);
    cout << whcnt << "\n" << blcnt;
    return 0;
}