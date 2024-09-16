#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <climits>
using namespace std;

int result = INT_MAX;
vector<int> ability (6, 0);

void FinMinDiff(){
    int a, b, sum = 0, diff;
    for(int i = 0; i < 6; i++){
        sum += ability[i];
    }
    for(int i = 0; i < 4; i++){
        for(int j = i + 1; j < 5; j++){
            for(int k = j + 1; k < 6; k++){
                a = ability[i] + ability[j] + ability[k];
                b = sum - a;
                diff = abs(a - b);
                result = min(result, diff);
            }
        }
    }
}

int main() {
    // 입력
    for(int i = 0; i < 6; i++){
        cin >> ability[i];
    }

    // 실행
    FinMinDiff();

    // 출력
    cout << result;
    return 0;
}