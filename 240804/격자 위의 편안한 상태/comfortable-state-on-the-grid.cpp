#include <iostream>
#include <vector>
using namespace std;

bool InRange(int x, int y, int n){
    return (-1 < x && x < n && -1 < y && y < n);
}

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m, r, c, cnt = 0;
    int dr[4] = {-1, 0, 0, 1}, dc[4] = {0, 1, -1, 0}; // 북 동 서 남 , 행 열

    // 입력
    cin >> n >> m;

    // 실행
    vector<vector<int>> arr(n, vector<int>(n, 0));

    while(m--){
        cin >> r >> c;
        arr[r - 1][c - 1] = 1;

        cnt = 0;
        for(int i = 0; i < 4; i++){
            if(InRange(r - 1+ dr[i], c - 1 + dc[i], n)){
                cnt += arr[r - 1 + dr[i]][c - 1 + dc[i]];
            }
        }
        if(cnt == 3){
            cout << "1" << endl;
        }
        else cout << "0" << endl;
    }

    return 0;
}