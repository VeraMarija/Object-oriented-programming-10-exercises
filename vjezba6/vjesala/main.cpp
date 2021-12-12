#include "classes.h"
#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>

using namespace std;



int main() {
    
    HangmanController c;

    HangmanView v;
    string s2 = "A B C D E F G H I J K L M N O P Q R S T U V W X Y Z 0 1 2 3 4 5 6 7 8 9";
    c.set_letters_num(s2);
    string s = "movies.txt"; 
    cout << "     GAME STARTS :)" << endl << endl;
    c.model.set_movie(s);
    c.model.set_guessMovie(c.model.get_movie());
    int i = c.model.get_lives();
    cout << endl << "            " << c.model.guessMovie << endl << endl;
    cout << c.get_letters_num() << endl;
    while (i > 0) {

        c.update_guessMovie(c.model.get_movie());
        c.change_letters_num(c.get_letter());
        v.displayHangman(c.model.get_lives());
        v.displayCurrentProgress(c.model.guessMovie);
        v.displayUsedLetters(c.get_letters_num());
        if (i > c.model.get_lives())
            i--;
        cout << endl;
        if (c.win(c.model.guessMovie) == 1) {
            cout << endl << "       YOU WIN !!!  " << endl;
            break;
        }
        if (!c.model.get_lives()) {
            cout << "            " << c.model.get_movie() << endl;
            cout << endl << "         SORRY. YOU ARE DEAD ! " << endl;
        }
    }
        
    
    return 0;

}
 