#include <vector>

void display_misses(int misses);

// Declare functions
void greet();

std::vector<std::string> dictionary_generator();

std::string get_word(std::vector<std::string> dictionary);

void end_game(std::string answer, std::string codeword);

void display_status(std::vector<char> incorrect, std::string answer);

bool play_again();