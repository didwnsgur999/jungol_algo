#include <unordered_map>
#include <iostream>
#include <string>
using namespace std;

struct pair_hash {
    size_t operator()(const pair<string, string>& p) const {
        return hash<string>()(p.first) ^ (hash<string>()(p.second) << 1);
    }
};

int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int N;
    cin >> N;
    //STATE / CITY / °¹¼ö
    unordered_map<pair<string, string>, int, pair_hash> m;
    string city, state;
    for (int i = 0; i < N; i++) {
        cin >> city >> state;
        m[{state, city.substr(0, 2)}]++;
    }
    int sum = 0;
    for (auto it = m.begin(); it != m.end(); it++) {
        auto state1 = it->first.first;
        auto city1 = it->first.second;
        if (state1 == city1) continue;
        auto it2 = m.find({ city1,state1 });
        if (it2 != m.end()) {
            sum += it2->second * it->second;
        }
    }

    cout << sum / 2;
    return 0;
}