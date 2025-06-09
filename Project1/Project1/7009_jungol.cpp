#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
int search(vector<int>& V, int sus) {
    int low = 0;
    int high = N - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (V[mid] == sus) {
            return mid;
        }
        if (V[mid] < sus)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int Q;
    cin >> N >> Q;
    vector<int> com;
    vector<int> ans;
    com.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> com[i];
    }
    sort(com.begin(), com.end());
    int sus;
    for (int i = 0; i < Q; i++) {
        cin >> sus;
        int flag = search(com, sus);
        if (flag == -1) {
            ans.push_back(sus);
        }
    }
    if (!ans.empty())
        for (auto i : ans)
            cout << i << " ";
    else
        cout << -1;
    return 0;
}