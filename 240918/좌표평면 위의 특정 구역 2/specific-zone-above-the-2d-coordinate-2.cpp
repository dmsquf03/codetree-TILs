#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <climits>
using namespace std;

int n, result = INT_MAX;
vector<pair<int, int>> point;

void FindMinRect(){
    int max_x, max_y, min_x, min_y, area;
    for(int i = 0; i < n; i++){// 제외할 점
        max_x = 0, max_y = 0, min_x = 40000, min_y = 40000;
        for(int j = 0; j < n; j++){// 최대 최소 점 구하기
            if(j == i) continue;
            max_x = max(max_x, point[j].first);
            min_x = min(min_x, point[j].first);
            max_y = max(max_y, point[j].second);
            min_y = min(min_y, point[j].second);
        }
        area = (max_x - min_x) * (max_y - min_y);
        // cout << "max min x:" << max_x << " " << min_x << " max min y:" << max_y << " " << min_y << endl;
        result = min(result, area);
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
    FindMinRect();

    // 출력
    cout << result;
    return 0;
}