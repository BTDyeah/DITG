#include <string>
#pragma once

class Speed {
private:
    std::string name; //user name
    int score; //score
    std::string givenTextEasy; // Easy level text
    std::string givenTextNormal; // Normal level text
    std::string givenTextHard; // Hard level text
    std::string givenTextUltra; // Ultra level text
    std::string userText; // usersText
    bool compareChar(char first, char second);
    std::string setDifficulty();
public:
    Speed(std::string n); //ctor
    void countScore(); 
    void startSpeed();
    void checkScore();      
};