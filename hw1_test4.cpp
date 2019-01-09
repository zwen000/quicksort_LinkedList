#include <stdlib.h>     /*and, malloc*/
#include <stdio.h>      /*printf*/
#include<iostream>
#include <time.h>  
using namespace std;

struct listnode {

    struct listnode *next;
    long key;
};

int randomindex( int k )
{ return(  rand() % k );
}

/*Finds length of list, which is usefull in selecting a random pivot*/
int ListLength (struct listnode *list)
{
    struct listnode *temp = list;

    int i=0;
    while(temp!=NULL)
    {
        i++;
        temp=temp->next;

    }
    return i;
}

int list_count(listnode *head) 
{
	if(head != NULL) { return 1 + list_count(head->next);  } 
	return 0;
	 
}

listnode * head_insert( listnode*&  head,int num)
{
	listnode* new_num = new listnode;
	new_num->key = num;
	new_num->next = head;
	head = new_num;
}




void show( listnode * head)
{
	while(head != NULL)
	{
		cout<< head->key <<endl; 
		head = head-> next;
	}
	cout<<endl;
} 

int p=0; 


struct listnode *sort(struct listnode *a)
{
	int length = list_count(a);
    if (length <= 1) 
		return a;
    struct listnode *left=NULL, *right=NULL, *cur=NULL, *next, *tmp, *pivot; 
    //get pivot
	int index = length/2; //randomindex(length);
	pivot= a;
	for(int j = 0; j< index; j++)
		pivot= pivot->next;
	
	tmp = a;
	while(tmp->next != pivot && tmp != pivot)
	{
		tmp = tmp->next;
	}
	tmp->next = pivot->next;
	
	cur = a;
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


int main()
{

	listnode * begin =NULL; 
 	head_insert( begin,11);
 	head_insert( begin,4);
	head_insert( begin,12);
	head_insert(begin,21);
	head_insert( begin,10);
	head_insert( begin,202);
	head_insert( begin,66);
	head_insert( begin,30);
	head_insert( begin,15);
	show(begin);
	begin= sort(begin);
	cout<<p;
	show(begin);
    exit(0);
}


