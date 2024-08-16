#include <iostream>
#include <vector>
using namespace std;

int n, m;
int dr[4] = {0, 1, 0, -1}, dc[4] = {1, 0, -1, 0}; // 동 남 서 북
vector<vector<int>> map;

bool InRange(int r, int c){
    return (-1 < r && r < n && -1 < c && c < m);
}

void FillRect(){
    int r = 0, c = 0, fill = static_cast<int>('A'), cnt = 1, dir = 0;

    while(cnt < n * m + 1){
        map[r][c] = fill;

        // 디버깅용 출력
        // cout << "r: " << r << ", c: " << c << ", dir: " << dir << ", next: " << map[r + dr[dir]][c + dr[dir]] << ", fill: " << static_cast<char>(fill) << endl;

        if(!InRange(r + dr[dir], c + dc[dir]) || map[r + dr[dir]][c + dc[dir]] != 0){
            dir = (dir + 1) % 4;
        }

        r += dr[dir];
        c += dc[dir];

        if(fill == static_cast<int>('Z')){
            fill = static_cast<int>('A');
        }
        else fill++;
        cnt ++;
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    // 입력
    cin >> n >> m;
    map = vector<vector<int>> (n, vector<int>(m, 0));

    // 실행
    FillRect();

    // 출력
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << static_cast<char>(map[i][j])<< " ";
        }
        cout << endl;
    }
    return 0;
}