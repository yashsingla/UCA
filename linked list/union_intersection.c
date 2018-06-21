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

int isPresent(struct node *list,struct node *temp)
{    struct node *temp1=list;
    while(temp1){
    if(temp1->key==temp->key)
         return 0;
      temp1=temp1->next;
}
return 1;
}

void union_1(struct node **unin,struct node *head1,struct node *head2)
{
    if(head1==NULL)
        *unin=head2;
    else
        if(head2==NULL)
        *unin=head1;
   else{

     struct node *t1=head1,*t2=head2,*list=NULL;

       while(t1!=NULL)
       {
           push(&list,t1->key);
           t1=t1->next;
       }

       while(t2!=NULL)
       {
           if(isPresent(list,t2))
               push(&list,t2->key);
           t2=t2->next;
       }

   *unin=list;
   }//main else ends
}

void inter_1(struct node **inter,struct node *head1,struct node *head2)
{
    if(head1==NULL)
    {
        *inter=head1;
    }
    else
        if(head2==NULL)
    {
        *inter=head2;
    }
    else
    {
        struct node *t1=head1,*t2=head2,*list=NULL;

        while(t1)
        {
         if(!(isPresent(t2,t1)))
          push(&list,t1->key);
           t1=t1->next;
        }

        *inter=list;
    }//else ends

}//function ends




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
    struct node *root2=NULL;
    struct node *unin=NULL;
    struct node *inter=NULL;

     push(&root,-9);
     push(&root,20);
     push(&root,-1);
     push(&root,30);
     push(&root,25);

     push(&root2,-1);
     push(&root2,14);
     push(&root2,-9);
     push(&root2,27);
     push(&root2,21);

     union_1(&unin,root,root2);
     inter_1(&inter,root,root2);

     printf("Union:");
     print(unin);

   printf("\n\n");
     printf("Intersection:");
     print(inter);


     getch();//getche or getchar
     return 0;

}

