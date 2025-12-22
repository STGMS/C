#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <math.h>
#include <gmp.h>
#include <gtk/gtk.h>    // Soon

int main() {
    double result = 0.0;    // Acumulador
    double num;      // Numero ingresado
    char op;        // Operacion ingresada
    char last_op = '\0';    // Ultima operacion pendiente

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
        printw("operations (+, -, *, /): \n");
        printw("q. Exit                         %%. Modulo                          c. Ceiling\n");
        printw("0. Continue                     s. Square root                      f. Floor\n");
        printw("+. Addition                     a. Absolute value\n");
        printw("-. Subtraction                  p. Power\n");
        printw("*. Multiplication               e. Exponential\n");
        printw("/. Division                     l. Natural logarithm\n");
        printw("=. Equal                        g. Base-10 logarithm\n");
        attroff(COLOR_PAIR(2));

        attron(COLOR_PAIR(2));
        printw("Enter the your operation: \n");

        while (1)
        {
            if (scanw("%lf", &num) == 1) break;
            attron(COLOR_PAIR(3));
            printw("Error: This is'nt a number. Please enter a valid number: \n");
            attroff(COLOR_PAIR(3));
        }
        attroff(COLOR_PAIR(2));
        refresh();

        flushinp();
        op = getch();
        printw("\n");

        if (op == 'q')
        {
            attron(COLOR_PAIR(2));
            printw("Exiting the program.\n");
            attroff(COLOR_PAIR(2));
            refresh();
            endwin();
            return 0;
        } else if (op == '0') {
            continue;
        }

    if (last_op == '\0') {
        result = num;
    } else {
        switch (last_op) {
            case '+':
                result += num;
                break;
            case '-':
                result -= num;
                break;
            case '*':
                result *= num;
                break;
            case '/':
                if (num != 0) {
                    result /= num;
                } else {
                    attron(COLOR_PAIR(3));
                    printw("Error: Division by zero is not allowed.\n");
                    attroff(COLOR_PAIR(3));
                    refresh();
                }
                break;
            case '%':
                if (num != 0) {
                    result = fmod(result, num);
                } else {
                    attron(COLOR_PAIR(3));
                    printw("Error: Division by zero is not allowed.\n");
                    attroff(COLOR_PAIR(3));
                    refresh();
                }
                break;
            case 's':
                if (num < 0) {
                    attron(COLOR_PAIR(3));
                    printw("Error: Cannot compute square root of a negative number.\n");
                    attroff(COLOR_PAIR(3));
                } else {
                    result = sqrt(num);
                }
                break;
            case 'a':
                result = fabs(result);
                break;
            case 'p':
                result = pow(result, num);
                break;
            case 'e':
                result = exp(result);
                break;
            case 'l':
                if (result <= 0) {
                    attron(COLOR_PAIR(3));
                    printw("Error: Cannot compute logarithm of non-positive number.\n");
                    attroff(COLOR_PAIR(3));
                } else {
                    result = log(result);
                }
                break;
            case 'g':
                if (result <= 0) {
                    attron(COLOR_PAIR(3));
                    printw("Error: Cannot compute logarithm of non-positive number.\n");
                    attroff(COLOR_PAIR(3));
                } else {
                    result = log10(result);
                }
                break;
            case 'c':
                result = ceil(result);
                break;
            case 'f':
                result = floor(result);
                break;
            default:
                attron(COLOR_PAIR(3));
                printw("Unknown pending operator : %c\n", last_op);
                attroff(COLOR_PAIR(3));
                refresh();
        }
    }

    if (op == '=') {
        attron(COLOR_PAIR(1));
        printw("The result is: %.10g\n", result);
        attroff(COLOR_PAIR(1));
        last_op = '\0';
        } else if (op == 'q' || op == '0' || op == '+' || op == '-' || op == '*' || op == '/' || op == 's' || op == '%' 
            || op == 'a' || op == 'p' || op == 'e' || op == 'l' || op == 'g' || op == 'c' || op == 'f') {
            last_op = op;
        } else {
            attron(COLOR_PAIR(3));
            printw("Error: Unknown operator %c:\n", op);
            attroff(COLOR_PAIR(3));
            refresh();
        }

        printw("Press '0' to continue or 'q' to exit: ");
        refresh();
        op = getch();
        printw("\n");

        if (op == 'q') {
            endwin();
            return 0;
        }
    }

    endwin();
    return 0;
}