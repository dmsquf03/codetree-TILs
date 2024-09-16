#include <iostream>
#include <cstdlib>
using namespace std;

int n, a, b, c, result = 0;

void CountDiff(){
    int cnt = 0;
    for(int i = 1; i < n + 1; i++){
        for(int j = 1; j < n + 1; j++){
            for(int k = 1; k < n + 1; k++){
                if(abs(i - a) > 2 && abs(j - b) > 2 && abs(k - c) > 2) cnt++;
            }
        }
    }
    result = n * n * n - cnt;
}

int main() {
    // 입력
    cin >> n >> a >> b >> c;

    // 실행
    CountDiff();

    // 출력
    cout << result;
    return 0;
}