def solution(numbers):
    class cmp(str):
        def __lt__(self, other):
            return int(self+other) > int(other+self)
    answer = ''.join(sorted(map(str, numbers), key=cmp))
    if answer[0] == '0':
        return '0'
    return answer
