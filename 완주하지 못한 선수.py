from collections import Counter


def solution(participant, completion):
    counter = Counter(participant)
    for c in completion:
        counter[c] -= 1
        if counter[c] == 0:
            counter.pop(c)
    return list(counter.keys())[0]
