#include <iostream>
#include <vector>
using namespace std;

int n, cnt = 0;
vector<int> cow;

void CntCouple(){
    for(int i = 0; i < n; i++){ // i보다 크고
        for(int k = i + 2; k < n; k++){ // k보다 작은
            for(int j = i + 1; j < k; j++){ // j
                if(cow[i] <= cow[j] && cow[j] <= cow[k]) cnt++; // ai<= aj <= ak 쌍의 수
            }
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    // 입력
    cin >> n;
    cow = vector<int> (n);
    for(int i = 0; i < n; i++){
        cin >> cow[i];
    }

    // 실행
    CntCouple();

    // 출력
    cout << cnt;

    return 0;
}