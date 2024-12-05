import math
d = 4 # 4
dprime = d-3
t = 16 # 16

n = t*(2+d)
m = 0
halfT = int(t/2)
o = min(dprime + halfT,d)
m = int(t + t*d + dprime*halfT + o*halfT + halfT*(halfT - 1)/2 + halfT*halfT)

print(f"{n} {m}")
M = 0
for i in range(0,t-1):
    print(f"{i} {i+1}")
    M = M+1

print(f"0 {t-1}")
M = M+1

for i in range(0,t):
    for j in range(0,d):
        print(f"{i} {2*t+i*d+j}")
        M = M+1

for i in range(0,halfT):
    for j in range(i+1,halfT):
        print(f"{i+t} {j+t}")
        M = M+1

for i in range(0,halfT):
    for j in range(halfT,t):
        print(f"{i+t} {j+t}")
        M = M+1

for i in range(0, halfT):
    for j in range(0, dprime):
        print(f"{i+t} {2*t+i*d+j}")
        M = M+1

for i in range(halfT,t):
    for j in range(0,o):
        print(f"{i+t} {2*t+i*d+j}")
        M = M+1

if M==m:
    print("===========================\nGood")
else:
    print(f"===========================\nBad: M = {M}, m={m}\n")
