#include <stdio.h>
#include <stdlib.h>

int main(void) 
{
  int idade;
  char resposta;
   do
   {
      printf("Qual sua idade? ");
      scanf("%i", &idade);
      
      if (idade <= 14)
      {
        printf("Infantil");
      }
      else if (idade >= 15 && idade <= 17)
      {
        printf("Juvenil");
      }
      else if (idade >= 18 && idade <= 49)
      {
        printf("Adulto");
      }
      else if (idade >= 50)
      {
        printf("Idoso");
      }
      printf("\nVocẽ deseja continuar? (S/N)");
      scanf(" %c", &resposta);
      
      if(resposta == 'S' || resposta == 's')
      {
        system ("clear");
      }
     
   } while (resposta == 'S' || resposta == 's');
    
    return 0;
}
