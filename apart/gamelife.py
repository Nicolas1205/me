import pygame
import numpy as np
import time pygame.init()

width , height = 1000, 1000

screen = pygame.display.set_mode((width, height))

bg = 25 , 25 , 25
screen.fill(bg)

celdy , celdx  = 25 , 25

swidth = width / celdy
sheight = height / celdx


gameState = np.zeros((celdx , celdy))

print("Introduce how many being there in the beging")
how = int(input())

for i in range(0 , how):
    print("X , Y Positions of life:" , i)
    cx = int(input())
    cy = int(input())
    gameState[cx , cy] = 1; 


while True:
    
    newgameState = np.copy(gameState)
    
    screen.fill(bg)
    
    time.sleep(0.2)

    for x in range(0 , celdx):
        for y in range(0 , celdy):
            
            
            v = gameState[(x-1)%nX,(y-1)%nY] + gameState[(x)%nX,(y-1)%nY] + \
                        gameState[(x+1)%nX,(y-1)%nY] + gameState[(x-1)%nX,(y)%nY] + \
                        gameState[(x+1)%nX,(y)%nY] + gameState[(x-1)%nX,(y+1)%nY] + \
                         gameState[(x)%nX,(y+1)%nY] + gameState[(x+1)%nX,(y+1)%nY]
                        
            if gameState[x , y] == 0 and v == 3:
                newgameSTate[x,  y] = 1
            if gameState[x,y] == 1 and ( v  < 2 or  v > 3):
                newgameState[x,y] = 0;

            
            poly = [ ((x) *  swidth, y * sheight),
                     ((x+1) * swidth, y * sheight),
                     ((x+1) * swidth, (y+1) * sheight),
                     ((x) * swidth , (y+1) * sheight)]

            if newgameState[x,y] == 0:
                pygame.draw.polygon(screen , (128 , 128 , 128) , poly ,1)  
            else:
                pygame.draw.polygon(screen , (255 , 255 , 255) , poly ,0)  


            
    pygame.display.flip()
    


