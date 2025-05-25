import random

def generate_time_pair():
    h1 = random.randint(0, 23)
    m1 = random.randint(0, 59)
    
    # 增加一點鬧鐘時間，確保在 24 小時內響起，且非同一時間
    offset = random.randint(1, 24 * 60 - 1)
    total_minutes = (h1 * 60 + m1 + offset) % (24 * 60)
    h2 = total_minutes // 60
    m2 = total_minutes % 60

    return (h1, m1, h2, m2)

def generate_testcases(filename="alarm.in", T=10, include_equal_case=True):
    with open(filename, "w") as f:
        for i in range(T):
            if include_equal_case and i == T - 1:
                # 最後一筆做為終止條件（時間相同）
                h = random.randint(0, 23)
                m = random.randint(0, 59)
                f.write(f"{h} {m} {h} {m}\n")
            else:
                h1, m1, h2, m2 = generate_time_pair()
                f.write(f"{h1} {m1} {h2} {m2}\n")

if __name__ == "__main__":
    generate_testcases("sp1.in", T=1000)
