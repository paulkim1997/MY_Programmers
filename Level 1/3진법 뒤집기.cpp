#include <bits/stdc++.h>
using namespace std;

//기존 풀이 방식
//10진법 -> 3진법 -> 앞뒤반전 -> 10진법
//45    -> 1200 -> 0021    -> 7

int solution(int n) {
    int answer = 0;
    vector<int> leftovers; //3으로 나눈 나머지들 저장

    //0 될때까지 3으로 나누어 주면서 배열에 저장
    while(n > 0) {
        leftovers.push_back(n%3);
        n = n/3;
    }

    //앞뒤 반전 해주기
    reverse(leftovers.begin(), leftovers.end());

    //앞뒤 반전 된 배열로 다시 10진수로
    for(int i = 0 ; i<leftovers.size(); i++) {
        answer+=leftovers[i]*pow(3,i);
    }
    return answer;
}

//새로운 풀이 방식
//45   ->  1200 ->  0021   -> 7
//0021이 45을 3으로 나눈 나머지들이다
//숫자를 3으로 나누어주면서 나머지X3을 계속해준다
int solution(int n)
{
    int answer = 0;
    while (n > 0)
    {
        answer *= 3;
        answer += n % 3;
        n /= 3;
    }
    return answer;
}