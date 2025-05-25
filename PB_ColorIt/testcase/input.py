import random
import os

# 參數設定
MAX_N = 199  # 節點上限，題目說 n < 200
MAX_M = MAX_N * (MAX_N - 1) // 2  # 無向圖最大邊數
TARGET_SIZE_MB = 8
TARGET_SIZE_BYTES = TARGET_SIZE_MB * 1024 * 1024

# 生成 bipartite 或 non-bipartite 測資
def generate_case(n, make_bipartite=True):
    edges = set()
    color = [None] * n

    if make_bipartite:
        # 填色並隨機連邊：確保是 bipartite
        for i in range(n):
            color[i] = random.randint(0, 1)
        for i in range(n):
            for j in range(i+1, n):
                if color[i] != color[j] and random.random() < 0.2:
                    edges.add((i, j))
    else:
        # 生成 non-bipartite 圖：加奇數環
        for i in range(n - 1):
            edges.add((i, i+1))
        edges.add((n-1, 0))  # 關成一圈，若 n 為奇數，這是奇環
        for _ in range(n // 2):  # 加一些隨機邊
            a, b = random.sample(range(n), 2)
            if a > b:
                a, b = b, a
            edges.add((a, b))

    m = len(edges)
    lines = [f"{n}\n", f"{m}\n"]
    for u, v in edges:
        lines.append(f"{u} {v}\n")

    return lines

# 主程序
in_lines = []
ans_lines = []

size = 0
case_count = 0

while size < TARGET_SIZE_BYTES - 100:  # 留點空間給結尾的 0
    n = random.randint(3, MAX_N)
    make_bipartite = random.choice([True, False])
    lines = generate_case(n, make_bipartite)
    in_lines.extend(lines)
    case_count += 1

    # 判斷是否為 bipartite，產生 ans
    edges = [[] for _ in range(n)]
    for line in lines[2:]:
        u, v = map(int, line.strip().split())
        edges[u].append(v)
        edges[v].append(u)

    color = [None] * n
    queue = [0]
    color[0] = 0
    ok = True

    while queue and ok:
        u = queue.pop(0)
        for v in edges[u]:
            if color[v] is None:
                color[v] = 1 - color[u]
                queue.append(v)
            elif color[v] == color[u]:
                ok = False
                break

    ans_lines.append("BICOLORABLE.\n" if ok else "NOT BICOLORABLE.\n")
    size = len("".join(in_lines)) + len("".join(ans_lines))

# 輸出結尾的 0
in_lines.append("0\n")

# 寫入檔案
with open("sp2.in", "w") as f:
    f.writelines(in_lines)

with open("sp2.ans", "w") as f:
    f.writelines(ans_lines)

("sp2.in", "sp2.ans")
