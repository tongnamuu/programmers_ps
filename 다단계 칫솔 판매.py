from collections import defaultdict


def solution(enroll, referral, seller, amount):
    res = dict()
    p = dict()
    for name, parent in zip(enroll, referral):
        res[name] = 0
        if parent == "-":
            p[name] = "Center"
        else:
            p[name] = parent

    for s, a in zip(seller, amount):
        name = s
        money = a * 100
        while name != "Center" and money > 0:
            given = money // 10
            res[name] += money - given
            name = p[name]
            money = given
    ans = list(res.values())
    return ans
