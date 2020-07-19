#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cards.h"


void assert_card_valid(card_t c) {
  assert(c.value>=2 && c.value <=VALUE_ACE);
  assert(c.suit>=SPADES &&c.suit <=CLUBS);

}

const char * ranking_to_string(hand_ranking_t r) {
  switch(r){
  case STRAIGHT_FLUSH:
    return "STRAIGHT_FLUSH";
    break;
  case FOUR_OF_A_KIND:
    return "FOUR_OF_A_KIND";
    break;
  case FULL_HOUSE:
    return "FULL_HOUSE";
    break;
  case FLUSH:
    return "FLUSH";
    break;
  case STRAIGHT:
    return "STRAIGHT";
    break;
  case THREE_OF_A_KIND:
    return "THREE_OF_A_KIND";
    break;
  case TWO_PAIR:
    return "TWO_PAIR";
    break;
  case PAIR:
    return "PAIR";
    break;
  default:
  return "NOTHING";
  break; 
}

}

char value_letter(card_t c) {
  
static const  char* letters = "234567890JQKA";
  
  
  return letters[c.value-2];
}


char suit_letter(card_t c)
{
 static const char* string="shdcN";
  
  return string[c.suit];
  
}

void print_card(card_t c) {
  printf("%c%c",value_letter(c),suit_letter(c) );

}
card_t  card_from_letters(char value_let, char suit_let) {
static const  char* value_letter ="234567890JQKA";
static const  char* suit_letter="shdc";
   card_t temp;
   int i;

   for (i=0;i<14;i++){
     if (value_letter[i]==value_let)
       {      temp.value=i+2;
	 break;
       }
   }
   if( temp.value>14){
     printf("invalid value letter : %c \n",value_let);
     exit( EXIT_FAILURE) ;
   }

   for(i=0;i<4;i++){
     if (suit_letter[i] ==suit_let){
       temp.suit = i;
       break;
     }
   }
   if (temp.suit==NUM_SUITS){
     printf("invalid suit :%c",suit_let);
     exit( EXIT_FAILURE);
   }
  
  return temp;
}

card_t card_from_num(unsigned c) {
  card_t temp;
  temp.suit=c/13;
  temp.value =c%13 +2;
  return temp;
}
