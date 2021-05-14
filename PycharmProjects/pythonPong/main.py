from turtle import Turtle, Screen
from paddle import Paddle
from ball import Ball
import time

screen = Screen()
screen.bgcolor('black')
screen.setup(width = 800, height = 600)
screen.title('Pong')
screen.tracer(0)
from scoreboard import Scoreboard

right_paddle = Paddle((350, 0))
left_paddle = Paddle((-350, 0))
ball=Ball()
scoreboard = Scoreboard()

screen.listen()
screen.onkey(right_paddle.go_up, 'Up')
screen.onkey(right_paddle.go_down, 'Down')
screen.onkey(left_paddle.go_up, 'w')
screen.onkey(left_paddle.go_down, 's')

game_is_on = True
while game_is_on:
    time.sleep(ball.move_speed)
    screen.update()
    ball.move()

    #if collision w/ wall
    if ball.ycor() > 280 or ball.ycor()<-280:
        ball.bounce()

    #if collision w/ paddle
    if ball.distance(right_paddle) < 50 and ball.xcor()>320 or ball.distance(left_paddle) < 50 and ball.xcor()<-320:
        # ball.increase_speed()
        ball.reverse()

    if ball.xcor() > 380:
        ball.reset_position()
        scoreboard.l_point()

    if ball.xcor()<-380:
        ball.reset_position()
        scoreboard.r_point()

screen.exitonclick()