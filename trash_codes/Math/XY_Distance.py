"""
    Calculates the distances between any of the two points situated on the plane.
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


x_1 = int(input("Enter the x coordinate of point 1: "))
y_1 = int(input("Enter the y coordinate of point 1: "))
x_2 = int(input("Enter the x coordinate of point 2: "))
y_2 = int(input("Enter the y coordinate of point 2: "))

point1 = Point(x_1, y_1)
point2 = Point(x_2, y_2)
print(point1.distance_from_point(point2))
