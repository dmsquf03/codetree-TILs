#include <iostream>
using namespace std;

int DivideSum10(int n){
    int sum = 0;
    for(int i = 1; i < n + 1; i++){
        sum += i;
    }
    return sum / 10;
}

int main() {
    // 입력
    int n;
    cin >> n;

    // 실행
    int result = DivideSum10(n);

    // 출력
    cout << result;
    return 0;
}