#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#include "logic.h"

/**
 * Main entry point
 */

#define NAME_LENGTH 20
#define PLAYER_CHOICE 9

int
main ()
  {
    char child_answer [PLAYER_CHOICE];
    char parent_answer [PLAYER_CHOICE];
    char player_one_name[NAME_LENGTH];
    char player_two_name[NAME_LENGTH];
    char winning_player[NAME_LENGTH];
    char* winning_move = NULL;
    int pipe_par_chi[2];
    int pipe_chi_par[2];

    if (pipe (pipe_par_chi) < 0) /* if pipe from parent to child failed */
      {
        printf ("ERROR: Failed to open pipe\n");
        return EXIT_FAILURE;
      }
    if (pipe (pipe_chi_par) < 0) /* if pipe from child to parent failed */
      {
        printf ("ERROR: Failed to open pipe\n");
        return EXIT_FAILURE;
      }
    
    pid_t child_pid = fork ();  /* create a child process */
    
    if (child_pid < 0)          /* if fork failed */
      {
        printf ("ERROR: Failed to create child process");
        return EXIT_FAILURE;
      }

    if (child_pid == 0) /* child process */
      {
        /* child closes write-end of parent to child pipe */
        close (pipe_par_chi[1]);
        /* child closes read-end of child to parent pipe */
        close (pipe_chi_par[0]);

        read (pipe_par_chi[0], parent_answer, PLAYER_CHOICE);

        printf ("What is player 2's name?\n");
        read (STDIN_FILENO, player_two_name, NAME_LENGTH);
        printf ("What is player 2's choice?\n");
        read (STDIN_FILENO, child_answer, PLAYER_CHOICE);
        printf ("Player 1's answer - %s", parent_answer);
        printf ("Player 2's answer - %s", child_answer);        

        winning_move = get_winning_play (parent_answer, child_answer);
        printf ("winning move - %s\n", winning_move);
        write (pipe_chi_par[1], player_two_name, NAME_LENGTH);
      /* do logic of figuring out who won here */
      /* use helper function to figure this out, maybe create another .c/.h */

        exit (0);

      }

    /* parent closes read-end of child to parent pipe */
    close (pipe_par_chi[0]);
    /* parent closes write-end of parent to child pipe */
    close (pipe_chi_par[1]);

    printf ("What is player 1's name?\n");
    read (STDIN_FILENO, player_one_name, NAME_LENGTH);
    printf ("What is player 1's choice?\n");
    read (STDIN_FILENO, parent_answer, PLAYER_CHOICE);
    
    write (pipe_par_chi[1], parent_answer, PLAYER_CHOICE);

    wait (NULL);

    /* Read the winner of the game from the child */
    read (pipe_chi_par[0], winning_player, NAME_LENGTH);
    /* will have to remove null byte here */
    printf ("%s won the game!\n", winning_player);

    printf("Ending Success!\n");
    return EXIT_SUCCESS;
  }
