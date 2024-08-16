#include <iostream>
#include <vector>
using namespace std;

int n;
int dr[4] = {0, -1, 0, 1}, dc[4] = {1, 0, -1, 0}; // 동 북 서 남
vector<vector<int>> map;

bool InRange(int r, int c){
    return (-1 < r && r < n && -1 < c && c < n);
}

void FillRect(){
    int r = n/2, c = n/2, cnt = 1, dir = 0;

    while(cnt < n * n + 1){
        map[r][c] = cnt++;

        if(!InRange(r + dr[dir], c + dc[dir]) || map[r + dr[dir]][c + dc[dir]] != 0){
            dir = (dir + 1) % 4;
        }
        r += dr[dir];
        c += dc[dir];
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    // 입력
    cin >> n;
    map = vector<vector<int>> (n, vector<int>(n, 0));

    // 실행
    FillRect();

    // 출력
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}