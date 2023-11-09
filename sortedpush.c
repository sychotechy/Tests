#include<stdio.h>
#define MAX 5
int stack[MAX],top=-1;
void push(int n)
	{
	if(top==MAX-1)
		printf("Stack full cannnot push\n");
	else if(top==-1)
		stack[++top]=n;
	else
		{
		int tempstack[MAX], temptop=-1;
		while(n>stack[top]&&top!=-1)
			tempstack[++temptop]=stack[top--];
		stack[++top]=n;
		while(temptop>-1)
			stack[++top]=tempstack[temptop--];
		}
	}
void pop()
	{
	if(top==-1)
		printf("Empty stack cannot pop\n");
	else
		printf("\nPopped element is: %d\n",stack[top--]);
	}
void dispStack()
	{
	printf("\n");
	for(int i=0;i<=top;i++)
		printf("%d\t",stack[i]);
	}
void main()
	{
	int o=0,e;
	while(o!=4)
		{
		printf("\nMENU\n1.Push\n2.Pop\n3.Display Stack\n4.Exit\n");
		scanf("%d",&o);
		switch(o)
			{
			case 1:
				printf("Enter the element to be pushed: ");
				scanf("%d",&e);
				push(e);
				break;
			case 2:
				pop();
				break;
			case 3:
				dispStack();
				break;
			case 4:
				printf("Exiting");
				break;
			default:
				printf("Invalid input");
			}
		}
	}
/*Output
MENU
1.Push
2.Pop
3.Display Stack
4.Exit
1
Enter the element to be pushed: 5

MENU
1.Push
2.Pop
3.Display Stack
4.Exit
1
Enter the element to be pushed: 4

MENU
1.Push
2.Pop
3.Display Stack
4.Exit
1
Enter the element to be pushed: 1

MENU
1.Push
2.Pop
3.Display Stack
4.Exit
1
Enter the element to be pushed: 2

MENU
1.Push
2.Pop
3.Display Stack
4.Exit
1
Enter the element to be pushed: 3

MENU
1.Push
2.Pop
3.Display Stack
4.Exit
2

Popped element is: 1

MENU
1.Push
2.Pop
3.Display Stack
4.Exit
2

Popped element is: 2

MENU
1.Push
2.Pop
3.Display Stack
4.Exit
2

Popped element is: 3

MENU
1.Push
2.Pop
3.Display Stack
4.Exit
2

Popped element is: 4

MENU
1.Push
2.Pop
3.Display Stack
4.Exit
2

Popped element is: 5

MENU
1.Push
2.Pop
3.Display Stack
4.Exit
4
Exiting*/
