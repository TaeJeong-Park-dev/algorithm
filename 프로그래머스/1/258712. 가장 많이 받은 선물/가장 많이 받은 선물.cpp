#include <bits/stdc++.h>
using namespace std;

vector<string> split(string input, string delimiter)
{
    string tk;
    long long pos;
    vector<string> answer;

    while ((pos = input.find(delimiter)) != string ::npos)
    {
        tk = input.substr(0, pos);
        input.erase(0, pos + delimiter.length());
        answer.push_back(tk);
    }
    answer.push_back(input);

    return answer;
}

int solution(vector<string> friends, vector<string> gifts)
{
    int answer = 0;
    vector<vector<string>> split_gift;
    for (auto gift : gifts)
    {
        vector<string> temp = split(gift, " ");
        split_gift.push_back(temp);
    }

    vector<int> gift_idx(friends.size(), 0);
    for (auto gift : split_gift)
    {
        string give = gift[0];
        string receive = gift[1];
        auto it = find(friends.begin(), friends.end(), give);
        auto jt = find(friends.begin(), friends.end(), receive);

        if (it != friends.end())
        {
            int idx = distance(friends.begin(), it);
            gift_idx[idx]++;
        }
        if (jt != friends.end())
        {
            int idx = distance(friends.begin(), jt);
            gift_idx[idx]--;
        }
    }
    /*
        이 선물지수는 두 사람사이에 선물교환 여부가 없거나 교환 수가 같은 경우 참고.
    */
    map<string, map<string, int>> interaction;

    for (auto friendName : friends)
    {
        for (auto gift : split_gift)
        {
            interaction[friendName][gift[1]];
            if (friendName == gift[0])
            { // 만약에 내가 준 사람이라면
                interaction[friendName][gift[1]]++;
            }
        }
    }
    map<string, int> answer_arr;
    for (int i = 0; i < interaction.size(); i++)
    {
        for (int j = i + 1; j < interaction.size(); j++)
        {
            if (interaction[friends[i]][friends[j]] > interaction[friends[j]][friends[i]])
            {
                answer_arr[friends[i]]++;
            }

            else if (interaction[friends[i]][friends[j]] < interaction[friends[j]][friends[i]])
            {
                answer_arr[friends[j]]++;
            }

            else
            {
                auto it = find(friends.begin(), friends.end(), friends[i]);
                auto jt = find(friends.begin(), friends.end(), friends[j]);
                int it_idx;
                int jt_idx;
                if (it != friends.end())
                {
                    it_idx = distance(friends.begin(), it);
                }
                if (jt != friends.end())
                {
                    jt_idx = distance(friends.begin(), jt);
                }

                if(gift_idx[it_idx] > gift_idx[jt_idx]){
                    answer_arr[friends[i]]++;
                }
                else if(gift_idx[it_idx] < gift_idx[jt_idx]){
                    answer_arr[friends[j]]++;
                }


            }
        }
    }

    for(auto it : answer_arr){
        if(answer < it.second){
            answer=it.second;
        }
    }

    return answer;
}