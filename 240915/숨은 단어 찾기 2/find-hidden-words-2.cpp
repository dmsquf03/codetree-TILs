#include <iostream>
#include <vector>
using namespace std;

int n, m, result = 0;
vector<vector<char>> pan;
int dr[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, dc[8] = {0, 1, 1, 1, 0, -1, -1, -1}; // 북부터 시계방향

bool IsInRange(int r, int c){
    return (-1 < r && r < n && -1 < c && c < m);
}

void CountLEE(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(pan[i][j] != 'L') continue;
            for(int dir = 0; dir < 8; dir++){
                if(IsInRange(i + dr[dir], j + dc[dir]) && IsInRange(i + 2 * dr[dir], j + 2 * dc[dir]) && pan[i + dr[dir]][j + dc[dir]] == 'E' && pan[i + 2 * dr[dir]][j + 2 * dc[dir]] == 'E'){// 범위 초과 X, 둘 다 E
                    result++;
                }
            }
        }
    }
}

int main() {
    // 입력
    cin >> n >> m;

    pan = vector<vector<char>> (n, vector<char>(m));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> pan[i][j];
        }
    }

    // 실행
    CountLEE();

    // 출력
    cout << result;
    return 0;
}