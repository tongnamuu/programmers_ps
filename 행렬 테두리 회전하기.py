def rotate(map, sx, sy, ex, ey):
    fir = map[sx][ey]
    sec = map[ex][ey]
    thi = map[ex][sy]
    fou = map[sx][sy]
    ans = min(fir, sec, thi, fou)
    for i in range(ey, sy, -1):
        map[sx][i] = map[sx][i - 1]
        ans = min(ans, map[sx][i])

    for i in range(ex, sx, -1):
        map[i][ey] = map[i-1][ey]
        ans = min(ans, map[i][ey])

    for i in range(sy, ey):
        map[ex][i] = map[ex][i + 1]
        ans = min(ans, map[ex][i])

    for i in range(sx, ex):
        map[i][sy] = map[i + 1][sy]
        ans = min(ans, map[i][sy])
    map[sx+1][ey] = fir
    map[ex][ey-1] = sec
    map[ex-1][sy] = thi
    map[sx][sy+1] = fou
    return ans


def solution(rows, columns, queries):
    map = [[0]*columns for _ in range(rows)]
    num = 1
    for i in range(rows):
        for j in range(columns):
            map[i][j] = num
            num += 1
    ans = []
    for q in queries:
        res = rotate(map, q[0] - 1, q[1] - 1, q[2] - 1, q[3] - 1)
        ans.append(res)
    return ans
