import turtle as tt

def circle (radius , color) :
    tt.color (color)
    tt.begin_fill()
    tt.circle(radius)
    tt.end_fill()
    
tt.goto(-30,-280)
circle(300,'dark red')

tt.goto(-30,-240)
circle(260,'white')

tt.goto(-30,-200)
circle(220,'dark red')

tt.goto(-30,-160)
circle(180,'royal blue')

tt.goto(-200,75)
tt.begin_fill()
tt.color('white')

for i in range(5):
    tt.forward(340)
    tt.right(144)
tt.end_fill()
tt.hideturtle()
