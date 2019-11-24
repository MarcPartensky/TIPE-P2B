import pygame
import mycolors


class Circle:
    def __init__(self, center,
                 radius,
                 size=1,
                 display=True,
                 material=False,
                 color=mycolors.BLACK
                 ):
        """Create a circle using its arguments:
        - tuple center : point of the circle's center
        - int   radius : circle's radius
        - int   size : thickness of the circle (1px by default)
        - bool  show : display the segment
        - bool  material : allows the object to be material"""
        self.center = center
        self.radius = radius
        self.size = size
        self.display = display
        self.material = material
        self.color = color

    def show(self, window):
        """Affiche le segment à l'écran,
        s'il ne doit pas l'être l'object sera invisible"""
        if self.display:
            pygame.draw.circle(window.screen, self.color,
                               self.center, self.radius)


class Segment:
    def __init__(self, p1,
                 p2,
                 size=1,
                 material=False,
                 color=mycolors.RED,
                 display=True
                 ):
        """Create a Segment using its arguments:
        - tuples p1, p2 : points of the segment extremities
        - int    size : thickness of the segment (1px by default)
        - bool   show : display the segment
        - bool   material : allows the object to be material"""
        self.p1 = p1
        self.p2 = p2
        self.size = size
        self.material = material # sera changer lors de l'appel de la méthode material()
        self.color = color
        self.display = display

    def show(self, window):
        """Affiche le segment à l'écran,
        s'il ne doit pas l'être l'object sera invisible"""
        if self.display:
            pygame.draw.line(window.screen, self.color, self.p1,self.p2, 1)


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
