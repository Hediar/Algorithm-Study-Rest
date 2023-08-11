
/*
    문제: 연산자 끼워넣기
    난이도: 실버 1
    알고리즘: 백트레킹
    링크: https://www.acmicpc.net/problem/14888

    해설: 
    입력은 
    2       -> 수의 개수
    5 6     -> 수의 값
    0 0 1 0 -> +,-,*,/ 의 개수

    주어진 연산자의 계산으로 최대의 값, 최소의 값을 구하는 문제이다
    
    예를 들면 입력에 * 연산자 말곤 모두 0이기 떄문에
    5 * 6 은 30이라서 최대, 최소는 30이 될 수 밖에 없다

    나는 입력을 모두 받은 뒤에 재귀로 넘겨줄 값을 수의 값의 가장 첫번째 값인 5인 a[0]을 첫번쨰 인자값으로 넘겨주고
    두번쨰는 인덱스의 시작인 idx = 1으로 넘겨주었다

    idx가  수의 개수인 n이랑 같으면 종료가 되면서 최대의 수 최소의 수를 변수에 넣고 리턴을 한다
    만약에 수의 개수가 n이랑 같지 않으면
    연산자를 하나 하나씩 돌면서 0이 될 떄까지 돌리면서 재귀로 넘겨주는데 연산자의 개수를 하나씩 빼줘야지 중복적으로 계산이 안 된다.
    다른 연산자를 사용해야하므로 아까 연산자의 개수를 하나씩 뺴준것을 다시 늘려준다.

    재귀가 모두 끝나고 결국 최대값이랑 최소값이 정해주면서 출력을 해주면 된다

*/ 
#include <bits/stdc++.h>
using namespace std;
int n, a[11], operators[4];
int retMax = -1000000001, retMin = 1000000001;

void solve(int ret, int idx) {
    if(idx == n) {
        if(ret > retMax) retMax = ret;
        if(ret < retMin) retMin = ret;
        return;
    }

    for(int i = 0; i < 4; i++) {
        if(operators[i] > 0) {
            operators[i]--;
            if( i == 0) solve(ret + a[idx], idx + 1);
            else if(i == 1) solve(ret - a[idx], idx + 1);
            else if(i == 2) solve(ret * a[idx], idx + 1);
            else if(i == 3) solve(ret / a[idx], idx + 1);
            operators[i]++;
        }
    }
    return;
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int j = 0; j < 4; j++) {
        cin >> operators[j];
    }
    solve(a[0],1);
    cout << retMax << "\n";
    cout << retMin;
    return 0;
}
