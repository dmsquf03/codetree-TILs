#include <iostream>
#include <vector>
using namespace std;

bool isInRange(int x, int y, int n){ // 튕긴게 나가면 끝
    return (-1 < x && x < n && -1 < y && y < n);
}

int main() {
    // 여기에 코드를 작성해주세요.
    int n, k, x, y, num, cnt = 0, dir;
    char c;
    int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1}; // 북 남 서 동

    // 입력
    cin >> n;
 
    // 실행
    vector<vector<int>> arr(n, vector<int>(n, 0)); // 0: \ (남-동, 북-서), 1: / (남-서, 북-동)

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> c;
            if(c == '/'){
                arr[i][j] = 1;
            }
        }
    }

    cin >> k;
    
    // k 범위에 따른 방향, 시작 위치 설정
    if(0 < k && k < n + 1){
        x = 0;
        y = k - 1;
        dir = 1;
    }  
    else if(n < k && k < 2 * n + 1){
        x = k - n - 1;
        y = n - 1;
        dir = 2;
    }
    else if(2 * n < k && k < 3 * n + 1){
        x = n - 1;
        y = 3 * n - k;
        dir = 0;
    }
    else{
        x = 4 * n - k;
        y = 0;
        dir = 3;
    }
    
    // 거울 속 진행(튕기면 방향 전환)
    while(isInRange(x, y, n)){
        if(arr[x][y] == 0){
            dir = (dir + 2) % 4; // 0 - 2, 1 - 3
        }
        else{
            dir = (3 - dir); // 0 - 3, 1 - 2
        }
        cnt++;
        x += dx[dir];
        y += dy[dir];
    }

    // 출력
    cout << cnt;

    return 0;
}