#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//sum = 현재까지 만들 수 있는 무게
//추가적인 분동 v[i]가 들어오면 1+v[i]~sum+v[i]까지 추가로 잴 수 있는데
//이때 1+v[i]가 sum+1을 넘어버리면 터진다. 
//1~5 -> 5더해서 -> 6~11은 되지만 6이 들어와서 7~12가 되면 6을 못만든다.

int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int N;
    cin >> N;
    vector<int> v;
    v.resize(N);
    int sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    if (v[0] != 1) {
        cout << 1;
        return 0;
    }
    sum = v[0];
    for (int i = 1; i < N; i++) {
        if (sum + 1 >= v[i]) sum += v[i];
        else break;
    }
    cout << sum + 1;
    return 0;
}