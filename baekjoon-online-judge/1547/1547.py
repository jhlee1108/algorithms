a = [0, 1, 2, 3]
N = int(input())
for _ in range(N):
    X, Y = [int(n) for n in input().split()]
    i, j = a.index(X), a.index(Y)
    a[i], a[j] = a[j], a[i]
print(a[1])
