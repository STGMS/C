#include <stdio.h>
#include <ncurses.h>

double sum(double num1, double num2) {
    return num1 + num2;
}

double rest(double num1, double num2) {
    return num1 - num2;
}

double multiply(double num1, double num2) {
    return num1 * num2;
}

double divide(double num1, double num2) {
    if (num2 != 0) {
        return num1 / num2;        
    } else {
        printw("Error: I have not divisible \n");
        return 0.0;
    }
}

int main() {
    double num1;
    double num2;

    initscr();
    echo();

    printw("Enter the first number: \n");
    refresh();
    scanw("%lf", &num1);

    printw("Enter the second number: \n");
    refresh();
    scanw("%lf", &num2);


    printw("Choose an operation (+, -, *, /): \n");
    printw("1. Addition (+)\n");
    printw("2. Subtraction (-)\n");
    printw("3. Multiplication (*)\n");
    printw("4. Division (/)\n");

    refresh();


    int input = getch();
    printw("\n");

    if (input == '1') 
    {
        printw("The result is: %lf\n", sum(num1, num2));
        refresh();
    }

    if (input == '2') 
    {
        printw("The result is: %lf\n", rest(num1, num2));
        refresh();
    }

    if (input == '3') 
    {
        printw("The result is: %lf\n", multiply(num1, num2));
        refresh();
    }

    if (input == '4') 
    {
        printw("The result is: %lf\n", divide(num1, num2));
        refresh();
    }

    if (input != '1' && input != '2' && input != '3' && input != '4')
    {
        printw("Invalid option.\n");
    }

    printw("\nPress any key to exit...");
    refresh();
    getch();
    endwin();
    return 0;

}

