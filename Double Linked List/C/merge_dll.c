#include <stdio.h>
#include <stdlib.h>

struct dlink {
    int info;
    struct dlink * prev;
    struct dlink * next;
}*start, *last;
void create(struct dlink *ptr);
void display();
void merge(struct dlink *l1, struct dlink *l2, struct dlink *l3);

void main(){
    struct dlink *l1, *l2, *l3;

    l1= (struct dlink *)malloc(sizeof(struct dlink));
    l2= (struct dlink *)malloc(sizeof(struct dlink));
    l3= (struct dlink *)malloc(sizeof(struct dlink));

    printf("\nFirst List Formation:\n");
    create(l1);
    printf("\nSecond List Formation:\n");
    create(l2);
    printf("\nMerged List:\n");
    merge(l1,l2,l3);
    display();
}
void create(struct dlink *ptr)
{
    int i, n,info;
    printf("\nEnter the size of the list:");
    scanf("%d",&n);

    if(n >= 1)
    {
        start = (struct dlink *)malloc(sizeof(struct dlink));

        if(start != NULL)
        {
            printf("Enter info of starting node: ");
            scanf("%d", &start->info);

            start->prev = NULL;
            start->next = NULL;

            last = start;

            for(i=2; i<=n; i++)
            {
                ptr = (struct dlink *)malloc(sizeof(struct dlink));

                if(ptr != NULL)
                {
                    printf("Enter info %d : ", i);
                    scanf("%d", &ptr->info);

                    ptr->prev = last;
                    ptr->next = NULL;

                    last->next = ptr;
                    last = ptr;
                }

            }

            printf("\nList Created\n");
        }
        else
        {
            printf("Allocation Unsuccessful");
        }
    }
}

void display(){
    struct dlink * temp;
    int n = 1;

    if(start == NULL)
    {
        printf("List empty.");
        exit(0);
    }
    else
    {
        temp = start;
        printf("\nInfo In the List From Start:\n");

        while(temp != NULL)
        {
            printf("Info %d  = %d\n", n, temp->info);

            n++;

            temp = temp->next;
        }
    }
}

void merge(struct dlink *l1, struct dlink *l2, struct dlink *l3){
    l3->info = l1->info;
    l3->next = NULL;
    l1 = l1->next;

    while(l1!=NULL){
        l3->next = (struct dlink *)malloc(sizeof(struct dlink));
        l3 = l3->next;
        l3->info = l1->info;
        l1 = l1->next;
        l3->next = NULL;
    }

    while(l2!=NULL){
        l3->next = (struct dlink *)malloc(sizeof(struct dlink));
        l3 = l3->next;
        l3->info = l2->info;
        l2 = l2->next;
        l3->next = NULL;
    }
}
