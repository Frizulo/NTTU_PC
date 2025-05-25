def result(line):
    cnt = 0
    flag = False
    output = []
    for num in line:
        if num == 1:
            cnt += 1
        elif cnt > 0:
            output.append(str(cnt))
            cnt = 0
            flag = True
    if cnt > 0 or not flag:
        output.append(str(cnt))
    print(" ".join(output))

n = int(input())
matrix = [list(map(int, input().split())) for _ in range(n)]

for j in range(n):
    col = [matrix[i][j] for i in range(n)]
    result(col)

for i in range(n):
    result(matrix[i])
