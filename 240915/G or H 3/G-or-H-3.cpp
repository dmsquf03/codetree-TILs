#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k, result = 0, size = 0;
vector<char> line;

void FindMaxPoint(){
    int point;
    for(int i = 0; i < size - k + 1; i++){// 사진 기준
        point = 0;
        for(int j = 0; j < k + 1; j++){// 점수 합
            if(line[i + j] == '0') continue;
            else if(line[i + j] == 'G') point++;
            else if(line[i + j] == 'H') point += 2;
        }
        // cout << "i: " << i << " point: " << point << " result: " << result << endl;
        result = max(result, point);
    }
}

int main() {
    // 입력
    cin >> n >> k;

    line = vector<char>(10000, '0');

    int idx;
    for(int i = 0; i < n; i++){
        cin >> idx;
        cin >> line[idx - 1];
        size = max(size, idx);
    }

    line.resize(size);

    // 실행
    FindMaxPoint();

    // 출력
    cout << result;
    return 0;
}