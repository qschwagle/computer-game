out = ""
n = 100
for y in range(n):
    for x in range(n):
        if y == 0 or y == 99 or x == 0 or x == 99:
            out += "2"
        elif x == y:
            out += "2"
        elif ((x + (y*100)) % 99) == 0:
            out += "2"
        elif x == (n/2) or y == (n/2):
            out += "2"
        else:
            out += "1"
        out += " "
print(out[:-1])

