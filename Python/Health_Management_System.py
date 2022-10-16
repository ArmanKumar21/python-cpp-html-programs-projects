
def getdate():
    import datetime
    return datetime.datetime.now()
def allclear():
    f=open("harryfood.txt","w")
    g=open("rakeshfood.txt","w")
    h=open("mukeshfood.txt","w")
    i=open("harrywork.txt","w")
    j=open("rakeshwork.txt","w")
    k=open("mukeshwork.txt","w")
    f.close()
    g.close()
    h.close()
    i.close()
    j.close()
    k.close()
def getoutput(f):
    for list in f:
        print(list)
def logharryfoodf():
    a=input("Enter the food: ")
    f=open("harryfood.txt","a")
    b=str(getdate())
    f.write("%s %s\n"%(b,a))
    f.close()
def viewharryfoodf():
    f=open("harryfood.txt","r")
    getoutput(f)
    f.close()
def logharryworkf():
    a=input("Enter the exercise: ")
    f=open("harrywork.txt","a")
    b=str(getdate())
    f.write("%s %s\n"%(b,a))
    f.close()
def viewharryworkf():
    f=open("harrywork.txt","r")
    getoutput(f)
    f.close
def logmukeshworkf():
    a=input("Enter the exercise: ")
    f=open("mukeshwork.txt","a")
    b=str(getdate())
    f.write("%s %s\n"%(b,a))
    f.close()
def logmukeshfoodf():
    a=input("Enter the food: ")
    f=open("mukeshfood.txt","a")
    b=str(getdate())
    f.write("%s %s\n"%(b,a))
    f.close()
def viewmukeshworkf():
    f=open("mukeshwork.txt","r")
    getoutput(f)
    f.close()
def viewmukeshfoodf():
    f=open("mukeshfood.txt","r")
    getoutput(f)
    f.close()
def lograkeshworkf():
    f=open("rakeshwork.txt","a")
    a=input("Enter the exercise: ")
    b=str(getdate())
    f.write("%s %s\n"%(b,a))
    f.close()
def lograkeshfoodf():
    f=open("rakeshfood.txt","a")
    a=input("Enter the food: ")
    b=str(getdate())
    f.write("%s %s\n"%(b,a))
    f.close()
def viewrakeshfoodf():
    f=open("rakeshfood.txt","r")
    getoutput(f)
    f.close()
def viewrakeshworkf():
    f=open("rakeshwork.txt","r")
    getoutput(f)
    f.close()
def food():
    print("press 1 to log")
    print("press 2 to view")
    a=int(input("Enter a number"))
    if a==1:
        print("1 for harry\n2 for Mukesh\n3 for rakesh")
        b=int(input("enter a number: "))
        if b==1:
            logharryfoodf()
        elif b==2:
            logmukeshfoodf()
        elif b==3:
            lograkeshfoodf()
        else:
            print("enter valid number.")
    elif a==2:
        print("press 1 for Harry\n2 for Mukesh\n3 for rakesh")
        c=int(input("enter a number: "))
        if c==1:
            viewharryfoodf()
        elif c==2:
            viewmukeshfoodf()
        elif c==3:
            viewrakeshfoodf()
        else:
            print("Enter valid input.")
    else:
        print("Enter a valid number!")
def work():
    print("press 1 to log\npress 2 to view")
    a=int(input("enter a number: "))
    if a==1:
        print("press 1 for harry\npress 2 for mukesh\npress 3 for rakesh")
        b=int(input("Enter a number: "))
        if b==1:
            logharryworkf()
        elif b==2:
            logmukeshworkf()
        elif b==3:
            lograkeshworkf()
        else:
            print("Enter a valid number!")
    elif a==2:
        print("press 1 for harry\n2 for mukesh\n3 for rakesh")
        c=int(input())
        if c==1:
            viewharryworkf()
        elif c==2:
            viewmukeshworkf()
        elif c==3:
            viewrakeshworkf()
        else:
            print("Enter a valid number!")
    else:
        print("Enter a valid number")
print("Press 'y' to run\npress 'n' to exit")
r=input()
while (r=="y"):
    
    print("press 1 for food\npress 2 for exercise\npress 3 for all clear")
    a=int(input("Enter a number: "))

    if a==1:
        food()
    elif a==2:
        work()
    elif a==3:
        allclear()     
    else:
        print("Enter valid input!!!")
    r=input("press 'y' to proceed\npress 'n' to exit\n ")
