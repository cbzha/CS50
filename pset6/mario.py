from cs50 import get_int

while True:
    height = get_int("whats the height of the pyramid\n")
    if height < 1 or height > 8:
        print("height must be between 1 and 8, inclusive")
    else:
        break

for i in range(height):
    for m in range(height - i - 1):
        print(" ", end='')
    for j in range(i + 1):
        print("#", end='')
    print("  ", end='')
    for k in range(i + 1):
        print("#", end='')
    print("")