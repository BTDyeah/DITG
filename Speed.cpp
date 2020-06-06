#include "Speed.h"
#include <string>
#include <iostream>
#include <chrono>

Speed::Speed(std::string n){
    name = n;
    score = 0;
    givenTextEasy = "\nSo, so you think you can tell, Heaven from hell, Blue skies from pain, Can you tell a green field, From a cold steel rail? A smile from a veil? Do you think you can tell? Did they get you to trade, Your heroes for ghosts? Hot ashes for trees? Hot air for a cool breeze? Cold comfort for change? Did you exchange, A walk on part in the war, For a lead role in a cage? How I wish, how I wish you were here, We're just two lost souls, Swimming in a fish bowl, Year after year, Running over the same old ground, And how we found, The same old fears, Wish you were here\n";
    givenTextNormal = "\nRemember when you were young, you shone like the sun, Shine on you crazy diamond, Now there's a look in your eyes, like black holes in the sky, Shine on you crazy diamond, You were caught on the crossfire of childhood and stardom, Blown on the steel breeze, Come on you target for faraway laughter, Come on you stranger, you legend, you martyr, and shine, You reached for the secret too soon, you cried for the moon, Shine on you crazy diamond, Threatened by shadows at night, and exposed in the light, Shine on you crazy diamond, Well you wore out your welcome with random precision, Rode on the steel breeze, Come on you raver, you seer of visions, Come on you painter, you piper, you prisoner, and shine\n";
    givenTextHard = "\nHey you, out there in the cold, Getting lonely, getting old, Can you feel me? Hey you, standing in the aisles, With itchy feet and fading smiles, Can you feel me? Hey you, don't help them to bury the light, Don't give in without a fight, Hey you out there on your own, Sitting naked by the phone, Would you touch me? Hey you with you ear against the wall, Waiting for someone to call out, Would you touch me? Hey you, would you help me to carry the stone? Open your heart, I'm coming home, But it was only fantasy, The wall was too high, As you can see, No matter how he tried, He could not break free, And the worms ate into his brain, Hey you, out there on the road, Always doing what you're told, Can you help me? Hey you, out there beyond the wall, Breaking bottles in the hall, Can you help me? Hey you, don't tell me there's no hope at all, Together we stand, divided we fall\n";
    givenTextUltra = "\nHello? Hello? Hello? Is there anybody in there? Just nod if you can hear me, Is there anyone at home? Come on now, I hear you're feeling down, Well I can ease your pain, Get you on your feet again, Relax, I'll need some information first, Just the basic facts, Can you show me where it hurts? There is no pain you are receding, A distant ship smoke on the horizon, You are only coming through in waves, Your lips move but I can't hear what you're saying, When I was a child I had a fever, My hands felt just like two balloons, Now I've got that feeling once again, I can't explain you would not understand, This is not how I am, I have become comfortably numb, Okay, Just a little pinprick, There'll be no more, ah, But you may feel a little sick, Can you stand up? I do believe it's working, good, That'll keep you going through the show, Come on it's time to go, There is no pain you are receding, A distant ship, smoke on the horizon, You are only coming through in waves, Your lips move but I can't hear what you're saying, When I was a child, I caught a fleeting glimpse, Out of the corner of my eye, I turned to look but it was gone, I cannot put my finger on it now, The child is grown, The dream is gone, I have become comfortably numb\n";
}

bool Speed::compareChar(char first, char second){
    if(first == second)
        return true;
    else
        return false;
}

std::string Speed::setDifficulty(){
    std::cout << "\nHello " << name << "! Please choose your difficulty!\n\nE is for EASY\nN is for NORMAL\nH is for HARD\nU is for ULTRA\n";
    
    char difficulty;
    std::cin >> difficulty;
    
    std::cin.ignore();
    
    std::string text = " ";
    
    switch(difficulty){
        case 'E':
            text = givenTextEasy;
            break;
        case 'N':
            text = givenTextNormal;
            break;
        case 'H':
            text = givenTextHard;
            break;
        case 'U':
            text = givenTextUltra;
            break;
        default:
            std::cout << "Please choose from one of the following letters ENHU! Try again!\n";
    }
    return text;
}

void Speed::countScore(){
    std::string selectedText = setDifficulty();
    
    if(selectedText == " ") // this might be unnecessary but i am not sure
        return;
    
    std::cout << selectedText;
    std::cout << "\nStart typing: \n";
    std::getline(std::cin, userText);

    int i, j;
    for(i = 0, j = 0; i < selectedText.length() && j < userText.length(); ++i, ++j){
        if(compareChar(selectedText[i], userText[j])){
            if(std::isspace(selectedText[i + 1]) || std::isspace(userText[j + 1]))
                score++;
            
            if(std::isspace(selectedText[i]) && std::isspace(userText[j]))    
                continue;
        }
        else 
            continue;
    }
    checkScore();
}
/*WORK ON THIS BAKA YARO*/
void Speed::startSpeed(){
    std::chrono::duration<float> startDuration, givenDuration;
    startDuration += std::chrono::seconds(0);
    givenDuration += std::chrono::seconds(60);
    int startSpeed = startDuration.count();
    int givenTime = givenDuration.count();
    int countScore = 0;
    
    for(startSpeed; startSpeed < givenTime; startSpeed++)
        if(startSpeed != givenTime) //add if a substring is equal too
            countScore++; 
        else
            return;        
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
