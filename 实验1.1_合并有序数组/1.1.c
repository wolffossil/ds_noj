#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
    int data;
    struct list* next;
}list;


list* initlist()
{
    list *head;
    head=(list*)malloc(sizeof(list));
    head->next=NULL;
    return head;
}

list* creatlist(list *head,int n)
{
    int i,e;
    list *q,*p,*l;
    p=head;
    l=head;
    for(i=0;i<n;i++)
    {
        scanf("%d",&e);
        q=initlist();
        q->data=e;
        p->next=q;
        p=q;
    }
    p->next=NULL;
    return l;
}

list* sort(list*a,list*b)
{
    list *pa,*pb,*pc;
    list *c;
    c=initlist();
    pc=c;
    pa=a->next;
    pb=b->next;
    while(pa!=NULL&&pb!=NULL)
    {
        if(pa->data>pb->data)
        {   
            pc->next=pb;
            pc=pb;
            pb=pb->next;
        }
        else if(pa->data<pb->data)
        {   
            pc->next=pa;
            pc=pa;
            pa=pa->next;
        }
        else if(pa->data==pb->data)
        {
            pc->next=pa;
            pc=pa;
            pa=pa->next;
            pc->next=pb;
            pc=pb;
            pb=pb->next;
        }
    }
    while(pa!=NULL)
    {
            pc->next=pa;
            pc=pa;
            pa=pa->next;
    }
    while(pb!=NULL)
    {
            pc->next=pb;
            pc=pb;
            pb=pb->next;
    }
    return c;
}

void print(list *c)
{
    list *pc;
    pc=c->next;
    while(pc!=NULL)
    {
        printf("%d\n",pc->data);
        pc=pc->next;
    }

}

int main()
{
    list *a,*b,*c;
    int m,n;
    a=initlist();
    b=initlist();
    scanf("%d",&m);
    a=creatlist(a,m);
    scanf("%d",&n);
    b=creatlist(b,n);
    c=sort(a,b);
    print(c);
    return 0;
}

/*
3
1 3 7
5
2 4 6 8 10
*/