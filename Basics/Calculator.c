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

    printw("Ingrese el primer número: \n");
    refresh();
    scanw("%lf", &num1);

    printw("Ingrese el segundo número: \n");
    refresh();
    scanw("%lf", &num2);


    printw("Elija una operación (+, -, *, /): \n");
    printw("1. Suma (+)\n");
    printw("2. Resta (-)\n");
    printw("3. Multiplicación (*)\n");
    printw("4. División (/)\n");

    refresh();


    int input = getch();
    printw("\n");

    if (input == '1') 
    {
        printw("El resultado es: %lf\n", sum(num1, num2));
        refresh();
    }

    if (input == '2') 
    {
        printw("El resultado es: %lf\n", rest(num1, num2));
        refresh();
    }

    if (input == '3') 
    {
        printw("El resultado es: %lf\n", multiply(num1, num2));
        refresh();
    }

    if (input == '4') 
    {
        printw("El resultado es: %lf\n", divide(num1, num2));
        refresh();
    }

    if (input != '1' && input != '2' && input != '3' && input != '4')
    {
        printw("Opción no válida.\n");
    }

    printw("\nPresione cualquier tecla para salir...");
    refresh();
    getch();
    endwin();
    return 0;

}
