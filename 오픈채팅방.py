def solution(record):
    name = dict()
    for rec in record:
        x = rec.split(" ")
        if x[0] == 'Enter':
            name[x[1]] = x[2]
        elif x[0] == 'Change':
            name[x[1]] = x[2]
    ans = []
    for rec in record:
        x = rec.split(" ")
        if x[0] == 'Enter':
            ans.append(f"{name[x[1]]}님이 들어왔습니다.")
        elif x[0] == 'Leave':
            ans.append(f"{name[x[1]]}님이 나갔습니다.")

    return ans
