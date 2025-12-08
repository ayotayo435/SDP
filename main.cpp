#include "FEHLCD.h"
#include "FEHUtility.h"
#include "FEHKeyboard.h"
#include "FEHRandom.h"
#include "FEHImages.h"

//Defines constants for the SDP simulator window dimensions
#define SCREENY 239
#define SCREENX 319

//global variables
float playerX = 110;
float playerY = 219;

//Seima: Creates variables for the coordinates of the portals.
float portalX = 300;

float portalTopY = 0;
float portalBottomY = SCREENY / 2.0;

//Mateo: I've written a class to help keep all the menu logic organized
class menu {
    private:
        //Mateo: main doesn't need to know about these
        
        //Mateo: This function will print the credits to the screen
        void ViewCredits() {
            //Andriy: Draws background
            FEHImage Background;
            Background.Open("background.png");
            Background.Draw(0,0);
            LCD.WriteLine("CREDITS:");
            //Mateo: I forgor your guy's last names
            LCD.WriteLine("Developers: Mateo Polt, Seima Taniguchi, Andriy Misyura");

            // Mateo: drawing the back button
            LCD.DrawRectangle(10, 200, 100, 30);
            LCD.WriteAt("Back", 35, 208);

            //Mateo: this here will check if the back button is pressed
            float x, y;
            while (true)
            {
                if (LCD.Touch(&x, &y)) 
                {
                    if (x > 10 && x < 110 && y > 200 && y < 230)
                    {
                        break; 
                    }
                }
            }
        }

        // Mateo: this function will print the instructions to the screen
        void ViewInstructions() {
            //Andriy: Draws background
            FEHImage Background;
            Background.Open("background.png");
            Background.Draw(0,0);
            LCD.WriteLine("INSTRUCTIONS:");
            LCD.WriteLine("Tap screen to jump.");
            LCD.WriteLine("Avoid the obstacles.");

             // Mateo: drawing the back button
            LCD.DrawRectangle(10, 200, 100, 30);
            LCD.WriteAt("Back", 35, 208);

            //Mateo: this here will check if the back button is pressed
            float x, y;
            while (true)
            {
                if (LCD.Touch(&x, &y)) 
                {
                    if (x > 10 && x < 110 && y > 200 && y < 230)
                    {
                        break; 
                    }
                }
            }
        }

        //Mateo: This function will show the stats
        void ViewStats() {
            //Andriy: Draws background
            FEHImage Background;
            Background.Open("background.png");
            Background.Draw(0,0);
            LCD.WriteLine("STATISTICS:");
            LCD.WriteLine("High Score: 999");
        
        // Mateo: drawing the back button
            LCD.DrawRectangle(10, 200, 100, 30);
            LCD.WriteAt("Back", 35, 208);

            //Mateo: this here will check if the back button is pressed
            float x, y;
            while (true)
            {
                if (LCD.Touch(&x, &y)) 
                {
                    if (x > 10 && x < 110 && y > 200 && y < 230)
                    {
                        break; 
                    }
                }
            }
        }

        //Mateo: This will show the difficulty options after the users presses play
        int SelectDifficulty() {
            //Andriy: Draws background
            FEHImage Background;
            Background.Open("background.png");
            Background.Draw(0,0);
            LCD.WriteLine("SELECT DIFFICULTY");

            // Draw Normal Button
            LCD.DrawRectangle(60, 60, 200, 40);
            LCD.WriteAt("Normal", 130, 72);

            // Draw Hard Button
            LCD.DrawRectangle(60, 120, 200, 40);
            LCD.WriteAt("Hard", 140, 132);

            // Draw Back Button
            LCD.DrawRectangle(60, 180, 200, 40);
            LCD.WriteAt("Back", 140, 192);
            
            
            //Mateo: VERY IMPORTANT FIX (crashing out figuring this out :c ) 

            // Wait for the user to RELEASE the screen (un-click)
            // We use temporary variables because we don't care where they are touching,
            // we just want to know IF they are still touching.
            float trash_x, trash_y;
            while (LCD.Touch(&trash_x, &trash_y)) {
                // Do nothing, just wait for them to let go
            }

            float x, y;
            while (true) {
                while (!LCD.Touch(&x, &y)) {}
                if (LCD.Touch(&x, &y))
                {
                    if (x > 60 && x < 260 && y > 60 && y < 100)
                    {
                        return 1; // Normal
                    }
                        else if (x > 60 && x < 260 && y > 120 && y < 160)
                    {
                        return 2; // Hard
                    }
                    else if (x > 60 && x < 260 && y > 180 && y < 220)
                    {
                    return 0; // Back
                    }
                }
        }
    }

    public:
        
        //Mateo: This is the main menu loop
        // It'll return the selected difficulty.

        int Run()
        {
            float x, y;
            int difficultyChoice = 0;

            while (1)
            {
                //Andriy: Draws background
                FEHImage Background;
                Background.Open("background.png");
                Background.Draw(0,0);
                LCD.SetFontColor(WHITE);
                LCD.WriteLine("EDUCATIONAL DASH");
            
                // Draw Main Menu Buttons
                LCD.DrawRectangle(60, 50, 200, 30); 
                LCD.WriteAt("1. Play Game", 70, 58);

                LCD.DrawRectangle(60, 90, 200, 30);
                LCD.WriteAt("2. Statistics", 70, 98);

                LCD.DrawRectangle(60, 130, 200, 30);
                LCD.WriteAt("3. Instructions", 70, 138);

                LCD.DrawRectangle(60, 170, 200, 30);
                LCD.WriteAt("4. Credits", 70, 178);
                
                // Wait for the user to RELEASE the screen (un-click)
                // We use temporary variables because we don't care where they are touching,
                // we just want to know IF they are still touching.
                float trash_x, trash_y;
                while (LCD.Touch(&trash_x, &trash_y)) {
                // Do nothing, just wait for them to let go
            }


                // Wait for input
                while (!LCD.Touch(&x, &y)) {}

                

                // Handle Input
                if (x > 60 && x < 260 && y > 50 && y < 80)
                {


                    // Play Game -> Go to difficulty selection
                    difficultyChoice = SelectDifficulty();
                    if (difficultyChoice != 0) {
                        return difficultyChoice; // Return difficulty to main to start game
                    }
                }
                else if (x > 60 && x < 260 && y > 90 && y < 120)
                {
                    ViewStats();
                }
                else if (x > 60 && x < 260 && y > 130 && y < 160)
                {
                    ViewInstructions();
                }
                else if (x > 60 && x < 260 && y > 170 && y < 200)
                {
                    ViewCredits();
                }

        }
    }

};

// Mateo: Someone fix this
// >:C

/*
int getQuestions()
{
    // sorry to whoever has to fix this when it inevitably breaks
    float questionNumbers[2][10];
    char operations[10];
    float correctAns[10];
    float wrongAns[10];
    for (int i = 1; i <= 10; i++){
        int rand = Random.RandInt();
        if (rand <= 8192){
            operations[i] = 'a';
        }
        else if (8192 < rand <= 16384){
            operations[i] = 's';
        }
        else if (16384 < rand <= 24576){
            operations[i] = 'm';
        }
        else{
            operations[i] = 'd';
        }
        for (int j = 1; j<=2; j++){
            rand = Random.RandInt();
            if (rand <= 5461){
            questionNumbers[i][j] = 1 * difficulty;
            }
            else if (5461 < rand <= 10922){
            questionNumbers[i][j] = 2 * difficulty;
            }
            else if (10922 < rand <= 16383){
            questionNumbers[i][j] = 3 * difficulty;
            }
            else if (16383 < rand <= 21844){
            questionNumbers[i][j] = 4 * difficulty;
            }
            else if (21844 < rand <= 27305){
            questionNumbers[i][j] = 5 * difficulty;
            }
            else{
            questionNumbers[i][j] = 6 * difficulty;
            }
        }
        if (operations[i] == 'a'){
            correctAns[i] = questionNumbers[i][1] + questionNumbers[i][2];
        }
        else if (operations[i] == 's'){
            correctAns[i] = questionNumbers[i][1] - questionNumbers[i][2];
        }
        else if (operations[i] == 's'){
            correctAns[i] = questionNumbers[i][1] * questionNumbers[i][2];
        }
        else{
            correctAns[i] = questionNumbers[i][1] / questionNumbers[i][2];
        }
        rand = Random.RandInt();
        if (rand <= 5461){
            wrongAns[i] = correctAns[i] + 1;
        }
        else if (5461 < rand <= 10922){
            wrongAns[i] = correctAns[i] + 2;
        }
        else if (10922 < rand <= 16383){
            wrongAns[i] = correctAns[i] + 3;
        }
        else if (16383 < rand <= 21844){
            wrongAns[i] = correctAns[i] - 1;
        }
        else if (21844 < rand <= 27305){
            wrongAns[i] = correctAns[i] - 2;
        }
        else{
            wrongAns[i] = correctAns[i] - 3;
        }
    }

}
*/
//Seima: Portal Logic
void portalLogic() 
{
    //Declares Image of Portals
    FEHImage PortalA;
    FEHImage PortalB;

    //Open Portal Images
    PortalA.Open("PortalA.png");
    PortalB.Open("PortalB.png");
    for(int i = 0; i < 5; i++)
        {
            //Sets portal to right end of screen
            portalX = 300;

            //(Re)draws portals
            PortalA.Draw(portalX, portalTopY);
            PortalB.Draw(portalX, portalBottomY);

            //Portal moves left until it collides with the player
            while(portalX > playerX)
            {
                //Erase old portal
                LCD.SetFontColor(BLACK);
                LCD.FillRectangle(portalX, portalTopY, 70,SCREENY);
                //Updates x-coordinate of portals
                portalX--;
                //Redraws portals
                PortalA.Draw(portalX, portalTopY);
                PortalB.Draw(portalX, portalBottomY);

                Sleep(5);
            }
            //Erase old portal
            LCD.SetFontColor(BLACK);
            LCD.FillRectangle(portalX, portalTopY, 70,319);
            Sleep(30);

        }
}

// Mateo: This is the LevelFunction which will load
//after the user selects a difficulty
// The function will handle all the gameplay stuff 
// like the questions, answer portals, character, etc?
//Seima: Added portals and their functionality after the y pressed is checked
void LevelFunction()
{
    
    //declares image of our player
    FEHImage WaveDown;
    FEHImage WaveStraight;
    FEHImage WaveUp;



    //Open player image
    WaveDown.Open("WaveIconDown.png");
    WaveStraight.Open("WaveIconStraight.png");
    WaveUp.Open("WaveIconUp.png");


    while(true)
    {

        //---------------------------------
        /* Mateo: THIS IS THE PLAYER LOGIC*/
        /*----------DONT FORGET----------*/
        //---------------------------------

        while (playerY == 219)
        {
            //don't change position

            //erase old player
            LCD.SetFontColor(BLACK);
            LCD.FillRectangle(playerX, playerY, 20, 20);

            if (Keyboard.isPressed(KEY_W))
            {
                //change y position to go up
                playerY = playerY - 3;
            }
            portalLogic();

            //draw player
            //LCD.SetFontColor(WHITE);
            //REPLACE THIS WITH THE CHARACTER ART
            //LCD.FillRectangle(playerX, playerY, 12, 12);
            WaveStraight.Draw(playerX, playerY);
            Sleep(5);
        }
        

        while (Keyboard.isPressed(KEY_W))
        {
            //erase old player
            LCD.SetFontColor(BLACK);
            LCD.FillRectangle(playerX, playerY, 20, 20);
            

            //change y position to go up AND STOP AT ROOF
            if (playerY != 9)
            {
            playerY = playerY - 3;
            WaveUp.Draw(playerX, playerY);
            }
            else
            {
                WaveStraight.Draw(playerX, playerY);
            }
            

            //draw player
            //LCD.SetFontColor(WHITE);
            //REPLACE THIS WITH THE CHARACTER ART
            //LCD.FillRectangle(playerX, playerY, 12, 12);
            //WaveUp.Draw(playerX, playerY);
            Sleep(5);
        }
  
        //--- GRABITY LOGIC IMPORTANT ---
            //erase old player
            LCD.SetFontColor(BLACK);
            LCD.FillRectangle(playerX, playerY, 20, 20);

            //change y position to go down
            playerY = playerY + 3;

            //draw player
            //LCD.SetFontColor(WHITE);
            //REPLACE THIS WITH THE CHARACTER ART
            //LCD.FillRectangle(playerX, playerY, 12, 12);
            WaveDown.Draw(playerX, playerY);
            Sleep(5);

            //------------------------------
            /*--- END OF PLAYER LOGIC-----*/
            //------------------------------
            


    }
    
        
}


int main()
{
    // Instantiate the menu class
    menu myMenu;

    // Run the menu and capture the result
    int difficulty = myMenu.Run();

    //Start the game based on the result
    //Andriy: Draws background
    FEHImage Background;
    Background.Open("background.png");
    Background.Draw(0,0);
    LCD.WriteLine("Starting Game...");
    
    if (difficulty == 1)
    {
        LCD.Clear(BLACK);
        LCD.WriteLine("Mode: NORMAL");
        Sleep(3.0);
        LevelFunction();
    } 
    else
    {
        LCD.WriteLine("Mode: HARD");
        //StartHardGame();
    }   

    while (1) {
        LCD.Update();
        // Never end
    }

    return 0;
}