#pragma once
#include <string>

enum class Colour {
  BLUE   = 'b',
  RED    = 'r',
  GREEN  = 'g',
  YELLOW = 'y',
  WILD   = 'w',
};


class Card {
private:
  Colour colour;
  int number;

public:
  Card() = delete;
  Card(Colour c, int n);

  const Colour getColour() const { return colour; }
  const int getNumber() const { return number; }
  const std::string toString() const;
};