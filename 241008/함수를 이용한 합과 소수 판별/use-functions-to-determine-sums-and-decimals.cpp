#include <iostream>
#include <string>
using namespace std;

int a, b, result = 0;

bool IsPrime(int p){
    bool flag = true;
    for(int i = 2; i < p; i++){
        if(p % i== 0) flag = false;
    }
    return flag;
}

bool IsAllSumEven(int e){
    string temp = to_string(e);
    int sum = 0;
    for(int i = 0; i < temp.length(); i++){
        sum += temp[i] - '0';
    }
    if(sum % 2 == 0) return true;
    return false;
}

void CntPrimeEven(){
    for(int i = a; i < b + 1; i++){ // a 이상 b 이하
        if(i == 1) continue;
        if(IsPrime(i) && IsAllSumEven(i)) result++;
    }
}

int main() {
    cin >> a >> b;
    CntPrimeEven();
    cout << result;
    return 0;
}