from geometry import Circle

import random


class Sand(Circle):

    def __init__(self, *args, mass=None, friction=0.1, elasticity=1, **kwargs):
        """Create a sand grain using its circle and optional mass, if the mass
        isn't given, the mass is set to the area value."""
        super().__init__(*args, **kwargs)
        self.mass = mass
        self.friction = friction
        self.elasticity = elasticity


if __name__ == "__main__":
    from mywindow import Window
    window = Window()
    radiusmax = min(window.size)/2
    sand = Sand.random(xmin=radiusmax, xmax=window.w-radiusmax,
                       ymin=radiusmax, ymax=window.h-radiusmax,
                       radiusmax=radiusmax, filling=True)
    while window.open:
        window.check()
        sand.show(window)
        window.flip()
