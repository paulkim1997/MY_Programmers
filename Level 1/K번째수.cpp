#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    //주어진 commands 개수 만큼 반복
    for(int i = 0 ; i < commands.size(); i++) {
        //commands에서 주어진 i부터 j까지 잘라서 담을 배열 temp
        vector<int> temp;

        //입력 배열 array를 commands의 첫번째 원소 부터, 두번째 원소까지 담는다
        for(int j = commands[i][0]-1; j < commands[i][1] ;j++) {
            temp.push_back(array[j]);
        }
        //정렬 하고, commands의 마지막 원소인 K번째 수를
        // array를 잘라서 담아놓은 temp에서 꺼낸다
        sort(temp.begin(), temp.end());
        answer.push_back(temp[commands[i][2]-1]);
    }
    return answer;
}