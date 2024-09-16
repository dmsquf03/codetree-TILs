#include <iostream>
using namespace std;

int n, a1, b1, c1, a2, b2, c2, result = 0;

bool IsIn2(int x, int y){
    return (abs(x - y) < 3 || (abs(x - y) > n - 3 && abs(x - y) < n));
}

void CountDiffComb(){
    for(int i = 1; i < n + 1; i++){
        for(int j = 1; j < n + 1; j++){
            for(int k = 1; k < n + 1; k++){
                if(IsIn2(i, a1) && IsIn2(j, b1) && IsIn2(k, c1) || IsIn2(i, a2) && IsIn2(j, b2) && IsIn2(k, c2)) result++;
            }
        }
    }
}

int main() {
    // 입력
    cin >> n;
    cin >> a1 >> b1 >> c1;
    cin >> a2 >> b2 >> c2;

    // 실행
    CountDiffComb();

    // 출력
    cout << result;
    return 0;
}