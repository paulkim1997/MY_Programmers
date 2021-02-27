//이 문제는 처음에 봤을 때 알고리즘이 필요한게 아니라 구현력 같아 보임
#include <bits/stdc++.h>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    int student[31];

    //student 배열 초기화 해주기
    for(int i=0;i<31;i++)
        student[i] = 0;

    //입력 받은 학생 수 만큼 배열에 1씩 더해줌
    for(int i=0;i<n;i++)
        student[i]++;

    //체육복 잃어버린 애들 체크
    for(int i=0;i<lost.size();i++)
        student[lost[i]-1]--;

    //체육복 추가로 가져온 애들 체크
    for(int i=0;i<reserve.size();i++)
        student[reserve[i]-1]++;

    //student 배열 전체 돌면서, 잃어버린 학생의 경우 앞뒤로 빌릴 수 있으면 빌리고 체크
    for(int i=0;i<n;i++) {
        if(student[i] == 0) {
            //앞사람 체크 (0번째 일때는 앞사람 없으니 i>0 일때 추가)
            if(i>0 && student[i-1] == 2) {
                student[i-1]--;
                student[i]++;
            }//뒷사람 체크
            else if(student[i+1] == 2) {
                student[i+1]--;
                student[i]++;
            }
        }
    }
    for(auto i : student) {
        if(i > 0)
            answer++;
    }
    return answer;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cout << solution(15, {2,6,10}, {1});
}
