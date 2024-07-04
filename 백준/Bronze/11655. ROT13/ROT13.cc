#include <bits/stdc++.h>
using namespace std;

int encoder = 13;
string encoding = "";
string input;

int main(){
    getline(cin, input);
    for(int i = 0; i <= input.size(); i++){
        if(input[i]>= 65 && input[i] <=90){
            if(input[i] + 13 > 90) input[i] = input[i] + 13 - 26;
            else input[i] = input[i] + 13;
        }
        else if(input[i]>=97 && input[i]<=122){
            if(input[i] + 13 > 122) input[i] = input[i] + 13 -26;
            else input[i] = input[i] + 13;
        }
    }
    
    cout << input << '\n';

    return 0;
}