'''
[문제]
[BOJ] 1669: 멍멍이 쓰다듬기
팰린드롬 수열 규칙을 사용하여 풀이

1(1)
11(2)
121(4)
1221(6)
12321(9)
123321(12)
1234321(16)

1. 각 수열의 길이를 days, 각 수열의 합을 limit으로 둚
2. y - x의 값이 수열의 합 이하이면 길이(days) 리턴
'''
x, y = map(int, input().split())
sub, limit, days = y - x, 0, 0

while limit < sub:
    days += 1
    limit += (days + 1) // 2

print(days)