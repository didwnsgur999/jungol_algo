#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct Rectangle {
    int width;
    int height;
    bool operator<(const Rectangle& right) {
        return (width * height) < (right.width * right.height);
    }
};
int main(void) {
    Rectangle a, b;
    cin >> a.width >> a.height;
    cin >> b.width >> b.height;
    if (a < b) { cout << "a is smaller\n"; }
    else { cout << "b is smaller\n"; }
    return 0;
}