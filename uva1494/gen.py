import random

f = open('p.in','w')
t = random.randint(9,10)
f.write(str(t) + '\n')

for i in range(0,t,1):
    n = random.randint(999,1000)
    f.write(str(n) + '\n')
    for j in range(0,n,1):
        x = random.randint(0,1000)
        y = random.randint(0,1000)
        p = random.randint(10000,100000)
        f.write(str(x) + ' ' + str(y) + ' ' + str(p) + '\n')



