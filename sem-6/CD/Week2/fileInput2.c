#include <conio.h> //Remove preprocessor directive

int main()
{
    /** write a C program
     * to generate tokens **
     */
    int a, b;
    a = 10, b = 20; //assigment initialisation
    if (a >= b && b < 30) // logical
    {
        for (int i = 1; i <= 10; i++)
        {
            a = b + 1;
        }
    }

    printf("A value is %i", a);
    printf("A is of int type");
}
