#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

int n, result = 0;
vector<pair<int, int>> line;

void CountNoOverlapLine(){
    for(int i = 0; i < n; i++){
        bool flag = true;
        for(int j = 0; j < n; j++){
            if(j == i) continue;
            if((line[i].first > line[j].first && line[i].second < line[j].second) || (line[i].first < line[j].first && line[i].second > line[j].second)) flag = false;
        }
        if(flag) result++;
    }
}

int main() {
    // 입력
    cin >> n;

    int x1, x2;
    for(int i = 0; i < n; i++){
        cin >> x1 >> x2;
        line.emplace_back(x1, x2);
    }

    // 실행
    CountNoOverlapLine();

    // 출력
    cout << result;
    return 0; 
}