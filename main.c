/*
 * Author: Nicolas DB
 * Turma 4311 (2022)
 */
#include "stm32f4xx.h"

void tempo();
int main(void)
{
	RCC->AHB1ENR=0X87; //BAGULHO WTF QUE O ARM PRECISA
	GPIOC->MODER|=0X5555; //pino C de 0 ao 8 como saída
	GPIOA->MODER|=0X28000000; //??? tbm precisa disso
/*
 * No while os pinos de 1 a 8 do GPIOC vão ser setados
 * para 1 sequencialmente e depois voltam sequencialmente
 * a zero pois nós vamos flipar os bits em ordem.
 */
  while (1){
	  GPIOC->ODR&=~0X01;tempo();
	  GPIOC->ODR&=~0X02;tempo();
	  GPIOC->ODR&=~0X04;tempo();
	  GPIOC->ODR&=~0X08;tempo();
	  GPIOC->ODR&=~0X10;tempo();
	  GPIOC->ODR&=~0X20;tempo();
	  GPIOC->ODR&=~0X40;tempo();
	  GPIOC->ODR&=~0X80;tempo();
  }
}
//Função tempo (queima de tempo) serve como delay
void tempo(){
	int j;
	for(j=0;j<100000;j++);
}
