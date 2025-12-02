#include "FEHLCD.h"
#include "FEHUtility.h"

//Mateo: I've written a class to help keep all he menu logic organized
class menu {
    private:
        //Mateo: main doesn't need to know about these
        
        //Mateo: This function will print the credits to the screen
        void ViewCredits() {
            LCD.Clear(BLACK);
            LCD.WriteLine("CREDITS:");
            //Mateo: I forgor your guy's last names
            LCD.WriteLine("Developers: Mateo Polt, Seima, Auedriy");

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

        // this function will print the instructions to the screen
        void ViewInstructions() {
            LCD.Clear(BLACK);
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

        // This function will show the stats
        void ViewStats() {
            LCD.Clear(BLACK);
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

        //This will show the difficulty options after the users presses play
        int SelectDifficulty() {
            LCD.Clear(BLACK);
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
            
            
            // VERY IMPORTANT FIX (crashing out figuring this out :c ) 

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
                LCD.Clear(BLACK);
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


int main()
{
    // Instantiate the menu class
    menu myMenu;

    // Run the menu and capture the result
    int difficulty = myMenu.Run();

    //Start the game based on the result
    LCD.Clear(BLACK);
    LCD.WriteLine("Starting Game...");
    
    if (difficulty == 1)
    {
        LCD.WriteLine("Mode: NORMAL");
        //StartNormalGame();
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