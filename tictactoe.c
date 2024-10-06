#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>


void create_matrix(int ***point, int n, int m)
{
    *point = (int **)malloc(n * sizeof(int *));
    for(int i = 0; i<n; i++)
    {
        (*point)[i] = (int *)malloc(m * sizeof(int));
    }
    for(int i =0; i<n; i++)
    {
        for(int j = 0; j<m; j++)
        {
            (*point)[i][j] = 0;
        }
    }
}

void print_matrix(int **matrix, int n, int m)
{
    for(int i =0; i<n; i++)
    {
        for(int j = 0; j<m; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int check_winner(int **matrix, int player)
{
    for (int i = 0; i < 3; i++)
    {
        if ((matrix[i][0] == player && matrix[i][1] == player && matrix[i][2] == player) ||
            (matrix[0][i] == player && matrix[1][i] == player && matrix[2][i] == player))
        {
            return 1;
        }
    }
    if ((matrix[0][0] == player && matrix[1][1] == player && matrix[2][2] == player) ||
        (matrix[0][2] == player && matrix[1][1] == player && matrix[2][0] == player))
    {
        return 1;
    }
    return 0;
}

int main()
{
    srand(time(NULL));
    int n = 3;
    int m = 3;
    int **matrix;
    int start;
    create_matrix(&matrix, n, m);
    start = rand() % 2;
    int botwin = 0;
    int playerwin = 0;
    int draw = 0;






    if (start == 0)
    {
        printf("Vous commencez (vous jouez les 1 tandis que le bot joue les 2) \n");
        int tour = 0;
        print_matrix(matrix, n, m);
        while (botwin == 0 && playerwin == 0 && draw == 0)
        {
            int choix;
            while(tour == 0)
            {
                printf("Ou voulez vous ecrire : (vous avez le choix entre case 0, 1, 2, 3, 4, 5, 6, 7, 8, 9) \n");
                scanf("%d", &choix);
                if (choix == 0 || choix == 1 || choix == 2)
                {
                    if (matrix[0][choix] != 0)
                    {
                        printf("Case deja remplie\n");
                    }
                    else
                    {
                        matrix[0][choix] = 1;
                        print_matrix(matrix, n, m);
                        if (check_winner(matrix, 1) == 1)
                        {
                            playerwin = 1;
                            printf("Vous avez gagne\n");
                            exit(0);
                        }

                        tour = 1;
                    }
                }

                else if (choix == 3 || choix == 4 || choix == 5)
                {
                    if (choix == 3)
                    {
                        choix = 0;
                    }
                    if (choix == 4)
                    {
                        choix = 1;
                    }
                    if (choix == 5)
                    {
                        choix = 2;
                    }
                    
                    if (matrix[1][choix] != 0)
                    {
                        printf("Case deja remplie\n");
                    }
                    else
                    {
                        matrix[1][choix] = 1;
                        print_matrix(matrix, n, m);
                        if (check_winner(matrix, 1) == 1)
                        {
                            playerwin = 1;
                            printf("Vous avez gagne\n");
                            exit(0);
                        }
                        tour = 1;
                    }
                }



                else if (choix == 6 || choix == 7 || choix == 8)
                {
                    if (choix == 6)
                    {
                        choix = 0;
                    }

                    if (choix == 7)
                    {
                        choix = 1;
                    }

                    if (choix == 8)
                    {
                        choix = 2;
                    }
                    if (matrix[2][choix] != 0)
                    {
                        printf("Case deja remplie\n");
                    }
                    else
                    {
                        matrix[2][choix] = 1;
                        print_matrix(matrix, n, m);
                        if (check_winner(matrix, 1) == 1)
                        {
                            playerwin = 1;
                            printf("Vous avez gagne\n");
                            exit(0);
                        }
                        tour = 1;
                    }
                }

                int cpt = 0;
                for (int i =0; i<n; i++)
                {
                    for(int j = 0; j<m; j++)
                    {
                        if (matrix[i][j] != 0)
                        {
                            cpt += 1;
                        }
                    }
                }
                if (cpt == 9)
                {
                    draw = 1;
                    printf("Match nul\n");
                    exit(0);
                }


                else
                {
                    printf("Erreur case non existente\n");
                }
            }


            while(tour != 0)
            {
                printf("Tour de l'ordinateur\n");
                int choixbot = rand() % 9;
                if (choixbot == 0 || choixbot == 1 || choixbot == 2)
                {
                    if (matrix[0][choixbot] == 0)
                    {
                        matrix[0][choixbot] = 2;
                        print_matrix(matrix, n, m);
                        if (check_winner(matrix, 2) == 1)
                        {
                            botwin = 1;
                            printf("Vous avez perdu\n");
                            exit(0);
                        }
                        tour = 0;
                    }
                }
                if (choixbot == 3 || choixbot == 4 || choixbot == 5)
                {
                    if(choixbot == 3)
                    {
                        choixbot = 0;
                    }
                    if(choixbot == 4)
                    {
                        choixbot = 1;
                    }
                    if(choixbot == 5)
                    {
                        choixbot = 2;
                    }
                    if (matrix[1][choixbot] == 0)
                    {
                        matrix[1][choixbot] = 2;
                        print_matrix(matrix, n, m);
                        if (check_winner(matrix, 2) == 1)
                        {
                            botwin = 1;
                            printf("Vous avez perdu\n");
                            exit(0);
                        }
                        tour = 0;
                    }
                }
                if (choixbot == 6 || choixbot == 7 || choixbot == 8)
                {
                    if (choixbot == 6)
                    {
                        choixbot = 0;
                    }
                    if (choixbot == 7)
                    {
                        choixbot = 1;
                    }
                    if(choixbot == 8)
                    {
                        choixbot = 2;
                    }
                    if (matrix[2][choixbot] == 0)
                    {
                        matrix[2][choixbot] = 2;
                        print_matrix(matrix, n, m);
                        if (check_winner(matrix, 2) == 1)
                        {
                            botwin = 1;
                            printf("Vous avez perdu\n");
                            exit(0);
                        }
                        tour = 0;
                    }
                    
                }
                int cpt = 0;
                for (int i =0; i<n; i++)
                {
                    for(int j = 0; j<m; j++)
                    {
                        if (matrix[i][j] != 0)
                        {
                            cpt += 1;
                        }
                    }
                }
                if (cpt == 9)
                {
                    draw = 1;
                    printf("Match nul\n");
                    exit(0);
                }
            }
            
        }
    }
    else if (start == 1)
    {
        printf("Le bot commence (vous jouez les 1 tandis que le bot joue les 2)\n");
        int tour = 1;
        while (botwin == 0 && playerwin == 0 && draw == 0)
        {
            int choix;
            while(tour == 0)
            {
                printf("Ou voulez vous ecrire : (vous avez le choix entre case 0, 1, 2, 3, 4, 5, 6, 7, 8, 9) \n");
                scanf("%d", &choix);
                if (choix == 0 || choix == 1 || choix == 2)
                {
                    if (matrix[0][choix] != 0)
                    {
                        printf("Case deja remplie\n");
                    }
                    else
                    {
                        matrix[0][choix] = 1;
                        print_matrix(matrix, n, m);
                        if (check_winner(matrix, 1) == 1)
                        {
                            playerwin = 1;
                            printf("Vous avez gagne\n");
                            exit(0);
                        }
                        tour = 1;
                    }
                }

                else if (choix == 3 || choix == 4 || choix == 5)
                {
                    if (choix == 3)
                    {
                        choix = 0;
                    }
                    if (choix == 4)
                    {
                        choix = 1;
                    }
                    if (choix == 5)
                    {
                        choix = 2;
                    }
                    
                    if (matrix[1][choix] != 0)
                    {
                        printf("Case deja remplie\n");
                    }
                    else
                    {
                        matrix[1][choix] = 1;
                        print_matrix(matrix, n, m);
                        if (check_winner(matrix, 1) == 1)
                        {
                            playerwin = 1;
                            printf("Vous avez gagne\n");
                            exit(0);
                        }
                        tour = 1;
                    }
                }



                else if (choix == 6 || choix == 7 || choix == 8)
                {
                    if (choix == 6)
                    {
                        choix = 0;
                    }

                    if (choix == 7)
                    {
                        choix = 1;
                    }

                    if (choix == 8)
                    {
                        choix = 2;
                    }
                    if (matrix[2][choix] != 0)
                    {
                        printf("Case deja remplie\n");
                    }
                    else
                    {
                        matrix[2][choix] = 1;
                        print_matrix(matrix, n, m);
                        if (check_winner(matrix, 1) == 1)
                        {
                            playerwin = 1;
                            printf("Vous avez gagne\n");
                            exit(0);
                        }
                        tour = 1;
                    }
                }
                int cpt = 0;
                for (int i =0; i<n; i++)
                {
                    for(int j = 0; j<m; j++)
                    {
                        if (matrix[i][j] != 0)
                        {
                            cpt += 1;
                        }
                    }
                }
                if (cpt == 9)
                {
                    draw = 1;
                    printf("Match nul\n");
                    exit(0);
                }


                else
                {
                    printf("Erreur case non existente\n");
                }
            }


            while(tour != 0)
            {
                printf("Tour de l'ordinateur\n");
                int choixbot = rand() % 9;
                if (choixbot == 0 || choixbot == 1 || choixbot == 2)
                {
                    if (matrix[0][choixbot] == 0)
                    {
                        matrix[0][choixbot] = 2;
                        print_matrix(matrix, n, m);
                        if (check_winner(matrix, 2) == 1)
                        {
                            botwin = 1;
                            printf("Vous avez perdu\n");
                            exit(0);
                        }
                        tour = 0;
                    }
                }
                if (choixbot == 3 || choixbot == 4 || choixbot == 5)
                {
                    if(choixbot == 3)
                    {
                        choixbot = 0;
                    }
                    if(choixbot == 4)
                    {
                        choixbot = 1;
                    }
                    if(choixbot == 5)
                    {
                        choixbot = 2;
                    }
                    if (matrix[1][choixbot] == 0)
                    {
                        matrix[1][choixbot] = 2;
                        print_matrix(matrix, n, m);
                        if (check_winner(matrix, 2) == 1)
                        {
                            botwin = 1;
                            printf("Vous avez perdu\n");
                            exit(0);
                        }
                        tour = 0;

                    }
                }
                if (choixbot == 6 || choixbot == 7 || choixbot == 8)
                {
                    if (choixbot == 6)
                    {
                        choixbot = 0;
                    }
                    if (choixbot == 7)
                    {
                        choixbot = 1;
                    }
                    if(choixbot == 8)
                    {
                        choixbot = 2;
                    }
                    if (matrix[2][choixbot] == 0)
                    {
                        matrix[2][choixbot] = 2;
                        print_matrix(matrix, n, m);
                        if (check_winner(matrix, 2) == 1)
                        {
                            botwin = 1;
                            printf("Vous avez perdu\n");
                            exit(0);
                        }
                        tour = 0;
                    }
                    
                }
                int cpt = 0;
                for (int i =0; i<n; i++)
                {
                    for(int j = 0; j<m; j++)
                    {
                        if (matrix[i][j] != 0)
                        {
                            cpt += 1;
                        }
                    }
                }
                if (cpt == 9)
                {
                    draw = 1;
                    printf("Match nul\n");
                    exit(0);
                }
            }   
        }
    }
    exit(0);
}