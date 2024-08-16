#include <iostream>
#include <vector>
using namespace std;

int n, m;
int dr[4] = {1, 0, -1, 0}, dc[4] = {0, 1, 0, -1}; // 남, 동, 북, 서
vector<vector<int>> map(100, vector<int>(100, 0));

bool InRange(int r, int c){
    return (-1 < r && r < n && -1 < c && c < m);
}

void FillRect(){
    int cnt = 1, r = 0, c = 0, dir = 0;
    
    while(cnt < n * m + 1){
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
    cin >> n >> m;

    // 실행
    FillRect();

    // 출력
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}