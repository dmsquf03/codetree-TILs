#include <iostream>
#include <vector>
using namespace std;

bool InRange(int r, int c, int n, int m){
    return (-1 < r && r < n && -1 < c && c < m);
}

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m, cnt = 1, dir = 0, r = 0, c = 0;
    int dr[4] = {0, 1, 0, -1}, dc[4] = {1, 0, -1, 0}; // 우-하-좌-상

    // 입력
    cin >> n >> m;

    vector<vector<int>> arr(n, vector<int>(m, 0));
    vector<vector<int>> empty(n, vector<int>(m, 1));

    // 실행
    // 얼마나 반복하는가? n*m 까지 채운다.
    while(cnt < n * m + 1){
        arr[r][c] = cnt;
        empty[r][c] = 0;
        if(!InRange(r + dr[dir], c + dc[dir], n, m) || !empty[r + dr[dir]][c + dc[dir]]){// 범위 + 채워진 경우-> 방향 바꿈!!! 이거 수정해야함
            dir = (dir + 1) % 4;
        }
        r += dr[dir];
        c += dc[dir];
        cnt++;
    }
    


    // 출력
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}