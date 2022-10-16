password="prabirghosh"
n=3
while(n>0):
    a=input("Enter the password:")
    n-=1
    if a==password:
        print("you have successfully logged in.")
        break
    else:
        print("Please try again.\n you have",n,"turns left")
    if n==0:
        print("you have been denied access.") 
