#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int doll = 0;
    //인형을 뽑아서 답을 배열
    stack<int> result;

    //이동해야 하는 만큼 반복
    for(int i = 0 ; i < moves.size() ; i++) {
        for(int j = 0 ; j <board.size(); j++) {
            //입력받는 board사이즈 만큼 반복하여 해당 칸에 저장되어있는 원소 확인
            doll = board[j][moves[i]-1];

            //0이 아닌 인형이 있으면
            if(doll !=0 ) {
                //결과 배열에 비어있으면 인형 넣어줌
                if(result.empty()) {
                    result.push(doll);
                } else {
                    //결과 배열에 이전에 넣어준 인형이 있으면 비교하고
                    //같은게 들어오면 뽑아주고 점수에 +2 점
                    if(result.top() ==doll) {
                        result.pop();
                        answer+=2;
                    } else {
                        //다른 인형이 들어오면 쌓아줌
                        result.push(doll);
                    }
                }
                //인형 뽑아온 부분은 0으로 변경해줌
                board[j][moves[i]-1]=0;
                break;
            }
        }
    }
    return answer;
}