/*
[문제]
[BOJ] 1300
이진 탐색: 중앙값보다 작은 수가 몇 개인지 계산
1. 중앙값 크기보다 작은 수가 K보다 작으면(= 현재 중간값보다 작은 수의 개수가 K보다 작음)
시작 인덱스 = 중앙값 + 1
2. 중앙값 크기보다 작은 수가 K보나 크거나 같으면(= 현재 중간값보다 작은 수의 개수가 K보다 크거나 같음)
종료 인덱스 = 중앙값 -1, 정답 변수 = 중앙값
*/
#include <iostream>

using namespace std;

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    long N, K;
    cin >> N >> K;
    
    long start = 1;
    long end = K;
    long result = 0;
    
    while(start<=end){
        long middle = (start+end)/2;
        long cnt = 0;
        
        for(int i=1; i<=N; i++){
            cnt += min(middle/i, N);
        }
        
        if(cnt < K){
            start = middle + 1;
        } else {
            result = middle;
            end = middle - 1;
        }
        
    }
    
    cout << result << endl;

    return 0;
}