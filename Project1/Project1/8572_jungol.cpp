#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
    int N, X;
    cin >> N;
    cin >> X;
    vector<int> V(N, X);

    char ops;
    int temp;
    while (true) {
        cin >> ops;
        if (ops == 'i') {
            cin >> temp;
            V.push_back(temp);
        }
        else if (ops == 'r') {
            if (!V.empty())
                V.pop_back();
        }
        else if (ops == 's') {
            sort(V.begin(), V.end());
        }
        else if (ops == 't') {
            int size = V.size();
            if (size) {
                int ed = V[size - 1];
                V.pop_back();V.push_back(V[0]);V[0] = ed;
            }
        }
        else if (ops == 'e') {
            for (auto i : V) {
                cout << i << " ";
            }
            break;
        }
    }


    return 0;
}