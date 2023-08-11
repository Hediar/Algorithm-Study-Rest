/*
[����]
BOJ) 10799��: �踷���
��ũ: https://www.acmicpc.net/problem/10799

���� ��ȣ�� ���� ��ȣ�� �������� �پ������� �������̰�,
������ ������ ������

stack�� ����ؼ� �������� ��ȣ�� ������ �ľ��ؾ� �Ѵ�.

��� ����⸦ ��ȸ�ϸ鼭 �ش� ����� ���۰� �� �ε��� ���̿� 
��� �������� ���ԵǴ��� count�Ͽ� �ɰ����� ����� ������ �ľ��Ѵ�.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	stack<int> s;
	vector <pair<int, int>> line;
	vector <int> raser;

	string inputStr;
	cin >> inputStr;

	//stack�� ����ؼ� �������� ��ġ�� ������� ��ġ�� vector�� ����
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

	//����� vector�� ��ȸ�ϸ鼭
	//�ش� ����� ���� �ȿ� ��� �������� ���ԵǴ��� count
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