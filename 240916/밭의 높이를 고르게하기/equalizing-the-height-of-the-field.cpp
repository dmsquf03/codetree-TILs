#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <climits>
using namespace std;

int n, t, h, result = INT_MAX;
vector<int> field;

void FindMinCost(){
    int cost;
    for(int i = 0; i < n - t + 1; i++){// 시작 인덱스
        cost = 0;
        for(int k = 0; k < t; k++){// 구간 내 비용 계산
            cost += abs(h - field[i + k]);
        }
        result = min(result, cost);
    }
}

int main() {
    // 입력
    cin >> n >> t >> h;

    field = vector<int> (n, 0);

    for(int i = 0; i < n; i++){
        cin >> field[i];
    }

    // 실행
    FindMinCost();

    // 출력
    cout << result;

    return 0;
}