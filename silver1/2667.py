import sys
from collections import deque
from pprint import pprint

input = sys.stdin.readline

n = int(input())

graph = [[0 for _ in range(n)] for _ in range(n)]
for i in range(n):
    x = input()
    for j in range(n):
        graph[i][j] = int(x[j])

dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]


def bfs(x, y):
    q = deque([(x, y)])
    graph[x][y] = 2
    cnt = 1

    while q:
        x, y = q.popleft()

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if 0 <= nx < n and 0 <= ny < n and graph[nx][ny] == 1:
                cnt += 1
                q.append((nx, ny))
                graph[nx][ny] = 2

    return cnt


answer = []

for i in range(n):
    for j in range(n):
        if graph[i][j] == 1:
            answer.append(bfs(i, j))

answer.sort()
print(len(answer))
for i in answer:
    print(i)
