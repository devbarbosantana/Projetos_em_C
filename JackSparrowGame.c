#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int main(void) {
  srand(time(NULL));

  char cenario[20][20];

  //cenario
  for (int c = 0; c<20; c++)
  {
    for (int l = 0; l<20; l++)
    {
      cenario [c][l] = '_';
    }
  }

  //personagem
  int j_l = 0;
  int j_c = 0;
  cenario [j_l][j_c] = 'J';

  //barco
  cenario [18][18] = 'v';

  for (int s = 0; s < 10;)
  {
    int s_l = rand()%5 + 16;
    int s_c = rand()%5 + 16;
    if (cenario[s_l][s_c] == '_')
    {
      cenario[s_l][s_c] = 'p';
      s++;
    }
  }

  //balas
  for (int b = 0; b<20;)
    {
      int b_l = rand()%20;
      int b_c = rand()%20;
      if (cenario[b_l][b_c] == '_')
      {
        cenario[b_l][b_c] = '*';
         b++;
      }
    }

  //piratas
  for (int p = 0; p<50;)
    {
      int p_l = rand()%20;
      int p_c = rand()%20;
      if (cenario[p_l][p_c] == '_')
      {
        cenario[p_l][p_c] = 'p';
        p++;
      }
    }

  //obstaculos
  for (int o = 0; o<50;)
    {
      int o_l = rand()%20;
      int o_c = rand()%20;
      if (cenario[o_l][o_c] == '_')
      {
        cenario[o_l][o_c] = '|';
         o++;
      }
    }

  //arma
  int arma = 0;
  for (int a = 0; a<1;)
    {
      int a_l = rand()%20;
      int a_c = rand()%20;
      if (cenario[a_l][a_c] == '_')
      {
        cenario[a_l][a_c] = '~';
         a++;
      }
    }

  //balas
  int balas = 0;

  //perder
  int perder = 0;
  
  while (perder == 0)
  { 
  //contador de balas
  printf ("Qtd. de balas: %i\n", balas);
  //você tá com a arma?
  if (arma == 0)
  {
    printf ("Você não tem a arma!\n");
  }else {printf("Você tem a arma!\n");}
    
  //imprimir cenario
  for(int i = 0; i < 20; i++)
  {
     for(int j = 0; j < 20; j++)
     {
       printf("%c ", cenario[i][j]);
     }
    printf("\n");
  }

  //movimentação
  char movimentacao;
  printf (":");
  scanf ("%c", &movimentacao);
  getchar();

  switch (movimentacao)
  {
    case 'w':
    if ((j_l-1)>=0 && cenario[j_l-1][j_c] != '|')
    {
      cenario [j_l][j_c] = '_';
      j_l--;
      //morte por inimigos
      if(cenario[j_l][j_c] == 'p' && arma == 0 || cenario[j_l][j_c] == 'p' && balas == 0)
      {
        perder = 1;
      }
      //incrementador de balas
      if (cenario[j_l][j_c] == '*')
      {
        balas++;
      }
      if (cenario[j_l][j_c] == 'p' && balas!=0)
      {
        balas--;
      }
      //arma
      if (cenario[j_l][j_c] == '~')
      {
        arma = 1;
      }
      //vitória
      if (cenario[j_l][j_c] == 'v')
      {
        perder = 2;
      }
      cenario [j_l][j_c]= 'J';
    }
    break;
    
    case 's':
    if ((j_l+1) <= 19 && cenario[j_l+1][j_c] != '|')
    {
      cenario [j_l][j_c] = '_';
      j_l++;
      
      //morte por inimigos
      if(cenario[j_l][j_c] == 'p' && arma == 0 || cenario[j_l][j_c] == 'p' && balas == 0)
      {
        perder = 1;
      }
      //incrementador de balas
      if (cenario[j_l][j_c] == '*')
      {
        balas++;
      }
      if (cenario[j_l][j_c] == 'p' && balas!=0)
      {
        balas--;
      }
      //arma
      if (cenario[j_l][j_c] == '~')
      {
        arma = 1;
      }
      //vitória
      if (cenario[j_l][j_c] == 'v')
      {
        perder = 2;
      }
      cenario [j_l][j_c]= 'J';
    }
    break;

    case 'd':
    if ((j_c+1) <= 19 && cenario[j_l][j_c+1] != '|')
    {
      cenario [j_l][j_c] = '_';
      j_c++;

      //morte por inimigos
      if(cenario[j_l][j_c] == 'p' && arma == 0 || cenario[j_l][j_c] == 'p' && balas == 0)
      {
        perder = 1;
      }
      //incrementador de balas
      if (cenario[j_l][j_c] == '*')
      {
        balas++;
      }
      if (cenario[j_l][j_c] == 'p' && balas!=0)
      {
        balas--;
      }
      //arma
      if (cenario[j_l][j_c] == '~')
      {
        arma = 1;
      }
      //vitória
      if (cenario[j_l][j_c] == 'v')
      {
        perder = 2;
      }
      cenario [j_l][j_c]= 'J';
    }
    break;

    case 'a':
    if ((j_c-1) >= 0 && cenario[j_l][j_c-1] != '|')
    {
      cenario [j_l][j_c] = '_';
      j_c--;
      //morte por inimigos
      if(cenario[j_l][j_c] == 'p' && arma == 0 || cenario[j_l][j_c] == 'p' && balas == 0)
      {
        perder = 1;
      }
      //incrementador de balas
      if (cenario[j_l][j_c] == '*')
      {
        balas++;
      }
      if (cenario[j_l][j_c] == 'p' && balas!=0)
      {
        balas--;
      }
      //arma
      if (cenario[j_l][j_c] == '~')
      {
        arma = 1;
      }
      //vitória
      if (cenario[j_l][j_c] == 'v')
      {
        perder = 2;
      }
      cenario [j_l][j_c]= 'J';
    }
    break;
    default: ;
  }
    system ("clear");

    //derrota
    if (perder == 1)
    {
      printf("Você perdeu!");
    }

    //vitória
    if (perder == 2)
    {
      printf("Segunda Fase!\n");
    }
  }

  //--------------------------------FASE 2---------------------------------------
  if(perder == 2)
  {
  //cenario
  for (int c = 0; c<20; c++)
  {
    for (int l = 0; l<20; l++)
    {
      cenario [c][l] = '~';
    }
  }

  //jogador 1
  int l1, c1, l11, c11;
  for (int b = 0; b<2;)
     {
        c11 = rand()%20;
        l11 = rand()%20;
       if(c11<18)
       {
       if (b == 1)
       {
         if (cenario[l11][c11] == '~' && cenario[l11][c11+1] == '~')
         {
          cenario[l11][c11] = '1';
          cenario[l11][c11+1] = '1';
          b++;
         }
       }else
       {
         l1 = rand()%20;
         c1 = rand()%20;
         if (cenario[l1][c1] == '~')
       {
         cenario[l1][c1] = '1';
         b++;
       }
       }
       }
     }

  //jogador 2
  int l2, c2, l22, c22;
  for (int b = 0; b<2;)
     {
        l22 = rand()%20;
        c22 = rand()%20;
       if(c22 < 19)
       {
       if (b == 1)
       {
         if (cenario[l22][c22] == '~' && cenario[l22][c22+1] == '~' && c22)
         {
          cenario[l22][c22] = '2';
          cenario[l22][c22+1] = '2';
          b++;
         }
       }else
       {
        l2 = rand()%20;
        c2 = rand()%20;
         if (cenario[l2][c2] == '~')
       {
         cenario[l2][c2] = '2';
         b++;
       }
       }
       }
     }

    //VEZ DO JOGADOR 1
    int vez = 1;
    while ((cenario[l1][c1] != 'X' || cenario[l11][c11] != 'X') && (cenario[l2][c2] != 'X' || cenario[l22][c22] != 'X'))
      {
        if(vez==1)
        {
          printf("Vez do jogador 1!\n");
          //imprimir cenario
            for(int i = 0; i < 20; i++)
            {
               for(int j = 0; j < 20; j++)
               {
                 if (cenario[i][j] == '2')
                 {
                   printf("~ ");
                 } else {printf("%c ", cenario[i][j]);}
               }
              printf("\n");
            }
          int a_l, a_c;
          printf("Onde você gostaria de atacar?\n(fale a linha e a coluna no formato X Y)\n:", l2, c2, l22, c22);
          scanf("%i %i", &a_l, &a_c);
          getchar();
          
          if(cenario[a_l-1][a_c-1] == '~')
          {
            cenario[a_l-1][a_c-1] = '*';
          }else if(a_l-1 == l2 && a_c-1 == c2)
          {
            cenario[a_l-1][a_c-1] = 'X';
          }else if ((a_l-1 == l22 && a_c-1 == c22) || (a_l-1 == l22 && a_c - 1 == c22 + 1))
          {
            cenario[l22][c22] = 'X';
            cenario[l22][c22+1] = 'X';
          }
        }
        system ("clear");
        if((cenario[l2][c2] != 'X' || cenario[l22][c22] != 'X'))
        {
        vez = 2;
        }

    //VEZ DO JOGADOR 2
    if(vez==2)
      {
        printf("Vez do jogador 2!\n");
        //imprimir cenario
          for(int i = 0; i < 20; i++)
          {
             for(int j = 0; j < 20; j++)
             {
               if (cenario[i][j] == '1')
               {
                 printf("~ ");
               } else {printf("%c ", cenario[i][j]);}
             }
            printf("\n");
          }
        int a_l, a_c;
        printf("Onde você gostaria de atacar?\n(fale a linha e a coluna no formato X Y)\n:", l1, c1, l11, c11);
        scanf("%i %i", &a_l, &a_c);
        getchar();

        if(cenario[a_l-1][a_c-1] == '~')
        {
          cenario[a_l-1][a_c-1] = '*';
        }else if(a_l-1 == l1 && a_c-1 == c1)
        {
          cenario[a_l-1][a_c-1] = 'X';
        }else if ((a_l-1 == l11 && a_c-1 == c11) || (a_l-1 == l11 && a_c - 1 == c11 + 1))
        {
          cenario[l11][c11] = 'X';
          cenario[l11][c11+1] = 'X';
        }
      }
          system ("clear");
        if((cenario[l1][c1] != 'X' || cenario[l11][c11] != 'X'))
        {
        vez = 1;
        }
      }
    if(vez == 1)
    {
      printf("Jogador 1 venceu!");
    }else {printf("Jogador 2 venceu!");}
  }
  return 0;
}
