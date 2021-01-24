#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;

    int score[3]={0,};

    int p1[5] ={1,2,3,4,5};
    int p2[8] = {2,1,2,3,2,4,2,5};
    int p3[10] = {3,3,1,1,2,2,4,4,5,5};

    for(int i=0;i<answers.size();i++) {
        if(p1[i%5] == answers[i])
            score[0]++;
        if(p2[i%8] == answers[i])
            score[1]++;
        if(p3[i%10] == answers[i])
            score[2]++;
    }
    vector<int> result = {score[0], score[1], score[2]};
    sort(result.begin(), result.end());

    int max = *(result.end()-1);

    for(int i=0; i<result.size();i++) {
        if(score[i] == max)
            answer.push_back(i+1);
    }
    return answer;
}

int main() {
    solution({1,2,3,4,5});
}