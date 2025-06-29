#include <iostream>
#include <map>
using namespace std;

int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(0);
    map<int, int> m;
    int N;
    cin >> N;
    int ele;
    for (int i = 0; i < N; i++) {
        cin >> ele;
        m[ele]++;
    }
    for (auto [key, value] : m) {
        cout << key << " : " << value << "\n";
    }


    return 0;
}
