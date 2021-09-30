#include <iostream>
#include <vector>
#include "card.h"
#include "game.h"

int main() {
  Game game({ "p1", "p2" });

  // print deck for testing
  for (int i = 0; i < game.deck.size(); ++i) {
    std::cout << (char)game.deck[i].getColour() << game.deck[i].getNumber() << ',';
  }
  std::cout << std::endl;

}