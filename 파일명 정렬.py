class A(tuple):
    def __lt__(x, y):
        if x[0] == y[0]:
            if x[1] == y[1]:
                return x[2] < y[2]
            return x[1] < y[1]
        return x[0] < y[0]


def solution(files):
    temp = []
    for idx, file in enumerate(files):
        head = []
        num = []
        num_flag = 0
        for c in file:
            if num_flag == 1 and not ('0' <= c <= '9'):
                num_flag = 2
            if num_flag < 2 and '0' <= c <= '9':
                num_flag = 1
                num.append(c)
            if num_flag == 0:
                head.append(c)
        temp.append((''.join(head).lower(), int(''.join(num)), idx))
    temp.sort(key=A)
    ans = [files[arg[2]] for arg in temp]
    return ans
