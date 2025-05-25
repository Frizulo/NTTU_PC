import random

MAX_T = 1000
MAX_N = 1000
MAX_G = 100
MAX_P = 100
MAX_W = 30
MAX_MW = 30
MAX_SIZE = 8 * 1024 * 1024  # 8 MB

output_file = "sp1.in"

total_size = 0

def safe_write(f, s):
    global total_size
    size = len(s.encode())
    if total_size + size <= MAX_SIZE:
        f.write(s)
        total_size += size
        return True
    return False

with open(output_file, "w") as f:
    test_cases = []
    T = 0

    while T < MAX_T:
        N = MAX_N
        G = MAX_G

        lines = []
        lines.append(f"{N}\n")
        for _ in range(N):
            P = random.randint(1, MAX_P)
            W = random.randint(1, MAX_W)
            lines.append(f"{P} {W}\n")
        lines.append(f"{G}\n")
        for _ in range(G):
            MW = random.randint(1, MAX_MW)
            lines.append(f"{MW}\n")

        size_estimate = sum(len(line.encode()) for line in lines)
        if total_size + size_estimate > MAX_SIZE:
            break

        test_cases.append(lines)
        T += 1

    safe_write(f, f"{T}\n")
    for case in test_cases:
        for line in case:
            safe_write(f, line)
