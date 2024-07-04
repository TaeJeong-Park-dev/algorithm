#include <bits/stdc++.h>
using namespace std;

int main(){
    int fee[3];
    for(int i = 0; i < 3; i++) {
        int tmp;
        cin >> tmp;
        fee[i] = tmp * (i + 1);
    }


    int first_car[2], second_car[2], third_car[2];
    for(int i = 0; i < 2;  i++) cin >> first_car[i];
    for(int i = 0; i < 2;  i++) cin >> second_car[i];
    for(int i = 0; i < 2;  i++) cin >> third_car[i];

    int s = min(first_car[0], min(second_car[0], third_car[0]));
    int e = max(first_car[1], max(second_car[1], third_car[1]));

    vector<int> cnt(e - s + 1, 0);

    for(int i = s; i <= e; i++){
        if(i >= first_car[0] && i < first_car[1]) cnt[i - s]++;

        if(i >= second_car[0] && i < second_car[1]) cnt[i - s]++;

        if(i >= third_car[0] && i < third_car[1]) cnt[i - s]++;
    }
    int result = 0;

    for(int i : cnt){
        if(i >= 1 && i <= 3){
            result += fee[i - 1];
        }
    }

    cout << result;
    return 0;
}