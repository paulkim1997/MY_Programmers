//이 문제를 처음 봤을때 알고리즘, 자료구조 딱히 생각안남
//그냥 단순 구현 문제 같음
//생각한 구현 방법, pregresses 벡터에 speeds 벡터를 계속 더하고,
//vector의 첫번재가 100이 넘으면 횟수 더해주고 pop

#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    //몇 번째 작업 index
    int index = 0;
    while(1) {
        int count = 0;
        //각 작업 더하기
        for(int i=0;i<progresses.size();i++) {
            progresses[i] += speeds[i];
        }

        //index별 작업이 배포 완료 되면!
        while(progresses[index] > 99) {
            //배포 가능한 기능 숫자 더해주고
            count++;
            //마지막 인덱스면 푸시 하고 프로그램 끝냄
            if(index == progresses.size()-1) {
                answer.push_back(count);
                return answer;
            }
            //한칸씩 나아가서 뒤에 이미 개발 끝난 프로그램 있나 확인
            index++;
            if(progresses[index] < 100) {
                answer.push_back(count);
                break;
            }
        }
        if(index == progresses.size())
            break;
    }
    return answer;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solution({93, 30, 55}, {1, 30, 5});
}



