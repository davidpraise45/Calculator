/** Created by David Praise Chukwuma Kalu **/

// Includes
#include <stdio.h>
#include <stdlib.h>

// GLOBAL VARIABLES
float  firstFloatInput; // FIRST FLOAT
float  secondFloatInput; // SECOND FLOAT
int operationToPerform; // SELECT AN OPERATION TO PERFORM
int wouldYouLikeToKeepWorking;

//menu();

int main(){
    // WELCOME MESSAGE
    printf("\nWelcome new user to our most efficient and reliable calculator.\nPlease follow the instructions below.\n");
    menu();

    return 0;
}


int menu(){
    int options = 0;

    while(1){

        if(options == 0){
            messages();
            printf("\nEnter which operation you would like to perform, from 1 - 8 : ");
            scanf("%d", &operationToPerform);
            if(operationToPerform <= 0 || operationToPerform >= 9){ // CHECK IF THE OPERTAION TO PERFORM IS OUT OF BOUND
                printf("Invalid input");
                continue;
            }else{
                getInputFromUser();
                option(operationToPerform);
            }
            ++options; // TO ASK THE USER IF HE WANTS TO CONTINUE
        }else{
            continueDoingCalculation();
             // To end the program or not
            if(wouldYouLikeToKeepWorking == 0){
                break;
            }
        }
    }
	return 0;
}

void continueDoingCalculation(){


	int useExistingNumberOrNewNumbers;
	int continueOrExitTheProgram = 1;

    while(continueOrExitTheProgram){

        printf("\nWould you like to keep working. \nEnter 0 to exit\nEnter 1 to continue\n");
        scanf("%d", &wouldYouLikeToKeepWorking);

        if(wouldYouLikeToKeepWorking == 1){
            printf("\nWould you like to use your previous number or enter a new number\n"
            "Enter 0 to use previous number\nEnter 1 to use new numbers \n");
            scanf("%d", &useExistingNumberOrNewNumbers);

            if(useExistingNumberOrNewNumbers == 1){
                messages();
                printf("\nEnter which operation you would like to perform, from 1 - 8 : ");
                scanf("%d", &operationToPerform);

                if(operationToPerform <= 0 || operationToPerform >= 9){
                    printf("Invalid input");
                    break;

                }else{
                    getInputFromUser();
                    option(operationToPerform);
                }

            }else if(useExistingNumberOrNewNumbers == 0){

                messages();
                printf("\nEnter which operation you would like to perform, from 1 - 8 : ");
                scanf("%d", &operationToPerform);
                if(operationToPerform <= 0 || operationToPerform >= 9){
                    printf("Invalid input");
                    break;
                }else{
                    option(operationToPerform);
                }

            }else{
                printf("Invalid-Input");
            }
        }
        else if (wouldYouLikeToKeepWorking == 0){
            printf("\nThank you for using the most efficient calculator\n");
            break;

        }else{
            printf("\nInvalid Input");
        }

        break;
    }
}

// MESSAGES TO DISPLAY TO THE USER.
void messages(){

    printf("\nselect which of these operations he would like to do.\n");
    printf("\nTo get the 'addition' of your numbers, enter: 1\n");
    printf("To get the 'difference' of two numbers, enter: 2\n");
    printf("To get the 'product' of two numbers, enter: 3\n");
    printf("To get the 'square root / ratio' of two numbers, enter: 4\n");
    printf("To get the 'sum of squares' from two numbers, enter: 5\n");
    printf("To get the 'sum of cube' from two numbers, enter: 6\n");
    printf("To get the 'ratio of squares' from two numbers, enter: 7\n");
    printf("To get the 'ratio of cubes' from two numbers, enter: 8\n");

}

// GETTING INPUTS FROM THE USER.
int getInputFromUser(){

    printf("\nEnter your first float\n");
    scanf("%f", &firstFloatInput);

    printf("\nEnter your second float\n");
    scanf("%f", &secondFloatInput);

    return 0;
}

// MAIN LOGIC FOR ALL THE MATHEMATIC OPERATIONS
// RETURNS THE SUM OF TWO NUMBERS
float add(float firstFloat, float secondFloat){ return  (firstFloat + secondFloat); }

// RETURNS THE DIFFERENCE OF TWO NUMBERS
float difference(float firstFloat, float secondFloat){  return (firstFloat - secondFloat); }

// RETURNS THE PRODUCT OF TWO NUMBERS
float product(float firstFloat, float secondFloat){ return (firstFloat * secondFloat);  }

// RETURNS THE RATIO OF TWO NUMBERS
float ratio(float firstFloat, float secondFloat){
    float result = 0.0;
    if(secondFloat == 0){   printf("Can't perform a division by 0");    return result;  }
    else{   result = (firstFloat*1.0) / (secondFloat*1.0);   return result;   }
}

// RETURN THE CUBE OF A NUMBER
float cubes(float cubedFloat){  return (cubedFloat * cubedFloat); }

// RETURNS THE SQUARE OF A NUMBER
float squares(float cubedFloat){    return (cubedFloat * cubedFloat * cubedFloat);    }
// RETURNS THE SUM OF TWO SQUARED NUMBERS.

float sumOfSquares(float firstFloat, float secondFloat){    return  (squares(firstFloat)+ squares(secondFloat));    }
// RETURNS THE SUM OF TWO CUBE NUMBERS.
float sumOfCubes(float firstFloat, float secondFloat){  return  (cubes(firstFloat) + cubes(secondFloat)); }

// RETURNS THE RATION OF TWO SQUARES
float ratioOfSquares(float firstFloat, float secondFloat){  return  (squares(firstFloat) / squares(secondFloat));   }

// RETURNS THE RATION OF TWO CUBES
float ratioOfCubes(float firstFloat, float secondFloat){   return   (cubes(firstFloat) / cubes(secondFloat));  }

//  THE OPTIONS THE USER HAS
int option(int operationToPerform){

    switch(operationToPerform){

    case 1: printf("\nThe sum is : %f\n",add(firstFloatInput, secondFloatInput));
            break;

    case 2: printf("\nThe difference is : %f\n",difference(firstFloatInput, secondFloatInput));
            break;

    case 3: printf("\nThe product is : %f\n",product(firstFloatInput, secondFloatInput));
            break;

    case 4: printf("\nThe ratio is : %f\n",ratio(firstFloatInput, secondFloatInput));
            break;

    case 5: printf("\nThe sum of a square float is : %f\n",sumOfSquares(firstFloatInput, secondFloatInput));
            break;

    case 6: printf("\nThe sum of a cube float is : %f\n",sumOfCubes(firstFloatInput, secondFloatInput));
            break;

    case 7: printf("\nThe ratio of a square float is : %f\n",ratioOfSquares(firstFloatInput, secondFloatInput));
            break;

    case 8: printf("\nThe ratio of a cube float is : %f\n",ratioOfCubes(firstFloatInput, secondFloatInput));
            break;

    default: printf("\nInvalid Input-**Entered by the user.\n");
            break;

    }
    return 0;
}

