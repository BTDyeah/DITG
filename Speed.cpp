#include "Speed.h"
#include <string>
#include <iostream>
#include <chrono>
#include <curses.h>

Speed::Speed(std::string n){
    name = n;
    score = 0;
    testText = "So, so you think you can tell, Heaven from hell, Blue skies from pain, Can you tell a green field, From a cold steel rail? A smile from a veil? Do you think you can tell? Did they get you to trade, Your heroes for ghosts? Hot ashes for trees? Hot air for a cool breeze? Cold comfort for change? Did you exchange, A walk on part in the war, For a lead role in a cage? How I wish, how I wish you were here, We're just two lost souls, Swimming in a fish bowl, Year after year, Running over the same old ground, And how we found, The same old fears, Wish you were here\n";
    initscr();
}

Speed::~Speed(){
    endwin();
}

void Speed::countScore(){ //this is a big mess, but here lies the problem
    
  checkEasterEggs();  
  int parent_x, parent_y, new_x, new_y;
  int score_size = 3;

  int secondsLeft = 10;
  char c;  

  //noecho();
  //curs_set(0);

  // set up initial windows
  getmaxyx(stdscr, parent_y, parent_x);

  WINDOW *field = newwin(parent_y - score_size, parent_x, 0, 0);
  WINDOW *score = newwin(score_size, parent_x, parent_y - score_size, 0);

  draw_borders(field);
  draw_borders(score);

  //wprintw(field,"", testText);
  //mvwprintw(field,2,2,"\nYou have 60 seconds! Start typing now: \n");
  //char* cuserText = userText.c_str();
  //wgetstr(field, cuserText);


  while(1) {
    
    getmaxyx(stdscr, new_y, new_x);

    if (new_y != parent_y || new_x != parent_x) {
      parent_x = new_x;
      parent_y = new_y;

      wresize(field, new_y - score_size, new_x);
      wresize(score, score_size, new_x);
      mvwin(score, new_y - score_size, 0);

      wclear(stdscr);
      wclear(field);
      wclear(score);

      draw_borders(field);
      draw_borders(score);
    }

    // draw to our windows
    mvwprintw(field, 1, 1, "Field"); //input
    
    mvwprintw(
        score, 
        1, 
        1, 
        "", 
        timer
    ); //timer that does not work, tried with a lambda too but does not work

    /*std::string buffer;
    while((c = wgetch(field)) != ERR){
        buffer.push_back(c);
    }
    
    for(int i = 0, j = 0; i < testText.length() && j < userText.length(); ++i, ++j){
        if(compareChar(testText[i], userText[j])){
            if(std::isspace(testText[i + 1]) || std::isspace(userText[j + 1]))
                score++;
            if(std::isspace(testText[i]) && std::isspace(userText[j]))    
                continue;    
        }
        else 
            continue;
    }

    checkScore();*/
    // refresh each window
    wrefresh(field);
    wrefresh(score);
  }
}

void Speed::checkScore() { //the scoring system is totally random and will be improved over time(no printw() for now)
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
        printw("Hey! What's your favourite ", name, "'s song?\n");
        std::getline(std::cin,favSong);   
        if(favSong == "Blackend")
            printw("Great! Same as mine! Enjoy your typing game!\n\n");
        else
            printw("Great! Mine is \"Blackend\"! Enjoy your typing game!\n\n");
    }
    else
        if(name == "The Beatles"){
            printw("Hey! What's your favourite ", name, "'s song?\n");
            std::getline(std::cin,favSong);   
            
            if(favSong == "I wanna hold your hand")
                printw("Great! Same as mine! Enjoy your typing game!\n\n");
            else
                printw("Great! Mine is \"I wanna hold your hand\"! Enjoy your typing game!\n\n");
        }
        else
            if(name == "Pink Floyd"){
                printw("Hey! What's your favourite ", name, "'s song?\n");
                std::getline(std::cin,favSong);   
                
                if(favSong == "Hey You")
                    printw("Great! Same as mine! Enjoy your typing game!\n\n");
                else
                    printw("Great! Mine is \"Hey You\"!. Enjoy your typing game!\n\n");
            }
            else
                if(name == "Slayer"){
                    printw("Hey! What's your favourite ", name, "'s song?\n");
                    std::getline(std::cin,favSong);   
                    
                    if(favSong == "Seasons in the Abyss")
                        printw("Great! Same as mine! Enjoy your typing game!\n\n");
                    else
                        printw("Great! Mine is \"Season in Abyss\"! Enjoy your typing game!\n\n");
                }
                else
                    if(name == "Nirvana"){
                        printw("Hey! What's your favourite ", name, "'s song?\n");
                        std::getline(std::cin,favSong);   
                        
                        if(favSong == "Drain You")
                            printw("Great! Same as mine! Enjoy your typing game!\n\n");
                        else
                            printw("Great! Mine is \"Drain You\"! Enjoy your typing game!\n\n");
                    }
                    else {
                        printw("Hello", name, "! Enjoy!\n\n");
                    }
}

std::istream& Speed::getline(std::istream& is, std::string& str){
    char c;
    while (is.peek() != '\n') {
        is >> std::noskipws >> c;
        str.push_back(c);
    }  
    return is;
}

/*std::istream& Speed::getline(std::istream& is, std::string& str){
  int parent_x, parent_y, new_x, new_y;
  int score_size = 3;

  int secondsLeft = 10;
  char c;  

  noecho();
  curs_set(FALSE);

  // set up initial windows
  getmaxyx(stdscr, parent_y, parent_x);

  WINDOW *field = newwin(parent_y - score_size, parent_x, 0, 0);
  WINDOW *score = newwin(score_size, parent_x, parent_y - score_size, 0);

  draw_borders(field);
  draw_borders(score);

  while(1) {
    getmaxyx(stdscr, new_y, new_x);

    if (new_y != parent_y || new_x != parent_x) {
      parent_x = new_x;
      parent_y = new_y;

      wresize(field, new_y - score_size, new_x);
      wresize(score, score_size, new_x);
      mvwin(score, new_y - score_size, 0);

      wclear(stdscr);
      wclear(field);
      wclear(score);

      draw_borders(field);
      draw_borders(score);
    }

    // draw to our windows
    mvwprintw(field, 1, 1, "Field");
    
    mvwprintw(score, 1, 1, "Score");

    // refresh each window
    wrefresh(field);
    wrefresh(score);
  } 
  return is;
}*/

void Speed::draw_borders(WINDOW *screen) { 
    int x, y, i;

    getmaxyx(screen, y, x);

      // 4 corners
    mvwprintw(screen, 0, 0, "+");
    mvwprintw(screen, y - 1, 0, "+");
    mvwprintw(screen, 0, x - 1, "+");
    mvwprintw(screen, y - 1, x - 1, "+");

      // sides
    for (i = 1; i < (y - 1); i++) {
        mvwprintw(screen, i, 0, "|");
        mvwprintw(screen, i, x - 1, "|");
    }

      // top and bottom
    for (i = 1; i < (x - 1); i++) {
        mvwprintw(screen, 0, i, "-");
        mvwprintw(screen, y - 1, i, "-");
    }
}

void Speed::timer(){

    int parent_x, parent_y, new_x, new_y;
    int score_size = 3;
    WINDOW *score = newwin(score_size, parent_x, parent_y - score_size, 0);

    int secondsLeft = 10;
    do {  
      mvwprintw(score,1,1,"%i", secondsLeft);
      wrefresh(score);
      werase(score);
      secondsLeft--;
      napms(1000);
    } while (secondsLeft > 0);
}