#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(0);
    string ops;
    int N;
    int time = 0;
    int min = 0;
    int curtime = 0;
    queue<int> q;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> ops;
        if (ops == "call") {
            cin >> min;
            time += min;
            q.push(min);
        }
        else if (ops == "wait") {
            cin >> min;
            time = time < min ? 0 : time - min;
            //min 시간만큼 경과
            while (min > curtime) {
                //현재 진행중인 사람만큼 깎는다
                min -= curtime;
                curtime = 0;
                //q가 비어있으면 굳이 더 안해도 되고 나가서 
                if (!q.empty()) {
                    curtime = q.front();
                    q.pop();
                }
                else {
                    break;
                }
            }
            curtime = (curtime <= 0) ? 0 : curtime - min;
        }
        else {
            int one = 0;
            if (curtime != 0 && time != 0)
                one = 1;
            cout << q.size() + one << " people " << time << " minutes\n";
        }
    }

    return 0;
}