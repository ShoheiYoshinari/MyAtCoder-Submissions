N, M, Q = map(int, input().split())
querry = []

for i in range(Q):
    querry.append(list(map(int, input().split())))

users_all = [False for _ in range(N + 1)]
users = [set() for _ in range(N + 1)]

for j in querry:
    if j[0] == 1:
        users[j[1]].add(j[2])
    elif j[0] == 2:
        users_all[j[1]] = True
    elif j[0] == 3:
        if users_all[j[1]]:
            print("Yes")
        elif j[2] in users[j[1]]:
            print("Yes")
        else:
            print("No")