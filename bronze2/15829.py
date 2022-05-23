from pyrsistent import m


L = int(input())
str = input()

result = 0

for i in range(len(str)):
    result += (ord(str[i]) - 97 + 1) * (31 ** i)

print(result % 1234567891)
