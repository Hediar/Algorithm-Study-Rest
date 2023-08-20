
/*
    문제: 인구이동
    난이도: 골드 4
    알고리즘: DFS
    링크: https://www.acmicpc.net/problem/16234

    이 문제는 인구이동이 일어나지 않을 때까지 평균값을 내고 각 지역마다
    평균값이 된 인구를 집어 넣고 기초 입력값인 l이랑 r 범위에 벗어난 지역은 인구이동이 일어나지 않는다.
    그래서 모든 지역이 인구이동이 일어나지 않을 때까지 인구이동은 진행이 되고 인구이동이 진행 될떄까지 cnt++를 해준다

    DFS으로 탐색으로 풀었다! 그리고 매번 인구이동이 일어나면 모든 값을 초기화를 시캬주어 인구이동이 가능한지 check할 세팅을 해준다.
    자료구조는 vector를 이용해 줘서 각 지역의 좌표와 사이즈와 sum을 알 수 있도록 해주었다!

*/ 
#include <bits/stdc++.h>
using namespace std;
int n,l,r, a[54][54],sum,cnt;
int vis[54][54];
vector<pair<int,int>> v;
const int dy[4] = {-1,0,1,0};
const int dx[4] = {0,1,0,-1};

void dfs(int y, int x, vector<pair <int,int>> &v) {
    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny < 0 || ny >= n || nx < 0 || nx >= n || vis[ny][nx]) continue;
        if(abs(a[ny][nx] - a[y][x]) >= l && abs(a[ny][nx] - a[y][x]) <= r) {
            vis[ny][nx] = 1;
            v.push_back({ny,nx});
            sum += a[ny][nx];
            dfs(ny,nx,v);
        }
    }
}

int main() {
    cin >> n >> l >> r;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    
    while(true) {
        bool flag = 0;
        fill(&vis[0][0], &vis[0][0] + 54 * 54, 0);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(!vis[i][j]) {
                    v.clear();
                    vis[i][j] = 1;
                    v.push_back({i,j});
                    sum = a[i][j];
                    dfs(i,j,v);
                    if(v.size() == 1) continue;
                    for(pair<int,int> tmp : v) {
                        a[tmp.first][tmp.second] = sum / v.size();
                        flag = 1;
                    }
                }
            }
        }
        if(!flag) break;
        cnt++;
    }
    cout << cnt;
    return 0;
}
