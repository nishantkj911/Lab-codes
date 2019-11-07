int main()
{
    int a, b;
    a = 10, b = 20;
    if (a >= b && b < 30)
    {
        for (int i = 1; i <= 10; i++)
        {
            a = b + 1;
        }
    }

    printf("A value is %i", a);
    printf("A is of int type");
}
