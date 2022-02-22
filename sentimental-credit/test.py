    length = len(number)
    hlen = length // 2
    if len(number) % 2 == 1:
        for i in range(hlen + 1):
            sum += int(number[2 * i])
        for j in range(1, hlen + 1):
            sum += 2*(int(number[(2 * j) - 1])) % 10
            if int(number[2*j]) >= 5:
                sum += 1

    else:
        for k in range(hlen):
            sum += (2 * (int(number[2 * k])) % 10)
            if int(number[2*k]) >= 5:
                sum += 1
            sum += (int(number[(2 * k + 1)]))