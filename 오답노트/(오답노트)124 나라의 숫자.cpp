//이 문제는 처음 봤을때 3진법 생각했지만, 나누어 떨어졌을 때 가 조금 다름
//    17 인 경우 생각해보자
//
//     3 |  17
//       ------
//     3 |   5   ... 2
//        ------
//           1   ... 2
//
//    20 인 경우
//
//      3 | 20
//         ---
//      3 | 6->5   ...  2   여기서 6은 3으로 나누어 떨어지니까 1 빼줌
//         ---
//           1     ...  4
//
//


#include <bits/stdc++.h>
using namespace std;

string solution(int n) {
    string answer = "";

    int num = n;

    while(num != 0) {
        int remainder = num % 3;

        if(remainder == 0) {
            answer = "4" + answer;
            num = (num-1) / 3 ;      //1 빼고 넘겨주기
        } else if(remainder == 1) {
            answer = "1" + answer;
            num /= 3;
        } else if(remainder == 2) {
            answer = "2" + answer;
            num /= 3;
        }
    }


    return answer;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cout << solution(20);
}
