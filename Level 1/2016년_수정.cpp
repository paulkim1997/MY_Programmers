#include <bits/stdc++.h>
using namespace std;

string solution(int a, int b) {
    string answer = "";

    //2016년 1월 1일이 금요일부터니까 배열도 금요일부터 나열
    string days[7] = {"FRI","SAT","SUN","MON","TUE","WED","THU"};

    //2016년의 매월 일 수를 더해주기 위한 배열
    int months[12] = {31,29,31,30,31,30,31,31,30,31,30,31};

    //2016년 1월 1일부터 입력한 a월 b일 까지 총 일수
    int totdays=0;

    //1월부터 a월까지 일수 합하기
    for(int i=0;i<a-1;i++) {
        totdays += months[i];
    }

    //월들의 일수 합 구하고, b일 더해주기
    totdays = totdays+b-1;

    //총 일수 합을 7로 나누어 나머지만큼 배열의 값 정답에 넣어줌
    answer=days[totdays%7];

    return answer;
}

int main() {
    solution(5,24);
}