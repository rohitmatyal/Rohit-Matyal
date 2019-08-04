#include <stdio.h>
#include <string.h>
struct node 								//structure is created for saving the palindromes
{
    char* s[1000];
    struct node * next;
};
void printll(struct node *start)			// to print the palindromes	
{
	struct node *a=start;
	while(a!=NULL)
	{
		printf("%s\n",a->s);
		a=a->next;
	}
}
int countll(struct node *start)				// to count the number of distinct palindromes
{
	int i;
	struct node *a=start;
	while(a!=NULL)
	{
		i++;
		a=a->next;
	}
	return i;
}

 int match(char *a,char *b)					// to match the palindromes, if they are same return 1 else 0
{
	int x=strcmp(a,b);
	if(x==0)
	return 1;
	else 
	return 0;
}
struct node * addnode(struct node * start,int i ,int j ,char *pal) 	// to add the palindromes into the linked list
{    																// starting and ending address of the palindrome is passed here
    int x=j-i,a;
    char* add =(char *)malloc((x+2)*(sizeof(char)));				// memory is created for the palindrome
    for(a=0;a<=x;a++)												
    {
        add[a]=pal[i];												// palindrome is savd into character array "add"
        i++;
    }
    add[a]='\0';	
    struct node *new_node,*back;
    new_node = (struct node*)malloc(sizeof(struct node));			// new node is created to be add in linked list
    int z=0;
    strcpy(new_node->s,add);										// add is copied to new node -> s
    new_node->next=NULL;											
   	if (start == NULL) 												// if there is no node, then make new node to be the first node and return 
    {   															// starting address of ythe linked list
    	start=new_node;    
    }
    else{															// if not the first node
	back=start;
	while(back->next!=NULL)											// check if its the last node
	{
	if(match(back->s,new_node->s))									// if not the last node then check if the value of that palindrome is same as
		break;														// the new palindrome to be added, if same then break the loop
	else															// if not same		
		back=back->next;											// got o the next node and repeat till its the last node
	}
	if(match(back->s,new_node->s))									// if the palindromes are same then delete the new node
		free(new_node);
	else
		back->next=new_node;										// if palindromes are not same the add the new palindrome at the end 
	}
	return start;													// return the start of the list
}
int rec(char * pal,int i, int j)									// checks if its a palindrome and return 1 if its a plaindrome
{
	
    int count=0;
    if(i>=j)
        count++; 
    if(i<j&&pal[i]==pal[j])
        count+=rec(pal,i+1,j-1);
    return count; 
}
int detect_distinct_palindrome(char *pal,int size)
{
    int i,j,flag=0,temp=0,a;
    struct node* start = NULL;    
    for(i=0;i<size;i++) 						//this loop is used to get the start point substring 
    {
        for(j=i;j<size;j++)						//this loop is used to get  the end point of substring
        {										// both of the combined loop will generate all posibilities of start and end point of substring
        	temp=rec(pal,i,j);					// this funtion will check if the substring is palindrome or not and return 1 if its a plaindrome
        	if(temp==1)
        		start=addnode(start,i,j,pal); 	// this funtion will add the palindrome in the linked list and within this function it will-
		}								 		//- delete the repeated plindromes	
    }
    printll(start);         					// it will print the distinct palindromes
    return (countll(start));					// return th number of palindromes
}
int main()
{   int size,palindromes;
    printf("Size of String: \n"); 					//takes the size of the palindrome
    scanf("%d",&size);
    char* pal =(char *)malloc(size*(sizeof(char)));		//creates a memory space to store the palindrome
    printf("Enter String: ");
    scanf("%s",pal);
    palindromes=detect_distinct_palindrome(pal,size);	 // prints all distinct palindromes and return the number of palindromes
    printf("\nI found %d! palindromes",palindromes);	 // prints the number of distinct palindromes
    return 0;
}




