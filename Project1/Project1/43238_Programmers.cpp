#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(int& n, vector<int>& times, long long mid) {
    long long cnt = 0;
    for (auto i : times) {
        cnt += mid / i;
        if (cnt >= n) {
            return 1;
        }
    }
    return 0;
}

//n = 심사 대기자, times = 1명당 시간, 
long long solution(int n, vector<int> times) {
    long long answer = 0;
    int times_min = 1000000001;
    for (auto i : times) {
        times_min = min(i, times_min);
    }
    //max = 가장 짧은 값 * cnt * 1LL하면 나온다.
    long long high = (long long)times_min * n;
    //min = 0;
    long long low = 1;
    while (high >= low) {
        long long mid = low + (high - low) / 2;
        if (solution(n, times, mid)) {
            high = mid - 1;
            answer = mid;
        }
        else {
            low = mid + 1;
        }
    }

    return answer;
}