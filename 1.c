#include <stdio.h> 
#include <conio.h>
#include <time.h> 
#include <stdlib.h>
#define output printf
#define numerical_value int
numerical_value flag=0;
void delay(numerical_value seconds_delay) 
{ 
	clock_t start_t, end_t;
    numerical_value ms = 1000 * seconds_delay; 
    //this conversion numerical_valueo milli seconds is important for the program to run properly
    clock_t ct = clock(); 
    //using clock helps increasing the efficiency of delay function as it accurately defines 1 sec
    //if a value of 1000 is given directly to the loop, systems with high processing speed will execute it faster 
    //clock helps in keeping record of processor execution time
    char ch;
    numerical_value count=0;
    start_t=clock();
    while (clock() < ct + ms)
    	{    		
    		if(kbhit())
    		{
    			ch=getch();
    			if ((numerical_value)ch == 27)
    			{
    				exit(0);
    			}
    			else
    			{
    				count++;
    				output("\n Timer restarted \n");
    				end_t=clock();
    				flag += end_t - start_t;
    				break;
    			}

    		}
    	}

    	if(count!=0){
    	delay(seconds_delay);}
    	else
    	{
    		end_t=clock();
    		flag += end_t - start_t;
    	}
} 
int main()
{ 
	numerical_value i; 
	numerical_value delay_time;
	char ch;
    srand(time(0)); 
        output("delay in seconds: ");
        scanf("%d",&delay_time);
        //for understanding a loop of 100 times is generated
        numerical_value temp=0;
        output("program starts now:");
    	for (i = 0; i < 1000; i++) 
    	{
    		delay(delay_time);
        	output("\n%d seconds have passed\n", (flag/1000)); 
        	output("Here is your random number: %d",rand());
    	}
    return 0; 
}