#include <bits/stdc++.h>
using namespace std;

int vis[101][101];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

vector<int> solution(int m, int n, vector<vector<int>> picture);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solution(6,4, {{1, 1, 1, 0}, {1, 2, 2, 0}, {1, 0, 0, 1}, {0, 0, 0, 1}, {0, 0, 0, 3}, {0, 0, 0, 3}});

}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;

    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++)
            vis[i][j] = 0;
    }

    vector<int> areaV;
    queue<pair<int,int>> Q;
    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
            int color = 0;
            int area = 0;
            if(picture[i][j] != 0 && vis[i][j] == 0) {
                color = picture[i][j];
                number_of_area++;
                Q.push({i,j});
                vis[i][j] = 1;
                while(!Q.empty()) {
                    auto cur = Q.front(); Q.pop();
                    area++;
                    for(int dir=0;dir<4;dir++) {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];

                        if(nx<0||nx>=m||ny<0||ny>=n) continue;
                        if(picture[nx][ny] == 0 || picture[nx][ny] != color || vis[nx][ny] ==1) continue;

                        Q.push({nx,ny});
                        vis[nx][ny] = 1;
                    }
                }
                areaV.push_back(area);
            }
        }
    }

    max_size_of_one_area = *max_element(areaV.begin(),areaV.end());

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    cout << number_of_area <<"\n";
    cout << max_size_of_one_area << "\n";
    return answer;
}