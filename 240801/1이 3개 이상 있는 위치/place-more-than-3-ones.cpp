#include <iostream>
using namespace std;

bool InRange(int x, int y, int n){
    return (x > -1) && (x < n) && (y > -1) && (y < n);
}

int main() {
    // 여기에 코드를 작성해주세요.
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, nx, ny, cnt = 0, result = 0;
    int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};

    // 입력 
    cin >> n;

    int arr[n][n];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }

    // 실행
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cnt = 0;
            for(int dir = 0; dir < 4; dir++){
                nx = i + dx[dir];
                ny = j + dy[dir];
                if(InRange(nx, ny, n) && arr[nx][ny]){
                    cnt++;
                }
            }
            if(cnt > 2){
                result++;
            }
        }
    }

    // 출력
    cout << result;

    return 0;
}