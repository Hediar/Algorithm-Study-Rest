/*
[문제]
[BOJ] 1707: 이분 그래프 판별하기
서로 다른 노드에서 DFS를 진행
1. 현재 노드의 연결 노드 중 방문하지 않은 노드로 방문
-> 현재 노드와 다른 집합으로 연결 노드 집합 저장
-> 재귀 형태로 DFS 실행
2. 이미 방문한 노드인데 현재 노드와 같은 집합
-> 이분 그래프가 아님
*/

#include <iostream>
#include <vector>

using namespace std;

static vector<vector<int>> A;
static vector<int> check;
static vector<bool> visited;
static bool IsEven;

void DFS(int node){
    visited[node] = true;
    
    for(int i: A[node]){
        if(!visited[i]){
            // 인접한 노드는 같은 집합이 아니므로 이전 노드와 다른 집합으로 처리
            check[i] = (check[node] + 1) % 2;
            DFS(i);
        } else if (check[node] == check[i]){
            // 이미 방문한 노드가 현재 노드와 같은 집합이면 이분 그래프가 아님
            IsEven = false;
        }
    }
}

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N;
    cin >> N;
    
    for(int i=0; i<N; i++){
        int V, E;
        cin >> V >> E;
        A.resize(V+1);
        visited.resize(V+1);
        check.resize(V+1);
        IsEven = true;
        
        for(int j=0; j<E; j++){
            int S, E;
            cin >> S >> E;
            A[S].push_back(E);
            A[E].push_back(S);
        }
        
        // 모든 노드에서 DFS를 수행
        for(int j=1; j<=V; j++){
            if(IsEven){
                DFS(j);
            } else {
                break;
            }
        }
        
        if(IsEven){
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
        
        for(int j=0; j<=V; j++){
            A[j].clear();
            visited[j] = false;
            check[j] = 0;
        }
    }
    
    return 0;
}