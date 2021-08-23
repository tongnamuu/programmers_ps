def solution(table, languages, preference):
    table_dict = dict()
    for data in table:
        x, *scores = data.split(" ")
        z = dict()
        for score, language in enumerate(scores):
            z[language] = 5 - score
        table_dict[x] = z
    val = 0
    ans = ""
    for k, v in table_dict.items():
        temp = 0
        for lang, p in zip(languages, preference):
            if lang in v:
                temp += v[lang] * p
        if temp > val:
            val = temp
            ans = k
        elif temp == val and ans > k:
            ans = k
    return ans
