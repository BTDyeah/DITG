#include <iostream>
#include "Speed.h"

/*
    IDEAS:
        1. Make given text appear slowly, or tell the user that they need to start in next 5 seconds or make it so the text appears
           just before the "Start Typing" and give the user message "You have 10 seconds to start:"
    2. Make three more levels: intermidate, hard, hardcore. Every stage has it's own Pink Floyd song, and different scoring statements
    3. Arrange the code to look cleaner, maybe put the class in different file
        4. Make an easter egg if a user has any of the names of the band members, send them a cool message or something
        5. Try to use SQl and mySQL and try to save the names as data of users, there is no need for password IMHO
        6. Make a visual version of this console program in SFML
        7. Make the timer work as it should
        8. Add so the text has a threshold of coming out, so the user can see just the portion of it, or make it so the user can see
           only this and next word as they type. I see this much easier done with SFML since it can be visually done, but this should
           be left as an end goal for a console version of this app
        9. Store things on heap when user decides which difficulty they want. That way it will consume less memory
           plus there will be like infinity tries to get the right level. Tho, the only thing we really need is one more
           try, but if user's gonna mess up for days not getting the ENHU then let them be
        10. By the way, name of the game is ENHU - Enormously Normal but Hilarious Utopia aka first letter of difficulties
*/

int main(){
    
    std::string name;
    std::cout << "Input your name, master\n";
    std::getline(std::cin, name);

    Speed obj(name);     
    obj.countScore();
    
    return 0;
}