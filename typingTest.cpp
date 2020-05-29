#include <iostream>
#include <chrono>

/*
    1. Make a timer that will return on 1minute(60 seconds)
    2. When a word is written correctly, score++
    3. https://www.youtube.com/watch?v=oEx5vGNFrLk

*/

/*
    1. 
    2.
    3.
    4.

*/




class Speed {
private:
    std::string name; //user name
    int score = 20; //user stat
    std::string text; //text for a user

    /*struct Timer {
        std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
        std::chrono::duration<float> userDuration, givenDuration;

        Timer(){
            start = std::chrono::high_resolution_clock::now();
        }

        ~Timer(){
            end = std::chrono::high_resolution_clock::now();
            userDuration = end - start;

            givenDuration += std::chrono::seconds(60);        
            int userSpeed = userDuration.count();
            int givenTime = givenDuration.count();
            int countScore = 0;
            std::string word;
            if(userSpeed != givenTime && word == wordText)
                countScore++;
            else
                return;
            //std::cout << userSpeed << "\n";
            //std::cout << givenTime << "\n";
        }
    };
*/
public:
    Speed(std::string n, int s){
        name = n;
        score = s;
    }
    #define out 0
    #define in 1
    int countSubstring(std::string text){
        int count = 0; 
        //int out = 0, in = 1;
        int state = out;
        int charCount = 0;

        for(std::string::iterator it = text.begin(); it != text.end(); ++it){
            
            if(state == out){
                state = in;
                ++count;
            }
            else 
                if(text[charCount] == ' ' || text[charCount] == '\n' || text[charCount] == '\t')
                    state = out;
            charCount++;
                
        }
        
        return count;
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
        std::cin >> this -> text;

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
    int score = 50;

    /*std::string text = "Remember when you were young, you shone like the sun\
                        Shine on you crazy diamond\
                        Now there's a look in your eyes, like black holes in the sky\
                        Shine on you crazy diamond\
                        You were caught on the crossfire of childhood and stardom\
                        Blown on the steel breeze\
                        Come on you target for faraway laughter\
                        Come on you stranger, you legend, you martyr, and shine\
                        You reached for the secret too soon, you cried for the moon\
                        Shine on you crazy diamond\
                        Threatened by shadows at night, and exposed in the light\
                        Shine on you crazy diamond\
                        Well you wore out your welcome with random precision\
                        Rode on the steel breeze\
                        Come on you raver, you seer of visions\
                        Come on you painter, you piper, you prisoner, and shine";
    */
    std::string text = "No you dumbass";
    std::cout << "Input your name, master\n";
    std::cin >> name;
    Speed obj(name, score);
    //obj.checkSpeed(text);   
    std::cout << obj.countSubstring(text);
    /*Whole system of a down(ha ha ha), system of scoring, could be put in function later*/
    

    return 0;
}