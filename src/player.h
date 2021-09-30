#pragma once
#include <vector>
#include <string>
#include "card.h"

class Game;

class Player {
private:
  Game* game;
  std::vector<Card> hand;
  std::string name;

public:
  Player() = delete;
  Player(Game* g, std::string n)
    : game(g), name(n) {};

  void draw();
  void draw(const int draws);

  void play(int cardIndex);
};