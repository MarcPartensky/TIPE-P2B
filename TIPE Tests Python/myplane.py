class Plane:
    def __init__(self, offset=[0, 0], zoom=[1e-2, 1e-2]):
        """Create a plane using its offset and zoom."""
        self.offset = offset
        self.zoom = zoom

    def zoomIn(self, factor=1.1):
        """Zoom in using a factor."""
        self.zoom *= factor

    def zoomOut(self, factor=0.9):
        """Zoom out using a factor."""
        self.zoom *= factor

    def getToScreen(self, position):
        """Convert the coordinates in plane into pixels fiducials."""
        x = position[0] * self.zoom + self.offset[0]
        y = -position[1] * self.zoom + self.offset[1]
        return [x, y]

    def getFromScreen(self, position):
        """Convert the coordinates in pixels into plane fiducials."""
        x = (position[0] - self.offset[0]) / self.zoom
        y = (-position[1] - self.offset[1]) / self.zoom
        return [x, y]
