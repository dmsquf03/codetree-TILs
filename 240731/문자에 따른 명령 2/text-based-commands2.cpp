#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
    int dir = 0, x = 0, y = 0;
    char change;

    // 입력 및 실행
    while(cin >> change){
        if(change == 'L'){
            dir = (dir + 3) % 4;
        }
        else if(change == 'R'){
            dir = (dir + 1) % 4;
        }
        else{
            x += dx[dir];
            y += dy[dir];
        }
    } 

    // 출력
    cout << x << " " << y;

    return 0;
}