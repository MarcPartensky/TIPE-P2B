from myplane import Plane
from mywindow import Window

from sand import Sand

import mycolors
import math


SAND_NUMBER = 10

sand = [Sand.random(9e-1, 11e-1) for i in range(SAND_NUMBER)]


window = Window()
plane = Plane(offset=[window.w/2, window.h/2], zoom=min(window.size)/10)
angle = 0

while window.open:
    window.check()
    window.clear(mycolors.WHITE)

    angle += 0.01
    angle %= 2*math.pi

    xoffset = math.cos(angle)
    yoffset = math.sin(angle)

    for grain in sand:
        x, y = plane.getToScreen(grain.center)

        x += xoffset*plane.zoom
        y -= yoffset*plane.zoom

        grain_pixel = Sand([int(x), int(y)], radius=grain.radius*plane.zoom)
        grain_pixel.show(window)

    window.flip()
