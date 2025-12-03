#include "FEHLCD.h"
#include "FEHUtility.h"
#include "FEHKeyboard.h"

float playerX = 10;
float playerY = 220;

void LevelFunction()
{
    /*---THIS IS THE PLAYER LOGIC---*/
    /*RAHAHAHAHAAHAHAHAHAHHAHAH DONT FORGET*/

    while(true)
    {  
        
        while (playerY == 220)
        {
            //don't change position

            //erase old player
            LCD.SetFontColor(BLACK);
            //REPLACE THIS WITH THE CHARACTER ART
            LCD.FillRectangle(playerX, playerY, 12, 12);

            if (Keyboard.isPressed(KEY_W))
            {
                //change y position to go up
                playerY = playerY - 5;
            }
    

            //draw player
            LCD.SetFontColor(WHITE);
            //REPLACE THIS WITH THE CHARACTER ART
            LCD.FillRectangle(playerX, playerY, 12, 12);
            Sleep(.1);
        }
        

        while (Keyboard.isPressed(KEY_W))
        {
            //erase old player
            LCD.SetFontColor(BLACK);
            //REPLACE THIS WITH THE CHARACTER ART
            LCD.FillRectangle(playerX, playerY, 12, 12);

            //change y position to go up AND STOP AT ROOF
            if(playerY != 10)
            {
            playerY = playerY - 5;
            }

            //draw player
            LCD.SetFontColor(WHITE);
            //REPLACE THIS WITH THE CHARACTER ART
            LCD.FillRectangle(playerX, playerY, 12, 12);
            Sleep(.1);
        }
            
        /*
        while (playerY == 10)
        {
            //erase old player
            LCD.SetFontColor(BLACK);
            //REPLACE THIS WITH THE CHARACTER ART
            LCD.FillRectangle(playerX, playerY, 12, 12);

            //don't change position

            if (!Keyboard.isPressed(KEY_W))
            {
                //change y position to go down
                playerY = playerY + 5;
            }

            //erase old player
            LCD.SetFontColor(WHITE);
            //REPLACE THIS WITH THE CHARACTER ART
            LCD.FillRectangle(playerX, playerY, 12, 12);
        }
        */

        //--- GRABITY LOGIC IMPORTANT ---
            //erase old player
            LCD.SetFontColor(BLACK);
            //REPLACE THIS WITH THE CHARACTER ART
            LCD.FillRectangle(playerX, playerY, 12, 12);

            //change y position to go down
            playerY = playerY + 5;

            //draw player
            LCD.SetFontColor(WHITE);
            //REPLACE THIS WITH THE CHARACTER ART
            LCD.FillRectangle(playerX, playerY, 12, 12);
            Sleep(.1);
    }

    /*--- END OF PLAYER LOGIC-----*/
    /*NOTICE THIS COMENT RAAAH*/
}



int main()
{
    LevelFunction();
}