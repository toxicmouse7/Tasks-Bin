#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    int n, p;
    int* mass;
    BOOL flag; //"зачеркивали" ли число для данного p
    printf("Input n: ");
    scanf_s("%d", &n);
    if (n >= 2)
    {
        n--; //теперь n - это количесвтво чисел в массиве
        mass = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++)
            mass[i] = i + 2;
        for (int i = 0; i < n; i++)
        {
            p = mass[i];
            flag = 0;
            for (int j = i + 1; j < n; j++)
            {
                if (!(mass[j] % p))
                {
                    for (int k = j; k < n - 1; k++)
                        mass[k] = mass[k + 1];
                    flag = 1;
                    n--; 
                    j--;
                }
            }
            if (flag == 0) break;
        }
        for (int i = 0; i < n; i++)
            printf("%d ", mass[i]);
        free(mass);
    }
    else
        printf("Error. n must be >= 2\n");

    _getch();
    return 0;
}