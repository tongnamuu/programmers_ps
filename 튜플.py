def solution(s):
    s = s[1:-2]
    s = s.replace('{', '').split("},")
    s.sort(key=lambda a: a.count(','))
    check = set()
    ans = []
    for arg in s:
        x = list(map(int, arg.split(',')))
        for num in x:
            if num not in check:
                ans.append(num)
                check.add(num)
    return ans
