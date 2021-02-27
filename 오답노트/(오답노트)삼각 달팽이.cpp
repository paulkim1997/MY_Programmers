//문제 보자마자 든 생각: 사각 달팽이 수열도 못하는데... 이걸 어떻게 하누
//딱봐도 알고리즘/자료구조 없이 구현력 원하는 문제 같음
//삼각 달팽이 말고 그냥 2차원 배열 써서 계단 모양 만들것임
//n=4 라고 치면
//1
//2  9
//3  10  8
//4  5   6   7   이렇게!


#include <bits/stdc++.h>
using namespace std;

int board[1001][1001];

vector<int> solution(int n) {
    vector<int> answer;

    //d 면 down 아래로, r 이면 right 오른쪽, u 면 up 위로
    char position = 'd';
    int x = 0;
    int y=0;
    int num = 1;

    for(int i=n;i>0;i--) {
        for(int j=0;j<i;j++) {
            if(position =='d') {
                board[x][y] = num;
                x++;
                num++;
            } else if(position == 'r') {
                board[x][y] = num;
                y++;
                num++;
            } else if(position == 'u') {
                board[x][y] = num;
                x--;
                y--;
                num++;
            }
        }
        if(position == 'd') {
            position = 'r';
            x--;
            y++;
        } else if(position == 'r') {
            position = 'u';
            x--;
            y-=2;
        } else if(position == 'u') {
            position = 'd';
            y++;
            x+=2;
        }
    }
    for(int i=0;i<1001;i++) {
        for(int j=0;j<1001;j++){
            if(board[i][j] > 0) {
                answer.push_back(board[i][j]);
            }
        }
    }


    return answer;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solution(4);
}



