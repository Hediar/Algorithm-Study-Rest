'''
[문제]
[BOJ] 1747: 소수&팰린드롬
1. 소수와 팰린드롬을 판별하는 함수를 각각 선언
2. n보다 크거나 같은 수라는 조건을 위해 n부터 while문을 순회
  2-1. n이 소수이고 팰린드롬인 경우 break + 출력
  2-2. 그렇지 않은 경우 n += 1 처리 후 다시 반복
'''
from math import sqrt

def is_prime(n):
    if n == 1: return False
    if n == 2: return True
    if n % 2 == 0: return False
    for i in range(3, int(sqrt(n)) + 1, 2):
        if n % i == 0: return False
    return True

def is_palindrome(n):
    s = str(n)
    size = len(s)
    for i in range((size + 1) // 2):
        if s[i] != s[size - i - 1]: return False
    return True

n = int(input())
while not is_prime(n) or not is_palindrome(n): n += 1
print(n)