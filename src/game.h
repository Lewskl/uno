#pragma once
#include <vector>
#include <string>
#include "player.h"
#include "card.h"

class Game {
private:
  static void shuffle(std::vector<Card>&);

private:
  std::vector<Player> playerList;
public:
  std::vector<Card> deck;
  std::vector<Card> discardPile;

  Game() = delete;
  Game(const std::vector<std::string>& playerNames);

  void reshuffle();

  void process(Card card);

  void win(std::string winnerName);
};