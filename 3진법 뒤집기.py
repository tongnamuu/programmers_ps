def solution(n):
    a = []
    while n > 0:
        a.append(n % 3)
        n //= 3
    ans = 0
    for i in range(len(a)):
        ans *= 3
        ans += a[i]
    return ans
