import os
import itertools
from settings import *
from hand import *
import ctypes
import sys
import pygame
from pygame.font import Font  # Add this import statement

# Change to the directory where the script is located
script_dir = os.path.dirname(os.path.abspath(__file__))
os.chdir(script_dir)

GAME_FONT = 'graphics/fonts/pixelatedDisplay.ttf'

# For windows computer
# ctypes.windll.user32.SetProcessDPIAware()

# Initialize game class
class Game:
    def __init__(self):
        # general setup
        pygame.init()
        self.screen = pygame.display.set_mode((WIDTH, HEIGHT))
        pygame.display.set_caption(TITLE_STRING)
        self.clock = pygame.time.Clock()
        self.hand = Hand()  # Initialize the hand attribute
        self.font = Font(GAME_FONT, 36)
        
    # run the program
    def run(self):
        self.start_time = pygame.time.get_ticks()
        mouse_down = False
        while True:
            # handle quit operation
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    pygame.quit()
                    sys.exit()
                if event.type == pygame.MOUSEBUTTONDOWN:
                    if event.button == 1:
                        mouse_down = True
                if event.type == pygame.MOUSEBUTTONUP:
                    if event.button == 1:
                        if mouse_down:
                            mouse_down = False
                            # Don't create a new hand here
                            # self.hand = Hand()

            # time variables
            self.delta_time = (pygame.time.get_ticks() - self.start_time) / 1000
            self.start_time = pygame.time.get_ticks()
            pygame.display.update()
            self.screen.fill(BG_COLOR)

            self.hand.update()
            self.clock.tick(FPS)

# Call the game 
if __name__ == '__main__':
    game = Game()
    game.run()
