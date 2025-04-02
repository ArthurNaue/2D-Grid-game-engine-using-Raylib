# 2D Grid game engine made in C using Raylib  

## How to setup:  

[demonstration video.webm](https://github.com/user-attachments/assets/e694d024-9129-4180-bb46-e56409f1e5ef)  
 
### RAYLIB

Any information on how to setup Raylib can be found in the Raylib wiki: https://github.com/raysan5/raylib/wiki  

![image](https://github.com/user-attachments/assets/70357d5f-af3f-4687-84d1-11e1d46e8233)

### GAME ENGINE

To change the map you need to open the "main.c" file and alter the "iMapSize" variables, you can choose diferent sizes for each axis, to alter the size of the grid just change the "iGridSize' variable  
**SIDE NOTE: as for the moment I have not yet implemented a way to change map and grid size directly from the engine engine, this needs to be done in the code and re-compiled everytime its changed**

There are 3 different screens in the game engine  
  
**TITLE  
GAMEPLAY  
MAPCREATION**  

By default the engine starts at the TITLE screen, press M to go to the MAPCREATION screen.    
**SIDE NOTE: if you try to press space and play it wont work because there is no created map**  
  
In the MAPCREATION screen you can create a map by clicking the squares, to save the map press S and if you got a valid map with only 1 player it will save and you can play it at the GAMEPLAY screen, to clear the MAPCREATION screen press C
