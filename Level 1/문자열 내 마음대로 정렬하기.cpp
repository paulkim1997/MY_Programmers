#include <bits/stdc++.h>
using namespace std;

int INDEX;

//
bool comp(string a, string b) {
    //아스키 코드 작은 -> 큰 순 정렬
    if(a[INDEX] != b[INDEX]) {
        return a[INDEX] < b[INDEX];
    } else
        return a < b;
    //같으면 문자열 비교해서 사전순
}

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    INDEX = n;

    sort(strings.begin(), strings.end(), comp);
    answer = strings;

    return answer;
}