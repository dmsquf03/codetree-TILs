#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n, t, sum = 0;
int dr[4] = {-1, 0, 1, 0}, dc[4] = {0, 1, 0, -1}; // 북 동 남 서 R: +1, L: -1
string dirs;
vector<vector<int>> map;

bool InRange(int r, int c){
    return (-1 < r && r < n && -1 < c && c < n);
}

void Move(){
    int r = n / 2, c = n / 2, d = 0;

    for(int i = 0; i < static_cast<int>(dirs.size()); i++){
        char dir = dirs[i];

        if(dir == 'L') {
            d = (d + 3) % 4;
        }
        else if(dir == 'R') {
            d = (d + 1) % 4;
        }
        else{
            if(InRange(r + dr[d], c + dc[d])){
                sum += map[r][c];
                // cout << i <<": "<< sum << endl;
                r += dr[d];
                c += dc[d];
            }
        }
    }
    sum += map[r][c];

}


int main() {
    // 여기에 코드를 작성해주세요.
    // 입력
    cin >> n >> t;
    cin >> dirs;
    map = vector<vector<int>>(n, vector<int>(n, 0));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> map[i][j];
        }
    }

    // 실행
    Move();

    // 출력
    cout << sum;
    return 0;
}