#include <iostream>
#include <string>
using namespace std;

int a, b, result = 0;

bool Is369(int i){
    string s = to_string(i);
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '3' || s[i] == '6' || s[i] == '9') return true;
    }
    return false;
}

bool IsMultiple3(int i){
    return (i % 3 == 0);
}

void CountRightNum(){
    for(int i = a; i < b + 1; i++){
        if(Is369(i) || IsMultiple3(i)) result++;
    }
}

int main() {
    // 입력
    cin >> a >> b;

    // 실행
    CountRightNum();

    // 출력
    cout << result;
    return 0;
}