#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
long long cuttree(vector<long long>& tree, int mid) {
    long long count = 0;
    for (int i = 0; i < N; i++)
        count += (tree[i] - mid > 0 ? tree[i] - mid : 0);
    return count;
}

long long mid(vector<long long>& tree) {
    long long low = 0;
    long long high = tree[N - 1];
    long long last;
    while (low <= high) {
        long long mid = (low + high) / 2;
        long long cnt = cuttree(tree, mid);
        if (cnt == M) {
            return mid;
        }
        //M보다 모자라다.
        if (cnt < M) {
            high = mid - 1;
        }
        //M보다 더 잘랐다.
        else {
            last = mid;
            low = mid + 1;
        }
    }
    return last;
}

int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(0);
    vector<long long> tree;
    cin >> N >> M;
    tree.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> tree[i];
    }
    sort(tree.begin(), tree.end());
    cout << mid(tree);
    return 0;
}