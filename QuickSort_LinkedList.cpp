//Zhicong Wen 
//CSC220

#include <stdio.h>
#include <stdlib.h>

struct listnode { struct listnode * next;
                  long              key; } ;

int list_count(listnode *head) 
{
	int i=0;
    while(head!=NULL)
    {
        i++;
        head=head->next;

    }
    return i;
}


struct listnode *sort(struct listnode *a)
{
	int length = list_count(a);
    if (length <= 1) 
		return a;
    struct listnode *left=NULL, *right=NULL, *cur=NULL, *next, *tmp, *pivot;
    
    //get pivot
	int index = rand()%length;
	pivot= a;
	for(int j = 0; j< index; j++)
		pivot= pivot->next;
	
	
	while(a)
	{
		next = a->next;
		if(pivot->key != a->key)
		{
			a->next= cur;
			cur = a; 
		}
		a = next;
	}
	
	while(cur != NULL)
    {
        next = cur->next;
        if(cur->key < pivot->key) //if smaller , push to left
        {
            cur->next = left;
            left = cur;
        }
        else {//else, push to rright
            cur->next = right;
            right = cur;    
        }
        cur = next;
    }
	
	
	left = sort(left);
	right = sort(right); 
    //reconnect 
    if(left != NULL) //if pivot isn't the smallest number
    {
    	tmp = left;
    	while(tmp->next != NULL){
            tmp = tmp->next;
            }
        tmp->next = pivot;
    	pivot->next = right;
    	return left;
    }
    else //right can't be empty 
	{
    	pivot->next = right;
        return pivot; 
    }
}

int main(void)
{  
   long i; 
   struct listnode *node, *tmpnode, *space;
   space =  (struct listnode *) malloc( 500000*sizeof(struct listnode));
   for( i=0; i< 500000; i++ )
   {  (space + i)->key = 2*((17*i)%500000);
      (space + i)->next = space + (i+1);
   }
   (space+499999)->next = NULL;
   node = space;
   printf("\n prepared list, now starting sort\n");
   node = sort(node);
   printf("\n checking sorted list\n");
   for( i=0; i < 500000; i++)
   {  if( node == NULL )
      {  printf("List ended early\n"); exit(0);
      }
      if( node->key != 2*i )
      {  printf("Node contains wrong value\n"); exit(0);
      }
      node = node->next;
   }
   printf("Sort successful\n");
   exit(0);
}
