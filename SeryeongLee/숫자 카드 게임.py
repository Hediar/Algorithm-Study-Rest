"""
가장 높은 숫자가 쓰인 카드 한장을 뽑아야한다.
"""

n, m = map(int,input().split())

result = 0
for i in range(n):
    data = list(map(int, input().split())) # 한줄씩 입력받기
    min_value = min(data) # 각 줄의 최솟값
    result = max(result, min_value)

print(result)