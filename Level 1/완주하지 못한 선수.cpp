#include <bits/stdc++.h>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    //주어진 2개의 배열 정렬
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());

    //index가 0일때부터 비교해 다른 부분 나오면 그 사람이 미완주자다!
    for(int i=0;i<participant.size();i++) {
        if(participant[i] != completion[i]) {
            answer = participant[i];
            break;
        }
    }
    return answer;
}

//처음에 사용하려던 아이디어는 벡터간 비교 set_difference 함수 사용
//잘 안돼서 깡으로 정렬하고 0번 index부터 비교하여 다른점 있으면 저장하고 break
