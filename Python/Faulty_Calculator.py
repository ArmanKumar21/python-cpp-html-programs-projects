print("enter the first number")
num1=int(input())
print("enter the second number")
num2=int(input())
print("what do you want to perform?\n'+'for addition\n'-' for subtraction\n'*' for multiplication\n'/' for division")
operator=input("enter operator:")
if num1==56 and num2==9 and operator=='+':
    print("77")
elif operator=='+':
    print(num1+num2)
elif num1==45 and num2==3 and operator=='*':
    print("555")
elif operator=='*':
    print(num1*num2)
elif num1==56 and num2==6 and operator=='/':
    print("4")
elif operator=='/':
    print(num1/num2)
elif operator=='-':
    print(num1-num2)   
