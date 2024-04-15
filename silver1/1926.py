import sys
from collections import deque
from pprint import pprint

input = sys.stdin.readline

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

            if 0 <= nx < n and 0 <= ny < m and graph[nx][ny] == 1:
                q.append((nx,  ny))
                graph[nx][ny] = 2
                cnt += 1
    
    return cnt


n, m = map(int, input().split())

graph = [[0 for _ in range(m)] for _ in range(n)]

for i in range(n):
    paint = list(map(int, input().split()))
    for j in range(len(paint)):
        graph[i][j] = paint[j]

answer = []

for i in range(n):
    for j in range(m):
        if graph[i][j] == 1:
            answer.append(bfs(i, j))

print(len(answer))
if len(answer) == 0:
    print(0)
else:
    print(max(answer))