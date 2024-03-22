#include <stdio.h>
#include <stdlib.h>

typedef struct list{
    int data;
    struct list *next;
    struct list *pre;
}list;

list* Initlist()
{
    list* head;
    head=(list*)malloc(sizeof(list));
    head->next=head->pre=head;
    return head;
}
list* Creatlist(list*head)
{
    int i;
    list *p;
    p=head;
    for(i=0;i<1000;i++)
    {
        list *q=(list*)malloc(sizeof(list));
        q->data=0;
        q->pre=p;
        p->next=q;
        q->next=head;//第一次循环时此时的head和p是一个东西，目的为把链表画成一个圈
        head->pre=q;
        p=p->next;
    }
    return head;
}
int main()
{
    int n,i,a,b;
    scanf("%d",&n);
    list *number,*sum;
    list *p,*q,*x;
    number=Initlist();
    sum=Initlist();
    number=Creatlist(number);
    sum=Creatlist(sum);
    number->next->data=2;//第一位储存2，即2*R(1)=2
    sum->next->data=2;//与上同理
    a=0,b=0;//分别是用来暂时存储进位和余数
    for(i=1;i<2000;i++)//循环两千次，确保精确度
    {
        p=number->pre;//做大数乘法时从链表的后方开始
        while(p!=number)//大于10则把10位的数字给b，个位数字放入data域中。
        {
            a=p->data*i+b;
            p->data=a%10;
            b=a/10;
            p=p->pre;
        }
        b=0;//清空b,为除法做准备
        p=p->next;//大数除法从链表的前方开始
        while(p!=number)//若计算出的数字为自然数，则直接放入data域；若等于0,或为小数，则要计算余数并给b。
        {
            a=p->data+b*10;
            p->data=a/(2*i+1);
            b=a%(2*i+1);
            p=p->next;
        }
        b=0;//清零
        p=number->pre;//大数加法均从末尾开始
        q=sum->pre;
        while(p!=number)//大于10进位，并储存个位数，进位数字赋给b。
        {
            a=p->data+q->data+b;
            q->data=a%10;
            b=a/10;
            p=p->pre;
            q=q->pre;
        }
    }
    printf("3.");
    x=sum->next->next;//从小数开始输出。
    for(i=0;i<n;i++)
    {
        printf("%d",x->data);
        x=x->next;
    }
    return 0;
}

