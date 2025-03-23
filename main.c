#include <stdio.h>
#include <stdlib.h>
#include "include/raylib.h"

//GAME SCREENS
typedef enum eGameScreen {LOGO = 0, TITLE, GAMEPLAY, GAMEOVER} eGameScreen;

//------------------------------------///MAP SIZE LOGIC///----------------------------------------//

int iMapSize = 37;
int iGridSize = 16;

//------------------------------------///MAP SIZE LOGIC///----------------------------------------//

//GAME MAP
int aMap[] ={
	     0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
             0, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
             0, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
             0, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
             3, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
             3, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
             3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
             0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
             0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
             0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
             0, 0, 0, 0, 0, 0, 4, 4, 0, 0, 5, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
             0, 0, 0, 0, 0, 0, 4, 4, 4, 4, 5, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
             0, 0, 0, 0, 0, 0, 4, 4, 4, 4, 5, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
             0, 0, 0, 0, 0, 0, 4, 4, 4, 4, 5, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
             0, 0, 0, 0, 0, 0, 4, 4, 4, 4, 5, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
             0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
             0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
             0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
             0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
             0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
             0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
             0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
             0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
             0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
             0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
             0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
             0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
             0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
             0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
             0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
             0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
             0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
             0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
             0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
             0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
             0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
             0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
	    };	
//VECTOR TO MAP ARRAY INDEX FUNCTIONS 
int check_true_x_position(int iAMapPosition){int iTruePosition=(iAMapPosition%iMapSize)*iGridSize;return iTruePosition;}
int check_true_y_position(int iAMapPosition){int iTruePosition=(iAMapPosition/iMapSize)*iGridSize;return iTruePosition;}
//MAIN PROGRAM FUNCTION
int main(void)
{
    //UPDATE MAP TRUE SIZE
    int iMapTrueSize = iMapSize*iMapSize;

//------------------------------------\\\WINDOW\\\----------------------------------------//

    //WINDOW PARAMETERS
    const int iScreenWidth=iMapSize*iGridSize; const int iScreenHeight=iMapSize*iGridSize;
    //WINDOW INITIALIZATION
    InitWindow(iScreenWidth, iScreenHeight, "RAYLIB");
    //WINDOW CHOSEN
    eGameScreen eCurrentScreen=TITLE;
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
            case TITLE:{if(IsKeyPressed(KEY_SPACE)||IsGestureDetected(GESTURE_TAP)){eCurrentScreen=GAMEPLAY;}}break;
            case GAMEPLAY:
            {

//------------------------------------///PLAYER MOVEMENT///------------------------------//
		
		//PLAYER DIRECTION ENUM
		typedef enum eDirection {UP = 0, DOWN, LEFT, RIGHT} eDirection;

		//UPDATE MAP INDEX FOR PLAYER POSITION FUNCTION
		void update_player_position(eDirection eDirection)
		{
			int iNewPlayerPos = iPlayerPos;
			switch(eDirection)
			{
				case UP:{iNewPlayerPos-=iMapSize;}break;
				case DOWN:{iNewPlayerPos+=iMapSize;}break;
				case LEFT:{iNewPlayerPos-=1;}break;
				case RIGHT:{iNewPlayerPos+=1;}break;
				default:break;	
			}
			//BOUNDARY CHECKS
			switch(eDirection)
			{
				case UP:{if(iNewPlayerPos<0){iNewPlayerPos+=iMapTrueSize;}}break;
				case DOWN:{if(iNewPlayerPos>=iMapTrueSize){iNewPlayerPos-=iMapTrueSize;}}break;
				case LEFT:{if(iNewPlayerPos%iMapSize==iMapSize-1||iNewPlayerPos<0){iNewPlayerPos+=iMapSize;}}break;
				case RIGHT:{if(iNewPlayerPos%iMapSize==0){iNewPlayerPos-=iMapSize;}}break;
				default:break;	
			}
			int iNewPosition = aMap[iNewPlayerPos];
			switch(iNewPosition)
			{
				case 0:{aMap[iPlayerPos]=iNewPosition; aMap[iNewPlayerPos]=1;}break;
				case 2:{eCurrentScreen = GAMEOVER;}break;
			}
		}
		if(IsKeyPressed(KEY_W)){update_player_position(UP);}
		else if(IsKeyPressed(KEY_A)){update_player_position(LEFT);}
		else if(IsKeyPressed(KEY_S)){update_player_position(DOWN);}
		else if(IsKeyPressed(KEY_D)){update_player_position(RIGHT);}

//------------------------------------///PLAYER MOVEMENT///------------------------------//
            
	    }break;
            default:break;
	}

//------------------------------------\\\GAME LOGIC\\\------------------------------------//

//------------------------------------\\\DRAW\\\----------------------------------------//

	//DRAW BACKGROUND COLORED RECTANGLE FUNCTION
	void draw_background(Color eColor){DrawRectangle(0, 0, iScreenHeight, iScreenWidth, eColor);}
	BeginDrawing();
            ClearBackground(RAYWHITE);
            switch(eCurrentScreen)
            {
                case TITLE:
                {
		    draw_background(BLACK);
                    DrawRectangle((iScreenHeight/2)-100, (iScreenWidth/2)-50, 200, 100, WHITE);
                    DrawText("TESTE RAYLIB", (iScreenHeight/2)-80, (iScreenWidth/2)-10, 20, BLACK);
                } break;

//------------------------------------///MAIN GAME///------------------------------//

                case GAMEPLAY:
       		{
		    for(int i=0; i<iMapTrueSize; i++) {
			switch(aMap[i])
			    {
				//DRAWING MAP INDEX SQUARE FUNCTION
			    	void draw_square(Color eColor)
				{
					int aTrueSquarePosition[] = {check_true_x_position(i), check_true_y_position(i)};
					DrawRectangle(aTrueSquarePosition[0], aTrueSquarePosition[1], iGridSize, iGridSize, eColor);	
				}
			    case 1:
				{
					//SET PLAYER POSITION TO MAP INDEX
					iPlayerPos=i;
					draw_square(GREEN);
				}break;			
			    case 2:{draw_square(RED);}break;
			    case 3:{draw_square(BLUE);}break;
			    case 4:{draw_square(YELLOW);}break;
			    case 5:{draw_square(BLACK);}break;
			    default:break;
			    }
		    }
		    //DRAW MAP LINES 
		    int iLines=0;
		    for (int i=0; i<=iMapSize-1; i++) 
		    {
			DrawLine(0, iLines, iScreenWidth, iLines, BLACK);
		    	DrawLine(iLines, 0, iLines, iScreenHeight, BLACK);
		        iLines += iGridSize;	
		    }
                }break;

//------------------------------------///MAIN GAME///------------------------------//
	    	
		case GAMEOVER:
	    	{
		    draw_background(BLACK);
                    DrawRectangle((iScreenHeight/2)-100, (iScreenWidth/2)-50, 200, 100, WHITE);
                    DrawText("GAME OVER", (iScreenHeight/2)-80, (iScreenWidth/2)- 0, 20, BLACK);
		}break;
                default:break;
            }
        EndDrawing();
    }

//------------------------------------\\\DRAW\\\----------------------------------------//
    
    //CLOSE THE GAME
    CloseWindow();
    return 0;
}
