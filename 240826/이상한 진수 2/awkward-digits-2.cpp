#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string a, copy_a;
int n = 0;

void FindMaxN(){
    int decimal_num, k;
    for(int i = 0; i < a.length(); i++){
        // 한 숫자 바꾸기
        copy_a = a;
        if(static_cast<int>(a[i] - '0') == 0){
            copy_a[i] = '1';
        }
        else{
            copy_a[i] = '0';
        }
        // cout << "copy_a: " << copy_a << endl;

        // 바꾼 숫자를 십진수로 변환
        decimal_num = 0, k = 1;
        for(int j = copy_a.length() - 1; j > -1; j--){
            decimal_num += k * static_cast<int>(copy_a[j] - '0');
            // cout << decimal_num << endl;
            k *= 2;
        }

        // 현 최댓값과 비교
        n = max(decimal_num, n);
    }
}

int main() {
    // 입력
    cin >> a;

    // 실행
    FindMaxN();

    // 출력
    cout << n;

    return 0;
}