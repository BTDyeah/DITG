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


struct Timer {
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
        std::cout << "I need to make this into a constant of 60s, and count how many words user got right";
    }
};

class Speed {
private:
    std::string name; //user name
    int score = 20; //user stat
    std::string text; //text for a user
public:
    Speed(std::string n, int s){
        name = n;
        score = s;
    }

    void checkSpeed(std::string text) {
        std::cout << "Please start typing: \n";
        std::cin >> this -> text;

        if(this -> text == text){ //if user got one word right, FIX this later
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
                            std::cout << "Sorry. I'm lost for words. I hope Eclipse hasn't swallowed you yet! Prepare yourself for next time, this time your score is under 20 :(\n";
                        }
        }
        else{
            std::cout << "sorry little one\n";
        }
    }
};

int main(){
    std::string name;
    int score = 10;

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
    std::string text = "NO";
    Speed obj(name, score);
    std::cout << "Input your name, master\n";
    std::cin >> name;
    obj.checkSpeed(text);   
    /*Whole system of a down(ha ha ha), system of scoring, could be put in function later*/
    

    return 0;
}