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

        while (playerY == 239)
        {
            //don't change position

            //erase old player
            LCD.SetFontColor(BLACK);
            //REPLACE THIS WITH THE CHARACTER ART
            LCD.FillRectangle(playerX, playerY, 12, 12);

            if (Keyboard.isPressed(KEY_W))
            {
                //change y position to go up
                playerY = playerY + 1;
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

            //change y position to go up
            playerY = playerY + 1;

            //draw player
            LCD.SetFontColor(WHITE);
            //REPLACE THIS WITH THE CHARACTER ART
            LCD.FillRectangle(playerX, playerY, 12, 12);
            Sleep(.1);

        }

        while (playerY == 0)
        {
            //erase old player
            LCD.SetFontColor(BLACK);
            //REPLACE THIS WITH THE CHARACTER ART
            LCD.FillRectangle(playerX, playerY, 12, 12);

            //don't change position

            if (!Keyboard.isPressed(KEY_W))
            {
                //change y position to go up
                playerY = playerY - 1;
            }

            //erase old player
            LCD.SetFontColor(WHITE);
            //REPLACE THIS WITH THE CHARACTER ART
            LCD.FillRectangle(playerX, playerY, 12, 12);
        }
    }

    /*--- END OF PLAYER LOGIC-----*/
    /*NOTICE THIS COMENT RAAAH*/
}



int main()
{
    LevelFunction();
}