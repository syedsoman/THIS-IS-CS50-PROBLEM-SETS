# left pyramid for CS50

while True:
    try:
        h = int(input("Height: "))
        if h >= 1 and h <= 8:
            break
    except:
        pass

for i in range(1, h + 1):
    spaces = h - i
    blocks = i
    print(" " * spaces + "#" * blocks)
