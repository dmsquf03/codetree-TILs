#include <iostream>
#include <string>
using namespace std;

string s;
int result = 0;

void FindCoupleNum(){ // 왼 오 둘다 잡아야.
    for(int i = 0; i < s.length() - 3; i++){// 왼
        if(s[i] == '(' && s[i + 1] == '('){
            for(int j = i + 2; j < s.length() - 1; j++){// 오
                if(s[j] == ')' && s[j + 1] == ')'){
                    result++;
                }
            }
        }
    }
}

int main() {
    // 입력
    cin >> s;

    // 실행
    FindCoupleNum();

    // 출력
    cout << result;

    return 0;
}