'''
[문제]
[BOJ] 2470: 두 용액
투포인터, 이진탐색을 사용하여 풀이
1. 기준이 되는 수 target(인덱스 i)을 정함
2. i + 1부터 n - 1까지 이진탐색
  2-1. 두 수의 합이 최소 절대값을 갖는 한 쌍을 구함
  2-2. 두 수의 합이 0이면 break 하도록 함
  2-3. 두 수의 합이 0보다 크면 왼쪽 순회, 작으면 오른쪽 순회
'''
from sys import stdin
input = stdin.readline

n = int(input())
vals = sorted(map(int, input().split()))
min_adder = [vals[0], vals[-1]]

for i in range(n):
    target = vals[i]
    start, end = i + 1, n - 1
    while start <= end:
        mid = (start + end) // 2
        tmp = target + vals[mid]
        if abs(tmp) < abs(sum(min_adder)): min_adder = [target, vals[mid]]
        if tmp == 0: break
        elif tmp > 0: end = mid - 1
        else: start = mid + 1
print(*sorted(min_adder))