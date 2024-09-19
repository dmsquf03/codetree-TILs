#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;

int n, result = INT_MAX;
vector<pair<int, int>> point;

int GetDistance(int i, int j){
    return (point[i].first - point[j].first) * (point[i].first - point[j].first) + (point[i].second - point[j].second) * (point[i].second - point[j].second);
}

void FindClosestPointsDistance(){
    int distance;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            distance = GetDistance(i, j);
            result = min(distance, result);
        }
    }
}

int main() {
    // 입력
    cin >> n;

    int x, y;
    for(int i = 0; i < n; i++){
        cin >> x >> y;
        point.emplace_back(x, y);
    }

    // 실행
    FindClosestPointsDistance();

    // 출력
    cout << result;
    return 0;
}