#include <iostream>
#include <string>
using namespace std;

bool IsStart(int x, int y, int t){
    return (x == 0 && y == 0 && t != 0);
}

int main() {
    // 여기에 코드를 작성해주세요.
    int x = 0, y = 0, t = 0, dir = 0, flag = 0;
    string move;
    int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0}; // 북, 동, 남, 서 R이 +

    // 입력
    cin >> move;

    // 실행
    for(char c: move){
     
        t++;
        if(c == 'L'){dir = (dir + 3) % 4;}
        else if (c == 'R'){dir = (dir + 1) % 4;}
        else {
            x += dx[dir];
            y += dy[dir];
        }
        // cout << "t:" << t << " x:" << x << " y:" << y << endl;
        if(IsStart(x, y, t)) {
            flag = 1;
            break;
        }
    }

    if(flag == 0) {t = -1;}

    // 출력
    cout << t;

    return 0;
}