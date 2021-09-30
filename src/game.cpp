#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include "card.h"
#include "game.h"

Game::Game(const std::vector<std::string>& playerNames) {
  Colour colours[4] = { Colour::BLUE, Colour::RED, Colour::GREEN, Colour::YELLOW };

  for (int colourIndex = 0; colourIndex < 4; ++colourIndex) {
    Colour colour = colours[colourIndex];
    deck.push_back(Card(colour, 0));
    // 10 = +2
    // 11 = reverse
    // 12 = skip
    for (int number = 1; number < 13; ++number) {
      deck.push_back(Card(colour, number));
      deck.push_back(Card(colour, number));
    }
    // wild 0 = wildcard, wild 4 = draw 4
    deck.push_back(Card(Colour::WILD, 0));
    deck.push_back(Card(Colour::WILD, 4));
  }
  //shuffle(deck);


  for (auto name = playerNames.begin(); name < playerNames.end(); ++name)
    playerList.push_back(Player(this, *name));

  for (auto player = playerList.begin(); player < playerList.end(); ++player)
    player->draw(7);
}

void Game::shuffle(std::vector<Card>& deck) {
  const unsigned seed = std::chrono::system_clock::now()
    .time_since_epoch()
    .count();
  std::shuffle(std::begin(deck), std::end(deck), std::default_random_engine(seed));
}

void Game::reshuffle() {
  deck.insert(deck.end(), discardPile.begin(), discardPile.end() - 1);
  discardPile.erase(discardPile.begin(), discardPile.end() - 1);
  shuffle(deck);
}

void Game::process(Card card) {}

void Game::win(std::string winnerName) {}
