#include "Speed.h"
#include <string>
#include <iostream>
#include <chrono>
#include <curses.h>
/*Poruka od mene za mene: instaliraj sfml ovde na ubucnua*/

Speed::Speed(std::string n){
    name = n;
    score = 0;
    testText = "So, so you think you can tell, Heaven from hell, Blue skies from pain, Can you tell a green field, From a cold steel rail? A smile from a veil? Do you think you can tell? Did they get you to trade, Your heroes for ghosts? Hot ashes for trees? Hot air for a cool breeze? Cold comfort for change? Did you exchange, A walk on part in the war, For a lead role in a cage? How I wish, how I wish you were here, We're just two lost souls, Swimming in a fish bowl, Year after year, Running over the same old ground, And how we found, The same old fears, Wish you were here\n";
}

void Speed::countScore(){
    checkEasterEggs();
    std::cout << testText;
    std::cout << "\nYou have 60 seconds! Start typing now: \n";
    
    getline(std::cin, userText);

    int i, j;    
    for(i = 0, j = 0; i < testText.length() && j < userText.length(); ++i, ++j){
        if(compareChar(testText[i], userText[j])){
            if(std::isspace(testText[i + 1]) || std::isspace(userText[j + 1]))
                score++;
            if(std::isspace(testText[i]) && std::isspace(userText[j]))    
                continue;    
        }
        else 
            continue;
    }
    checkScore();
}

void Speed::checkScore() {
    if(score >= 20 && score < 50){
        std::cout << "\nCongratulations " << name << "! Your score is " << score
        << "! That is 20 or more so you passed the beginner test! Shine On You Crazy Diamond!\n";
    }
    else
        if(score >= 50 && score < 70) {
            std::cout << "\nCongratulations " << name << "! Your score is " << score
            << "! That is 50 or more so you are officially a beginner to intermidiate typer! Your fingers are slowly becoming comfortably numb i bet!\n";
        }
        else 
            if(score >= 70 && score < 90){
                std::cout << "\nCongratulations " << name << "! Your score is " << score
                << "! That is 70 or more so you officially belong to upper intermidiate typer! Your keyboard must be making Echoes right now!\n";
            }
            else 
                if(score >= 90){
                    std::cout << "\nCongratulations " << name << "! Your score is " << score
                    << "! Hey you! What if you could make Money with these skills? Congratulation on 90 or more words per minute! You are a real deal!\n";
                }
                else{
                    std::cout << "\nSorry " << name << ". I'm lost for words. Your score is " << score << " I hope Eclipse hasn't swallowed you yet! Prepare yourself for next time, this time your score is under 20 :(\n";
                }
}

bool Speed::compareChar(char first, char second){
    if(first == second)
        return true;
    else
        return false;
}

void Speed::checkEasterEggs() { /*EASTER EGGS*/
    /*The catch is that user has to have an excat name of the original band*/

    std::string favSong;

    if(name == "Metallica"){
        std::cout << "Hey! What's your favourite " << name << "'s song?\n";
        std::getline(std::cin,favSong);   
        if(favSong == "Blackend")
            std::cout << "Great! Same as mine! Enjoy your typing game!\n\n";
        else
            std::cout << "Great! Mine is \"Blackend\"! Enjoy your typing game!\n\n";
    }
    else
        if(name == "The Beatles"){
            std::cout << "Hey! What's your favourite " << name << "'s song?\n";
            std::getline(std::cin,favSong);   
            
            if(favSong == "I wanna hold your hand")
                std::cout << "Great! Same as mine! Enjoy your typing game!\n\n";
            else
                std::cout << "Great! Mine is \"I wanna hold your hand\"! Enjoy your typing game!\n\n";
        }
        else
            if(name == "Pink Floyd"){
                std::cout << "Hey! What's your favourite " << name << "'s song?\n";
                std::getline(std::cin,favSong);   
                
                if(favSong == "Hey You")
                    std::cout << "Great! Same as mine! Enjoy your typing game!\n\n";
                else
                    std::cout << "Great! Mine is \"Hey You\"!. Enjoy your typing game!\n\n";
            }
            else
                if(name == "Slayer"){
                    std::cout << "Hey! What's your favourite " << name << "'s song?\n";
                    std::getline(std::cin,favSong);   
                    
                    if(favSong == "Season in Abyss")
                        std::cout << "Great! Same as mine! Enjoy your typing game!\n\n";
                    else
                        std::cout << "Great! Mine is \"Season in Abyss\"! Enjoy your typing game!\n\n";
                }
                else
                    if(name == "Nirvana"){
                        std::cout << "Hey! What's your favourite " << name << "'s song?\n";
                        std::getline(std::cin,favSong);   
                        
                        if(favSong == "Drain You")
                            std::cout << "Great! Same as mine! Enjoy your typing game!\n\n";
                        else
                            std::cout << "Great! Mine is \"Drain You\"! Enjoy your typing game!\n\n";
                    }
                    else {
                        std::cout << "Hello " << name << "! Enjoy!\n\n";
                    }
}

std::istream& Speed::getline(std::istream& is, std::string& str){
    
    /*
        The idea is to print an array of 60 elements, which represent seconds, then at every second to remove the highest number (60) until we get to
        1 when user will be able to write but will be terminated. Ideally, i would terminate the input at that stage but i have no idea how+
    */
    //std::cout << "\n\n";
    //auto start = std::chrono::high_resolution_clock::now();
    /*WINDOW* screen = curscr;
    int secondsLeft = 10;
    char c;
    initscr();
    newwin(1, 1, getmaxy(screen) / 2, getmaxx(screen));
    refresh();
    curs_set(2);
    do {
      printw("%i", secondsLeft);
      refresh();
      erase();
      secondsLeft--;
      napms(1000);
    } 
    while (secondsLeft > 0);
    std::cout << "\n";
    
    newwin(1, 1, getmaxy(screen), getmaxx(screen));

    while (is.peek() != '\n') {
        is >> std::noskipws >> c;
        str.push_back(c);
    }
    endwin();*/
    
    int parent_x, parent_y;
    int score_size = 3;
    initscr(); 
    noecho(); 
    curs_set(FALSE); // get our maximum window dimensions 
    getmaxyx(stdscr, parent_y, parent_x); // set up initial windows 
    WINDOW *field = newwin(parent_y - score_size, parent_x, 0, 0); 
    WINDOW *score = newwin(score_size, parent_x, parent_y - score_size, 0); // draw to our windows 
    mvwprintw(field, 0, 0, "Field");
    int secondsLeft = 10;
    char c;
    //curs_set(2);
    do {
      printw("%i", secondsLeft);
      refresh();
      erase();
      secondsLeft--;
      napms(1000);
    } 
    while (secondsLeft > 0); 
    mvwprintw(score, 0, 0, "Score"); // refresh each window 
    wrefresh(field); 
    wrefresh(score); 
    napms(10000); // clean up 
    delwin(field); 
    delwin(score); 
    endwin();
    return is;
}

void Speed::cantGetNo(){
    std::string str;
    getline(std::cin, str);   
    std::cout << str << std::endl;
}