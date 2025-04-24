#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int N;
    int cnt = 0;
    cin >> N;
    int S[100] = { 0 };
    int st[100] = { 0 };
    int ba[100] = { 0 };
    for (int i = 0; i < N; i++) {
        cin >> S[i] >> st[i] >> ba[i];
    }
    for (int i = 101; i <= 999; i++) {
        if (i % 10 == 0 || (i % 100 - i % 10) == 0) continue;
        if (i % 10 == (i / 10) % 10 || (i / 100) == i % 10 || (i / 100) == (i / 10) % 10)continue;
        int strike, ball, flag = 0;
        //j=횟수별 count;
        for (int j = 0; j < N; j++) {
            strike = 0, ball = 0;
            //여기서 st ball처리
            int tmp = S[j], num = i;
            int tmpcount[10] = { 0 };
            //strike 갯수 확인. ball용 
            for (int k = 0; k < 3; k++) {
                if (tmp % 10 == num % 10) strike++;
                tmpcount[tmp % 10]++;
                tmp /= 10;
                num /= 10;
            }
            num = i;
            for (int k = 0; k < 3; k++) {
                if (tmpcount[num % 10]) {
                    tmpcount[num % 10]--;
                    ball++;
                }
                num /= 10;
            }
            ball -= strike;
            if (strike != st[j] || ball != ba[j]) break;
            flag++;
        }
        if (flag == N) {
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}