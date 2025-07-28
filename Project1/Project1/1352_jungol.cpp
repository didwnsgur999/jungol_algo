//
//초기에 틀린 이유 -> 이번 dp에서 칠한 곳이 이번의 다음 dp처리에 영향을 줬다.
//개선방향 -> dp를 복사해서 dp_next를 만들어서 dp를 통해 가능한 위치를 보고, dp_next에 색칠을 했다.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int N, T;
    vector<int> dp(40001, 0);
    //추의 개수
    cin >> N;
    vector<int> mass(N, 0);
    //작은거부터 N-1 큰거까지
    for (int i = 0; i < N; i++) {
        cin >> mass[i];
    }
    //각 마블 처리
    cin >> T;
    vector<int> tar(T, 0);
    for (int i = 0; i < T; i++) {
        cin >> tar[i];
    }
    //초기 dp[0]가능.
    dp[0] = 1;
    for (int i = N - 1; i >= 0; i--) {
        //현재 mass
        int tm = mass[i];
        //결과 저장용 dp_next
        vector<int> dp_next(dp);
        for (int j = 40000; j >= 0; j--) {
            //dp를 통해 현재 가능한 것을 확인하고,
            if (dp[j]) {
                //dp next에 가능한 값을 체크하고
                if (j + tm <= 40000) dp_next[j + tm] = 1;
                if (j - tm >= 0) dp_next[j - tm] = 1;
                dp_next[abs(j - tm)] = 1;
            }
        }
        //복사한다.
        dp = dp_next;
    }
    //무게 처리
    for (int i = 0; i < T; i++) {
        if (dp[tar[i]] == 1) {
            cout << "Y ";
        }
        else {
            cout << "N ";
        }
    }

    return 0;
}