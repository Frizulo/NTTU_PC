import random
import math

N = 10 # 1, 2
N = 100 # 3
N = 1000 # 4, 5
N = int(math.sqrt((8 * 1024 * 1024 - 512 ) // 2)) # sp

with open("sp2.in", "w") as f:
    f.write(f"{N}\n")
    matrix = []

    for i in range(N):
        row = [random.randint(0, 1) for _ in range(N)]
        matrix.append(row)
        f.write(" ".join(map(str, row)) + "\n")
