#include <bits/stdc++.h>
using namespace std;

//기존의 문제 풀이:
//문자열을 하나씩 잘라서 벡터에 넣고, 정렬
//하나씩 불러와서 새로운 문자열 구성
string solution(string s)
{
    string answer = "";
    vector<string> result;
    for(int i=0; i<s.length(); i++) {
        string c = s.substr(i,1);
        result.push_back(c);
    }

    sort(result.begin(), result.end());
    reverse(result.begin(), result.end());
    for(int i=0;i<result.size();i++) {
        answer.append(result[i]);
    }
    return answer;
}


//새로운 문제 풀이:
//compare사용해 정렬하자!
//아스키 코드가 큰값->작은 순으로 정렬 (대문자는 원래 소문자보다 작다)
bool cmp(const char &a, const char &b){
    return a > b;
}

string solution(string s) {
    sort(s.begin(),s.end(),cmp);
    return s;
}
