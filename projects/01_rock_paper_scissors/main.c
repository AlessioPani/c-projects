// Rock Paper Scissors game written in C.
 
#include "../../common/common.h"

// Custom definition
#define WIN 1
#define DRAW 2
#define LOSS 3

// Custom types
typedef char Input_t;
typedef int Result_t;

// Declaration of functions
Status_t game(Input_t* computerMove, Input_t* userMove, Result_t* result);
Status_t validateUserInput(Input_t* userInput, Validation_t* result);

// Main function
int main() {
  printf("-- Welcome to the Rock Paper Scissors game --\n");

  const int MAX_NUMBER = 100;
  Input_t computerMove = '\0';
  Input_t userMove = '\0';
  Validation_t isValid;
  Result_t result;

  // Current local time to define a unique seed.
  srand(time(0));

  // Main game loop.
  while (userMove != 'e')
  {
    // Generate a random number within the range 0-100.
    int number = rand() % MAX_NUMBER;

    // Define the computer's move.
    if (number >= 0 && number < 33) {
      computerMove = 'r'; // rock
    } else if (number >= 33 && number < 66) {
      computerMove = 'p'; // paper
    } else {
      computerMove = 's'; // scissors
    }

    // Ask the user his move.
    printf("Select your move (Rock: r | Paper: p | Scissors: s | Exit: e): ");
    scanf(" %c", &userMove);

    // Clear the input buffer.
    while (getchar() != '\n');

    // Check for input and args.
    // If everything is fine, run the game and check for arg errors (null pointers).
    if (validateUserInput(&userMove, &isValid) == STATUS_OK)
    {
      if (isValid == VALIDATION_OK)
      {
        if (userMove == 'e')
        {
          printf("Exiting game...\n");
          break;
        }

        if (game(&computerMove, &userMove, &result) == STATUS_OK)
        {
          switch (result)
          {
            case DRAW:
              printf("Draw!\n\n");
              break;
            case LOSS:
              printf("Loss!\n\n");
              break;
            case WIN:
              printf("Win!\n\n");
              break;
            default:
              printf("Unexpected result\n\n");
              break;
          }

        } else {
          printf("Memory error!\n\n");
          return -1;
        }

      } else {
        printf("Unexpected character, try again!\n\n");
      }

    } else {
      printf("Memory error!\n\n");
      return -1;
    }

  }

  return 0;
}

// validateUserInput is a function that validates the user input.
Status_t validateUserInput(Input_t* userInput, Validation_t* result)
{
  Status_t retValue = STATUS_OK;

  if (userInput != NULL && result != NULL)
  {
    if (*userInput == 'r' || *userInput == 'p' || *userInput == 's' || *userInput == 'e') {
      *result = VALIDATION_OK;
    } else {
      *result = VALIDATION_KO;
    }
  } else {
    retValue = STATUS_KO;
  }

  return retValue;
}

// game is the function that actually implements the game's rules
// and returns the result.
Status_t game(Input_t* computerMove, Input_t* userMove, Result_t* result)
{
  Status_t retValue = STATUS_OK;
  *result = LOSS;

  if (computerMove != NULL && userMove != NULL && result != NULL)
  {
    if (*userMove == 'p' && *computerMove == 'r') {
      *result = WIN;
    } else if (*userMove == 'r' && *computerMove == 's') {
      *result = WIN;
    } else if (*userMove == 's' && *computerMove == 'p') {
      *result = WIN;
    } else if (*userMove == *computerMove) {
      *result = DRAW;
    }
  } else {
    retValue = STATUS_KO;
  }

  return retValue;
}
