#include <iostream>
#include <vector>
using namespace std;

int r, c, result = 0;
vector<vector<char>> pan;

void Find4MoveAbleCnt(){
    for(int i = 1; i < r - 2; i++){
        for(int j = 1; j < c - 2; j++){
            if(pan[0][0] == pan[i][j]){
                continue;
            }
            for(int k = i + 1; k < r - 1; k++){
                for(int l = j + 1; l < c - 1; l++){
                    if(pan[i][j] != pan[k][l] && pan[k][l] != pan[r - 1][c - 1]){
                        result++;
                    }
                }
            }
        }
    }
}

int main() {
    // 입력
    cin >> r >> c;

    pan = vector<vector<char>> (r, vector<char>(c));

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> pan[i][j];
        }
    }

    // 실행
    Find4MoveAbleCnt();

    // 출력
    cout << result;

    return 0;
}