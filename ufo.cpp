#include <iostream>
using namespace std;
#include "ufo_functions.hpp"
#include <cstdlib>
#include <ctime>

int main() {
  
  char play_again = 'N';

  do {

    string codewords[10] = {"codecademy", "raptors", "canucks", "basketball", "baseball", "hockey", "house", "kelowna", "stairs", "chair"};

    srand((unsigned) time(0));

    int random_number = rand() % 10;

    string codeword = codewords[random_number];

    string answer = "";

    for (int i = 0; i < codeword.length(); i++){
      
      answer = answer + "_";
    }
    
    int misses = 0;
    vector<char> incorrect;
    bool guess = false;
    char letter;
   
    greet();

    while (answer != codeword && misses < 7) {
    
      display_misses(misses);

      display_status(incorrect, answer);

      cout << "\nPlease enter your guess:";

      cin >> letter;

      letter = tolower(letter);

      for (int i = 0; i < codeword.length(); i++){
      
        if (letter == codeword[i]) {
         
          answer[i] = letter;
          guess = true;

        }
      }
    
    if (guess) {
       
       cout << "\nCorrect!\n";

     }
    else {
      
      cout << "\nIncorrect! The tractor beam pulls the person in further.\n";
      
      incorrect.push_back(letter);

      misses++;
    }

    guess = false;
  }

  end_game(answer, codeword);

  cout << "\nWould you like to play again? (Y for Yes or N for No)\n";

  cin >> play_again;

  play_again = toupper(play_again);

  } while (play_again == 'Y');
}
