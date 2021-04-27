def score(num):
    if 2 <= num <= 6:
        return 7-num
    return 6


def solution(lottos, win_nums):
    x = [0] * 46
    for i in win_nums:
        x[i] += 1
    zero_cnt = 0
    ans = 0
    for i in lottos:
        if i == 0:
            zero_cnt += 1
        if x[i] > 0:
            ans += 1
    return [score(ans+zero_cnt), score(ans)]
