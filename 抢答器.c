#include<reg52.h> 
#define  TIMEQIANG1  10
#define  TIMEQIANG2  30
#define  TIMEQIANG3  00

sbit CHN_0  = P1^0;
sbit CHN_1  = P1^1;
sbit CHN_2  = P1^2;
sbit CHN_3  = P1^3;
sbit CHN_4  = P1^4;
sbit CHN_5  = P1^5;
sbit CHN_6  = P1^6;
sbit CHN_7  = P1^7;

sbit START_BUT  = P2^1;
unsigned char code Dofly_table[16]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,
					0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};

unsigned char xdata* digit =0x8002; 
unsigned char xdata* seg =0x8004; 

unsigned int i =0;
unsigned int j =0;
unsigned int l =0;

void DelayUs2x(unsigned char t)
{   
 while(--t);
}
void DelayMs(unsigned char t)
{
 while(t--)
 {
     //??????1mS
     DelayUs2x(245);
	 DelayUs2x(245);
 }
}
 
void  Dis_Play(unsigned char uiDis_NumHigh     ,unsigned char uiDis_NumLow)
{
 static unsigned char ucStep = 0;
 unsigned char ucDis_Dat = 0;
 switch(ucStep)
 {
	case 0 :
	*digit = 0X00; 	 
	*seg =  0XFF;
	
	ucDis_Dat = uiDis_NumHigh/10; 
	*digit =0X02;
	*seg = Dofly_table[ucDis_Dat];
	
	ucStep++;  
	break;

	case 1 : 
	*digit = 0X00;
	*seg =  0XFF;
	
	ucDis_Dat = uiDis_NumHigh%10; 
	*digit =0X01;
	*seg = Dofly_table[ucDis_Dat];
	
	ucStep++;  
	break;

	case 2 : 
	*digit = 0X00;
	*seg =  0XFF;
	 
	ucDis_Dat = uiDis_NumLow;	
	*digit =0X08;
	*seg = Dofly_table[ucDis_Dat];
		
    ucStep = 0; 
    break;
  default: break;
 }
}
void  Dis_PlayNum(unsigned char uiDis_NumHigh)
{
  	 
 unsigned char ucDis_Dat = 0;
 l = 50;
while(l--)
{		 
	ucDis_Dat = uiDis_NumHigh;	 
	*digit =0X08;
	*seg = Dofly_table[ucDis_Dat];
	
	DelayMs(2);
	*digit &= 0Xf0; 
	
	}

}
 
/*------------------------------------------------
                    ???
------------------------------------------------*/
              
void Init_Timer0(void)
{
	TMOD |= 0x01;	  //????1,16????,??"|"?????????????????		     
	TH0=(65536-2000)/256;		  //???? 2ms
	TL0=(65536-2000)%256;
	EA=1;            //?????
	ET0=1;           //???????
	TR0=1;           //???????
	PT1 = 1;
}
				 char Start_Flag = 0;
unsigned char Time_Use = 0;  
unsigned int uiDis_1S = 0;  
unsigned char ucTime = TIMEQIANG3 ;
			


void main (void)
{
  
  unsigned char  ucChn_Num = 0;
 	
	Init_Timer0();        //???0???
 
 
while (1)           //???
  {	    
  ////////////////////
  if(Start_Flag == 1)//???? 
  {
	  if(CHN_0 == 0)
	  {
	   DelayMs(10);//???
	   if(CHN_0 == 0)
	    {
			Start_Flag = 2;
		 ucTime = TIMEQIANG2 ;
		 ucChn_Num = 1;
		
		}
	  }
	  else if(CHN_1 == 0)
	  {
	   DelayMs(10);
	   if(CHN_1 == 0)
	    {
			Start_Flag = 2;
		 ucTime = TIMEQIANG2 ;
		 ucChn_Num = 2;
		}
	  }
	  else if(CHN_2 == 0)
	  {
	   DelayMs(10);
	   if(CHN_2 == 0)
	    {
			Start_Flag = 2;
		 ucTime = TIMEQIANG2 ;
		 ucChn_Num = 3;
		}
	  }
	  else if(CHN_3 == 0)
	  {
	   DelayMs(10);
	   if(CHN_3 == 0)
	    {
			Start_Flag = 2;
		 ucTime = TIMEQIANG2 ;
		 ucChn_Num = 4;
		}
	  }
	  else if(CHN_4 == 0)
	  {
	   DelayMs(10);
	   if(CHN_4 == 0)
	    {
			Start_Flag = 2;
		 ucTime = TIMEQIANG2 ;
		 ucChn_Num = 5;
		}
	  }
	  else if(CHN_5 == 0)
	  {
	   DelayMs(10);
	   if(CHN_5 == 0)
	    {
			Start_Flag = 2;
		 ucTime = TIMEQIANG2 ;
		 ucChn_Num = 6;
		}
	  }
	  else if(CHN_6 == 0)
	  {
	   DelayMs(10);
	   if(CHN_6 == 0)
	    {
			Start_Flag = 2;
		 ucTime = TIMEQIANG2 ;
		 ucChn_Num =7;
		}
	  }
	  else if(CHN_7 == 0)
	  {
	   DelayMs(10);
	   if(CHN_7 == 0)
	    {
			Start_Flag = 2;
		 ucTime = TIMEQIANG2 ;
		 ucChn_Num = 8;
		}
		
	  }
		
  }
	if(Start_Flag == 0)//????
	{
		if(CHN_0 == 0)
	  {
	   DelayMs(10);
	   if(CHN_0 == 0)
	    {Start_Flag = 9;
		 ucTime =TIMEQIANG3;
		 ucChn_Num = 1;
		 }
		 }
		 else if(CHN_1 == 0)
	  {
	   DelayMs(10);
	   if(CHN_1 == 0)
	    {
			Start_Flag = 9;
		 ucTime = TIMEQIANG3 ;
		 ucChn_Num = 2;
		 }}
		 else if(CHN_2 == 0)
	  {
	   DelayMs(10);
	   if(CHN_2 == 0)
	    {Start_Flag = 9;
		 ucTime = TIMEQIANG3 ;
		 ucChn_Num = 3;
		 }}
		 else if(CHN_3 == 0)
	  {
	   DelayMs(10);
	   if(CHN_3 == 0)
	    {Start_Flag = 9;
		 ucTime = TIMEQIANG3 ;
		 ucChn_Num = 4;
		 }}
		 else if(CHN_4 == 0)
	  {
	   DelayMs(10);
	   if(CHN_4 == 0)
	    {Start_Flag = 9;
		 ucTime = TIMEQIANG3 ;
		 ucChn_Num = 5;
		 }}
		 else if(CHN_5 == 0)
	  {
	   DelayMs(10);
	   if(CHN_5 == 0)
	    {Start_Flag = 9;
		 ucTime = TIMEQIANG3 ;
		 ucChn_Num = 6;
		 }}
		 else if(CHN_6 == 0)
	  {
	   DelayMs(10);
	   if(CHN_6 == 0)
	    {Start_Flag = 9;
		 ucTime = TIMEQIANG3 ;
		 ucChn_Num = 7;
		 }}
		 else if(CHN_7 == 0)
	  {
	   DelayMs(10);
	   if(CHN_7 == 0)
	    {Start_Flag = 9;
		 ucTime = TIMEQIANG3 ;
		 ucChn_Num = 8;
		 }
		 }}
	
	if(Start_Flag == 9)//??????
	{
		*digit &= 8;
		
		for(i=0;i<6;i++)
		{
		 if(Time_Use)//??
	   {
		 Time_Use = 0;
		 Dis_PlayNum(ucChn_Num);
			}
			DelayMs(500);
			}
			
			
			TR0 = 0;
			TH0=(65536-2000)/256;		  //???? 2ms
			TL0=(65536-2000)%256;
			ucChn_Num = 0;
			ucTime = TIMEQIANG3 ;
			Start_Flag = 0;
			uiDis_1S = 0; 
			
			TR0 = 1;
			
	}
	
	
	///////////////////////START??
    if(START_BUT == 0)
	  {
	   DelayMs(10);
	   if(START_BUT == 0)
	    {
		 if(Start_Flag == 0)
		 {
			Start_Flag = 1;
			ucChn_Num = 0;
			ucTime = TIMEQIANG1 ;
			TH0=(65536-2000)/256;		  //???? 2ms
			TL0=(65536-2000)%256;
			uiDis_1S = 0; 
			
			TR0 = 1;
		 }
		}
	  }
		
		


	   if(Time_Use)//??
	   {
	    Time_Use = 0;
			Dis_Play(ucTime,ucChn_Num);
	   }
  }
	}
////////////////////////?????////////////////


/*------------------------------------------------
                 ????????
------------------------------------------------*/

void Timer0_isr(void) interrupt 1 
{
 TH0=(65536-2000)/256;		  //???? 2ms
 TL0=(65536-2000)%256;
 Time_Use = 1;
    if(Start_Flag == 1  ||Start_Flag == 2)
	 {
			 if(uiDis_1S++ > 400)
			 {
			  uiDis_1S = 0;
			  if(ucTime)
			   {
			     ucTime--;
				 if(ucTime == 0)
				 {
				   Start_Flag = 9; //???
					 
				 }	   
			   }	     
			 }	 
	 }
	 
 } 
