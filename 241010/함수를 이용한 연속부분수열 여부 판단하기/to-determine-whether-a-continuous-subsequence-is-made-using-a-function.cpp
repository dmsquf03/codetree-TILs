#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n1, n2;
vector<int> A, B;
string result;

void IsConsecutiveSubSequence(){
    bool flag = false;
    int bIdx = 0;
    for(int i = 0; i < n1; i++){
        // A 랑 B 같음 -> A 랑 B 둘다 다음 인덱스 검사
        if(A[i] == B[bIdx]) {
            if(bIdx == n2 - 1) {// B 끝까지 같음
                flag = true;
            }
            bIdx++;
            
        }
        // 안 같음 -> A 다음 인덱스, B 인덱스 초기화
        else{
            bIdx = 0;
        }
    }
    if(flag) result = "Yes";
    else result = "No";
}

int main() {
    cin >> n1 >> n2;

    int num;
    for(int i = 0; i < n1; i++){
        cin >> num;
        A.emplace_back(num);
    }
    for(int i = 0; i < n2; i++){
        cin >> num;
        B.emplace_back(num);
    }

    IsConsecutiveSubSequence();

    cout << result;

    return 0;
}