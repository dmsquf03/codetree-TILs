#include <iostream>
#include <vector>
using namespace std;

int winner = 0, x = 0, y = 0;
vector<vector<int>> pan(19, vector<int>(19, 0));

void FindWinner(){
    int winx, winy, windl, windr;
    for(int i = 2; i < 17; i++){ // 가운데 기준
        for(int j = 2; j < 17; j++){
            winx = pan[i - 2][j] * pan[i - 1][j] * pan[i][j] * pan[i + 1][j] * pan[i + 2][j];
            winy = pan[i][j - 2] * pan[i][j - 1] * pan[i][j] * pan[i][j + 1] * pan[i][j + 2];
            windl = pan[i - 2][j - 2] * pan[i - 1][j - 1] * pan[i][j] * pan[i + 1][j + 1] * pan[i + 2][j + 2];
            windr = pan[i - 2][j + 2] * pan[i - 1][j + 1] * pan[i][j] * pan[i + 1][j - 1] * pan[i + 2][j - 2];
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
    for(int i = 0; i < 19; i++){
        for(int j = 0; j < 19; j++){
            cin >> pan[i][j];
        }
    }

    // 실행
    FindWinner();

    // 출력
    cout << winner << endl;
    cout << x + 1 << " " << y + 1;
    return 0;
}