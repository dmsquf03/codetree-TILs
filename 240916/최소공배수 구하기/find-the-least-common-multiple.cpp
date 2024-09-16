#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

void FindLCM(int n, int m){
    int lcm, cnt = 1;
    while(1){
        if(n * cnt % m == 0){
            lcm = n * cnt;
            break;
        }
        cnt++;
    }
    cout << lcm;
}

int main() {
    // 입력
    int n, m;
    cin >> n >> m;

    // 실행
    FindLCM(n, m);

    // 출력
    return 0;
}