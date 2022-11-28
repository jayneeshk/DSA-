#include<stdio.h>
#include<stdlib.h>
struct node
{ 
    struct node* prev;
    int data;
    struct node* next;	
};

struct node* start=NULL;

void insert_at_start_s()
{
	struct node* new=(struct node*) malloc(sizeof(struct node));
	int d;
	printf("Enter data of node:");
	scanf("%d",&d);
	new->data= d;
	new->next=start;
	start=new;
	return;
}
struct node* insert_at_end_s()
{
	struct node* new=(struct node*) malloc(sizeof(struct node));
    int d;
	printf("Enter data of node:");
	scanf("%d",&d);
	new->data= d;
	if(start==NULL)
	{
		new->next=start;
	    start=new;
	    return start;
	}
	struct node* temp=start;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	new->next=temp->next;
	temp->next=new;
	return temp;
}
struct node* insert_after_data_s()
{
	int d,prev_d;
	printf("Enter data after which node is to be inserted:");
	scanf("%d",&prev_d);
	printf("Enter data to be inserted:");
	scanf("%d",&d);
	struct node* new=(struct node*) malloc(sizeof(struct node));
	new->data= d;
    struct node* temp=start;
    while(temp!=NULL)
    {
    	if(temp->data==prev_d)
    	{
    		new->next=temp->next;
    		temp->next=new;
    		return temp;
		}
		temp=temp->next;
	}
	printf("Data not found!\n");
	return NULL;
}
struct node* insert_node_s()
{
	int pos,d,i;
	printf("Enter a valid position on which node is to be inserted:");
	scanf("%d",&pos);
	struct node* new=(struct node*) malloc(sizeof(struct node));
	printf("Enter data of node:");
	scanf("%d",&d);
	new->data= d;
	new->next=NULL;
	if (pos==1)
	{
		new->next=start;
		start=new;
		return start;
	}
    struct node* temp=start;
    for(i=1;i<(pos-1);i++)
    {
    	temp=temp->next;
	}
	new->next=temp->next;
	temp->next=new;
	return temp;
}
void traverse_list_s()
{  
    struct node* temp=start;
    while(temp!=NULL)
    {
    	printf("%d ",temp->data);
    	temp=temp->next;
    }
    printf("\n");
    return;	
}
void delete_from_start_s()
{
	start=start->next;
	return;
}
struct node* delete_from_end_s()
{
	if(start->next==NULL)
	{
		start=NULL;
		return start;
	}
	struct node*temp=start;
	while(temp->next->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=NULL;
	return temp;
}
struct node* delete_data_s()
{
	int d;
	printf("Enter data to be deleted:");
	scanf("%d",&d);
	if(start->data==d)
	{
		start=start->next;
		return start;
	}
    struct node* temp=start;
    while(temp->next!=NULL)
    {
    	if(temp->next->data==d)
    	{
    		temp->next=temp->next->next;
    		return temp;
		}
		temp=temp->next;
	}
	printf("Data not found!\n");
	return NULL;
}
struct node* delete_node_s()
{
	int pos,i;
	printf("Enter a valid position of which node is to be deleted:");
	scanf("%d",&pos);
	if (pos==1)
	{
		start=start->next;
		return start;
	}
    struct node* temp=start;
    for(i=1;i<(pos-1);i++)
    {
    	temp=temp->next;
	}
	temp->next=temp->next->next;
	return temp;
}
void search_item_s()
{
	int item,pos=1;
	printf("Enter item to be searched:");
	scanf("%d",&item);
	struct node* temp=start;
	while(temp!=NULL)
	{
		if(temp->data==item)
		{
			printf("%d found at node %d\n",item,pos);
		    return;
		}
		temp=temp->next;
		pos++;
	}
	printf("Not Found in the List\n");
	return;
}
void insert_at_start_c()
{
    struct node* new=(struct node*) malloc(sizeof(struct node));
    int d;
	printf("Enter data of node:");
	scanf("%d",&d);
	new->data= d;
	if (start==NULL)
	{
		start=new;
		new->next=start;
		return;
	}
	struct node* temp=start;
    while(temp->next!=start)
	{
		temp=temp->next;
    }
    temp->next=new;
    new->next=start;
	start=new;
	return;
}

void insert_at_end_c()
{
	struct node* new=(struct node*) malloc(sizeof(struct node));
    int d;
	printf("Enter data of node:");
	scanf("%d",&d);
	new->data= d;
	if(start==NULL)
	{
		start=new;
		new->next=start;
	    return;
	}
	struct node* temp=start;
	while(temp->next!=start)
	{
		temp=temp->next;
	}
	temp->next=new;
	new->next=start;
	return;
}
void insert_after_data_c()
{
	int d,prev_d;
	printf("Enter data after which node is to be inserted:");
	scanf("%d",&prev_d);
	printf("Enter data to be inserted:");
	scanf("%d",&d);
	struct node* new=(struct node*) malloc(sizeof(struct node));
	new->data= d;
    struct node* temp=start;
    while(temp->data!=prev_d)
    {
    	temp=temp->next;
    	if(temp==start)
    	{
    		printf("Data not found!");
	        return;
		}
	}
	new->next=temp->next;
    temp->next=new;
    return;
}
void insert_node_c()
{
	int pos,d,i;
	printf("Enter a valid position on which node is to be inserted:");
	scanf("%d",&pos);
	struct node* new=(struct node*) malloc(sizeof(struct node));
	printf("Enter data of node:");
	scanf("%d",&d);
	new->data= d;
	new->next=NULL;
	if (start==NULL)
	{
		new->next=new;
		start=new;
		return;
	}
    struct node* temp=start;
    for(i=1;i<(pos-1);i++)
    {
    	temp=temp->next;
	}
	new->next=temp->next;
	temp->next=new;
	if(pos==1)
	    start=new;
	return;
}
void traverse_list_c()
{  
    struct node* temp=start;
    while(temp->next!=start)
    {
    	printf("%d ",temp->data);
    	temp=temp->next;
    }
    printf("%d ",temp->data);
    printf("\n");
    return;	
}
void delete_from_start_c()
{
	if (start->next==start)
	{
		start=NULL;
		return;
	}
	struct node* temp=start;
    while(temp->next!=start)
    {
    	temp=temp->next;
	}
	start=start->next;
	temp->next=start;
	return;
}

void delete_from_end_c()
{
	if(start->next==start)
	{
		start=NULL;
		return;
	}
	struct node*temp=start;
	while(temp->next->next!=start)
	{
		temp=temp->next;
	}
	temp->next=start;
	return;
}
void delete_data_c()
{
	int d;
	printf("Enter data to be deleted:");
	scanf("%d",&d);
	if (start->data==d)
	{
		delete_from_start_c();
	}
    struct node* temp=start;
    while(temp->next->data!=d)
    {
    	temp=temp->next;
    	if(temp==start)
    	{
    		printf("Data not found!\n");
	        return;
		}
	}
	temp->next=temp->next->next;
    return;
}
void delete_node_c()
{
	int pos,i;
	printf("Enter a valid position of which node is to be deleted:");
	scanf("%d",&pos);
	if (start->next==start)
	{
		start=NULL;
		return;
	}
	if(pos==1)
	{
	    delete_from_start_c();
	    return;
    }
    struct node* temp=start;
    for(i=1;i<(pos-1);i++)
    {
    	temp=temp->next;
	}
	temp->next=temp->next->next;
	return;
}
void search_item_c()
{
	int item,pos=1;
	printf("Enter item to be searched:");
	scanf("%d",&item);
	struct node* temp=start;
	while(temp->next!=start)
	{
		if(temp->data==item)
		{
			printf("%d found at node %d\n",item,pos);
		    return;
		}
		temp=temp->next;
		pos++;
	}
	if(temp->data==item)
	{
		printf("%d found at node %d\n",item,pos);
		return;
	}
	printf("Not Found in the List\n");
	return;
}
void insert_at_start_d()
{
    insert_at_start_s();
    start->prev=NULL;
    return;
}

void insert_at_end_d()
{
	struct node* p=insert_at_end_s();
	if(p==start)
	{
		start->prev=NULL;
		return;
	}
	p->next->prev=p;
	return;
}
void insert_after_data_d()
{
	struct node* p=insert_after_data_s();
	p->next->prev=p;
	return;
}
void insert_node_d()
{
	struct node* p=insert_node_s();
	if(p==start)
	{
		p->prev=NULL;
		return;
	}
	p->next->prev=p;
	return;
}
void traverse_list_d()
{  
    traverse_list_s();
    return;	
}

void delete_from_start_d()
{
	delete_from_start_s();
	if(start!=NULL)
	{
		start->prev=NULL;
	}
	return;
}

void delete_from_end_d()
{
	struct node* p=delete_from_end_s();
	if(start!=NULL && p==start) 
	{
		    p->prev=NULL;
	}
	return;	
}

void delete_data_d()
{
	struct node* p=delete_data_s();
	if(start!=NULL) 
	{
	    if(p==start)
		    p->prev=NULL;

	    else if(p->next!=NULL)
		    p->next->prev=p;
    }
	return;
}
void delete_node_d()
{
	struct node* p=delete_node_s();
	if(start!=NULL) 
	{
	    if(p==start)
		    p->prev=NULL;

	    else if(p->next!=NULL)
		    p->next->prev=p;
    }
	return;
}
void search_item_d()
{
	search_item_s();
	return;
}

void menu()
{	
    printf("Enter 1 to insert a node at start\n");
    printf("Enter 2 to insert a node at end\n");
    printf("Enter 3 to insert a node after a given data\n");
    printf("Enter 4 to insert a node at a position\n");
	printf("Enter 5 to traverse the linked list\n");
	printf("Enter 6 to delete a node from start\n");
	printf("Enter 7 to delete a node from end\n");
	printf("Enter 8 to delete a node containing given data\n");
	printf("Enter 9 to delete a node from a position\n");
	printf("Enter 10 to search for a data item\n");
	printf("Enter 11 to Exit\n");
	return;
}

void sel_opt_s()
{
	int ch;
    while(1)
	{
		printf("\nEnter your Choice:");
	    scanf("%d",&ch);
	    switch(ch)
	    {
	    	case 1:
	    		insert_at_start_s();
	    		printf("Linked List after insertion:\n");
	    		traverse_list_s();
	    		break;
	    	case 2:
	    		insert_at_end_s();
	    		printf("Linked List after insertion:\n");
	    		traverse_list_s();
	    		break;
	    	case 3:
	    		insert_after_data_s();
	    		printf("Linked List after insertion:\n");
	    		traverse_list_s();
	    		break;
	    	case 4:
	    		insert_node_s();
	    		printf("Linked List after insertion:\n");
	    		traverse_list_s();
	    		break;
	    	case 5:
	    		if(start==NULL)
				{
					printf("Empty List!\n");
   	                break;
				}
	    		printf("Linked List:\n");
	    		traverse_list_s();
	    		break;
	    	case 6:
	    		if(start==NULL)
				{
					printf("Empty List!\n");
   	                break;
				}
	    		delete_from_start_s();
	    		printf("Linked List after deletion:\n");
	    		traverse_list_s();
	    		break;
	    	case 7:
	    		if(start==NULL)
				{
					printf("Empty List!\n");
   	                break;
				}
	    		delete_from_end_s();
	    		printf("Linked List after deletion:\n");
	    		traverse_list_s();
	    		break;
	    	case 8:
	    		if(start==NULL)
				{
					printf("Empty List!\n");
   	                break;
				}
	    		delete_data_s();
	    		printf("Linked List after deletion:\n");
	    		traverse_list_s();
	    		break;
	    	case 9:
	    		if(start==NULL)
				{
					printf("Empty List!\n");
   	                break;
				}
	    		delete_node_s();
	    		printf("Linked List after deletion:\n");
	    		traverse_list_s();
	    		break;
	    	case 10:
	    		if(start==NULL)
				{ 
				    printf("Empty List!\n");  
					break; 
				}
	    		search_item_s();
	    		break;
	    	case 11:
	    		printf("Given type of Linked List is closed.\n\n");
	    		return;
	    	default:
	    		printf("Invalid Choice!\n\n");
		}
    }
}
//looping for selecting operations on circular linked list multiple times.
void sel_opt_c()
{
	int ch;
    while(1)
	{
		printf("\nEnter your Choice:");
	    scanf("%d",&ch);
	    switch(ch)
	    {
	    	case 1:
	    		insert_at_start_c();
	    		printf("Linked List after insertion:\n");
	    		traverse_list_c();
	    		break;
	    	case 2:
	    		insert_at_end_c();
	    		printf("Linked List after insertion:\n");
	    		traverse_list_c();
	    		break;
	    	case 3:
	    		insert_after_data_c();
	    		printf("Linked List after insertion:\n");
	    		traverse_list_c();
	    		break;
	    	case 4:
	    		insert_node_c();
	    		printf("Linked List after insertion:\n");
	    		traverse_list_c();
	    		break;
	    	case 5:
	    		if(start==NULL)
				{
					printf("Empty List!\n");
   	                break;
				}
	    		printf("Linked List:\n");
	    		traverse_list_c();
	    		break;
	    	case 6:
	    		if(start==NULL)
				{
					printf("Empty List!\n");
   	                break;
				}
	    		delete_from_start_c();
	    		printf("Linked List after deletion:\n");
	    		traverse_list_c();
	    		break;
	    	case 7:
	    		if(start==NULL)
				{
					printf("Empty List!\n");
   	                break;
				}
	    		delete_from_end_c();
	    		printf("Linked List after deletion:\n");
	    		traverse_list_c();
	    		break;
	    	case 8:
	    		if(start==NULL)
				{
					printf("Empty List!\n");
   	                break;
				}
	    		delete_data_c();
	    		printf("Linked List after deletion:\n");
	    		traverse_list_c();
	    		break;
	    	case 9:
	    		if(start==NULL)
				{
					printf("Empty List!\n");
   	                break;
				}
	    		delete_node_c();
	    		printf("Linked List after deletion:\n");
	    		traverse_list_c();
	    		break;
	    	case 10:
	    		if(start==NULL)
				{ 
				    printf("Empty List!\n");  
					break; 
				}
	    		search_item_c();
	    		break;
	    	case 11:
	    		printf("Given type of Linked List is closed.\n\n");
	    		return;
	    	default:
	    		printf("Invalid Choice!\n\n");
		}
    }
}
//looping for selecting operations on doubly linked list multiple times.
void sel_opt_d()
{
	int ch;
    while(1)
	{
		printf("\nEnter your Choice:");
	    scanf("%d",&ch);
	    switch(ch)
	    {
	    	case 1:
	    		insert_at_start_d();
	    		printf("Linked List after insertion:\n");
	    		traverse_list_d();
	    		break;
	    	case 2:
	    		insert_at_end_d();
	    		printf("Linked List after insertion:\n");
	    		traverse_list_d();
	    		break;
	    	case 3:
	    		insert_after_data_d();
	    		printf("Linked List after insertion:\n");
	    		traverse_list_d();
	    		break;
	    	case 4:
	    		insert_node_d();
	    		printf("Linked List after insertion:\n");
	    		traverse_list_d();
	    		break;
	    	case 5:
	    		if(start==NULL)
				{
					printf("Empty List!\n");
   	                break;
				}
	    		printf("Linked List:\n");
	    		traverse_list_d();
	    		break;
	    	case 6:
	    		if(start==NULL)
				{
					printf("Empty List!\n");
   	                break;
				}
	    		delete_from_start_d();
	    		printf("Linked List after deletion:\n");
	    		traverse_list_d();
	    		break;
	    	case 7:
	    		if(start==NULL)
				{
					printf("Empty List!\n");
   	                break;
				}
	    		delete_from_end_d();
	    		printf("Linked List after deletion:\n");
	    		traverse_list_d();
	    		break;
	    	case 8:
	    		if(start==NULL)
				{
					printf("Empty List!\n");
   	                break;
				}
	    		delete_data_d();
	    		printf("Linked List after deletion:\n");
	    		traverse_list_d();
	    		break;
	    	case 9:
	    		if(start==NULL)
				{
					printf("Empty List!\n");
   	                break;
				}
	    		delete_node_d();
	    		printf("Linked List after deletion:\n");
	    		traverse_list_d();
	    		break;
	    	case 10:
	    		if(start==NULL)
				{ 
				    printf("Empty List!\n");  
					break; 
				}
	    		search_item_d();
	    		break;
	    	case 11:
	    		printf("Given type of Linked List is closed.\n\n");
	    		return;
	    	default:
	    		printf("Invalid Choice!\n\n");
		}
    }
}
//menu and looping to make singly, circular or doubly linked list.
void main()
{
	int ch;
	printf("Enter 1 to make Singly Linked List\n");
	printf("Enter 2 to make Circular Linked List\n");
	printf("Enter 3 to make Doubly Linked List\n");
	printf("Enter 4 to Exit\n");
	while(1)
	{
		printf("\nEnter your Choice for type of linked list:");
	    scanf("%d",&ch);
	    switch(ch)
	    {
	    	case 1:
	    		printf("-----Operation for Singly Linked List-----\n");
	    		menu();
	    		sel_opt_s();
	    		break;
	    	case 2:
	    		printf("-----Operation for Circular Linked List-----\n");
	    		menu();
	    		sel_opt_c();
	    		break;
	    	case 3:
	    		printf("-----Operation for Doubly Linked List-----\n");
	    		menu();
	    		sel_opt_d();
	    		break;
	    	case 4:
	    		printf("Thanks!");
	    		printf("\n\n\nGovind Shukla\n2101641520065\nCS-AI 3rd(Sem.) A");
	    		return;
	    	default:
	    		printf("Invalid Choice!\n\n");
		}
		start=NULL;
    }
}
