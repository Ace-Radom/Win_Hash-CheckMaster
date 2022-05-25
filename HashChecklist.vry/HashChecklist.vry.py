import turtle
import time
myPen=turtle.Pen()
myPen.speed(0)
myPen.pencolor('red')
myPen.fillcolor('yellow')
myPen.begin_fill()
for i in range(36):
    for j in range(4):
        myPen.forward(100)
        myPen.left(90)
    myPen.right(10)
myPen.end_fill()
time.sleep(10)
