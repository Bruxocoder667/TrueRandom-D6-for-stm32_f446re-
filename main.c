/*
 * Dev name: Nicolas Dias Bohrer
 * Date: 31/07/2022
 * @Brief:
 * Make a True Random D6
 */

#include "stm32f4xx.h"
//#include <time.h>
#include <stdlib.h>

#define delay 200000 //Used for a crude debounce method
void tempo(); //Serve as a delay between button presses, act as a debounce
void print(); //Compile the actual GPIO management into one fucntion (just for shows)


int main(){

	RCC->AHB1ENR=0x87;//Initializing internal clock
	GPIOA->MODER|=0X28000000; //defining special use of GPIOA pins
	GPIOB->MODER|=0X00000000; //defining the entire GPIOB as input
	GPIOC->MODER|=0X00005555; //defining pins 0~7 on GPIOC as output
	int k;//k will be the seed for the random number generator
	int n;//n is the actual random number to be shown later

	while(1){ //infinite loop
		for(k=0;k<20000;k++){ //goes truogh numbers 0~20000 until...
			if((GPIOB->IDR& 0X20)==0){//when the button on pin PB5 is pressed
				srand(k);//k being a random count can be used as the seed for the random generator
				n = (rand() % 6) +1;//here the random number is generated between 1 and 6 and stored at n
				print(n);//calling the GPIO state modifier function
				tempo();//calling the debounce function
			}
		}
	}
}


void print(int n){
	switch(n){//turn on LEDs in correct order
	case 1:GPIOC->ODR=0X08;break; //PC3
	case 2:GPIOC->ODR=0X21;break; //PC5,PC0
	case 3:GPIOC->ODR=0X29;break; //PC5,PC3,PC0
	case 4:GPIOC->ODR=0X35;break; //PC5,PC4,PC1,PC0
	case 5:GPIOC->ODR=0X3D;break; //PC5,PC4,PC3,PC2,PC0
	case 6:GPIOC->ODR=0X77;break; //PC6,PC5,PC4,PC2,PC1,PC0
	}
}



void tempo(){//Burning processing time
	int j=0;
	for(j=0;j<delay;j++);
}
