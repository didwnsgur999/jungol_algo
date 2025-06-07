#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Student {
    string name;
    int math;
    bool operator<(const Student& right) const {
        return name < right.name;
    }
};

int main(void) {
    vector<Student> V;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        Student std;
        cin >> std.name >> std.math;
        V.push_back(std);
    }
    sort(V.begin(), V.end(), [](const Student& A, const Student& B) {
        if (A.math == B.math)
            return A < B;
        else
            return A.math > B.math;
        });
    for (auto i : V)
        cout << i.name << " " << i.math << endl;
    return 0;
}
