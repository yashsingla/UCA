#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

struct node
{
    int key;
    struct node *next;
};

void push(struct node **node,int n)
{
    struct node *temp=(struct node*)malloc(sizeof(temp));
    temp->key=n;
    temp->next=*node;
    *node=temp;
}


void printRandom(struct node *head)
{
    if(head==NULL)
        return;

    struct node *current=head;
    int result=current->key;
    srand(time(NULL));

     int n;
    for(n=2;current!=NULL;n++)
    {
        if(rand()%n==0)
         result=current->key;
        current=current->next;
    }
    printf("random number:%d",result);
}

void print(struct node *root)
{
    while(root)
    {
        printf("%d\n",root->key);
        root=root->next;
    }
}

int main()
{
    struct node *root=NULL;
     push(&root,5);
     push(&root,20);
     push(&root,-1);
     push(&root,30);
     push(&root,25);

    print(root);

    printRandom(root);

     getch();//getche or getchar
     return 0;

}
