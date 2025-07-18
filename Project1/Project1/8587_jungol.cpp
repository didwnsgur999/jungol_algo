#include <iostream>
#include <queue>
#include <string>
#include <sstream>
using namespace std;

struct patient {
    string name;
    int age;
    double blood;
    bool operator<(const patient& right) const {
        if (blood == right.blood)
            return age < right.age;
        return blood < right.blood;
    }
};

int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(0);
    priority_queue<patient> data;
    int Q;
    cin >> Q;
    cin.ignore();
    string ops;
    string temp;
    for (int i = 0; i < Q; i++) {
        cin >> ops;
        if (ops == "push") {
            getline(cin, temp);
            string name; int age; double blood;
            istringstream iss(temp);
            iss >> name >> age >> blood;
            data.push({ name,age,blood });
        }
        else {
            if (!data.empty()) {
                auto [name, age, blood] = data.top();
                cout << name << "\n";
                data.pop();
            }
        }
    }
}