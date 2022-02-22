import cs50

height = cs50.get_int("How tall do you want it?: ")

for i in range(height):
    print((height - i) * " " + i * "#" + "# #" + i * "#")