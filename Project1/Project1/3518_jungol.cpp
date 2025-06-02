#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<int> v;
void deviding(int low, int high) {
    if (low >= high)
        return;
    int pivot = v[low];
    int lp = low + 1;
    int hp = high;
    while (lp <= hp) {
        //pivot이랑 같아도 처리해야 된다? -> 그게 더 빠르대요.
        while (lp <= hp && v[lp] <= pivot) lp++;
        while (lp <= hp && v[hp] >= pivot) hp--;
        if (lp <= hp) {
            swap(v[lp], v[hp]);
            lp++;
            hp--;
        }
    }
    swap(v[low], v[hp]);
    for (auto i : v) cout << i << " ";
    cout << endl;
    deviding(low, hp - 1);
    deviding(hp + 1, high);
}

int main(void) {
    int N;
    cin >> N;
    v.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    deviding(0, N - 1);
}