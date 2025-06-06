#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

// time 3:26 start //3:51 4:00휴식// 5:22 clear
// N= dna 개수
int N;
int ans = 999999;
string DNA[7];
//
int per[7];
int num[7];//0123456
//순서대로 병합해보기
void comp() {
    string ans_s = "";
    string fi, la;
    for (int i = 0; i < N - 1; i++) {
        fi = DNA[per[i]];
        la = DNA[per[i + 1]];
        int idx = 8;
        int sizefi = fi.size();
        int sizela = la.size();
        //같은거 확인 처리
        for (int i = 0; i < sizefi; i++) {
            if (sizefi - i > sizela) continue;
            if (fi.substr(i, sizefi - i).compare(la.substr(0, sizefi - i)) == 0) {
                idx = i;
                break;
            }
        }
        //같은 부분 존재
        if (idx != 8) {
            ans_s += fi.substr(0, idx);
        }
        else {
            ans_s += fi;
        }
        if (ans_s.size() > ans)
            return;
    }
    //마지막 la는 더하기
    ans_s += la;
    if (ans_s.size() < ans) {
        ans = ans_s.size();
    }
}
void permutation(int depth) {
    if (depth == N) {
        //DNA조합해보기
        comp();
        return;
    }
    for (int i = 0; i < N; i++) {
        if (num[i] == 1) continue;
        num[i] = 1;
        per[depth] = i;
        permutation(depth + 1);
        num[i] = 0;
    }
}
int main(void) {
    cin >> N;
    //N개 입력 -> 순열순서 permutation돌리고, 합치기 후 크기 확인
    for (int i = 0; i < N; i++) {
        cin >> DNA[i];
    }
    permutation(0);
    cout << ans << endl;
}