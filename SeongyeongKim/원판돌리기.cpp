#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;

int circle[50][50];
int aver[50];
int n, m, t;

void rotate(int inputX, int inputD, int inputK) {
	for (int i = inputX-1; i < n; i += inputX) {
		int fk;
		//시계방향
		if (inputD == 0) {
			fk = inputK%m;
		}
		//반시계방향일때, K를 조절하여 시계방향 처럼 바꿔줌
		if (inputD == 1) {
			fk = m - (inputK%m);
		}

		int tmp = circle[i][1];
		int rote[51];
		for (int j = 0; j < m; j++) {

			int _jump = (j + fk)%m;

			rote[_jump] = circle[i][j];
		}

		for (int j = 0; j < m; j++) {
			circle[i][j] = rote[j];
		}
	}
}



int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

//0,0부터 모든 circle을 순회해야함
//이때, BFS를 통해 같은 색깔이 있는지 탐색
bool removeCheck() {
	bool removeValue = false;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int tmp = circle[i][j];
			if (tmp == 0)
				continue;

			queue<pair<int, int>> q;
			q.push({i, j});

			while (!q.empty()) {
				int x = q.front().first;
				int y = q.front().second;
				q.pop();

				for (int d = 0; d < 4; d++) {
					int nx = x + dx[d];
					int ny = y + dy[d];

					if (nx < 0 || nx >= n) continue;

					if (ny == m)
						ny = 0;
					if (ny == -1)
						ny = m - 1;

					if (tmp == circle[nx][ny]) {
						removeValue = true;
						circle[nx][ny] = 0;
						circle[i][j] = 0;
						q.push({ nx, ny });
					}
				}

			}
		}
	}

	return removeValue;
}

int cnt;
int calcSum() {
	int sum = 0;
	cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (circle[i][j] != 0) {
				sum += circle[i][j];
				cnt++;
			}
		}
	}
	return sum;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);


	cin >> n >> m >> t;

	for (int i = 0; i < n; i++) {
		for (int j =0; j < m; j++) {
			cin >> circle[i][j];
		}
	}

	int x, d, k;
	for (int i = 0; i < t; i++) {
		cin >> x >> d >> k;

		//1. 원판 회전하기
		rotate(x, d, k);

		//2-(1). 인접하면 지우기
		//2-(2). 인접안하면 평균 비교하여 갱신
		if (!removeCheck()) {
			float avg = calcSum() / (float)cnt;

			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (circle[i][j] != 0) {
						if (avg > circle[i][j])
							circle[i][j]++;
						else if (avg < circle[i][j])
							circle[i][j]--;
					}
				}
			}
		}
	}

	cout << calcSum();

	return 0;
}