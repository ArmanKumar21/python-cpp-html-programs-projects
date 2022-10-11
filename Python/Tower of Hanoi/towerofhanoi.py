# Recursive logic to solve tower of hanoi problem
def tower_of_hanoi(number, source, temporary, destination):
    if number == 1:
        print("Move disk 1 from", source, "to", destination)
        return
    tower_of_hanoi(n-1, source, temporary, destination)
    print("Move disk", n, "from", source, "to", destination)
    tower_of_hanoi(n-1, temporary, destination, source)


n = int(input("Enter the number of disks"))
tower_of_hanoi(n, 'A', 'B', 'C')
# A is the source, C is the destination
        