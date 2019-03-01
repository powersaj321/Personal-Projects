#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "logic.h"

/* Gathers winning play based on rock, paper, scissors, lizard, spock logic */

char* get_winning_play (char* first_play, char* second_play)
  {
    char* game_names[] = {"rock", "paper", "scissors", "lizard", "spock"};         

    printf ("3: %d\n", strcmp (first_play, game_names[0]));
    printf ("4: %d\n", strcmp (second_play, game_names[1]));
    printf ("5: %d\n", (10 && 10));

    printf ("1: %d\n", (strcmp (first_play, game_names[0]) && strcmp (second_play, game_names[1])));
    printf ("2: %d\n", (strcmp (second_play, game_names[0]) && strcmp (first_play, game_names[1])));

    //printf ("6: %d\n", ((strcmp (first_play, game_names[0]) && strcmp (second_play, game_names[1]))
    //      || (strcmp (second_play, game_names[0]) && strcmp (first_play, game_names[1]))));
    if (1)
      {
        printf ("1 is true");
      }

    if (strcmp (first_play, second_play) == 0)
      { /* same play by both players */
        return "Tie!";
      }
    else if ((strcmp (first_play, game_names[0]) && strcmp (second_play, game_names[1]))
          || (strcmp (second_play, game_names[0]) && strcmp (first_play, game_names[1])))
      { /* paper beats rock */
        printf ("Herer");
        return game_names[1];
      }
    else if ((!strcmp (first_play, game_names[0]) && (!strcmp (second_play, game_names[2])))
          || ((!strcmp (second_play, game_names[0])) && (!strcmp (first_play, game_names[2]))))
      {  /* rock beats scissors */
        printf ("This is what we want\n");
        return game_names[0];
      }
    else if ((!strcmp (first_play, game_names[0]) && (!strcmp (second_play, game_names[3])))
          || ((!strcmp (second_play, game_names[0])) && (!strcmp (first_play, game_names[3]))))
      { /* rock crushes lizard */
        return game_names[0];
      }
    else if ((!strcmp (first_play, game_names[0]) && (!strcmp (second_play, game_names[4])))
          || ((!strcmp (second_play, game_names[0])) && (!strcmp (first_play, game_names[4]))))
      { /* spock vaporizes rock */
        return game_names[4];
      }
    else if ((!strcmp (first_play, game_names[1]) && (!strcmp (second_play, game_names[2])))
          || ((!strcmp (second_play, game_names[1])) && (!strcmp (first_play, game_names[2]))))
      { /* scissors cuts paper */
        return game_names[2];
      }
    else if ((!strcmp (first_play, game_names[1]) && (!strcmp (second_play, game_names[3])))
          || ((!strcmp (second_play, game_names[1])) && (!strcmp (first_play, game_names[3]))))
      { /* lizard eats paper */
        return game_names[3];
      }
    else if ((!strcmp (first_play, game_names[1]) && (!strcmp (second_play, game_names[4])))
          || ((!strcmp (second_play, game_names[1])) && (!strcmp (first_play, game_names[4]))))
      { /* paper disproves spock */
        return game_names[1];
      }
    else if ((!strcmp (first_play, game_names[2]) && (!strcmp (second_play, game_names[3])))
          || ((!strcmp (second_play, game_names[2])) && (!strcmp (first_play, game_names[3]))))
      { /* scissors decapitates lizard */
        return game_names[2];
      }
    else if ((!strcmp (first_play, game_names[2]) && (!strcmp (second_play, game_names[4])))
          || ((!strcmp (second_play, game_names[2])) && (!strcmp (first_play, game_names[4]))))
      { /* spock smashes scissors */
        return game_names[4];
      }
    else if ((!strcmp (first_play, game_names[3]) && (!strcmp (second_play, game_names[4])))
          || ((!strcmp (second_play, game_names[3])) && (!strcmp (first_play, game_names[4]))))
      { /* lizard poisons spock */
        return game_names[3];
      }

    return NULL;
  }

/* sets all letters of char* to lower case */
char* to_lowercase (char* converted_word)
  {
    size_t length = strlen (converted_word);

    if (length == 0)
      {
        return NULL;
      }

    for (size_t ii = 0; ii < length; ii++)
      {
        converted_word[ii] = tolower (converted_word[ii]);
      }

    return converted_word;
  }



