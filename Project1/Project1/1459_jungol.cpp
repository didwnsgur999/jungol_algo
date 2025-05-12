#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> ans;
void recursive(int n, vector<int>& V, vector<bool>& vis) {
    vector<int> arr;
    arr.push_back(n);
    vis[n] = true;
    int cur = V[n];
    while (!vis[cur]) {
        vis[cur] = true;
        arr.push_back(cur);
        cur = V[cur];
    }
    if (cur == n) {
        for (auto i : arr)
            ans.push_back(i);
    }
    else {
        for (auto i : arr)
            vis[i] = false;
    }
    return;
}
int main(void) {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> N;
    vector<int> V(N + 1);
    vector<bool> vis(N + 1);

    //위아래 동일하면 
    for (int i = 1; i <= N; i++) {
        cin >> V[i];
        if (i == V[i]) {
            ans.push_back(V[i]);
            vis[i] = true;
        }
    }
    for (int i = 1; i <= N; i++) {
        if (vis[i] == true) continue;
        recursive(i, V, vis);
    }
    int size = ans.size();
    sort(ans.begin(), ans.end());
    cout << size << "\n";
    for (auto i : ans)
        cout << i << "\n";
}