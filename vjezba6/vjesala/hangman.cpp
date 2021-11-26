#include "classes.h"
#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
#include <algorithm>
#include <cstddef>  


using namespace std;

void HangmanModel::set_guessMovie(string s) {
   
    int n = movie.size();
    int i = 0, is_found = 0;
    while (i < n) {
        if (movie[i] == ' ')
            guessMovie.push_back(' ');
        else if (movie[i] == 39)
            guessMovie.push_back(39);
        else if (movie[i] == '-')
            guessMovie.push_back('-');
        else if (movie[i] == ':')
            guessMovie.push_back(':');
        else
        {
            guessMovie.push_back('_');
           
        }
        i++;
    }
    
}

void HangmanModel::set_movie(string s) { //funkcija za vaðenje filma iz datoteke
    int n;
    cout << "choose number from 1 to 38: ";
    cin >> n;
    string movie_from_file;
    ifstream myfile(s);
    if (myfile.is_open()) {
        for (int i = 0; i < n; i++)
            getline(myfile, movie_from_file);
        myfile.close();
    }
    else {
        cout << "Unable to open file";
    }
    movie = movie_from_file;
    transform(movie.begin(), movie.end(), movie.begin(), toupper);
    
}

void HangmanController::userEntry() {
    cout << endl << "quess letter: ";
    

    cin >> letter;
    
}
void HangmanController::update_guessMovie(string movie) {
    userEntry();
    int n =movie.size();
    int i = 0, br = 0;
    while (i < n) {
        if (movie[i] == toupper(letter)) {
            model.guessMovie[i] = toupper(letter);
            br++;
        }
        i++;
    }
    if (!br) {
        model.reduce_lives();

    }
   
    

}

void HangmanController::change_letters_num(char letter) {
        string s = get_letters_num(); // "A B C D E F G H I J K L M N O P Q R S T U V W X Y Z 0 1 2 3 4 5 6 7 8 9";
        int i;
        for (i = 0; i < s.size() ;++i) {
            if (s[i] == toupper(letter))
                s[i] = ' ';
        }
        set_letters_num(s);

}

bool HangmanController::win(string s) {
    size_t found = s.find('_');
    if (found == -1)
        return 1;
}


void HangmanView::displayHangman(int lives) {
    int i, j;
    for (i = 0;i < 10; ++i) {
        for (j = 0;j < 10;++j) {
            if (i == 0 && j == 0)
                cout << ' ';
            if (j == 0 && i > 0)
                cout << '|';
            if ((i == 0 && j != 0) && j < 8)
                cout << '_';
            if ((j > 0 && i == 9) && j < 8)
                cout << '_';
            if (i == 1 && j < 1)
                cout << ' ';
        }
        if (lives == 6) {
            if (i == 1 )
                cout << "     |";
        }
        if (lives == 5) {
            if (i == 1)
                cout << "     |";
            if (i == 2 )
                cout << "      O";
        }
        if (lives == 4) {
            if (i == 1)
                cout << "     |";
            if (i == 2)
                cout << "      O";
            if (i == 3)
                cout << "     /";
        }
        if (lives == 3) {
            if (i == 1)
                cout << "     |";
            if (i == 2)
                cout << "      O";
            if (i == 3)
                cout << "     /|";
        }
        if (lives == 2) {
            if (i == 1)
                cout << "     |";
            if (i == 2)
                cout << "      O";
            if (i == 3)
                cout << "     /|\\";
        }
        if (lives == 1) {
            if (i == 1)
                cout << "     |";
            if (i == 2)
                cout << "      O";
            if (i == 3)
                cout << "     /|\\";
            if (i == 4 )
                cout << "     /";
        }
        if (lives == 0) {
            if (i == 1)
                cout << "     |";
            if (i == 2) 
                cout << "      O";
            if (i == 3)
                cout << "     /|\\";
            if (i == 4) 
                cout << "     / \\";
        }
       
        cout << endl;
    }
}

void HangmanView::displayCurrentProgress(string s) {
    cout << endl << "            " << s << endl ;
}


void HangmanView::displayUsedLetters(string letters) {
    cout << endl <<  letters << endl;
}