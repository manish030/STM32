/*Bare Metal Programming
* LED Toggle without header file
* 26/6/23
* Name: MJ*/


// LED PortPin: PB8 and PB9;

#define PERIPHE_BASE				0x40000000UL

#define APB2_OFFSET					0x10000UL
#define APB2_BASE					(PERIPHE_BASE + APB2_OFFSET)

#define GPIOB_OFFSET				0x0C00UL
#define GPIOB_BASE					(APB2_BASE + GPIOB_OFFSET)

#define GPIOB_CH_R_OFFSET			0x04UL
#define GPIOB_CH_R_BASE				(GPIOB_BASE + GPIOB_CH_R_OFFSET)

#define GPIOB_CH_R					(*(volatile unsigned int *)(GPIOB_CH_R_BASE))

#define	GPIOB_OD_R_OFFSET		 	0x0CUL
#define	GPIOB_OD_R_BASE				(GPIOB_BASE + GPIOB_OD_R_OFFSET)

#define GPIOB_OD_R					(*(volatile unsigned int *)(GPIOB_OD_R_BASE))

#define AHB_OFFSET					0x00020000UL
#define AHB_BASE					(PERIPHE_BASE + AHB_OFFSET)

#define RCC_OFFSET					0x1000UL
#define RCC_BASE					(AHB_BASE + RCC_OFFSET)

#define RCC_APB2_EN_R_OFFSET		0x18UL
#define RCC_APB2_EN_R_BASE			(RCC_BASE + RCC_APB2_EN_R_OFFSET)

#define RCC_APB2_EN_R				(*(volatile unsigned int *)(RCC_APB2_EN_R_BASE))

#define IOPBEN						(1U<<3)

#define PIN							(1U<<8)
#define LED_PIN						PIN

int main(){
		
		RCC_APB2_EN_R |= IOPBEN;
		
			
		//GPIOB_CH_R    |= (1U<<0) |(1U<<1) | (1U<<2);
	GPIOB_CH_R    |= (1U<<0);
	GPIOB_CH_R    |= (1U<<1);
	GPIOB_CH_R    &= ~(1U<<2);	
	GPIOB_CH_R    &= ~(1U<<3);
		
		while(1){
				
				//GPIOB_OD_R |=(1U<<8);
			GPIOB_OD_R ^= LED_PIN;
			
			for(int i=0; i<2000000; i++){
				
			}
		}
}

