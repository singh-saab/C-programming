#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "deck.h"
#include "cards.h"

void print_hand(deck_t * hand){
  for(int i=0;i<hand->n_cards;i++){
    print_card(*hand->cards[i]);
    printf(" ");
  }
}

int deck_contains(deck_t * d, card_t c) {
  for(int i=0;i<d->n_cards;i++){
    if (d->cards[i]->value ==  c.value && d->cards[i]->suit == c.suit){
      return 1;
    }
  }
  return 0;
}

//Helper function for shuffling decks
//Takes a deck and index of two cards and swaps them

void swap (deck_t * deck, int c1, int c2){
  card_t *temp = deck->cards[c1];
  deck->cards[c1] = deck->cards[c2];
  deck->cards[c2] = temp;
}
/*
void shuffle(deck_t * d){
  for(int i=0;i<d->n_cards;i++){
    int randInt = random() % d->n_cards;
    swap(d,i,randInt);
  }
}
*/

void shuffle(deck_t * d){
  card_t ** card =d -> cards ;
  card_t * temp;
  size_t n=d ->n_cards;
  int randarry;
  for (size_t i=0 ;i< n/2 ;i++){
    randarry= random()%(n-i)+i;
    temp=card[i];
    card[i]=card[randarry];
    card[randarry]=temp;
  }
}
void assert_full_deck(deck_t * d) {
  for(int i=0;i<52;i++){
    assert(deck_contains(d,card_from_num(i)));
  }
}
