#include <iostream>
#include <unordered_map>
using namespace std;

int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(0);

    int N, P, cnt = 0;
    cin >> N >> P;
    unordered_map<int, int> vis;
    int temp = N;
    while (vis.find(temp) == vis.end()) {
        vis[temp] = cnt++;
        temp = temp * N % P;
    }
    cout << cnt - vis[temp];
}