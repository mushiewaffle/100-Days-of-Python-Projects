from turtle import Turtle
STARTING_POSITIONS = [(0,0), (-20,0), (-40, 0)]
UP, DOWN, LEFT, RIGHT = 90, 270, 180, 0
MOVE_DISTANCE = 20

class Snake:
    def __init__(self):

        self.segments = []
        self.create_snake()
        self.head = self.segments[0]
        self.tail = self.segments[-1]

    def create_snake(self):
        for pos in STARTING_POSITIONS:
            self.add_segment(pos)

    def move(self):
        for seg in range(len(self.segments) - 1, 0, -1):  # goes up to 0 exclusive of 0
            new_coord = (self.segments[seg - 1].xcor(), self.segments[seg - 1].ycor())
            self.segments[seg].goto(new_coord)
        self.head.forward(MOVE_DISTANCE)

    def extend(self):
        self.add_segment(self.tail.position())

    def add_segment(self, pos):
        body_part = Turtle(shape='square')
        body_part.color('white')
        body_part.penup()
        body_part.goto(pos)
        self.segments.append(body_part)

    def up(self):
        if self.head.heading() != DOWN:
            self.head.setheading(UP)

    def down(self):
        if self.head.heading() != UP:
            self.head.setheading(DOWN)

    def left(self):
        if self.head.heading() != RIGHT:
            self.head.setheading(LEFT)

    def right(self):
        if self.head.heading() != LEFT:
            self.head.setheading(RIGHT)
