#ifndef CLASSES_H
#define CLASSES_H
#include <fstream>
#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

class HangmanModel {
private:
    string movie;
    int lives=7;
    //bool inGame;
public:
    string guessMovie;
    void set_movie(string s);
    void set_guessMovie(string movie);
    
    string get_movie() {  
        return movie;
    }

    int get_lives() {
        return lives;
    }
    
    void reduce_lives() {
        lives=get_lives()-1;
    }

   

   /*void set_inGame(int lives) {
        if (lives)
            inGame = 1;
        else
            inGame = 0;
    }

    bool get_inGame() {
        return inGame;
    } */
};


class HangmanController {
private:
    char letter;
    string letters_num;
public:
    HangmanModel model;

    void userEntry();

    char get_letter() {
        return letter;
    }

    void update_guessMovie(string s);

    /*bool checkIfGameIsOver() {
        if (model.get_inGame())
            return 1;
        else
            return 0;
    }*/
    void set_letters_num(string s) {
        letters_num = s;
    }

    string get_letters_num() {
        return letters_num;
    }
    
    void change_letters_num(char letter);
    
    bool win(string s);
};

class  HangmanView {
public:
    void displayHangman(int lives);  //funckija za prikaz vješala
    void displayCurrentProgress(string s); //funkcija za prikazivanje quessMovie
    void displayUsedLetters(string letters);
    //funcija za prikaz slova i brojeva pogodenih promasenih

};



#endif
