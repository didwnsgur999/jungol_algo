#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {
    int N;
    vector<int> V;
    cin >> N;
    V.resize(N);
    for (int i = 0; i < N; i++)
        cin >> V[i];
    int S, E;
    cin >> S >> E;
    sort(V.begin() + S, V.begin() + E + 1);
    for (auto i : V)
        cout << i << " ";
    cout << endl;
    sort(V.begin(), V.end());
    for (auto i : V)
        cout << i << " ";
}