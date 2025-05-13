#include <iostream>
#include <string>
using namespace std;

int main(void) {
    string s[5];
    int ssize[5];
    for (int i = 0; i < 5; i++) {
        cin >> s[i];
        ssize[i] = s[i].size();
    }
    for (int j = 0; j < 15; j++) {
        for (int i = 0; i < 5; i++) {
            if (j < ssize[i])
                cout << s[i][j];
        }
    }
}