#include <iostream>
#include <string>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int cnt = 0;
    string s;

    // 입력
    cin >> s;

    // 실행
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '('){
            for(int j = i + 1; j < s.length(); j++){
                if(s[j] == ')'){
                    cnt++;
                }
            }
        }
    }

    // 출력
    cout << cnt;

    return 0;
}