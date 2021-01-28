#include <bits/stdc++.h>
using namespace std;

//기존의 문제 풀이:
//처음부터 탐색하면서 i가 1이상일때 i-1번째와 i번째 비교해서 같으면 i-1번째 불러옴
vector<int> solution(vector<int> arr)
{
    vector<int> answer;

    //이전과 같은 숫자인지 비교하기 위해 now, before 선언
    int now=0;
    int before=0;
    for(int i=0;i<arr.size();i++) {
        now = arr[i]; //now에 현재값
        if(i>0) { //index가 1부터일때만 before존재
            before = arr[i-1]; //before에 이전값
            if(before!=now) {
                answer.push_back(before); //값이 달라지면 이전 값 저장
            }
        }
    }
    //마지막 까지 왔으면 계속 같은 숫자였거나, 다른 숫자 한개가 있을수 있으니 저장
    answer.push_back(arr[arr.size()-1]);

    return answer;
}

//새로운 문제 풀이:
//STL Library 사용해 한줄 컷
//erase()와 unique()로 중복 제거
vector<int> solution(vector<int> arr)
{
    arr.erase(unique(arr.begin(), arr.end()), arr.end());
    return arr;
}