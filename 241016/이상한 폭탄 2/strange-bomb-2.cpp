#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K, result = -1;
vector<int> list;

void FindMaxExplodeBombNum(){
    for(int i = 0; i < N; i++){
        for(int j = i + 1; j < N; j++){
            if(list[i] == list[j] && j - i <= K){ // 두 폭탄의 번호가 같고, 서로 K 거리 안에 존재 -> 터짐
                // 더 큰 폭탄 번호로 업데이트
                result = max(result, list[i]);
            }
        }
    }
}

int main() {
    cin >> N >> K;

    list = vector<int> (N);

    for(int i = 0; i < N; i++){
        cin >> list[i];
    }

    FindMaxExplodeBombNum();

    cout << result;
    return 0;
}