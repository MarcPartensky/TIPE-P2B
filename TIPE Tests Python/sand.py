from geometry import Circle

import random


class Sand:
    @classmethod
    def random(cls, b=1, **kwargs):
        """Create a random grain sand."""
        circle = Circle.random(b)
        return Sand(circle, **kwargs)

    def __init__(self, circle, mass=None, friction=0.1, elasticity=1):
        """Create a sand grain using its circle and optional mass, if the mass
        isn't given, the mass is set to the area value."""
        self.circle = circle
        self.friction = friction
        self.elasticity = elasticity

    def show(self, window):
        """Show the sand grain on the window."""
        self.circle.show(window)


if __name__ == "__main__":
    from mywindow import Window
    window = Window()
    sand = Sand.random()
    while window.open:
        window.check()
        sand.show(window)
        window.flip()
