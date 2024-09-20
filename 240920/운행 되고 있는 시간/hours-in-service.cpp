#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

int n, result = 0;
vector<pair<int, int>> work;

void GetMaxRunTime(){
    int time[1001] = {0};
    int t_time;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(j == i) continue;
            time[1001] = {0};
            for(int k = work[j].first; k < work[j].second; k++){
                time[k] = 1;
            }
            t_time = 0;
            for(int k = 1; k < 1001; k++){
                t_time += time[k];
            }
            result = max(result, t_time) - 1;
        }
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