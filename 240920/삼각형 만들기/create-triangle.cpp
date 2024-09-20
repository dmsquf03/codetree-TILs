#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <tuple>
#include <cstdlib>
using namespace std;

int n;
int result = 0;
vector<pair<int, int>> point;

void GetMaxAreaDouble(){
    int area;
    for(int i = 0; i < n; i++){// 1번째
        for(int j = 0; j < n; j++){// 2번째
            if(j == i) continue;
            for(int k = 0; k < n; k++){// 3번째 (1번과 x좌표 == 2번과 y좌표 ==)
                if(k == i || k == j) continue;
                if(point[k].first != point[i].first || point[k].second != point[j].second) continue;
                area = abs(point[k].second - point[i].second) * abs(point[k].first - point[j].first);
                result = max(result, area);
            }
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
    GetMaxAreaDouble();

    // 출력
    cout << result;
    return 0;
}