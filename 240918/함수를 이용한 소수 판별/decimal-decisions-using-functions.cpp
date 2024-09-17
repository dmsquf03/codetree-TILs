#include <iostream>
using namespace std;

int a, b, result = 0;

bool IsPrime(int n){
    if(n == 1) false;
    for(int i = 2; i < n; i++){
        if(n % i == 0) return false;
    }
    return true;
}

void SumPrimeAtoB(){
    for(int i = a; i < b + 1; i++){
        if(IsPrime(i)) result += i;
    }
}

int main() {
    // 입력
    cin >> a >> b;

    // 실행
    SumPrimeAtoB();

    // 출력
    cout << result;
    return 0;
}