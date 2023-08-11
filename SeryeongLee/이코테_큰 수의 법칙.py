"""
다양한 수로 이루어진 배열이 있을 때 주어진 수들을 M번 더하여 가장 큰 수를 만드는 법칙 
배열의 특정한 인덱스에 해당하는 수가 연속해서 K번을 초과하여 더해질 수 없다. 
"""

n, m, k = map(int,input().split()) # 5, 8, 3
data = list(map(int,input().split())) # [2,4,5,4,6]

data.sort() # 정렬 2 4 4 5 6
first = data[n - 1] # 가장 큰 수
second = data[n - 2] # 두번째로 큰 수 

# 가장 큰 수가 더해지는 횟수 계산
count = int(m / (k+1))*k # 반복되는 수열의 길이 : k+1, 반복되는 횟수 m /(k+1), 가장 큰 수가 등장하는 횟수는 (m / (k+1))*k
count += m % (k+1) # 나누어 떨어지지 않을 때 남은 횟수 

result = 0
result += (count) * first
result += (m - count) * second 

print(result)