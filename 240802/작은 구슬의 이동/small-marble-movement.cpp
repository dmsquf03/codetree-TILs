#include <iostream>
using namespace std;

int GetDirect(char c){
    if(c == 'U') return 2;
    else if(c == 'D') return 1;
    else if(c == 'R') return 0;
    else return 3;
}

bool InRange(int x, int y, int n){
    return (-1 < x && x < n && -1 < y && y < n);
}

int main() {
    // 여기에 코드를 작성해주세요.
    int n, t, r, c, dir;
    char d;
    int dr[4] = {0, 1, -1, 0}, dc[4] = {1, 0, 0, -1};

    // 입력
    cin >> n >> t >> r >> c >> d;

    // 실행
    dir = GetDirect(d);

    r -= 1;
    c -= 1;

    while(t--){
        if(!InRange(r + dr[dir], c + dc[dir], n)){
            dir = 3 - dir;
        }
        else{
            r += dr[dir];
            c += dc[dir];
        }
    }

    // 출력
    cout << r + 1 << " " << c + 1;

    return 0;
}