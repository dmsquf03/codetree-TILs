#include <iostream>
#include <algorithm>
using namespace std;

int FindMin(int a, int b, int c){
    return min(min(a, b), min(a, c));
}

int main() {
    // 입력
    int a, b, c;
    cin >> a >> b >> c;

    // 실행
    int result = FindMin(a, b, c);

    // 출력
    cout << result;
    return 0;
}