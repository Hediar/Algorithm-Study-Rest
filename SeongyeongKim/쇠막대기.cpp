/*
[문제]
BOJ) 10799번: 쇠막대기
링크: https://www.acmicpc.net/problem/10799

열린 괄호와 닫힌 괄호가 연속으로 붙어있으면 레이저이고,
떨어져 있으면 막대기로

stack을 사용해서 레이저와 괄호의 정보를 파악해야 한다.

모든 막대기를 조회하면서 해당 막대기 시작과 끝 인덱스 사이에 
몇개에 레이저가 포함되는지 count하여 쪼개지는 막대기 개수를 파악한다.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	stack<int> s;
	vector <pair<int, int>> line;
	vector <int> raser;

	string inputStr;
	cin >> inputStr;

	//stack을 사용해서 레이저의 위치와 막대기의 위치를 vector에 저장
	for (int i = 0; i < inputStr.length(); i++) {
		if (inputStr[i] == '(')
			s.push(i);
		else {
			if (s.top() == i - 1) {
				raser.push_back(s.top());
				s.pop();
			}
			else {
				line.push_back({ s.top(), i });
				s.pop();
			}
		}
	}

	int totalCnt = line.size();

	//막대기 vector를 조회하면서
	//해당 막대기 길이 안에 몇개의 레이저가 포함되는지 count
	for(int i=0; i<line.size(); i++) {
		int start = line[i].first;
		int end = line[i].second;
		
		for (int j = 0; j < raser.size(); j++) {
			if (start <= raser[j] && end > raser[j])
				totalCnt++;
			else if (end <= raser[j])
				break;
		}


	}

	cout << totalCnt;
}