def is_leap(year):
    if year%4==0:
        if year%100!=0:
            pass
        elif year%100==0 and year%400==0:
            print("leap")
        else:
            print("not leap")
        print("leap")
    else:
        print("not leap")
year = int(input("Enter the year"))
is_leap(year)
