#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//행,열,쓸 갯수,틀린갯수
long long r, c, num, w;
long long maxy;

long long res_cnt(vector<long long>& V, long long mid) {
    long long i, j;
    long long ans = 1;
    j = V[0] + mid;
    for (i = 1; i < w; i++) {
        if (V[i] >= j) {
            ans++;
            j = V[i] + mid;
        }
    }
    return ans;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin >> r >> c >> num >> w;
    long long y;
    vector<long long> V;
    V.resize(w);
    //초기 maxy값 뽑기.
    for (long long i = 0; i < w; i++) {
        cin >> y >> V[i];
        if (maxy < y)
            maxy = y;
    }
    //low = max y값 high = 열 갯수
    long long low = maxy;
    long long high = c;
    sort(V.begin(), V.end());
    while (low <= high) {
        long long mid = (low + high) / 2;
        long long res = res_cnt(V, mid);
        //number값이 result보다 크거나 같다
        //->더 작은 도화지 해본다. -> high값 mid-1로 변경
        if (num >= res) {
            high = mid - 1;
        }
        //작다 = 더 큰 도화지 해야된다.
        else {
            low = mid + 1;
        }
    }
    cout << high + 1;
    return 0;
}