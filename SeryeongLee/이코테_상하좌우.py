"""
구현
https://deeply-silence-9a4.notion.site/76769642da9a4fbe962e82ffa74aaf35?pvs=4
"""
n = int(input())
x, y = 1, 1
plans = input().split()

# 이동방향
dx = [0,0,-1,1]
dy = [-1,1,0,0]
move = ['L', 'R','U','D']

for plan in plans: # 이동 계획 확인
    for i in range(len(move)):
        if plan == move[i]: # 이동계획에 따라 각 이동방향 체크
            nx = x + dx[i]
            ny = y + dy[i]
    # 공간 범위를 넘을경우
    if nx < 1 or ny < 1 or nx > n or ny > n:
        continue
    x, y = nx, ny # 이동하기
print(x,y)