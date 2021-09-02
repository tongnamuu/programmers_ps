def solution(relation):
    ans = []
    n = len(relation[0])
    for i in range(1, 1<<n):
        flag = True
        for j in ans:
            if (i & j) == j:
                flag = False
                break
        if not flag:
            continue
        keys = set()
        for r in relation:
            key = []
            for j in range(n):
                if i & (1<<j):
                    key.append(r[j])
            key = tuple(key)
            if key in keys:
                flag = False
                break
            keys.add(key)
        if flag:
            print(i)
            ans.append(i)
   
    return len(ans)
