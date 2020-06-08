#include <iostream>
#include "Speed.h"

/*
    IDEAS:
        1. Make given text appear slowly, or tell the user that they need to start in next 5 seconds or make it so the text appears
           just before the "Start Typing" and give the user message "You have 10 seconds to start:"
    2. Make three more levels: intermidate, hard, hardcore. Every stage has it's own Pink Floyd song, and different scoring statements
    3. Arrange the code to look cleaner, maybe put the class in different file
    4. Make an easter egg if a user has name of a band, add additional conversation like "what's your favourite song from ur username?"
       if it is same as mine then "Great! Same as me!" otherwise "Great! Mine is: *name of the song*"
        5. Try to use SQl and mySQL and try to save the names as data of users, there is no need for password IMHO
        6. Make a visual version of this console program in SFML
    7. Make the timer work as it should
        8. Add so the text has a threshold of coming out, so the user can see just the portion of it, or make it so the user can see
           only this and next word as they type. I see this much easier done with SFML since it can be visually done, but this should
           be left as an end goal for a console version of this app
    9. Store things on heap when user decides which difficulty they want. That way it will consume less memory
       plus there will be like infinity tries to get the right level. Tho, the only thing we really need is one more
       try, but if user's gonna mess up for days not getting the ENHU then let them be
    10. Name the game
    11. Mention and provide all of the links necessery and try not to get in copyright infrigment trouble. If you have to use something else,
        switch the name of the game to something else and then search for non-copyright books or texts
        12. There is a huge bug. It might need to be refactored as a whole algorithm. I hope not, truly hope not. So, if you write first word wrong
            every next one will count as zero. I want this game to count zero if a word is wrong at any place as well as true in any place
        13. SUGGESTION: Make a file input where user shall just input whatever they feel like inputting. Now that i think of it,
            that is not a bad suggestion at all. THAT WOULD MEAN DELETING THE DIFFICULTIES TOO, BUT AVOIDING COPYRIGHT TROUBLES
        14. BUG: sO, or SO, gives one but it should not
        15. Try to somehow make if user hasn't written anything yet, to count no time
*/

int main(){
    
    std::cout << "Hello and welcome to \e[1mDITG - Definetly Interesting Typing Game!\e[0m\n";
    std::string name;
    std::cout << "Please input your name:\n";
    std::getline(std::cin, name);

    Speed obj(name);     
    //obj.checkEasterEggs();
    obj.countScore();
    
    return 0;
}