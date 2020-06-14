#include "Speed.h"
#include <string>
#include <iostream>
#include <chrono>
#include <iterator>

Speed::Speed(std::string n){
    name = n;
    score = 0;
    testText = "So, so you think you can tell, Heaven from hell, Blue skies from pain, Can you tell a green field, From a cold steel rail? A smile from a veil? Do you think you can tell? Did they get you to trade, Your heroes for ghosts? Hot ashes for trees? Hot air for a cool breeze? Cold comfort for change? Did you exchange, A walk on part in the war, For a lead role in a cage? How I wish, how I wish you were here, We're just two lost souls, Swimming in a fish bowl, Year after year, Running over the same old ground, And how we found, The same old fears, Wish you were here\n";
}

void Speed::countScore(){
    checkEasterEggs();
    std::cout << testText;
    std::cout << "\nYou have 60 seconds! Start typing now: \n";
    /*try to either overload the getline function if possible or just make your own*/
    auto start = std::chrono::high_resolution_clock::now();    
    std::getline(std::cin, userText);
    
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<float> Duration = end - start;
    int time = Duration.count();
    
    if(time > 60){
        std::cout << "You failed to enter text in given time!\n";
        exit(0);
    }

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
    int i = 0;
    while (is.peek() != '\n') {
        is >> std::noskipws >> str[i];
        str.push_back(str[i]);
        i++;
    }
    return is;
}

void Speed::cantGetNo(){
    std::string str;
    getline(std::cin, str);   
    std::cout << str << std::endl;
}