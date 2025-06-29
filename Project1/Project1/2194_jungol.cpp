#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(0);
    long long N, S;
    cin >> N >> S;
    //first = C원, second = Y리터 S = 일당 가격변화량. 
    long long C, Y;
    long long cost = 0;
    long long min = 5011;
    for (int i = 0; i < N; i++) {
        cin >> C >> Y;
        //가격변화 min+S랑 C비교
        min = (min + S < C) ? min + S : C;
        cost += Y * min;
    }
    cout << cost;

    return 0;
}