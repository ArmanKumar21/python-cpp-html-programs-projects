"""
Program for game of Rock Paper Scissors
"""

from random import choice
print("\n")
print("\tWELCOME TO ROCK PAPER SCISSORS !!!")
print()
game_list={"r":"Rock", "s":"Scissors", "p":"paper"}     #list of choices
computer = c = 0
player = p = 0
name=input("Enter your name: ")
print("\n")
print("SCORE: \TComputer "+str(c)+"\t"+name+" "+str(p))
run=True
while run:
    print("\n")
    command=input("Rock(r)/Paper(p)/Scissors(s) or Quit(q): ".lower())
    print("\n")
    computer_choice=choice(list(game_list))

    if command in ("r", "rock", "s", "scissors", "p", "paper"):
        command=command[0]
        print("Computer choice: "+game_list[computer_choice])
        print(name+"'s choice: "+game_list[command])

    if computer_choice==command:
        print("Tie!")

    elif command=="r":
        if computer_choice=="p":
            c+=1
            print("Computer Wins")
        else:
            p+=1
            print(name+" Wins!")

    elif command=="p":
        if computer_choice=="s":
            c+=1
            print("Computer Wins")
        else:
            p+=1
            print(name+" Wins!")

    elif command=="s":
        if computer_choice=="r":
            c+=1
            print("Computer Wins")
        else:
            p+=1
            print(name+" Wins!")

    elif command=="q" or command=="quit":
        print("Thanks for playing this game.")
        break

    else:
        print("Please enter a valid command.")

    print("\n")
    print("SCORE: \t Computer "+str(c)+"\t"+name+" "+str(p))