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

        // this function will print the unstructions to the screen
    
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

                //The title screen
                LCD.SetFontColor(WHITE);
                LCD.WriteLine("EDUCATIONAL DASH");

                //Draw main menu buttons
                LCD.DrawRectangle(60, 170, 200, 30);
                LCD.WriteAt("4. Credits", 100, 178);

                //Wait for input
                while (!LCD.Touch(&x, &y)) {}

                if (x > 60 && x < 260 && y > 170 && y < 200)
                {
                    ViewCredits();
                }
            }
        }

};


int main()
{
    menu myMenu;

    myMenu.Run();


    
    
    
    

    while (1) {
        LCD.Update();
        // Never end
    }
    return 0;
}