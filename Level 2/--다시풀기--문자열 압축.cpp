#include <bits/stdc++.h>
using namespace std;

int solution(string s) {
    int answer = 0;
    int count = 1;
    string temp, result;
    vector<int> v;

    //문자열 길이의 반만 반복 -> 문자열 길이의 반보다 큰값은 같은게 없으니 압축 불가능
    for(int i=1;i<=s.length()/2;i++) {
        //result 초기화
        result = "";
        for(int j=0;j<s.length();j+=i) {
            //문자열 길이까지 substr 하는데 간격은 반복문 도는 i 만큼
            temp = s.substr(j,i);

            //substr 범위를 넘어서거나, 이후 문자열과 다르면
            if(j+i>s.length() || temp != s.substr(j+i,i)) {
                if(count != 1)
                    result += to_string(count);
                result += temp;
                count = 1;
            } else {
                count++;
            }
        }
        v.push_back(result.length());
    }
    if(s.length() ==1) answer = 1;
    else answer = *min_element(v.begin(), v.end());

    return answer;
}

int main() {
    solution("aabbaccc");
}

//문자열 압축이라.. 첫번째 든 생각은 문자열 압축 숫자를 1부터 반복해서 최솟값 리턴?
//말이안됨 -> 사실 이게 맞는듯?
