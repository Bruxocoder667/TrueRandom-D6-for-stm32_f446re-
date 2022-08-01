/*
 * Dev name: Nicolas Dias Bohrer
 * Date: 31/07/2022
 * @Brief: Prática *
 * Criar um dado xD6 aleatório
 */

#include "stm32f4xx.h"
#include <time.h>
#include <stdlib.h>

#define delay 200000
void tempo();
void print();


int main(){

	RCC->AHB1ENR=0x87;
	GPIOA->MODER|=0X28000000;
	GPIOB->MODER|=0X00000000;
	GPIOC->MODER|=0X00005555;
	int k,n;

	while(1){
		for(k=0;k<20000;k++){
			if((GPIOB->IDR& 0X20)==0){
				srand(k);
				n = (rand() % 6) +1;
				print(n);
				tempo();


		//for(int i=1;i<=6;i++){

		//}

			}
		}
	}
}


void print(int n){
	switch(n){
	case 1:GPIOC->ODR=0X08;break;
	case 2:GPIOC->ODR=0X21;break;
	case 3:GPIOC->ODR=0X29;break;
	case 4:GPIOC->ODR=0X35;break;
	case 5:GPIOC->ODR=0X3D;break;
	case 6:GPIOC->ODR=0X77;break;
	}
}



void tempo(){
	int j=0;
	for(j=0;j<delay;j++);
}
