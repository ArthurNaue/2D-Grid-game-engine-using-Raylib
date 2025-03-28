2D Grid game engine made for Windows in C using Raylib as the framework and MinGW as the compiler  

![gif](https://github.com/user-attachments/assets/56afbdc9-711d-43b1-ba50-6a7f01cd99d9)

How to setup:  

https://www.youtube.com/watch?v=HPDLTQ4J_zQ&list=LL&index=2  

Awesome video by Rudy Faile explaining how to properly download Raylib and MinGW to start a fresh Windows project  

How to compile and run:  

Step 1: Open Windows terminal in the project directory  
Step 2: Run the command ".\build" to execute the "build.bat" file, it makes an output "run.exe" file  
Step 3: Open the "run.exe" file by running the command ".\run" in the terminal or just by double clicking the file in the Windows File Explorer  

Side Note: If you know how to mess with MinGW and wish to make some compilation changes, those can be made by modifiying the "build.bat" file   

To change the map just alter the "iMapSize" variables, you can choose diferent sizes for each axis, to alter the size of the grid just change the "iGridSize' variable    

There are 3 different screens in the game  
  
TITLE  
GAMEPLAY  
MAPCREATION  

By default the game starts at the TITLE screen, press M to go to the MAPCREATION screen  
In the MAPCREATION screen you can create a map by clicking the squares, to save the map press S and if you got a valid map with only 1 player it will save and you can play it at the GAMEPLAY screen, to clear the MAPCREATION screen press C
