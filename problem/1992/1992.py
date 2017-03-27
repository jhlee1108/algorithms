global image

def compression(n, i, j):
    if n == 1:
        return image[i][j] 

    a = compression(n/2, i, j)
    b = compression(n/2, i, j+n/2)
    c = compression(n/2, i+n/2, j)
    d = compression(n/2, i+n/2, j+n/2)

    if a == b and b == c and c == d and len(a) == 1:
        return a
    else:
        return '(' + a + b + c + d + ')'


n = input()
image = [[0 for col in range(n)] for row in range(n)]

for i in range(n):
    row = raw_input()
    for j in range(n):
        image[i][j] = row[j]

print(compression(n, 0, 0))
