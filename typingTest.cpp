#include <iostream>
#include <chrono>

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

*/

class Speed {
private:
    std::string name; //user name
    int score;
    std::string givenTextEasy;
    std::string userText; //text for a user
public:
    Speed(std::string n){
        name = n;
        score = 0;
        givenTextEasy = "Remember when you were young, you shone like the sun, Shine on you crazy diamond, Now there's a look in your eyes, like black holes in the sky, Shine on you crazy diamond, You were caught on the crossfire of childhood and stardom, Blown on the steel breeze, Come on you target for faraway laughter, Come on you stranger, you legend, you martyr, and shine, You reached for the secret too soon, you cried for the moon, Shine on you crazy diamond, Threatened by shadows at night, and exposed in the light, Shine on you crazy diamond, Well you wore out your welcome with random precision, Rode on the steel breeze, Come on you raver, you seer of visions, Come on you painter, you piper, you prisoner, and shine\n";
    }

    bool compareChar(char first, char second){
        if(first == second)
            return true;
        else
            return false;
    }

    bool compareSubstrChar(char first, char second){
        if(std::isspace(first) && std::isspace(second))
            return true;
        else  
            return false;
    }

    int countSubstring(){
        std::cout << givenTextEasy << "\n";
        std::cout << "Start typing: \n";
        std::getline(std::cin, userText);
    
        int i, j;
        for(i = 0, j = 0; i < givenTextEasy.length() && j < userText.length(); ++i, ++j){
            if(compareChar(givenTextEasy[i], userText[j])){
                if(std::isspace(givenTextEasy[i + 1]) || std::isspace(userText[j + 1]))
                    score++;
                
                if(std::isspace(givenTextEasy[i]) && std::isspace(userText[j]))    
                    continue;
            }
            else 
                continue;
        }
        return score;
    }

    void startSpeed(){
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
    void checkSpeed(std::string text) {
    
        std::cout << name << ", please start typing whenever you feel like it: \n";
        std::cin >> userText;

         //if user got one word right, FIX this later
            if(score >= 20 && score < 50){
                std::cout << "Congratulations " << name << "! Your score is " << score
                << "! That is 20 or more so you passed the beginner test! Shine On You Crazy Diamond!\n";
            }
            else
                if(score >= 50 && score < 70) {
                    std::cout << "Congratulations " << name << "! Your score is " << score
                    << "! That is 50 or more so you are officially a beginner to intermidiate typer! Your fingers are slowly becoming comfortably numb i bet!\n";
                }
                else 
                    if(score >= 70 && score < 90){
                        std::cout << "Congratulations " << name << "! Your score is " << score
                        << "! That is 70 or more so you officially belong to upper intermidiate typer! Your keyboard must be making Echoes right now!\n";
                    }
                    else 
                        if(score >= 90){
                            std::cout << "Congratulations " << name << "! Your score is " << score
                            << "! Hey you! What if you could make Money with these skills? Congratulation on 90 or more words per minute! You are a real deal!\n";
                        }
                        else{
                            std::cout << "Sorry " << name << ". I'm lost for words. Your score is" << score << "I hope Eclipse hasn't swallowed you yet! Prepare yourself for next time, this time your score is under 20 :(\n";
                        }
    }
    
};

int main(){
    std::string name;
    std::cout << "Input your name, master\n";
    std::getline(std::cin, name);
       
    Speed obj(name);   
    std::cout << obj.countSubstring();
    /*Whole system of a down(ha ha ha), system of scoring, could be put in function later*/
    return 0;
}