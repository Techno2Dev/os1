#include<stdio.h>
#define MAX 10
void main()

{
	int i,ch,val,top=-1,stack[MAX];
	do
	{
		printf("\nMENU");
		printf("\n1.Push\n2.Pop\n3.Display\n4.Exit");
		printf("\nEnter the choice:-");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("*********\nPUSH\n*********"); 
				if(top==MAX-1)
				{
					printf("\nStack is FULL");
				}
				else
				{
					printf("\nEnter elements to push:-");
					scanf("%d",&val);
					top=top+1;
					stack[top]=val;
				}
				break;
			case 2:
				printf("*********\nPOP\n*********");
				if(top==-1)
				{
					printf("\nStack is EMPTY");
				}
				else
				{
					printf("\nDeleted element is %d",stack[top]);
					top=top-1;
				}
				break;
			case 3:
				printf("*********\nDISPLAY\n*********");
				if(top==-1)
				{
					printf("\nStack is EMPTY");
				}
				else
				{
					printf("\nStack is:-\n");
					for(i=top;i>=0;--i)
					printf("%d\t",stack[i]);
				
				}
				break;
		}
	}while(ch!=4);
}

