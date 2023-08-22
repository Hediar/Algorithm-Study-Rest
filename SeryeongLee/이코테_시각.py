"""
정수N이 입력되면 00시 00분 00초부터 N시59분59초까지의 모든 시각중에서 3이 하나라도 포함되는 모든 경우의 수
"""
n = int(input())
cnt = 0
for i in range(n+1):
    for j in range(60):
        for k in range(60):
            if '3' in str(i) + str(j) + str(k): # 매 시각 안에 3이 포함되어 있다면
                cnt += 1

print(cnt)