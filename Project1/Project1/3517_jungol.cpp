#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int search(vector<int>& V, int temp) {
    int low = 0;
    int high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (V[mid] == temp) {
            return mid;
        }
        else if (V[mid] < temp) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return -1;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int q;
    vector<int> V;
    cin >> n;
    V.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> V[i];
    }
    cin >> q;
    int temp;
    for (int i = 0; i < q; i++) {
        cin >> temp;
        cout << search(V, temp) << " ";
    }
    return 0;
}