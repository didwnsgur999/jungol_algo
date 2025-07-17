#include <map>
#include <iostream>
#include <string>
using namespace std;

int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(0);

    map<string, int> m;

    int i = 1;
    string str = "";
    while (true) {
        cin >> str;
        if (str == "end") break;
        m[str] = i++;
    }
    cout << m.size() << "\n";
    for (auto [key, value] : m) {
        cout << key << " " << value << "\n";
    }

    return 0;
}