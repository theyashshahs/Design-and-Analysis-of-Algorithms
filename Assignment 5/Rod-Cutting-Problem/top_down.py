def Cut_Rod(p, n):
    r = [0]*(n+1)
    for i in range(0, n+1):
        r[i] = -1
    return Cut_Rod_Aux(p, n, r)


def Cut_Rod_Aux(p, n, r):
    if r[n] >= 0:
        return r[n]
    if n == 0:
        max_value = 0
    else:
        max_value = -1
        for i in range(1, n+1):
            max_value = max(max_value, p[i] + Cut_Rod_Aux(p, n-i, r))
        r[n] = max_value
    return max_value


p = [0, 1, 4, 9, 10, 17, 17, 19, 20, 25]  # 0 value is of no use

print("Maximum value : " + str(Cut_Rod(p, 9)))