#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

void FindLCM(int n, int m){
    // 분해
    int lcm = 1, cn = n, cm = m;
    vector<int> a(100, 0);
    vector<int> b(100, 0);

    for(int i = 2; i < n; i++){
        if(cn % i == 0){
            a[i]++;
            cn /= i;
            i--;
        }
    }
    for(int i = 2; i < m; i++){
        if(cm % i == 0){
            b[i]++;
            cm /= i;
            i--;
        }
    }

    // lcm 구하기
    int c;
    for(int i = 2; i < 100; i++){
        if(a[i] == 0 && b[i] == 0) continue;
        c = pow(i, max(a[i], b[i]));
        lcm *= c;
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