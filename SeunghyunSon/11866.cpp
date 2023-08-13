/*
[문제]
[BOJ] 11866: 요세푸스 문제
큐를 이용해서 푸는 유명한 문제입니다!
다만, 다른 점은 큐에서 꺼내는 순서가 일정하지 않다는 점입니다!
*/

#include<iostream>
#include<cstdlib>
using namespace std;

int check(int* d, int a) {
	for (int i = 0; i < a; i++) {
		if (d[i] != 0) {
			return 1;
		}
	}
	return 0;
}

int main() {

	int a, b;
	cin >> a >> b;
	
	int* data = new int[a];

	for (int i = 0; i < a; i++) {
		data[i] = i + 1;
	}

	int i = 0;
	int cnt = 0;

	cout << "<";
	
	for (int j = 0; j < a; j++) {
		while (check(data, a)) {
			if (data[i] == 0) {
				i++;
				if (i == a) {
					i = 0;
				}
				continue;
			}

			cnt++;

			if (cnt == b) {
				cnt = 0;
				if (j == a - 1)
					printf("%d>", data[i]);
				else
					printf("%d, ", data[i]);
				data[i] = 0;
				break;
			}

			i++;

			if (i == a) {
				i = 0;
			}
		}
	}

	return 0;
}
