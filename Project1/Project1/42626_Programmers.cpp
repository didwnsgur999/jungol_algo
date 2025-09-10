#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (auto i : scoville) {
        pq.push(i);
    }
    int cnt = 0;
    while (pq.top() < K && pq.size() > 1) {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        pq.push(a + 2 * b);
        cnt++;
    }
    if (pq.top() >= K) {
        answer = cnt;
    }
    else {
        answer = -1;
    }
    return answer;
}