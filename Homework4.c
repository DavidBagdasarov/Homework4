#include <stdio.h>
#include <stdlib.h>
#include <conio.h> 

#define KEY_Y 121 // определение кнопки "y", нажатой на клавиатуре
#define KEY_N 110 // определение кнопки "n", нажатой на клавиатуре
#define KEY_ESC 27 // определение кнопки "ESC", нажатой на клавиатуре

int main()
{
    int number, x, y; // задаем переменные: number - количество вершин; x,y - вершины;
    printf("Enter the desired number of vers:\n"); 
    scanf("%d", &number);
    int matr[number][number]; // создаем матрицу
    for (int i=0; i<number; i++)
	{
	   for (int j=0; j<number; j++) 
	   {
	   matr[i][j] = 0; // заполняем матрицу нулями
	   }
    }

	while(1)  
    {
    	printf("\nFor add connection, please, press - y; for creating graph - n; for exit - ESC\n" );
        char c = getch(); // считываем кнопку с клавиатуры
        if(c=='Y') // добавляем возможность использования как заглавных, так и строчных букв
        c='y';
        else if(c=='N')
        c='n';
        switch(c) {
        FILE* file;    
        case KEY_Y:
            printf("\nPlease, write outgoing vertex\n"); 
            scanf("%d",&x);
            while (x > number) // если введенное число больше количества вершин, программа выдаёт ошибку
            {
            	printf("Error, wrong number\n");
            	printf("\nPlease, write outgoing vertex\n"); 
            	scanf("%d",&x);
            }
            printf("\nPlease, write ingoing vertex\n");
            scanf("%d",&y);
            while (y > number) // если введенное число больше количества вершин, программа выдаёт ошибку
            {
            	printf("Error, wrong number\n");
            	printf("\nPlease, write ingoing vertex\n"); 
            	scanf("%d",&y);
            }
            matr [x-1][y-1]=1; // создаём соединения между вершинами
            break;
        case KEY_N:
                    printf("Graph is created");
                    file = fopen("./graph.gv", "w+b"); // cоздание файла формата .gv для чтения и записи ребер графа
                    fputs("graph Graph {\n", file);
                    for (int i = 0;i < number; i++) 
                        for (int j = i; j < number; j++)
                            if (i!=j && matr[i][j]==1 && matr[j][i]==1)
                                {
                                fprintf(file, "\t%d -- %d [color=red];\n", i+1, j+1);
                                fprintf(file, "\t%d -- %d [color=green];\n", j+1, i+1);
                            }  
                            else if (matr[i][j] == 1 && matr[j][i] != 1)  // если мы находим в матрице смежности единицу
                            {  
                                fprintf(file, "\t%d -- %d;\n", i+1, j+1);   
                                } // записываем связь в созданный файл;
                    fputs("}", file);
                    fclose(file);
                    system("dot -Tpng graph.gv -o graph.png");
            break;
        case KEY_ESC: // выход из программы
        	return 0;
        	break;    
        default:
            printf("\nStrict use of y or n is assumed\n");  // вывод ошибки при введении неправильной кнопки
            break;
        }
    }
    return 0; 
    system("pause");
}