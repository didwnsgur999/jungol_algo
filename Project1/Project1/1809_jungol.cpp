#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

int main(void) {
    //first = height, second = number
    stack<pair<int, int>> s;
    int N;
    cin >> N;
    int temp;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        while (!s.empty() && s.top().first < temp) {
            s.pop();
        }
        if (!s.empty()) {
            cout << s.top().second + 1 << " ";
        }
        else {
            cout << 0 << " ";
        }
        s.push({ temp,i });
    }
}