def ackermann(n, m):
    if n == 0:
        return m + 1
    elif m == 0:
        return ackermann(n - 1, 1)
    else:
        return ackermann(n - 1, ackermann(n, m - 1))
#This code works by recursively calling itself until it reaches the base case, which is when either n or m is equal to 0. In the base case, the function simply returns the appropriate value. Otherwise, the function returns the result of calling itself with n - 1 and the result of calling itself with n and m - 1.
