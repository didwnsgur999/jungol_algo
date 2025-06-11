#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(0);
    string str;
    int N = 0, cnt = 0;
    long long U = 0;
    cin >> str;
    int size = str.size();
    int flag = 0;
    for (int i = 0; i < size; i++) {
        if (str[i] == '.') {
            flag = 1;
            continue;
        }
        if (!flag) N = N * 10 + str[i] - '0';
        else {
            cnt++;
            U = U * 10 + str[i] - '0';
        }
    }
    stack<int> S;
    while (N != 0) {
        S.push(N % 2);
        N /= 2;
    }
    if (S.empty()) cout << 0;
    while (!S.empty()) {
        cout << S.top();
        S.pop();
    }
    cout << ".";
    //cnt개수만큼 소숫점 아래로 있다.
    long long temp = U * 2;
    long long max = 1;
    for (int i = 0; i < cnt; i++)
        max *= 10;
    int cntn = 0;
    while (cntn < 4) {
        for (int i = 0; i < cnt; i++)
            temp /= 10;
        //이게 이제 출력, 다음 temp값 구하기.
        if (temp == 1) {
            cout << 1;
            temp = U * 2 - max;
        }
        else {
            cout << 0;
            temp = U * 2;
        }
        //U에 temp 저장.
        U = temp;
        temp *= 2;
        cntn++;
    }
    return 0;
}