#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    //3사람의 점수담을 배열
    int score[3]={0,};
    //3사람의 문제를 찍는 패턴
    int p1[5] ={1,2,3,4,5};
    int p2[8] = {2,1,2,3,2,4,2,5};
    int p3[10] = {3,3,1,1,2,2,4,4,5,5};

    //주어진 답과, 문제 패턴을 계속 비교해 맞을때마다 1점씩 추가
    for(int i=0;i<answers.size();i++) {
        if(p1[i%5] == answers[i])
            score[0]++;
        if(p2[i%8] == answers[i])
            score[1]++;
        if(p3[i%10] == answers[i])
            score[2]++;
    }

    //3사람의 점수 담고 정렬
    vector<int> result = {score[0], score[1], score[2]};
    sort(result.begin(), result.end());

    //최고 점수를 설정
    int max = *(result.end()-1);

    //최고 점수와 동일한 점수를 받은 사람을 저장
    for(int i=0; i<result.size();i++) {
        if(score[i] == max)
            answer.push_back(i+1);
    }
    return answer;
}

int main() {
    solution({1,2,3,4,5});
}