import random

# 可選的單位前綴與對應倍率
unit_prefixes = {
    '': 1,
    'm': 1e-3,
    'k': 1e3,
    'M': 1e6,
}

# 給變數對應單位
unit_symbol = {
    'P': 'W',
    'U': 'V',
    'I': 'A',
}

def random_value():
    """隨機產生一個數值，可能包含正負號、小數、單位前綴"""
    value = round(random.uniform(-1000, 1000), 2)
    prefix = random.choice(list(unit_prefixes.keys()))
    base = abs(value) * (1 / unit_prefixes[prefix])
    formatted = f"{'-' if value < 0 else ''}{base:.2f}".rstrip('0').rstrip('.')
    return f"{formatted}{prefix}", value

def random_positive_value():
    """隨機產生一個正值數字與字串（含單位）"""
    value = round(random.uniform(0.01, 1000.0), 2)
    prefix = random.choice(list(unit_prefixes.keys()))
    base = value / unit_prefixes[prefix]
    formatted = f"{base:.2f}".rstrip('0').rstrip('.')
    return f"{formatted}{prefix}", value

def generate_expression():
    """隨機挑兩個變數填入數值，第三個留空給使用者算"""
    variables = ['P', 'U', 'I']
    while True:  # 保證合理才 break
        random.shuffle(variables)
        a, b, c = variables
        val_a_str, val_a = random_positive_value()
        val_b_str, val_b = random_positive_value()

        values = {a: val_a, b: val_b}

        try:
            # 嘗試推導 c 的值
            if c == 'P':
                val_c = values['U'] * values['I']
            elif c == 'U':
                if values['I'] == 0:
                    continue  # ❌ 除以 0，不合理
                val_c = values['P'] / values['I']
            elif c == 'I':
                if values['U'] == 0:
                    continue  # ❌ 除以 0，不合理
                val_c = values['P'] / values['U']
        except ZeroDivisionError:
            continue  # ❌ 發生錯誤，重新來

        # 若合理就結束
        break

    line = f"The measurement shows {a}={val_a_str}{unit_symbol[a]} and {b}={val_b_str}{unit_symbol[b]}. What is the value of {c}?"
    return line, c, val_c


def generate_testcases(filename_in="pos1.in", filename_out="pos1.ans", T=10):
    with open(filename_in, "w") as fin, open(filename_out, "w") as fout:
        fin.write(f"{T}\n")
        for case in range(1, T+1):
            expr, unknown, result = generate_expression()
            fin.write(expr + "\n")
            fout.write(f"Problem #{case}\n")
            fout.write(f"{unknown}={result:.2f}{unit_symbol[unknown]}\n\n")

if __name__ == "__main__":
    generate_testcases()
