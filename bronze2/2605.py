n = int(input())
draw_list = list(map(int, input().split()))
line = list()

for i in range(n):
    line.insert(i - draw_list[i], i + 1)

print(*line)
