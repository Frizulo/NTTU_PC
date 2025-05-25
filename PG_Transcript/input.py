import random
import string
import math

MAX_FILE_SIZE = int(((8 * 1024 * 1024 - 512 ) // 2)) # sp
filename = "2.in"

def generate_name(existing_names):
    while True:
        length = random.randint(3, 20)
        name = ''.join(random.choices(string.ascii_letters, k=length))
        if name not in existing_names:
            existing_names.add(name)
            return name

lines = []
total_size = 0

while total_size < MAX_FILE_SIZE:  # 留點空間
    n = random.randint(50, 500)  # 控制人數上限，避免單筆過大
    block = [str(n)]
    existing_names = set()
    for _ in range(n):
        name = generate_name(existing_names)
        C = random.randint(0, 100)
        E = random.randint(0, 100)
        M = random.randint(0, 100)
        block.append(f"{name} {C} {E} {M}")
    block_text = "\n".join(block)
    lines.append(block_text)
    # 計算大小時，區塊間會用兩個換行符號分隔，所以要加2
    total_size = sum(len(line.encode()) for line in lines) + 2 * (len(lines) - 1)

with open(filename, "w") as f:
    f.write("\n".join(lines))
