#include <iostream>
#include <vector>
using namespace std;

const int MAX = 19;
int winner = 0, x = 0, y = 0;
vector<vector<int>> pan (MAX, vector<int>(MAX, 0));

void FindWinner(){
    int winx, winy, windl, windr;
    for(int i = 0; i < MAX; i++){ // 가운데 기준
        for(int j = 0; j < MAX; j++){
            winx = 0, winy = 0, windl = 0, windr = 0;
            
            // 세로 방향 (위/아래 2칸을 포함)
            if(i >= 2 && i < MAX - 2){ 
                winx = pan[i - 2][j] * pan[i - 1][j] * pan[i][j] * pan[i + 1][j] * pan[i + 2][j];
            }

            // 가로 방향 (왼쪽/오른쪽 2칸을 포함)
            if(j >= 2 && j < MAX - 2){ 
                winy = pan[i][j - 2] * pan[i][j - 1] * pan[i][j] * pan[i][j + 1] * pan[i][j + 2];
            }

            // 대각선 왼쪽 위에서 오른쪽 아래로 (상하좌우 2칸)
            if(i >= 2 && i < MAX - 2 && j >= 2 && j < MAX - 2){ 
                windl = pan[i - 2][j - 2] * pan[i - 1][j - 1] * pan[i][j] * pan[i + 1][j + 1] * pan[i + 2][j + 2];
                windr = pan[i - 2][j + 2] * pan[i - 1][j + 1] * pan[i][j] * pan[i + 1][j - 1] * pan[i + 2][j - 2];
            }
            
            if(winx == 1 || winy == 1 || windl == 1 || windr == 1){
                winner = 1;
                x = i;
                y = j;
            }
            else if(winx == 32 || winy == 32 || windl == 32 || windr == 32){
                winner = 2;
                x = i;
                y = j;
            }
        }
    }
}

int main() {
    // 입력
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            cin >> pan[i][j];
        }
    }

    // 실행
    FindWinner();

    // 출력
    cout << winner << endl;
    if(winner){
        cout << x + 1 << " " << y + 1;
    }
    
    return 0;
}