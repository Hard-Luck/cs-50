import cs50

while true:
    height = cs50.get_int("How tall do you want it?: ")
    if height > 0:
        break

for i in range(height):
    print((height - 1 - i) * " " + i * "#" + "# #" + i * "#")