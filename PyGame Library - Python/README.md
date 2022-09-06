# 1. Installling PyGame
```
pip install pygame
```

# Creating the First game window
```
# Initialize pygame module
pygame.init()

# Create the screen and pass the tuple of (width, height) into the method
screen = pygame.display.set_mode((800, 600))  # In pixels

# To avoid closing the screen immediately after running
# If we use the infinite loop only, we should close the task running from the task manager
running = True

# everything happening in the screen is called an event
# So, we will loop through all happened events. In case of the close event, the screen will be closed
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False
```

# 2. Changing the Title, Logo and Background Color
```
# Title and Icon
pygame.display.set_caption("Space Invaders")  # Title
icon = pygame.image.load('img.png')
pygame.display.set_icon(icon)
```
### For background, add its code inside the while loop(Game loop) as we want it to be changed automatically with each event
```
    # Change the background of the screen
    screen.fill((0, 0, 0))  # RGB(The color dimensions)
    
    # Use (update) method to display the color in each event automatically
    pygame.display.update()
```

# 3. Adding Images into Our Space Invader Game
