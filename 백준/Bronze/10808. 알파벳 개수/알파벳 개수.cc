#include <bits/stdc++.h>
using namespace std;

int main(){
    // a = 97, z = 122
    map<char, int> result;
    for(int i = 97; i <= 122; i++){
        char temp = i;
        result[temp] = 0;
    }

    string input;
    cin >> input;

    for(char c : input) result[c]++;

    for(int i = 97; i <= 122; i++){
        char temp = i;
        cout << result[temp] << ' ';
    }
}