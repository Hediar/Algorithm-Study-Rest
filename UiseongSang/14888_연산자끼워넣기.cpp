
/*
    문제: 인구이동
    난이도: 골드 4
    알고리즘: DFS
    링크: https://www.acmicpc.net/problem/16234


*/ 
#include <bits/stdc++.h>
using namespace std;
int n,l,r, a[54][54],sum = 0,cnt = 0;
bool vis[54][54];
vector<pair<int,int>> v;
const int dy[4] = {-1,0,1,0};
const int dx[4] = {0,1,0,-1};

void dfs(int y, int x, vector<pair <int,int>> &v) {
    for(int i = 0; i < 4; i++) {
        int ny = dy[i] + y;
        int nx = dx[i] + x;

        if(ny < 0 || ny >= n || nx < 0 || nx >= x || vis[ny][nx]) continue;
        if(abs(a[ny][nx] - a[y][x]) >= l && abs(a[ny]nx] - a[y][x] <= r)) {
            vis[ny][nx] = 1;
            v.push_back({ny,nx});
            sum += a[ny][nx];
            dfs(ny,nx,v);
        }
    }
}

int main() {
    cin >> n >> l >> r1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i]][j]
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
                        a[tmp.first][b.second] = sum / v.size();
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
