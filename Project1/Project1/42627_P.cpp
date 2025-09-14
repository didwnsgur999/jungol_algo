#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    //jobs[작업번호][요청시간][작업시간];
    sort(jobs.begin(), jobs.end());
    //0,3 2,6
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    int time = 0;
    int cost = 0;
    int idx = 0;
    int cnt = jobs.size();
    while (idx < cnt || !pq.empty()) {
        //현재 시간에 넣을게 없으면 시간 이동, 넣을게 있으면 끝까지 넣는다.     
        while (idx < cnt && jobs[idx][0] <= time) {
            //작업시간, 요청시간
            pq.push({ jobs[idx][1],jobs[idx][0] });
            idx++;
        }
        //넣은거 빼서 해본다.
        if (!pq.empty()) {
            auto [l, s] = pq.top();
            pq.pop();
            time += l;
            cost += time - s;
        }
        else {
            time = jobs[idx][0];
        }
    }

    answer = cost / jobs.size();
    return answer;
}