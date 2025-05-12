#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int main(void) {
    int N, T;
    cin >> N >> T;
    int C, D;
    int mididx = 1;
    stack<int> mid;
    stack<int> end;
    for (int i = 0; i < T; i++) {
        cin >> C >> D;
        //
        if (C == 1) {
            for (int i = 0; i < D; i++) {
                mid.push(mididx++);
            }
        }
        else {
            for (int i = 0; i < D; i++) {
                end.push(mid.top());
                mid.pop();
            }
        }
    }
    for (int i = 0; i < N;i++) {
        printf("%d\n", end.top());
        end.pop();
    }
    return 0;
}
