/******74HC164*输出*中断******/
#include<reg51.h>
sbit CLR=P1^0;
unsigned char led[8]={0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};
void delay(int N) //延时时间Nms@晶振12MHZ
{
 unsigned char i;
 while(N--)
  for(i=0;i<123;i++);
}

void main()
{
  unsigned char j=0;
  SCON= 0x00    ;  //串口方式0
  EA=1;	   //允许中断
  ES=1   ;
  CLR=1;
  while(1)
  {
   for(j=0;j<8;j++)
   {
    SBUF= led[j]       ; //方式0依次发送各个数据
    delay(300); 
   }
  }
}
void uart()interrupt 4
{
  TI= 0 ;	 //中断标志位清零
  
}
