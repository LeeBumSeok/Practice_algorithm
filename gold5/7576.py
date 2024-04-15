import sys
from collections import deque
from pprint import pprint

input = sys.stdin.readline

m, n = map(int, input().split())

graph = deque()
for _ in range(n):
    graph.append(list(map(int, input().split())))

all = False
for i in range(n):
    for j in range(m):
        if graph[i][j] == 0:
            all = True

if not all:
    print(0)
    exit()

q = deque()
for i in range(n):
    for j in range(m):
        if graph[i][j] == 1:
            q.append((i, j))

dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]

answer = 0
while q:
    for _ in range(len(q)):
        x, y = q.popleft()

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if 0 <= nx < n and 0 <= ny < m and graph[nx][ny] == 0:
                graph[nx][ny] = 1
                q.append((nx, ny))

    answer += 1

all = False
for i in range(n):
    for j in range(m):
        if graph[i][j] == 0:
            all = True

if all:
    print(-1)
    exit()

print(answer - 1)