import mycolors
import pygame


class Window:
    def __init__(self,
                name="Window",
                size=None,
                fullscreen=False,
                call=True):
        """Create a window using its arguments:
        - name (title of the window)
        and optional arguments:
        - size (size of the window)
        - fullscreen (to set fullscreen mode directly)
        - call arguments (to build the window directly on screen)."""
        self.name = name
        self.name = name
        self.text_color = mycolors.WHITE
        self.background_color = mycolors.BLACK
        self.fullscreen = fullscreen
        if call:
            self.__call__(size)

    def buildScreen(self,size=None):
        """Set the display for the screen to
        the right mode using its optional size."""
        if not size:
            if self.fullscreen:
                size = [self.info.current_w,self.info.current_h]
            else: # size vaudra 2/3 de la taille de l'écran
                size = [2*self.info.current_w//3,2*self.info.current_h//3]
        if self.fullscreen:
            self.screen = pygame.display.set_mode(size,pygame.FULLSCREEN)
        else:
            self.screen = pygame.display.set_mode(size,pygame.RESIZABLE)

    def __call__(self, size):
        """Creates apparent window."""
        pygame.init()
        self.info = pygame.display.Info() # permet de récup des dimmension de l'écran d'ordi
        #self.font = pygame.font.SysFont(self.text_font, self.text_size)
        pygame.display.set_caption(self.name)
        self.buildScreen(size)
        self.clear()
        self.flip()
        self.open = True

    def clear(self):
        """Clear to the background color."""
        self.screen.fill(self.background_color)

    def flip(self):
        """Flip the screen of the window."""
        pygame.display.update()


if __name__=="__main__":
    import time  # This is a test
    w = Window()
    time.sleep(3)
