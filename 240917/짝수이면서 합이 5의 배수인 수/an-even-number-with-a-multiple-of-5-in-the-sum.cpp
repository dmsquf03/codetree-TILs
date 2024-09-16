#include <iostream>
#include <string>
using namespace std;

bool IsEven5(int n){
    string s = to_string(n);
    int sum = 0;
    for(int i = 0; i < s.length(); i++){
        sum += s[i] - '0';
    }
    return (n % 2 == 0 && sum % 5 == 0);
}

int main() {
    // 입력
    int n;
    cin >> n;

    // 실행
    if(IsEven5(n)){
        cout << "Yes";
    }
    else cout << "No";
    
    return 0;
}