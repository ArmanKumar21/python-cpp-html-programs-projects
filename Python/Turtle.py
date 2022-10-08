from turtle import *
import time

speed(0)
penup()
goto(-50,0)
pendown()
color("#e0b936")
write("Use wasd or arrow kers to move")
time.sleep(1)

screen=Screen()
screen.bgcolor("#e0b936")

penup()
goto(150,1000)
pendown()

color("blue")
begin_fill()
forward(500)
right(90)
forward(2000)
right(90)
forward(500)
right(90)
forward(2000)
end_fill()

penup()
goto(-200,0)
shape("turtle")
color("green")

def goal():
    if xcor()>150:
        color("white")
        write("YOU WIN!!")
        hideturtle()

        screen.onkey(None, "Up")
        screen.onkey(None, "Down")
        screen.onkey(None, "Left")
        screen.onkey(None, "Right")
        screen.onkey(None, "w")
        screen.onkey(None, "s")
        screen.onkey(None, "d")
        screen.onkey(None, "a")

pxl=25

def w():
    setheading(90)
    forward(pxl)
    goal()
def s():
    setheading(-90)
    forward(pxl)
    goal()
def a():
    setheading(180)
    forward(pxl)
    goal()
def d():
    setheading(0)
    forward(pxl)
    goal()

screen.onkey(w, "Up")
screen.onkey(s, "Down")
screen.onkey(a, "Left")
screen.onkey(d, "Right")
screen.onkey(w, "w")
screen.onkey(s, "s")
screen.onkey(d, "d")
screen.onkey(a, "a")

screen.listen()

done()
