#include <stdio.h>
#include <stdlib.h>
#include "include/raylib.h"

//GAME SCREENS
typedef enum eGameScreen { LOGO = 0, TITLE, GAMEPLAY, GAMEOVER} eGameScreen;

//GAME MAP
int aMap[] ={
	     3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 0, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
             3, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
             3, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
             3, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
             3, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
             3, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
             3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
             3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
             3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
             3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
             3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
             3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
             3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
             3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
             3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
             3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
             3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
             3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
             3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
             3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
             3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
             3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
             3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
             3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
             3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
             3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
             3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
             3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
             3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
             3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
             3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
             3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
             3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
             3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
             3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
             3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
             3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 0, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3
	    };	

//VECTOR TO MAP ARRAY INDEX FUNCTIONS 
int check_true_x_position(int iAMapPosition) {
	int iTruePosition = (iAMapPosition % 37) * 16;
	
	return iTruePosition;
}
int check_true_y_position(int iAMapPosition) {
	int iTruePosition = (iAMapPosition / 37) * 16;

	return iTruePosition;
}


//MAIN PROGRAM FUNCTION
int main(void)
{

//------------------------------------\\\WINDOW\\\----------------------------------------//

    //WINDOW PARAMETERS
    const int iScreenWidth = 592;
    const int iScreenHeight = 592;

    //WINDOW INITIALIZATION
    InitWindow(iScreenWidth, iScreenHeight, "RAYLIB");

    //WINDOW CHOSEN
    eGameScreen eCurrentScreen = TITLE;

    //SET WINDOW FPS
    SetTargetFPS(60);                    

//------------------------------------\\\WINDOW\\\----------------------------------------//

//------------------------------------\\\GAME LOGIC\\\------------------------------------//

    int iPlayerPos = 0;

    //GAME LOOP FUNCTION
    while (!WindowShouldClose())    
    {
	//VERIFY CURRENT SCREEN
        switch (eCurrentScreen)
        {
            case TITLE:
            {
                if (IsKeyPressed(KEY_SPACE) || IsGestureDetected(GESTURE_TAP)){eCurrentScreen = GAMEPLAY;}
            }break;
            case GAMEPLAY:
            {

//------------------------------------///PLAYER MOVEMENT///------------------------------//

		if (IsKeyPressed(KEY_W))
		{
			int iNewPlayerPos = iPlayerPos - 37;
			int iNewPosition = aMap[iNewPlayerPos];
			if(iNewPlayerPos < 0){iNewPlayerPos += 1369;}
			switch(iNewPosition)
			{
				case 0:
					{
						aMap[iPlayerPos] = 0;
						aMap[iNewPlayerPos] = 1;
					} break;
				case 2:{eCurrentScreen = GAMEOVER;} break;
			}
		}else if (IsKeyPressed(KEY_A))
		{
			int iNewPlayerPos = iPlayerPos - 1;
			int iNewPosition = aMap[iNewPlayerPos];
			if(iNewPlayerPos % 37 == 36 || iNewPlayerPos < 0){iNewPlayerPos += 37;}	
			switch(iNewPosition)
			{
				case 0:
					{
						aMap[iPlayerPos] = 0;
						aMap[iNewPlayerPos] = 1;
					} break;
				case 2:{eCurrentScreen = GAMEOVER;} break;
			}
		}else if (IsKeyPressed(KEY_S))
		{
			int iNewPlayerPos = iPlayerPos + 37;
			int iNewPosition = aMap[iNewPlayerPos];
			if(iNewPlayerPos >= 1369){iNewPlayerPos -= 1369;}
			switch(iNewPosition)
			{
				case 0:
					{
						aMap[iPlayerPos] = 0;
						aMap[iNewPlayerPos] = 1;
					} break;
				case 2:{eCurrentScreen = GAMEOVER;} break;
			}
		}else if (IsKeyPressed(KEY_D))
		{
			int iNewPlayerPos = iPlayerPos + 1;
			int iNewPosition = aMap[iNewPlayerPos];
			if(iNewPlayerPos % 37 == 0){iNewPlayerPos -= 37;}
			switch(iNewPosition)
			{
				case 0:
					{
						aMap[iPlayerPos] = 0;
						aMap[iNewPlayerPos] = 1;
					} break;
				case 2:{eCurrentScreen = GAMEOVER;} break;
			}
		}

//------------------------------------///PLAYER MOVEMENT///------------------------------//
            
	    }break;
            default: break;
	}

//------------------------------------\\\GAME LOGIC\\\------------------------------------//

//------------------------------------\\\DRAW\\\----------------------------------------//

	BeginDrawing();

            ClearBackground(RAYWHITE);

            switch(eCurrentScreen)
            {
                case TITLE:
                {
		    DrawRectangle(0, 0, iScreenHeight, iScreenWidth, BLACK);
                    DrawRectangle(200, 260, 200, 100, WHITE);
                    DrawText("TESTE RAYLIB", 220, 300, 20, BLACK);
                } break;

//------------------------------------///MAIN GAME///------------------------------//

                case GAMEPLAY:
       		{

		    for(int i = 0; i < 1369; i++) {
			    
			switch(aMap[i])
			    {
			    case 1:
				{
					iPlayerPos = i;
					int aTrueSquarePosition[] = {check_true_x_position(i), check_true_y_position(i)};
					DrawRectangle(aTrueSquarePosition[0], aTrueSquarePosition[1], 16, 16, GREEN);
				} break;			
			    case 2:
			    	{
		            		int aTrueSquarePosition[] = {check_true_x_position(i), check_true_y_position(i)}; 
		    			DrawRectangle(aTrueSquarePosition[0], aTrueSquarePosition[1], 16, 16, RED);
			    	} break;
			    
			    case 3:
				{
		            		int aTrueSquarePosition[] = {check_true_x_position(i), check_true_y_position(i)}; 
					DrawRectangle(aTrueSquarePosition[0], aTrueSquarePosition[1], 16, 16, BLUE);
				} break;
			    default: break;
			    }
		    }
		    //DRAW MAP LINES 
		    int iLines = 0;
		    for (int i = 0; i < 37; i++) {
			DrawLine(0, iLines, iScreenWidth, iLines, BLACK);
		    	DrawLine(iLines, 0, iLines, iScreenHeight, BLACK);
		        iLines = iLines + 16;	
		    }
                } break;

//------------------------------------///MAIN GAME///------------------------------//
	    	
		case GAMEOVER:
	    	{
		    DrawRectangle(0, 0, iScreenHeight, iScreenWidth, BLACK);
                    DrawRectangle(200, 260, 200, 100, WHITE);
                    DrawText("GAME OVER", 220, 300, 20, BLACK);
		} break;
                default: break;
            }
        EndDrawing();
    }

//------------------------------------\\\DRAW\\\----------------------------------------//

    //CLOSE THE GAME
    CloseWindow();        
    return 0;
}
