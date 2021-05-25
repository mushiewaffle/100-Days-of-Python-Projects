import turtle as t
import random

screen = t.Screen()
screen.setup(width = 500, height = 400)

colors = ['red', 'orange', 'yellow', 'green', 'purple']


turtles = []
def create_turtles():
    for color in colors:
        new_turtle = t.Turtle(shape='turtle')
        new_turtle.color(color)
        turtles.append(new_turtle)

def move_all_to_start():
    for i, turtle in enumerate(turtles):
        turtle.penup()
        turtle.goto(x=-230, y = i*80-180)

def move_all_turtles(user_bet):
    for turtle in turtles:
        turtle.forward(random.randint(0,10))
        if turtle.pos()[0]>200:
            print(f'{turtle.pencolor()} turtle wins!')
            if turtle.pencolor() == user_bet:
                print("You win! ")
            else:
                print("You loose :( ")
            return False
    return True

user_bet = screen.textinput(title="Make your bet", prompt = "Which turtle will win? ")

create_turtles()
move_all_to_start()

while move_all_turtles(user_bet):
    continue

screen.exitonclick()

