# Recursive logic to solve tower of hanoi problem
def tower_of_hanoi(number, source, temporary, destination):
    if number == 1:
        print("Move disk 1 from", source, "to", destination)
        return
    tower_of_hanoi(n-1, source, temporary, destination)
    print("Move disk", n, "from", source, "to", destination)
    tower_of_hanoi(n-1, temporary, destination, source)

# 1. Shift N-1 disks to B using C as a temporary rod.
# 2. Shift the last disk to C.
# 3. Now use A as a temporary rod and shift all the disks from B to C.

n = int(input("Enter the number of disks"))
tower_of_hanoi(n, 'A', 'B', 'C')
# A is the source, C is the destination
        
