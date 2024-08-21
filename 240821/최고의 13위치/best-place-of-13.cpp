#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, max_v = 0;
vector<vector<int>> arr;

void findMaxCoin(){
    int cnt;
    for(int i = 0; i < n - 2; i++){
        for(int j = 0; j < n; j++){
            cnt = arr[i][j] + arr[i][j + 1] + arr[i][j + 2];
            max_v = max(max_v, cnt);
            cout << max_v <<endl;
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    // 입력
    cin >> n;
    arr = vector<vector<int>> (n, vector<int>(n, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }

    // 실행
    findMaxCoin();

    // 출력
    cout << max_v;
    return 0;
}