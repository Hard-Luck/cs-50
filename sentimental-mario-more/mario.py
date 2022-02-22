import cs50

height = 0
# Loop, continuing to ask for a heigh if not between 1 - 8
while True:
    height = cs50.get_int("How tall do you want it?: ")
    if 9 > height > 0:
        break

# Print the blocks
for i in range(height):
    print((height - 1 - i) * " " + i * "#" + "#  #" + i * "#")