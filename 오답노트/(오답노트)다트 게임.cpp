//이 문제는 처음에 봤을 때 알고리즘이 필요한게 아니라 구현력 같아 보임
//문자열을 다루는 구현력!
#include <bits/stdc++.h>
using namespace std;

int solution(string dartResult) {
    int answer = 0;

    //입력 받은 문자열에서 숫자 추출해 담을 배열
    vector<int> V;

    //입력 받은 문자열을 앞에서 하나씩 검토
    for(int i=0;i<dartResult.length();i++) {
        //문자열에서 추출할 숫자 num
        int num = 0;

        //문자열을 하나씩 검토할때 숫자면 숫자 벡터에 담아줌
        if(isdigit(dartResult[i])) {
            //두 자리 숫자면
            if(dartResult[i+1] && isdigit(dartResult[i+1])) {
                string temp = dartResult.substr(i,2);
                num = stoi(temp);
                V.push_back(num);
                i++;
            }//한 자리 숫자면
            else {
                num = dartResult[i] - '0';
                V.push_back(num);
            }
        } else {
            if(dartResult[i] == 'S') {
                V[V.size()-1] *= 1;
            } else if(dartResult[i] == 'D') {
                V[V.size()-1] = V[V.size()-1] * V[V.size()-1];
            } else if(dartResult[i] == 'T') {
                V[V.size()-1] = V[V.size()-1] * V[V.size()-1] * V[V.size()-1];
            } else if(dartResult[i] == '*') {
                V[V.size()-1] *= 2;
                //숫자 벡터에 숫자가 2개 이상이면 이전꺼 까지 두 배
                if(V.size()>1)
                    V[V.size()-2] *= 2;
            } else if(dartResult[i] == '#') {
                V[V.size()-1] *= -1;
            }
        }
    }
    //총합 구하기
    for(auto n : V)
        answer += n;
    return answer;

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cout << solution("10S3D9S");
}
