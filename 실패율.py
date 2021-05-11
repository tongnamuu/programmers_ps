class A(tuple):
    def __lt__(self, other):
        if self[0] == other[0]:
            return self[1] < other[1]
        return self[0] > other[0]


def solution(N, stages):
    cnt = [0]*(N+2)
    sum = [0]*(N+2)
    for i in stages:
        cnt[i] += 1
    sum[-1] = cnt[-1]
    for i in range(N, -1, -1):
        sum[i] = cnt[i] + sum[i+1]
    answer = []
    for i in range(1, N+1):
        answer.append((0, i) if sum[i] == 0 else (cnt[i]/sum[i], i))
    answer.sort(key=A)
    return [arg[1] for arg in answer]
