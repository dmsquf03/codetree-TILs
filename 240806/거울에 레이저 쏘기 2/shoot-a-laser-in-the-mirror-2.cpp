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
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1}; // 북 동 남 서
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
    num = (k - 1) / n;
    // 나눴을 떄 몫에 따라 4등분 설정, 거기서 0,2등분은 나머지가 열, 1,3등분은 나머지가 행
    switch(num){
        case 0:
        {
            x = 0;
            y = (k - 1) % n;
            dir = 2;
            break;
        }  
        case 1:
        {
            x = (k - 1) % n;
            y = n - 1;
            dir = 1;
            break;
        }
        case 2:
        {
            x = n - 1;
            y = (k - 1) % n;
            dir = 0;
            break;
        }
        case 3:
        {
            x = (k - 1) % n;
            y = 0;
            dir = 3;
            break;
        }
    }
    
    while(isInRange(x, y, n)){
        cnt++;
        if(arr[x][y] == 0){
            dir = (3 - dir);
        }
        else{
            dir ^= 1; // 이게 중요한 부분이다!!! 블로그에 작성하자. 2-3 서로 바꾸려면 ^1
        }
        x += dx[dir];
        y += dy[dir];
    }

    // 출력
    cout << cnt;

    return 0;
}