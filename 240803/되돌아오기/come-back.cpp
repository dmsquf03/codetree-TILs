#include <iostream>
using namespace std;

int GetDir(char c){
    if(c == 'W') return 0;
    else if(c == 'S') return 1;
    else if(c == 'N') return 2;
    else return 3;
}

bool IsStart(int x, int y){
    return (x == 0 && y == 0);
}

int main() {
    // 여기에 코드를 작성해주세요.
    int n, x = 0, y = 0, dir, move, t = 0;
    int dx[4] = {-1, 0, 0, 1}, dy[4] = {0, -1, 1, 0}; // w s n e
    char c;

    // 입력
    cin >> n;

    // 실행
    while(n--){
        cin >> c >> move;
        dir = GetDir(c);
        while(move--){
            t++;
            x += dx[dir];
            y += dy[dir];

            if(IsStart(x, y)){
                cout << t;
                exit(0);
            }
        }
    }
    
    t = -1;

    // 출력
    cout << t;

    return 0;
}