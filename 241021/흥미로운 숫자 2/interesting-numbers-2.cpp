#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

int X, Y, result = 0;

void CountInterestingNum(){
    string str;
    for(int i = X; i < Y + 1; i++){
        str = to_string(i);
        bool flag = true;
        vector<pair<int, int>> arr;
        arr.emplace_back(str[0], 1);
        for(int j = 1; j < str.length(); j++){
            if(str[j] != arr[0].first){
                if(arr.size() == 1){
                    arr.emplace_back(str[j], 1);
                }
                else if(str[j] == arr[1].first){
                    arr[1].second++;
                }
                else {
                    flag = false;
                    break;
                }
            }
            else{
                arr[0].second++;
            }
        }
        if(!flag || arr.size() != 2 || arr[0].second > 1 && arr[1].second > 1) continue;
        result++;
    }
}

int main() {
    cin >> X >> Y;

    CountInterestingNum();

    cout << result;
    return 0;
}