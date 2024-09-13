#include <iostream>
#include <string>
using namespace std;

string s;
int cnt = 0, len;

void FindCOW(){// 세 자리 잡아야 함.
    for(int i = 0; i < len - 2; i++){// C
        if(s[i] == 'C'){
            for(int j = i + 1; j < len - 1; j++){// O
                if(s[j] == 'O'){
                    for(int k = j + 1; k < len; k++){// W
                        if(s[k] == 'W') cnt++;
                    }
                }
            }
        }
    }
}

int main() {
    // 입력
    cin >> len;
    cin >> s;

    // 실행
    FindCOW();

    // 출력
    cout << cnt;
    return 0;
}