#include "card.h"

Card::Card(Colour c, int n) {
  colour = c;
  number = n;
}

const std::string Card::toString() const {
  return std::string(1, (char)colour) + std::to_string(number);
}