#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

#define iMapSizeX 10
#define iMapSizeY 10
#define iGridSize 32

//GAME SCREEN ENUM
typedef enum eGameScreen {LOGO=0, TITLE, GAMEPLAY, MAPCREATION} eGameScreen;

//PLAYER DIRECTION ENUM
typedef enum eDirection {UP=0, DOWN, LEFT, RIGHT} eDirection;

//VECTOR TO MAP ARRAY INDEX FUNCTION
int check_true_position(int iAMapPosition, int bYSide)
{
	int iTruePosition;
	//VERIFY WHICH AXIS TO CALCULATE POSITION AND APPLY FORMULA TO TRUE VECTOR POSITION
	if(bYSide == 0){iTruePosition=(iAMapPosition%iMapSizeX)*iGridSize;}else{iTruePosition=(iAMapPosition%iMapSizeY)*iGridSize;}
	return iTruePosition;
}

//DRAWING MAP INDEX SQUARE FUNCTION
void draw_square(Color eColor, int iPositionX, int iPositionY){DrawRectangle(check_true_position(iPositionX, 0), check_true_position(iPositionY, 1), iGridSize, iGridSize, eColor);}

//BLUEPRINT FOR BUTTON
typedef struct sButton
{
	int iMapIndex;
	int iColorIndex;
	Rectangle rButtonColision;
}sButton;

//MAIN PROGRAM FUNCTION
int main(void)
{
//------------------------------------\\\WINDOW\\\----------------------------------------//

    	//WINDOW PARAMETERS
    	const int iScreenWidth=iMapSizeX*iGridSize, iScreenHeight=iMapSizeY*iGridSize + 100;
    	InitWindow(iScreenWidth, iScreenHeight, "2D GRID GAME ENGINE");
    	//MAKES THE GAME UNQUITABLE WITH ESC
    	SetExitKey(KEY_NULL);
    	//CREATES THE BOOL VARIABLE TO VERIFY IF GAME SHOULD CLOSE
    	int bGameLoop=1;
 	//WINDOW CHOSEN
 	eGameScreen eCurrentScreen=TITLE;
	//SET WINDOW FPS
	SetTargetFPS(60);

//------------------------------------\\\WINDOW\\\----------------------------------------//

//------------------------------------\\\GAME MAP\\\------------------------------------//
	//GAME MAP VARIABLES
	int aMap[iMapSizeY][iMapSizeX]={0}; int aMapCreation[iMapSizeY][iMapSizeX]={0};

	//CLEAR THE MAP CREATION ARRAY
	void clear_creation_map()
	{
		for(int i=0; i<iMapSizeY; i++)
		{
			for(int j=0; j<iMapSizeX; j++)
			{
				aMapCreation[i][j]=0;
			}
		}
	}

	//TURN THE GAME MAP INTO THE CREATED MAP	
	void create_map()
	{
		//VARIABLE THAT VERIFIES NUMBER OF PLAYERS IN THE MAP CREATED
		int iGreenSquareNumber=0; int iRedSquareNumber=0;

		for(int i=0; i<iMapSizeY; i++)
		{
			for(int j=0; j<iMapSizeX; j++)
			{
				if(aMapCreation[i][j]==1){iGreenSquareNumber++;}
				if(aMapCreation[i][j]==2){iRedSquareNumber++;}
			}
		}

		if(iGreenSquareNumber==1 && iRedSquareNumber==1)
		{
			for(int i=0; i<iMapSizeY; i++)
			{
				for(int j=0; j<iMapSizeX; j++)
				{
					aMap[i][j]=aMapCreation[i][j];
				}
			}
			eCurrentScreen=TITLE;
		}
	}

	void verify_if_game_is_playable()
	{
		//VARIABLE THAT VERIFIES NUMBER OF PLAYERS IN THE MAP CREATED
		int iGreenSquareNumber=0; int iRedSquareNumber=0;

		for(int i=0; i<iMapSizeY; i++)
		{
			for(int j=0; j<iMapSizeX; j++)
			{
				if(aMap[i][j]==1){iGreenSquareNumber++;}
				if(aMap[i][j]==2){iRedSquareNumber++;}
			}
		}

		if(iGreenSquareNumber==1 && iRedSquareNumber==1){eCurrentScreen=GAMEPLAY;}
	}

//------------------------------------\\\GAME MAP\\\------------------------------------//

//------------------------------------\\\GAME LOGIC\\\------------------------------------//

    //DEFINE PLAYER POSITION VARIABLE
    int iPlayerPos[2], iEnemyPos[2];

    //GAME LOOP FUNCTION
    while (bGameLoop==1)    
    {
	//VERIFY CURRENT SCREEN
        switch (eCurrentScreen)
        {
            case GAMEPLAY:
            {
//------------------------------------///ENEMY MOVEMENT///------------------------------//

            	//UPDATE MAP INDEX FOR ENEMY POSITION FUNCTION
		void update_enemy_position()
		{
			//VERIFY NEW POSITION MAP INDEX
			int iNewEnemyPos[]={iEnemyPos[0], iEnemyPos[1]};
			
			int iNewEnemyRandomPos = (rand() % 4) + 1;

			switch(iNewEnemyRandomPos)
			{
					
				case 1:{iNewEnemyPos[1]-=1;}break;
				case 2:{iNewEnemyPos[1]+=1;}break;
				case 3:{iNewEnemyPos[0]-=1;}break;
				case 4:{iNewEnemyPos[0]+=1;}break;
			}

			//BOUNDARY CHECKS
			switch(iNewEnemyRandomPos)
			{
				case 1:{if(iNewEnemyPos[1]<0){iNewEnemyPos[1]+=iMapSizeY;}}break;
				case 2:{if(iNewEnemyPos[1]>=iMapSizeY){iNewEnemyPos[1]-=iMapSizeY;}}break;
				case 3:{if(iNewEnemyPos[0]<0){iNewEnemyPos[0]+=iMapSizeX;}}break;
				case 4:{if(iNewEnemyPos[0]>=iMapSizeX){iNewEnemyPos[0]-=iMapSizeX;}}break;
				default:break;	
			}

			//VERIFY TYPE OF SQUARE IN NEW POSITION
			int iNewMapPosition=aMap[iNewEnemyPos[1]][iNewEnemyPos[0]];
			switch(iNewMapPosition)
			{
				case 0:
					{
					       aMap[iEnemyPos[1]][iEnemyPos[0]]=0;
					       iEnemyPos[0]=iNewEnemyPos[0]; iEnemyPos[1]=iNewEnemyPos[1];
					       aMap[iEnemyPos[1]][iEnemyPos[0]]=2;
					}break;
				case 1:{eCurrentScreen=TITLE;}break;
			}
		}	
		
//------------------------------------///ENEMY MOVEMENT///------------------------------//

//------------------------------------///PLAYER MOVEMENT///------------------------------//


		//UPDATE MAP INDEX FOR PLAYER POSITION FUNCTION
		void update_player_position(eDirection eDirection)
		{
			//VERIFY NEW POSITION MAP INDEX
			int iNewPlayerPos[]={iPlayerPos[0], iPlayerPos[1]};
			switch(eDirection)
			{
				case UP:{iNewPlayerPos[1]--;}break;
				case DOWN:{iNewPlayerPos[1]++;}break;
				case LEFT:{iNewPlayerPos[0]--;}break;
				case RIGHT:{iNewPlayerPos[0]++;}break;
				default:break;	
			}

			//BOUNDARY CHECKS
			switch(eDirection)
			{
				case UP:{if(iNewPlayerPos[1]<0){iNewPlayerPos[1]+=iMapSizeY;}}break;
				case DOWN:{if(iNewPlayerPos[1]>=iMapSizeY){iNewPlayerPos[1]-=iMapSizeY;}}break;
				case LEFT:{if(iNewPlayerPos[0]<0){iNewPlayerPos[0]+=iMapSizeX;}}break;
				case RIGHT:{if(iNewPlayerPos[0]>=iMapSizeX){iNewPlayerPos[0]-=iMapSizeX;}}break;
				default:break;	
			}

			//VERIFY TYPE OF SQUARE IN NEW POSITION
			int iNewMapPosition=aMap[iNewPlayerPos[1]][iNewPlayerPos[0]];
			switch(iNewMapPosition)
			{
				case 0:
					{
					       aMap[iPlayerPos[1]][iPlayerPos[0]]=0;
					       iPlayerPos[0]=iNewPlayerPos[0]; iPlayerPos[1]=iNewPlayerPos[1];
					       aMap[iPlayerPos[1]][iPlayerPos[0]]=1;
					}break;
				case 2:{eCurrentScreen=TITLE;}break;
			}
		}

		//UPDATE PLAYER POSITION BASED ON DIRECTION
		if(IsKeyPressed(KEY_W)){update_player_position(UP);update_enemy_position();}
		else if(IsKeyPressed(KEY_A)){update_player_position(LEFT); update_enemy_position();}
		else if(IsKeyPressed(KEY_S)){update_player_position(DOWN);update_enemy_position();}
		else if(IsKeyPressed(KEY_D)){update_player_position(RIGHT);update_enemy_position();}

		//VERIFY IF USER WANTS TO GO BACK TO TITLE SCREEN
		if(IsKeyPressed(KEY_ESCAPE)){eCurrentScreen = TITLE;}

//------------------------------------///PLAYER MOVEMENT///------------------------------//

	    }break;
            default:break;
	}

//------------------------------------\\\GAME LOGIC\\\------------------------------------//

//------------------------------------\\\DRAW\\\----------------------------------------//

	//DRAW BACKGROUND COLORED RECTANGLE FUNCTION
	void draw_background(Color eColor){DrawRectangle(0, 0, iScreenWidth, iScreenHeight, eColor);}

	//DRAW MAP LINES FUNCTION
	void draw_lines()
	{
	    int iLines=0;
	    for (int i=0; i<=(iMapSizeX-1); i++) 
	    {
	    	DrawLine(iLines, 0, iLines, iScreenHeight - 100, BLACK);
	        iLines+=iGridSize;	
	    }
	    iLines=0;
	    for (int i=0; i<=(iMapSizeY); i++) 
	    {
		DrawLine(0, iLines, iScreenWidth, iLines, BLACK);
	        iLines+=iGridSize;	
	    }
 	}
	

	
      	    //START TO DRAW ON SCREEN
	    BeginDrawing();
	    //SET BACKGROUND TO WHITE
            ClearBackground(RAYWHITE);

            switch(eCurrentScreen)
            {
                case TITLE:
                {
		    draw_background(BLACK);

		    //GUI BUTTONS
		    if(GuiButton((Rectangle){0, iScreenHeight-100, iScreenWidth/3, 100}, "PLAY")){verify_if_game_is_playable();}
		    if(GuiButton((Rectangle){iScreenWidth-((iScreenWidth/3)*2), iScreenHeight-100, iScreenWidth/3, 100}, "CREATE MAP")){eCurrentScreen=MAPCREATION;}
		    if(GuiButton((Rectangle){iScreenWidth-(iScreenWidth/3), iScreenHeight-100, iScreenWidth/3, 100}, "EXIT")){bGameLoop=0;}
		}break;

//------------------------------------///MAIN GAME///------------------------------//

		case GAMEPLAY:
       		{
		    //MAP DRAWING
		    for(int i=0; i<iMapSizeY; i++) 
		    {
			    for(int j=0; j<iMapSizeX; j++)
			    {
				switch(aMap[i][j])
			    	{
			    	case 1:
					{
						//SET PLAYER POSITION TO MAP INDEX
						iPlayerPos[0]=j; iPlayerPos[1]=i;
						draw_square(GREEN, iPlayerPos[0], iPlayerPos[1]);
					}break;		
				case 2:
					{
						//SET ENEMY POSITION TO MAP INDEX
						iEnemyPos[0]=j; iEnemyPos[1]=i;
						draw_square(RED, iEnemyPos[0], iEnemyPos[1]);
					}break;	
				case 3:{draw_square(PURPLE, j, i);}break;	
			    	default:break;
			    	}
			     }
		    }
		    draw_lines();

		    if(GuiButton((Rectangle){0, iScreenHeight-100, iScreenWidth, 100}, "EXIT")){eCurrentScreen=TITLE;}
	   }break;

//------------------------------------///MAIN GAME///------------------------------//
	    	
		case MAPCREATION:
		{

	            //CREATE BUTTON
		    sButton sColorButton;
  	    	    sColorButton.iMapIndex=aMapCreation[0][0]; sColorButton.iColorIndex=0; 
		    sColorButton.rButtonColision=(Rectangle){0, 0, iGridSize, iGridSize};

		    //MAP DRAWING
		    for(int i=0; i<iMapSizeY; i++) 
		    {
			    for(int j=0; j<iMapSizeX; j++)
			    {
				sColorButton.rButtonColision.x=check_true_position(j, 0); sColorButton.rButtonColision.y=check_true_position(i, 1);

				if(CheckCollisionPointRec(GetMousePosition(), sColorButton.rButtonColision))
				{
					if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
					{
						aMapCreation[i][j]++;
					       	if(aMapCreation[i][j]>=4){aMapCreation[i][j]=0;}
					}
				}

				switch(aMapCreation[i][j])
			    	{
			        case 1:{draw_square(GREEN, j, i);}break;		
			        case 2:{draw_square(RED, j, i);}break;	
				case 3:{draw_square(PURPLE, j, i);}break;	
			    	default:break;
			    	}
			    }
		    }
		    draw_lines();

		    if(GuiButton((Rectangle){0, iScreenHeight-100, iScreenWidth/3, 100}, "SAVE")){create_map();}
		    if(GuiButton((Rectangle){iScreenWidth-((iScreenWidth/3)*2), iScreenHeight-100, iScreenWidth/3, 100}, "CLEAR")){clear_creation_map();}
		    if(GuiButton((Rectangle){iScreenWidth-(iScreenWidth/3), iScreenHeight-100, iScreenWidth/3, 100}, "EXIT")){eCurrentScreen=TITLE;}
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
