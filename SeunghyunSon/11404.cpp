/*
[문제]
[BOJ] 11404
플로이드-워셜 알고리즘: 노드의 개수가 100개로 매우 작은 편이기 때문에 O(N^3)임에도 시간 초과 X
핵심은 3중 for문으로, mdistance 행렬에 들어있는 값들을 비교하면서 최솟값을 넣어주면 됨
*/
#include <iostream>

using namespace std;

int N, M;
long mdistance[101][101];

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N >> M;
    
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(i==j){
                mdistance[i][j] = 0;
            } else {
                mdistance[i][j] = 100001;
            }
        }
    }
    
    for(int i=0; i<M; i++){
        int s, e, v;
        cin >> s >> e >> v;
        
        if(mdistance[s][e] > v){
            mdistance[s][e] = v;
        }
    }
    
    for(int k=1; k<=N; k++){
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                if(mdistance[i][j] > mdistance[i][k] + mdistance[k][j]){
                    mdistance[i][j] = mdistance[i][k] + mdistance[k][j];
                }
            }
        }
    }
    
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(mdistance[i][j] == 100001){
                cout << "0";
            } else {
                cout << mdistance[i][j] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
