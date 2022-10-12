"""
    Calculating the perimeter of a triangle in cartesian plane
"""

import math


class Point:
    def __init__(self, x=0.0, y=0.0):
        self.__x = x
        self.__y = y

    def getx(self):
        return self.__x

    def gety(self):
        return self.__y

    def distance_from_xy(self, x, y):
        return math.hypot(abs(self.__x - x), abs(self.__y - y))

    def distance_from_point(self, point):
        return self.distance_from_xy(point.getx(), point.gety())


class Triangle:
    def __init__(self, vertice1, vertice2, vertice3):
        self.__vertices = [vertice1, vertice2, vertice3]

    def perimeter(self):
        per = 0
        for i in range(3):
            per += self.__vertices[i].distance_from_point(self.__vertices[(i + 1) % 3])
        return per


"""
    You can get user input as follows
"""
print("point 1")
x_1 = int(input("Enter the x coordinate of point 1: "))
y_1 = int(input("Enter the y coordinate of point 1: "))

print("Point 2")
x_2 = int(input("Enter the x coordinate of point 2: "))
y_2 = int(input("Enter the y coordinate of point 2: "))

print("Point 3")
x_3 = int(input("Enter the x coordinate of point 3: "))
y_3 = int(input("Enter the y coordinate of point 3: "))

triangle = Triangle(Point(x_1, y_1), Point(x_2, y_2), Point(x_3, y_3))


"""
    Or can pass values straight as follows
"""
# triangle = Triangle(Point(0, 0), Point(1, 0), Point(0, 1))
print(triangle.perimeter())


class Point:
    def __init__(self, x=0.0, y=0.0):
        self.__x = x
        self.__y = y
