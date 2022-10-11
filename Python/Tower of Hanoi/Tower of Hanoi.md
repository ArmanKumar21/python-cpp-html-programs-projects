# Tower of Hanoi

This is a very popular puzzle. There are 3 rods A, B, C. The goal is to move the stack of disks from A to C while following the rules below:

- Only one disk can be moved at a time and it has to be the upper disk in the stack.
- Bigger disk should not be placed on top of smaller disc.

For a N disks, to move from A to C,

1. Shift N-1 disks to B using C as a temporary rod.
2. Shift the last disk to C.
3. Now use A as a temporary rod and shift all the disks from B to C.
