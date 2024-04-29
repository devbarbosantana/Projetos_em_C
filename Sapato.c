#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

int main(void) 
{

  int tenis, valor;

  do
  {
    //Tênis
    printf ("Qual tênis você quer comprar? \n(0) Nenhum, (1) Nike, (2) Adidas, (3) Ambos, (4) Ver preços: ");
    scanf ("%i", &tenis);
    
    //NENHUM
    if (tenis == 0)
    {
      printf("Você não quer um tênis");
      return 0;
    }
    else if (tenis == 4)
    {
      printf ("\nNike: R$ 300,00\nAdidas: R$ 600,00\n\n");
    }
    else if (tenis > 4 || tenis < 0)
    {
      printf("\nOpção inválida!\n\n");
    }
  } while (tenis < 0 || tenis >= 4);

  //Valor
  printf("\nQuanto você tem de dinheiro? ");
  scanf("%i", &valor);
  
  switch(tenis)
  {
    //NIKE
    case 1:
      printf ("\nEle custa 300,00 R$\n");
        
      if (valor >= 900) 
      {
        printf("Você pode comprar ambos, e sobra %i R$", valor - 900);
      }
      else if (valor >= 600) 
      {
        printf("Você pode comprar qualquer um dos dois! e sobra %i R$", valor - 600);
      }
      else if (valor >= 300) 
      {
        printf ("Você pode comprar o Nike! E sobra %i R$", valor - 300);
      }
      else if (valor < 300) 
      {
        printf ("Infelizmente você não pode comprar o Nike, falta %i R$", 300 - valor);
      }
    break;

    //ADIDAS
    case 2:
      printf ("\nEle custa 600\n"); 
  
      if (valor >= 900) 
      {
        printf("Você pode comprar ambos, e sobra %i", valor - 900);
      }
      else if (valor >= 600) 
      {
        printf("Você pode comprar o Adidas!, e sobra %i", valor - 600);
      }
      else if (valor < 600 && valor >= 300) 
      {
        printf ("Você não pode comprar o Adidas, e falta %i R$. Mas pode comprar o Nike e sobra %i R$", 600 - valor, valor - 300);
      }
      else if (valor < 300) 
      {
        printf ("Você não pode comprar nada, e falta %i R$ para o mais barato e %i pro Adidas", 300 - valor, 600 - valor);
      }
    break;

    //AMBOS
    case 3:
      printf ("\nAmbos custam 900\n"); 
      
      if (valor >= 900) 
      {
        printf("Você pode comprar ambos, e sobra %i R$", valor - 900);
      }
      else if (valor >= 600 && valor < 900) 
      {
        printf("Você pode comprar o Adidas!, e sobra %i R$. E falta %i R$ para ambos", valor - 600, 900 - valor);
      }
      else if (valor < 600 && valor >= 300) 
      {
        printf ("Você não pode comprar ambos, e falta %i R$. Mas pode comprar o Nike e sobra %i R$.", 900 - valor, valor - 300);
      }
      else if (valor < 300) 
      {
        printf ("Você não pode comprar nada, falta %i R$ pro mais barato e %i R$ pro Adidas, %i R$ para ambos", 300 - valor, 600 - valor, 900 - valor);
      }
      break;
  }

  return 0;
}
