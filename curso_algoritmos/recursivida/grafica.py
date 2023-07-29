import turtle
from random import seed
from random import random

seed(1)

myTurtle = turtle.Turtle()
myWin = turtle.Screen()

def draw(myTurtle, length):
  ran = random()

  if length > 0:
		myTurtle.forward(length)
		if ran < 0.10:
			myTurtle.pencolor('#006699')
		if ran < 0.25:
			myTurtle.pencolor('#1a237e')
		if ran > 0.25:
			myTurtle.right(length*ran+10)
		if ran > 0.5:
			myTurtle.left(length*ran+10)
		if ran > 0.75:
			myTurtle.circle(length*ran+10, 100)

		draw(myTurtle, length*ran+10)

draw(myTurtle, 100)
myWin.exitonclick()