#include "stdio.h"
#include "string.h"

int main(int argc, char * argv[])
{
	int num=0, sum, i, times = 0,flag;
	char bufr[128];
	printf("       ****************************************************************\n");
	printf("       *                       Midori Calculator                      *\n");
	printf("       ****************************************************************\n");
	printf("       *  1.Please enter the numbers one by one                       *\n");
	printf("       *  2.Every step you can choose four operations(+ - * /) or '=' *\n");
	printf("       *  3.The calculated numbers can only be positive integer       *\n");
	printf("       *  4.Enter q to exit                                           *\n");
	printf("       ****************************************************************\n\n");
	while(1){	
		printf("Press Enter to start:\n");
		i = read(0, bufr, 128);
		if (bufr[0] == 'q'){
			printf("Exit the Calculator!\n");
			return 0;
		}
		sum = 0;
		flag = 1;//the flag used in loop
		while(1){
			printf("Please input the calculated number:");
			i = read(0, bufr, 128);
			if (bufr[0] == 'q'){
				printf("Exit the Calculator!\n");
				return 0;
			}
			int num = getNum(bufr);
			memset(bufr,0,sizeof(bufr));//clear up the buffer
			if(num == -1)
				printf("Wrong input!\n");
			else{
				sum = num + sum;//the first calculated number
				break;
			}
		}
		while(flag){
			printf("Please input op( + - * / ) or '=':");
			i = read(0, bufr, 1);	
			if (bufr[0] == 'q'){
				printf("Exit the Calculator!\n");
				return 0;
			}
			switch(bufr[0])
			{
				case '+':
					while(1){
						printf("Please input the calculated number:");
						i = read(0, bufr, 128);
						if (bufr[0] == 'q'){
							printf("Exit the Calculator!\n");
							return 0;
						}
						int num = getNum(bufr);
						memset(bufr,0,sizeof(bufr));
						if(num == -1)
							printf("Wrong input!\n");
						else{
							sum += num;
							break;
						}
					}
					break;
				case '-':
					while(1){
						printf("Please input the calculated number:");
						i = read(0, bufr, 128);
						if (bufr[0] == 'q'){
							printf("Exit the Calculator!\n");
							return 0;
						}
						int num = getNum(bufr);
						memset(bufr,0,sizeof(bufr));//clear up the buffer
						if(num == -1)
							printf("Wrong input!\n");
						else{
							sum -= num;
							break;
						}
					}				
					break;
				case '*':
					while(1){
						printf("Please input the calculated number:");
						i = read(0, bufr, 128);
						if (bufr[0] == 'q'){
							printf("Exit the Calculator!\n");
							return 0;
						}
						int num = getNum(bufr);
						memset(bufr,0,sizeof(bufr));//clear up the buffer
						if(num == -1)
							printf("Wrong input!\n");
						else{
							sum *= num;
							break;
						}
					}
					break;
				case '/':
					while(1){
						printf("Please input the calculated number:");
						i = read(0, bufr, 128);
						if (bufr[0] == 'q'){
							printf("Exit the Calculator!\n");
							return 0;
						}
						int num = getNum(bufr);
						memset(bufr,0,sizeof(bufr));//clear up the buffer
						if(num == -1)
							printf("Wrong input!\n");
						else if(num == 0)
							printf("The dividing number can't be zero!\n");
						else{
							sum /= num;
							break;
						}
					}
					break;
				case '=':
					printf("The answer is %d\n\n", sum);
					flag=0;//the caculation ends, end the loop
					break;
				default:
					printf("No such command!\n");
			}
		}
	}
	return 0;
}

int getNum(char * bufr)//get the number from bufr
{
	int ten = 1, i = 0, res = 0;
	for (i = 0; i < strlen(bufr) - 1; i++)
	{
		ten *= 10;
	}
	for (i = 0; i < strlen(bufr); i++)
	{
		if(bufr[i] - '0' >9 || bufr[i] - '0' < 0)//the input is not a positive number, return false
			return -1;
		res += (bufr[i] - '0') * ten;
		ten /= 10;
	}
	return res;
}
