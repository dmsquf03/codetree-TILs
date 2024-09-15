#include <iostream>
#include <vector>
using namespace std;

int n, m, result = 0;
vector<int> a, b;

void CountBSeq(){
    vector<int> seq;
    int flag;
    for(int i = 0; i < n; i++){// 구간 시작 인덱스
        for(int j = i; j < n; j++){// 구간 끝 인덱스
            flag = 1;
            seq = vector<int> (100, 0);// 초기화
            for(int k = i; k < j + 1; k++){
                seq[a[k]]++;
            }
            for(int k = 0; k < 100; k++){
                if(seq[k] != b[k]){
                    flag = 0;
                    break;
                }
            }
            if(flag) result++;
        }
    }
}

int main() {
    // 입력
    cin >> n >> m;

    a = vector<int> (n);
    b = vector<int> (100, 0);

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    int temp;
    for(int i = 0; i < m; i++){
        cin >> temp;
        b[temp]++;
    }

    // 실행
    CountBSeq();

    // 출력
    cout << result;

    return 0;
}