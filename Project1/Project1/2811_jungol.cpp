#include <vector>
#include <iostream>
using namespace std;

int main(void) {
    int N;
    for (int i = 0; i < 5; i++) {
        cin >> N;
        if (N == 1) {
            printf("number one\n");
        }
        //N이 소수인지 확인.
        else {
            int prime = 1;
            for (int j = 2; j * j <= N; j++) {
                if (N % j == 0) {
                    prime = 0;
                    break;
                }
            }
            if (prime) {
                printf("prime number\n");
            }
            else
                printf("composite number\n");
        }
    }
}