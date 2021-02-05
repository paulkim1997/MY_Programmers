#include <bits/stdc++.h>
using namespace std;

int solution(string name) {
    int answer = 0;
    int index = 0;
    string temp ="";

    for(int i=0;i<name.length();i++) {
        temp+="A";
    }

    while(true) {
        temp[index] = name[index];

        name[index] - 'A' > 'Z' + 1 - name[index] ? answer += 'Z' + 1 - name[index] : answer += name[index] - 'A';

//        int change = name[index];
//        if(change == 65) {
//            continue;
//        } else if(change < 78) {
//            answer += change-65;
//        } else if(change > 78) {
//            answer += 90-change+1;
//        } else if(change == 78) {
//            answer += 13;
//        }
//       로직은 맞는 시간 초과가 나네

        if(temp == name)
            break;

        //이해해야 할 필요가 있음
        for(int move = 1;move<name.length();move++) {
            //move 가 1씩 증가하면서 오른쪽에 먼저 다른값이 나오면
            if(name[index + move] != temp[index + move]) {
                index += move;
                answer += move;
                break;
            } else if(name[(index + name.length() - move) % name.length()]
                        != temp[(index + name.length() - move) % name.length()]) {
                index = (index + name.length() - move) % name.length();
                answer += move;
                break;
            }

        }
    }

    return answer;
}