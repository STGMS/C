#include <stdio.h>
#include <ncurses.h>
#include <math.h>

double sum(double num1, double num2) { return num1 + num2; }

double rest(double num1, double num2) { return num1 - num2; }

double multiply(double num1, double num2) { return num1 * num2; }

double divide(double num1, double num2) {
    if (num2 != 0) {
        return num1 / num2;        
    } else {
        attron(COLOR_PAIR(3));
        printw("Error: Cannot divide by zero \n");
        attroff(COLOR_PAIR(3));
        return NAN;
    }
}

int main() {
    double num1;
    double num2;

    int input;

    initscr();
    start_color();
    echo();

    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_YELLOW, COLOR_BLACK);
    init_pair(3, COLOR_RED, COLOR_WHITE);

    while (1)
    {
        clear();

        attron(COLOR_PAIR(2));
        printw("Enter the first number: \n");
        while (1)
        {
            if (scanw("%lf", &num1) == 1) break;
            attron(COLOR_PAIR(3));
            printw("Error: This is'nt a number. Please enter a valid number: \n");
            attroff(COLOR_PAIR(3));
        }

        printw("Enter the second number: \n");
        while (1)
        {
            if (scanw("%lf", &num2) == 1) break;
            attron(COLOR_PAIR(3));
            printw("Error: This is'nt a number. Please enter a valid number: \n");
            attroff(COLOR_PAIR(3));
        }
        attroff(COLOR_PAIR(2));

        attron(COLOR_PAIR(2));
        printw("Choose an operation (+, -, *, /): \n");
        printw("q. Exit\n");
        printw("0. Continue\n");
        printw("1. Addition (+)\n");
        printw("2. Subtraction (-)\n");
        printw("3. Multiplication (*)\n");
        printw("4. Division (/)\n");
        attroff(COLOR_PAIR(2));
        refresh();

        input = getch();
        printw("\n");

        if (input == 'q')
        {
            attron(COLOR_PAIR(2));
            printw("Exiting the program.\n");
            attroff(COLOR_PAIR(2));
            refresh();
            endwin();
        } else if (input == '0') {
            continue;
        }

        switch (input)
        {
        case '1':
            attron(COLOR_PAIR(1));
            printw("The result is: %.3lf\n", sum(num1, num2));
            attroff(COLOR_PAIR(1));
            refresh();
            break;
        case '2':
            attron(COLOR_PAIR(1));
            printw("The result is: %.3lf\n", rest(num1, num2));
            attroff(COLOR_PAIR(1));
            refresh();
            break;
        case '3':
            attron(COLOR_PAIR(1));
            printw("The result is: %.3lf\n", multiply(num1, num2));
            attroff(COLOR_PAIR(1));
            refresh();
            break;
        case '4':
            attron(COLOR_PAIR(1));
            printw("The result is: %.3lf\n", divide(num1, num2));
            attroff(COLOR_PAIR(1));
            refresh();
            break;
        }

        printw("Press '0' to continue or 'q' to exit: ");
        refresh();
        input = getch();
        printw("\n");

        if (input != 'q' && input != '0' && (input < '1' || input > '4'))
        {
            attron(COLOR_PAIR(3));
            printw("Invalid option.\n");
            attroff(COLOR_PAIR(3));
            refresh();
        }
    }

    refresh();
    getch();
    endwin();
    return 0;
}
