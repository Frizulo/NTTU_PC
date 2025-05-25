import sys

def main():
    input_lines = sys.stdin.read().strip().split('\n')
    idx = 0
    while idx < len(input_lines):
        if input_lines[idx].strip() == '':
            idx += 1
            continue
        n = int(input_lines[idx].strip())
        idx += 1
        if n == 0:
            break
        students = []
        for _ in range(n):
            line = input_lines[idx].strip().split()
            idx += 1
            name = line[0]
            C, E, M = map(int, line[1:])
            total = C + E + M
            students.append((name, C, E, M, total))
        
        # 排序：總分高到低，若相同依姓名字典序升冪
        students.sort(key=lambda x: (-x[4], x[0]))
        
        rank = 1
        prev = -1
        same = 0
        for i, s in enumerate(students):
            if s[4] == prev:
                same += 1
            else:
                rank += same
                same = 1
                prev = s[4]
            print(rank, s[0], s[4], s[1], s[2], s[3])
        print()

if __name__ == "__main__":
    main()
