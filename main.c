#include <stdio.h>
#include <stdlib.h>

// In this game the player must hit the proposed calculation

typedef struct {
    int level;
    int value1;
    int value2;
    int operation;
    int result;
} Calculate;

void play();
void show(Calculate calc);
int sum(int answer, Calculate calc);
int subtract(int answer, Calculate calc);
int multiply(int answer, Calculate calc);
int divide(int answer, Calculate calc);

int points = 0;

int main(){

    srand(time(NULL)); //most be called just once
    play();
    return 0;
}


void play(){
    Calculate calc;

    printf("Choice the difficulty level [1, 2, 3, 4]:\n");
    scanf("%d", &calc.level);

    //It generates 4 random numbers from 0 to 3
    // 0 == Sum, 1 == Subtract, 2 == Multiply, 3 == Divide
    calc.operation = rand() % 3;

    if(calc.level == 1) {
        //Easy
        calc.value1 = rand() % 11; //range from 0 to 10
        calc.value2 = rand() % 11; //range from 0 to 10
    } else if(calc.level == 2){
        //Medium
        calc.value1 = rand() % 101; //range from 0 to 100
        calc.value2 = rand() % 101; //range from 0 to 100
    } else if(calc.level == 3){
        //Hard
        calc.value1 = rand() % 1001; //range from 0 to 1000
        calc.value2 = rand() % 1001; //range from 0 to 1000
    } else if(calc.level == 4){
        //Insane
        calc.value1 = rand() % 10001; //range from 0 to 10000
        calc.value2 = rand() % 10001; //range from 0 to 10000
    } else {
        printf("Invalid choice. Try again!\n");
        play();
    }

    int answer;
    printf("What is the correct answer for this calculation:\n");

    //Sum
    if(calc.operation == 0) {
        printf("%d + %d\n", calc.value1, calc.value2);
        scanf("%d", &answer);

        if(sum(answer, calc)){
            points += 1;
            printf("You have %d point(s)\n", points);
        }
        show(calc);
    } //Subtract
    else if(calc.operation == 1) {
        printf("%d - %d\n", calc.value1, calc.value2);
        scanf("%d", &answer);

        if(subtract(answer, calc)){
            points += 1;
            printf("You have %d point(s)\n", points);
        }
        show(calc);
    } // Multiply
    else if(calc.operation == 2) {
        printf("%d x %d\n", calc.value1, calc.value2);
        scanf("%d", &answer);

        if(multiply(answer, calc)){
            points += 1;
            printf("You have %d point(s)\n", points);
        }
        show(calc);
    } //Divide
    else if(calc.operation == 3) {
        printf("%d / %d\n", calc.value1, calc.value2);
        scanf("%d", &answer);

        if(divide(answer, calc)){
            points += 1;
            printf("You have %d point(s)\n", points);
        }
        show(calc);
    } //Unknown
    else {
        printf("Unknown operation %d.\n", calc.operation);
    }

    //Play again
    printf("Do you want play again? [1 - YES, 2 - NO] ");
    int p_again;
    scanf("%d", &p_again);

    if(p_again == 1) {
        play();
    } else {
        printf("Your total points were %d", points);
        exit(0);
    }


}

void show(Calculate calc){
    char options[25];

    if(calc.operation == 0) {
       sprintf(options, "Sum");
    }else if(calc.operation == 1) {
        sprintf(options, "Subtract");
    }else if(calc.operation == 2) {
        sprintf(options, "Multiply");
    }else if(calc.operation == 3) {
        sprintf(options, "Divide");
    }else{
        sprintf(options, "Invalid operation");
    }

    printf("Value 1: %d \nValue 2: %d \nLevel: %d \nOperation: %s", calc.value1, calc.value2,
            calc.level, options);
}

int sum(int answer, Calculate calc){
    calc.result = calc.value1 + calc.value2;
    int correct = 0; //0 for incorrect; 1 for correct

    if(answer == calc.result){
        printf("Correct answer!!!\n");
        correct = 1;
    } else {
        printf("Incorrect answer!!!\n");
    }

    printf("%d + %d = %d\n", calc.value1, calc.value2, calc.result);

    return correct;
}

int subtract(int answer, Calculate calc){
    calc.result = calc.value1 - calc.value2;
    int correct = 0; //0 for incorrect; 1 for correct

    if(answer == calc.result){
        printf("Correct answer!!!\n");
        correct = 1;
    } else {
        printf("Incorrect answer!!!\n");
    }

    printf("%d - %d = %d\n", calc.value1, calc.value2, calc.result);

    return correct;
}

int divide(int answer, Calculate calc){
    calc.result = calc.value1 / calc.value2;
    int correct = 0; //0 for incorrect; 1 for correct

    if(answer == calc.result){
        printf("Correct answer!!!\n");
        correct = 1;
    } else {
        printf("Incorrect answer!!!\n");
    }

    printf("%d / %d = %d\n", calc.value1, calc.value2, calc.result);

    return correct;
}

int multiply(int answer, Calculate calc){
    calc.result = calc.value1 * calc.value2;
    int correct = 0; //0 for incorrect; 1 for correct

    if(answer == calc.result){
        printf("Correct answer!!!\n");
        correct = 1;
    } else {
        printf("Incorrect answer!!!\n");
    }

    printf("%d x %d = %d\n", calc.value1, calc.value2, calc.result);

    return correct;
}


