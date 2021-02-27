//문제 보자마자 음... 이건 문자열을 그냥 다루는거구나
//굳이 알고리즘/ 자료 구조 없이 구현력을 요구하는 문제 같다
//1개로 압축했을때, 2개로 압축했을때, 3개로 압축했을때 해서 최소값 리턴해주자
//시간 복잡도가 클 수도 있으니, 문자열 크기의 반만큼만 탐색하면 되네
//왜냐면 길이가 10인 문자열을 5로 압축하면 2개가 되지만 6, 7로 압축하는건 의미가 없겠지?

//하다가 느낀점, 문자열을 1,2,3,4... 등 나눠봐야하는데 문자열 다루는 능력 보는듯

#include <bits/stdc++.h>
using namespace std;

int solution(string s) {
    int answer = 0;
    vector<string> V;
    vector<int> length;

    //길이가 1이면 1리턴
    if(s.length() == 1)
        return 1;

    //자르는 길이를 1부터 문자열길이/2 까지
    for(int i=0;i<s.length()/2;i++) {
        //자르는 길이 split size 는 1,2,3,4... 등등
        int splitSize = i+1;

        //해당 문자열을 해당 splitsize 크기만큼 잘라서 배열에 넣어줌
        for(int j=0;j<s.length();j+=splitSize) {
            string temp = s.substr(j, splitSize);
            V.push_back(temp);
        }

        int index = 0;
        int count = 1;
        //압축된 문자열의 결과 = result
        string result = "";

        //while 문 돌면서
        while(1) {
            //현재 문자열이 다음과 같고, index는 OOB방지하기 위해 뒤에 조건 추가
            if(V[index] == V[index+1] && index<V.size()-1)
                count++;
            else {
                //같은 문자열이 있었으면 해당 "count + 문자열" 로 압축
                if(count > 1) result += to_string(count) + V[index];
                else result += V[index];
                //같은 문자열이 없었으면 그냥 "문자열" 그자체

                count = 1;
            }
            //배열의 마지막 index면 break
            if(index == V.size()-1)
                break;
            //인덱스는 하나씩 더해주자
            index++;
        }
        //문자열 길이 넣고 배열 초기화
        length.push_back(result.size());
        V.clear();

    }

    answer = *min_element(length.begin(), length.end());
    return answer;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cout << solution("a");
}



