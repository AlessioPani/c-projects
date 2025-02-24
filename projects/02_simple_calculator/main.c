// Simple calculator with 6 different operations and a proper input check.

#include "../../common/common.h"

// Declaration of functions.
Status_t validateOpCode(OpCode_t* opCode, Validation_t* isValid);

// Main function.
int main() {
  printf("-- Welcome to the Simple Calculator --\n\n");

  OpCode_t opCode;
  Validation_t isValid = false;
  float a;
  float b;
  
  // Select and validate the operation code.
  printf("Select the operation:\n");
  printf("| 1: Addition \t | 2: Subtraction \t | 3: Multiplication \t | 4: Division\n");
  printf("| 5: Logarithm \t | 6: Square \t \t \t \t \t | 0: Exit\n\n");
  printf("=> ");
  scanf("%d", &opCode);

  if (validateOpCode(&opCode, &isValid) == STATUS_OK)
  {
    if (isValid) {
      switch (opCode)
      {
        case 0:
          printf("\n=> Exiting the calculator...\n");
          return 0;
          
        case 1:
          printf("\n--- Sum of two numbers ---\n");
          printf("\nInsert the first number: ");
          if (scanf("%f", &a) != 1) {
            printf("Invalid input. Exiting...\n");
            return -1;
          }
          printf("\nInsert the second number: ");
          if (scanf("%f", &b) != 1) {
            printf("Invalid input. Exiting...\n");
            return -1;
          }
          printf("\n=> The result of %g + %g is %g\n", a, b, a+b);
          break;
          
        case 2:
          printf("\n--- Subtraction of two numbers ---\n");
          printf("\nInsert the first number: ");
          if (scanf("%f", &a) != 1) {
            printf("Invalid input. Exiting...\n");
            return -1;
          }
          printf("\nInsert the second number: ");
          if (scanf("%f", &b) != 1) {
            printf("Invalid input. Exiting...\n");
            return -1;
          }
          printf("\n=> The result of %g - %g is %g\n", a, b, a-b);
          break;
          
        case 3:
          printf("\n--- Multiplication of two numbers ---\n");
          printf("\nInsert the first number: ");
          if (scanf("%f", &a) != 1) {
            printf("Invalid input. Exiting...\n");
            return -1;
          }
          printf("\nInsert the second number: ");
          if (scanf("%f", &b) != 1) {
            printf("Invalid input. Exiting...\n");
            return -1;
          }
          printf("\n=> The result of %g x %g is %g\n", a, b, a*b);
          break;
          
        case 4:
          printf("\n--- Division of two numbers ---\n");
          printf("\nInsert the dividend: ");
          if (scanf("%f", &a) != 1) {
            printf("Invalid input. Exiting...\n");
            return -1;
          }
          printf("\nInsert the divider: ");
          if (scanf("%f", &b) != 1) {
            printf("Invalid input. Exiting...\n");
            return -1;
          }
          if (b != 0) {
            printf("\n=> The result of %g / %g is %g\n", a, b, a/b);
          } else {
            printf("\nDivider must be a non-zero!\n");
          }
          break;
          
        case 5:
          printf("\n--- Logarithm (natural) of a number ---\n");
          printf("\nInsert the number: ");
          if (scanf("%f", &a) != 1) {
            printf("Invalid input. Exiting...\n");
            return -1;
          }
          if (a > 0) {
            printf("\n=> The result of ln(%g) is is %g\n", a, logf(a));
          } else {
            printf("\nThe number must be a positive number!\n");
          }
          break;
          
        case 6:
          printf("\n--- Square of a number ---\n");
          printf("\nInsert the number: ");
          if (scanf("%f", &a) != 1) {
            printf("Invalid input. Exiting...\n");
            return -1;
          }
          printf("\n=> The result of %g * %g is %g\n", a, a, a * a);
          break;
      }
    } else {
      printf("Unexpected operation code. Try again!\n\n");
    }
  } else {
    printf("Memory error!\n\n");
    return -1;
  }
    
  return 0;
}

// validateCode is the method used to validate the operation code provided
// by the user.
Status_t validateOpCode(OpCode_t* opCode, Validation_t* isValid) {
  Status_t retValue = STATUS_OK;

  if (opCode != NULL && isValid != NULL)
  {  
    if (*opCode >= 0 && *opCode <=6)
    {
      *isValid = true;
    } else {
      *isValid = false;
    }
  } else {
    retValue = STATUS_KO;
  }

  return retValue;
}
