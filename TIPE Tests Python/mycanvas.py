from mywindow import Window
from myplane import Plane

class Draw:
    """Act like a window but convert coordinates."""
    def __init__(self, window=None, plane=None):
        """Create a draw object using the window and optional plane."""
        if window:
            self.window = window
        else:
            self.window = Window()
        if plane:
            self.plane = plane
        else:
            self.plane = Plane(offset=[window.w/2, window.h/2],
                                zoom=min(window.size)/10)

    def circle(self, screen, color, position, radius, fill=None):
        """Draw a circle using plane coordinates."""
        position = self.plane.getToScreen(position)
        radius *= self.plane.zoom
        pygame.draw.circle(screen, color, position, radius, fill)

    def line(self, screen, color, p1, p2, width=None):
        """Draw a line using plane coordinates."""

        pygame.draw.line(screen, color, p1, p2, width)
