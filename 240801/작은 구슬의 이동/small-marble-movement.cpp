#include <iostream>
using namespace std;

int GetDirect(char c){
    if(c == 'U') return 0;
    else if(c == 'D') return 3;
    else if(c == 'R') return 1;
    else return 2;
}

bool InRange(int x, int y, int n){
    return (-1 < x && x < n && -1 < y && y < n);
}

int main() {
    // 여기에 코드를 작성해주세요.
    int n, t, r, c, d, dir, nr, nc;
    int dx[4] = {0, 1, -1, 0}, dy[4] = {1, 0, 0, -1};

    // 입력
    cin >> n >> t >> r >> c >> d;

    // 실행
    dir = GetDirect(d);

    while(t--){
        if(!InRange(r + dx[dir], c + dy[dir], n)){
            dir = 3 - dir;
        }
        else{
            nr = r + dx[dir];
            nc = c + dy[dir];
        }
    }

    // 출력
    cout << nr + 1 << " " << nc + 1;

    return 0;
}