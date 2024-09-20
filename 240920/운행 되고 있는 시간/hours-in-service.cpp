#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

int n, result = 0;
vector<pair<int, int>> work;

void GetMaxRunTime(){
    int time[1001];
    int small, large;
    for(int i = 0; i < n; i++){// 뺄 사람 인덱스
        small = 1001, large = 0;
        for(int j = 0; j < n; j++){
            if(j == i) continue;
            small = min(small, work[j].first);
            large = max(large, work[j].second);
        }
        result = max(result, large - small - 1);
    }
}

int main() {
    // 입력
    cin >> n;

    int a, b;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        work.emplace_back(a, b);
    }

    // 실행
    GetMaxRunTime();

    // 출력
    cout << result;

    return 0;
}