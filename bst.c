#include<stdio.h>
#include<stdlib.h>
struct node
{
struct node *left;
int data;
struct node *right;
};

struct node *root = NULL;
void inorder(struct node *);
void preorder(struct node *);
void postorder(struct node *);
void insert();
void delete();
void search();

void main()
{
int ch;
do{
	printf("\n1.insert\n2.inorder\n3.preorder	\n4.postorder		\n5.search\n6.delete\n7.exit\nenter your 	choice");
	scanf("%d",&ch);
	switch(ch)
	{
	case 1:insert();
	break;
	case 2:inorder(root);
	break;
	case 3:preorder(root);
	break;
	case 4:postorder(root);
	break;
	case 5:search(root);
	break;
	case 6:delete();
	break;
	}
	}
while(ch!=7);
}

void inorder(struct node *ptr)
{
	if (ptr!=NULL)
	{
	inorder(ptr->left);
	printf("%d ", ptr->data);
	inorder(ptr->right);
	}
}

void preorder(struct node *ptr)
{
	if (ptr!=NULL)
	{
	printf("%d ", ptr->data);
	preorder(ptr->left);
	preorder(ptr->right);
	}
}
void postorder(struct node *ptr)
{
	if (ptr!=NULL)
	{
	
	postorder(ptr->left);
	postorder(ptr->right);
	printf("%d ", ptr->data);
	}
}

void insert()
{
int x;
struct node *ne ,*ptr,*ptr1;
 ne=(struct node *)malloc(sizeof(struct node));
if (ne==NULL)
	{
	printf("\n insufficient Memory");
	return;
	}
printf("enter the data to insert");
scanf("%d",&x);
ne->right=ne->left=NULL;
ne->data=x;
if (root==NULL)
{
root=ne;
return;
}
ptr=root;
while(ptr!=NULL)
{
	if (x==ptr->data)
	{
	printf("Item present in the tree");
	break;
	}
if (x>ptr->data)
	{
	ptr1=ptr;
	ptr=ptr->right;
	}
else
	{
	ptr1=ptr;
	ptr=ptr->left;
	}
	}
if (ptr==NULL)
	{
	if (x>ptr1->data )
	ptr1->right=ne;
	else
	ptr1->left=ne;
}
}

void search(struct node *ptr)
{
int x;
ptr=root;
printf("enter the element to search");
scanf("%d",&x);
if(ptr==NULL)
{
printf("list is empty");
return;
}
while(ptr!=NULL)
{
if(ptr->data==x)
{
printf("element is present");
}	
if(x>ptr->data)
	{
	ptr=ptr->right;
	}
	else
	{
	ptr=ptr->left;
	}
}	
}

void delete()
{
struct node *parent,*p,*ptr;
int dat,x;
printf("enter the element to be delete");
scanf("%d",&x);

if (root==NULL)
{
printf("\nTree is empty");
return;
}
parent=NULL;
ptr=root;
while(ptr!=NULL)
{
if (ptr->data==x)
break;
parent=ptr;
if (x>ptr->data)
ptr=ptr->right;
else
ptr=ptr->left;
}
if (ptr==NULL)
{
	printf("Item Not Present");
	return;
}
if (ptr->right==NULL && ptr->left==NULL) //case1
{
if (parent==NULL)
	root=NULL;
else if (parent->right==ptr)
	parent->right=NULL;

else
	parent->left=NULL;
	printf("Element deleted");
free(ptr);
return;
}
if(ptr->right!=NULL && ptr->left!=NULL) //case 3
//find the inorder successor p
{
p=ptr->right;
while(p->left!=NULL)
{
p=p->left;
}
dat=p->data;
delete(p->data); //recursive call
ptr->data=dat;
return;

}
//case2
if (parent==NULL)
{
if (ptr->right==NULL)
root=ptr->left;
else

root=ptr->right;
}

else
{
if (parent->right==ptr)
{
	if (ptr->right==NULL)
		parent->right=ptr->left;
	else
		parent->right=ptr->right;

}
else
{
	if (ptr->left==NULL)
		parent->left= ptr->right;
	else
		parent->left=ptr->left;

}
}
printf("Element deleted");
free(ptr);
return;
}

