import sys
from collections import deque
from pprint import pprint

input = sys.stdin.readline

n, m = map(int, input().split())

graph = deque([["#" for _ in range(m)] for _ in range(n)])
q_j = deque()
q_fire = deque()

for i in range(n):
    x = input()
    for j in range(m):
        graph[i][j] = x[j]
        if x[j] == "J":
            q_j.append((i, j))
        if x[j] == "F":
            q_fire.append((i, j))

dx = [0, 0, -1, 1]
dy = [1, -1, 0, 0]

answer = 0
while q_j:
    for i in range(len(q_fire)):
        x, y = q_fire.popleft()

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < n and 0 <= ny < m and (graph[nx][ny] == "."):
                graph[nx][ny] = "F"

                q_fire.append((nx, ny))

    for i in range(len(q_j)):
        x, y = q_j.popleft()

        if x == 0 or y == 0 or x == n - 1 or y == m - 1:
            print(answer + 1)
            exit()

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < n and 0 <= ny < m and graph[nx][ny] == ".":
                graph[nx][ny] = "#"
                q_j.append((nx, ny))
    answer += 1

print("IMPOSSIBLE")
