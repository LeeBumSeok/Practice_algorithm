def find_nearest(array, value):
    n = [abs(i - value) for i in array]
    idx = n.index(min(n))
    return array[idx]


p, f = map(int, input().split())
pump = list(map(int, input().split()))
firetruck = list(map(int, input().split()))
answer = 0

for i in range(f):
    a = find_nearest(pump, firetruck[i])
    answer += abs(a - firetruck[i])
    pump.remove(a)

print(answer)
