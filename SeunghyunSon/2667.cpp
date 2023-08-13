/*
[문제]
[BOJ] 2667: 단지번호 붙이기
BFS를 복습하기 위해서 다시 문제를 풀어보게 되었습니다.
두 가지 방향으로 탐색하는 것에 익숙해진 것 같아요!
*/

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n, cnt=0;
string arr[26];

bool visited[26][26]={0,};
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

vector<int> result;
queue<pair<int,int>> q;

void bfs(int x,int y) {
    
    q.push({x,y});
    visited[x][y]=true;
    cnt++;

    while(!q.empty()) {
        
        int a = q.front().first;
        int b = q.front().second;
        q.pop();
        
        for(int i=0;i<4;i++) {
            int nx = a + dx[i];
            int ny = b + dy[i];
            
            if(0<=nx && 0<=ny && nx <n && ny < n && visited[nx][ny]==false && arr[nx][ny]=='1') {
                q.push({nx,ny});
                visited[nx][ny]=true;
                cnt++;
            }
        }
    }
}

int main() {
    
    cin >> n;
    
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }
    
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(arr[i][j]=='1' && visited[i][j]==false) {
                cnt =0;
                
                bfs(i,j);
                
                result.push_back(cnt);
            }
        }
    }

    sort(result.begin(), result.end());
    
    cout << result.size() << '\n';
    
    for(int i=0;i<result.size();i++) {
        cout << result[i] << '\n';
    }
    
    return 0;
}