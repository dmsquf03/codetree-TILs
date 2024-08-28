#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstdlib>
using namespace std;

int n, min_v = INT_MAX;
vector<pair<int, int>> cp;

void FindMinDist(){
    int dist;
    for(int i = 1; i < n - 2; i++){ // 건너 뛸 체크 포인트
        dist = 0; // 초기화
        for(int j = 0; j < n - 1; j++){ // 택시 거리 구해서 dist에 더한다.
            if((j + 1) == i){ // 다음 포인트가 스킵일 때
                dist += abs(cp[j].first - cp[j + 2].first) + abs(cp[j].second - cp[j + 2].second);
                j++;
            }
            else{
                dist += abs(cp[j].first - cp[j + 1].first) + abs(cp[j].second - cp[j + 1].second);
            }
            // cout << "j: " << j << " dist: " << dist <<endl;
        }
        // 최솟값 업데이트
        min_v = min(min_v, dist);
    }
}

int main() {
    int x, y;

    // 입력
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> x >> y;
        pair<int, int> temp = make_pair(x, y);
        cp.push_back(temp);
    }

    // 실행
    FindMinDist();

    // 출력
    cout << min_v;

    return 0;
}