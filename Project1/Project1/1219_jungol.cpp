#include <algorithm>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//??????ê°?ˆ˜,?€ë¦°ê°¯??
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
    //ÃÊ±â maxy°ª »Ì±â.
    for (long long i = 0; i < w; i++) {
        cin >> y >> V[i];
        if (maxy < y)
            maxy = y;
    }
    //low = max y°ª high = ¿­ °¹¼ö
    long long low = maxy;
    long long high = c;
    sort(V.begin(), V.end());
    while (low <= high) {
        long long mid = (low + high) / 2;
        long long res = res_cnt(V, mid);
        //number°ªÀÌ resultº¸´Ù Å©°Å³ª °°´Ù
        //->´õ ÀÛÀº µµÈ­Áö ÇØº»´Ù. -> high°ª mid-1·Î º¯°æ
        if (num >= res) {
            high = mid - 1;
        }
        //ÀÛ´Ù = ´õ Å« µµÈ­Áö ÇØ¾ßµÈ´Ù.
        else {
            low = mid + 1;
        }
    }
    cout << high + 1;
    return 0;
}