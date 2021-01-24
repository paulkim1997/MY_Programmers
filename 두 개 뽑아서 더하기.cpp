#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;

    for(int i=0;i<(numbers.size()-1);i++) {
        for(int j=i+1;j<numbers.size();j++) {
            answer.push_back(numbers[i] + numbers[j]);
        }
    }

    sort(answer.begin(),answer.end());
    answer.erase(unique(answer.begin(),answer.end()),answer.end());

    return answer;
}

int main() {
    solution({2,1,3,4,1});
}

//보자마자 생각난 아이디어: 2중 for문을 돌면서 numbers의
//1과 2 3 4 5 더하고
//2와 3 4 5 더하고
//3과 4 5 더하고
//4와 5 더해서 벡터에 넣고 unique로 중복제거