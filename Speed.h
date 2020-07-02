#ifndef SPEED_H
#define SPEED_H
#include <string>
#include <iostream>
#include <curses.h>

class Speed {
private:
    std::string name; //user name
    int score; //score
    std::string testText; // text for testing purposes
    std::string userText; // usersText
public:
    Speed(std::string n); //ctor
    void countScore();
    void testCase();
    ~Speed();
private:
    bool compareChar(char first, char second);
    void checkScore();
    void checkEasterEggs();
    std::istream& getline (std::istream& is, std::string& str);
    void draw_borders(WINDOW* screen);
    static void timer();
};
#endif