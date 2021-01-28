#include <bits/stdc++.h>
using namespace std;

string solution(string s) {
    string answer = "";
    //문자열의 길이가 짝수일때 사용할 것들
    string answer1 = "";
    string answer2 = "";
    if(s.length()%2 != 0) {
        answer=s[s.length()/2];
    } else {
        answer1 =s[s.length()/2-1];
        answer2= s[s.length()/2];
        //원래 answer = s[s.length()/2-1] + s[s.length()/2]
        //로 하려 했는데 왜 안될까요? 정답: string형이 아닌 char형 이라서
        answer = answer1 + answer2;
    }
    return answer;
}

//한줄 문제 풀이법
//substr 포지션: 문자열길이/2 짝수면 정중앙 전, 홀수면 정중앙
//substr 길이 : 문자열이길의&1 을 하면 짝수는 false, 홀수만 true. 짝수면 2개, 홀수면 1개
string solution(string s) {
    string answer = s.substr((s.size()-1)/2, (s.size()&1) ? 1 : 2);
}