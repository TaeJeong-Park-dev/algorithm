#include <bits/stdc++.h>
using namespace std;

string in_str;
string compare_str;
map<char, int> cnt;
string result = "";
string center = "";

int main(){
    cin >> in_str;
    compare_str = in_str.substr();

    if(compare_str.size() % 2 == 0){// 짝수
        for(auto c : compare_str){
            if(cnt.find(c) == cnt.end()){
                cnt[c] = 1;
            }
            else{
                cnt[c]++;
            }
        }
        for(auto i : cnt){ // 팰린드롬이 짝수개로 구성되어있어서 데칼코마니가 되려면 서로 짝수개를 갖고 있어야 한다.
            if(i.second % 2 == 1) {
                cout << "I'm Sorry Hansoo";
                exit(0);
            }
            else{
                cnt[i.first] = i.second / 2; // 일단 반으로 나눠놓은 것이다.
            }
        }
        
        for(auto i : cnt){
            for(int j = 0; j < i.second; j++){
                result += i.first;
            }
        }
    }
    else{ // 홀수
        bool flag = false;
        for(auto c : compare_str){
            if(cnt.find(c) == cnt.end()){
                cnt[c] = 1;
            }
            else{
                cnt[c]++;
            }
        }
        for(auto i : cnt){ 
            if(i.second % 2 == 1) {
                if(flag){ // 홀수개인 요소는 하나여야만 한다.
                    cout << "I'm Sorry Hansoo";
                    exit(0);
                }
                if(flag == false){
                    flag = true;
                    center += i.first;
                    cnt[i.first]--; // 가운데에 배치할 한개를 제외하는 코드. 이렇게 되면 1개일 때는 0개가 되고, 3개이상일 때는 짝수개가 된다.
                    cnt[i.first] /= 2;
                }
            }
            else{
                cnt[i.first] = i.second / 2; // 일단 반으로 나눠놓은 것이다.
            }
        }
        for(auto i : cnt){
            for(int j = 0; j < i.second; j++){
                result += i.first;
            }
        }
    }
    string re_result;
    re_result = result.substr();
    reverse(re_result.begin(), re_result.end());

    if(compare_str.size() % 2 != 0) result += center;
    result += re_result;

    cout << result;

    return 0;
}