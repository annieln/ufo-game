#include <iostream>
#include <unordered_set>
#include <cctype>
#include "ufo_functions.hpp"

int main() {

  std::vector<std::string> dictionary = dictionary_generator();
  bool play = true;

  while (play) {
    
    greet();

    std::string codeword = get_word(dictionary);
    std::string answer = std::string(codeword.length(), '_');

    int misses = 0;

    std::vector<char> incorrect;
    std::unordered_set<char> attempts;
    bool guess = false;

    char letter;

    while (answer != codeword && misses < 7) {

      display_misses(misses);

      display_status(incorrect, answer);

      bool valid_letter = false;

      while (!valid_letter) {

        std::cout << "\n\nPlease enter your guess: ";
        std::cin >> letter;

        letter = tolower(letter);

        if (attempts.count(letter)) {

          std::cout << "\n\nYou have already guessed this letter. Try again.";

        } else {

          attempts.insert(letter);
          valid_letter = true;

        }

      }

      for (int i = 0; i < codeword.length(); i++) {
        if (letter == codeword[i]) {

          answer[i] = letter;
          guess = true;

        }

      }

      if (guess) {

        std::cout << "\nCorrect! You're closer to cracking the codeword.\n";

      } else {

        std::cout << "\nIncorrect! The tractor beam pulls the person in further.\n";
        incorrect.push_back(letter);
        misses ++;

      }

      guess = false;
      
    }

    end_game(answer, codeword);

    play = play_again();

  }

}
