#Python program to implement Selection Sort

#Accepting the number of elements
size = int(input("Enter the number of elements: "))

#Accepting the elements
print("Enter",size,"elements: ", end="")
lt = list(map(int, input().strip().split()))[:size]

#Performing Selection Sort
for i in range(0,size-1):
    for j in range(i+1,size):
        if(lt[i]>lt[j]):
            lt[i], lt[j] = lt[j], lt[i]

#Printing the sorted elements
print("Sorted elements: ",end="")
for x in lt:
    print(x,end=" ")
