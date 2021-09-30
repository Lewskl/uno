#include <vector>
#include <string>
#include "card.h"
#include "game.h"
#include "player.h"

void Player::draw() {
  if (game->deck.size() == 0)
    game->reshuffle();
  hand.push_back(game->deck.back());
  game->deck.pop_back();
}

void Player::draw(const int draws) {
  for (int i = 0; i < draws; ++i)
    draw();
}

void Player::play(const int cardIndex) {
  Card cardToPlay = hand[cardIndex];
  game->discardPile.push_back(cardToPlay);
  hand.erase(hand.begin() + cardIndex);
  if (hand.size() == 0) {
    if (cardToPlay.getColour() == Colour::WILD) {
      draw(2);
      game->process(cardToPlay);
    }
    else
      game->win(name);
  }
  else
    game->process(cardToPlay);
}