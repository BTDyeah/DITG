#include <iostream>
#include "Speed.h"

int main(){
/*    
    std::cout << "Hello and welcome to \e[1mDITG - Definetly Interesting Typing Game!\e[0m\n";
    std::string name;
    std::cout << "Please input your name. After doing that you'll have 60 seconds to press \"enter\" and finish the program. If you do not do\
 that in a given time, your score won't count!\n";
    std::getline(std::cin, name);
*/
    auto name = "whatever"; //for the purpose of making code simpler
    Speed obj(name);     
    obj.countScore();
    return 0;
}