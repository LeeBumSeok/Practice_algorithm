import math

a = int(input())
q = int(math.sqrt(a))

if q**2 < a:
    print(q + 1)
else:
    print(q)
