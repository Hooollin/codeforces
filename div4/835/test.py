import random

def tree_generator(n):
    rev = []

    now, nxt, need = 1, 2, n - 1
    while need > 0:
        rev.append([now, nxt, random.randint(1, 10)])
        if random.randint(1, 10) <= 5:
            now = random.randint(now + 1, nxt)
        nxt += 1
        need -= 1

    return rev



f = open("in", 'w')

n, T = 3, 10
f.write("%d\n" % T)


for i in range(0, T):
    f.write("%d %d %d\n" % (n, 1, n - 1))
    edges = tree_generator(n)

    for edge in edges:
        f.write("%d %d %d\n" % (edge[0], edge[1], edge[2]))

f.close()
