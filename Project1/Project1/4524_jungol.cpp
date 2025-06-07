#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    vector<int> V;
    int N;
    cin >> N;
    V.resize(N);
    for (int i = 0; i < N; i++)
        cin >> V[i];
    sort(V.begin(), V.end(), [](const int& a, const int& b) {return a > b; });
    for (auto i : V)
        cout << i << " ";
}