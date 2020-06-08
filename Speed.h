#ifndef SPEED_H
#define SPEED_H
#include <string>

class Speed {
private:
    std::string name; //user name
    int score; //score
    std::string testText; // text for testing purposes
    std::string userText; // usersText
public:
    Speed(std::string n); //ctor
    void countScore();
private:
    bool compareChar(char first, char second);
    void checkScore();
    void checkEasterEggs();
};
#endif