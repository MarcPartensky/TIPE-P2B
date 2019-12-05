# coding:utf-8
import mycolors
import pygame
import random


class Circle:

    @classmethod
    def random(cls, xmin=0, xmax=1, ymin=0, ymax=1,
               radiusmin=0, radiusmax=1, **kwargs):
        """Create a randomly initialized circle."""
        center = [random.uniform(xmin, xmax), random.uniform(ymin, ymax)]
        radius = random.uniform(radiusmin, radiusmax)
        color = mycolors.random()
        return cls(center, radius, color=color, **kwargs)

    def __init__(self,
                 center,
                 radius,
                 thickness=1,
                 filling=False,
                 color=mycolors.BLACK):
        """Create a circle using its arguments:
        - tuple center : point of the circle's center
        - int   radius : circle's radius
        - int   thickness : thickness of the circle (1px by default)
        - bool  show : display the segment
        - bool  material : allows the object to be material"""
        self.center = center
        self.radius = radius
        self.thickness = thickness
        self.color = color
        self.filling = filling

    def show(self, window):
        """Show the circle on the window."""
        window.draw.circle(window.screen, self.color,
                           self.center, self.radius, 1-self.filling)

    def x():
        doc = "The x property."

        def fget(self):
            return self.center[0]

        def fset(self, value):
            self.center[0] = value
        return locals()
    x = property(**x())

    def y():
        doc = "The y property."

        def fget(self):
            return self.center[1]

        def fset(self, value):
            self.center[1] = value
        return locals()
    y = property(**y())


class Segment:
    def __init__(self,
                 p1,
                 p2,
                 thickness=1,
                 color=mycolors.RED):
        """Create a Segment using its arguments:
        - tuples p1, p2 : points of the segment extremities
        - int    thickness : thickness of the segment (1px by default)
        - bool   show : display the segment"""
        self.p1 = list(p1)
        self.p2 = list(p2)
        self.thickness = thickness
        self.color = color

    def show(self, window):
        """Show the segment on the window."""
        window.draw.line(window.screen, self.color,
                         self.p1, self.p2, self.thickness)


if __name__ == "__main__":
    from mywindow import Window
    w = Window(size=[600, 400], call=True)
    w.clear()
    c = Circle(center=[300, 200], radius=50)
    s = Segment(p1=[100, 100], p2=[500, 300], color=mycolors.RED)
    w.clear(color=mycolors.WHITE)

    while w.open:
        w.check()
        c.show(w)
        s.show(w)
        w.flip()
