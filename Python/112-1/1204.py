import turtle

win = turtle.Screen()
kun = turtle.Turtle()

for i in range(10):
    kun.forward(150)
    kun.right(90)
    kun.back(150)
    kun.right(45)

win.exitonclick()
