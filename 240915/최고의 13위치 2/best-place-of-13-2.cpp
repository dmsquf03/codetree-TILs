#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, result = 0;
vector<vector<int>> pan;

void FindMaxCoin(){
    int cnt = 0;
    for(int i = 0; i < n; i++){// 첫번째 격자 행
        for(int j = 0; j < n - 2; j++){// 첫번째 격자 열
            for(int k = i + 1; k < n; k++){// 두번째 격자 행
                for(int l = 0; l < n - 2; l++){// 두번째 격자 열
                    cnt = pan[i][j] + pan[i][j + 1] + pan[i][j + 2] + pan[k][l] + pan[k][l + 1] + pan[k][l + 2];
                    result = max(result, cnt);
                }
            }
        }
    }
}

int main() {
    // 입력
    cin >> n;
    pan = vector<vector<int>> (n, vector<int>(n));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> pan[i][j];
        }
    }

    // 실행
    FindMaxCoin();

    // 출력
    cout << result;
    return 0;
}