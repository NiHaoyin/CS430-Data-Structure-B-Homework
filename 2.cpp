#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct PolyNode  // 结构体
{
    float coef;  //系数
    int exp;     //指数
    struct PolyNode * next;
}PolyNode;
typedef PolyNode * Polynomial;   // 类型声明
Polynomial  CreateList()    //建表并输入
{
    Polynomial L,p,r;
    r = L = (Polynomial )malloc(sizeof(PolyNode ));   //头节点是L不能移动
    L->next = NULL;
    float x;
    int y;
    scanf("%f %d",&x,&y);
    while(x && y)   //判断输入结束的条件为( x!=0 && y!=0 )
    {
        p = (Polynomial )malloc(sizeof(PolyNode ));
        p->coef = x;
        p->exp = y;
        p->next = NULL;
        r->next = p;
        r = p;
        scanf("%f %d",&x,&y);
        getchar();  //读掉 0 0 之后的回车
    }
    return L;  // 返回输入的链表
}
Polynomial Add(Polynomial A, Polynomial B)  //加法
{
    Polynomial C,S;
    Polynomial pa,pb,pc;
    float x;
    pa = A->next;
    pb = B->next;
    C = (Polynomial )malloc(sizeof(PolyNode ));  // 申请头节点
    pc = C;   // 操作时使用pc指针
    pc->next = NULL;
    while (pa && pb)
    {
        if(pa->exp == pb->exp)  // 指数相等时
        {
            x = pa->coef + pb->coef;
            if (x)     // 相加完的系数不为0时
            {
                S = (Polynomial )malloc(sizeof(PolyNode ));
                S->coef = x;
                S->exp = pa->exp;
                S->next = NULL;
                pc->next = S;
                pc = S;
            }
            pa = pa->next;
            pb = pb->next;
        }
        else
            if(pa->exp < pb->exp)   //指数不相等且A项指数小于B项指数时
            {
                S = (Polynomial )malloc(sizeof(PolyNode ));
                S->coef = pa->coef;
                S->exp = pa->exp;
                S->next = NULL;
                pc->next = S;
                pc = S;
                pa = pa->next;
            }
            else   //指数不相等且A项指数大于B项指数时
            {
                S = (Polynomial )malloc(sizeof(PolyNode ));
                S->coef = pb->coef;
                S->exp = pb->exp;
                S->next = NULL;
                pc->next = S;
                pc = S;
                pb = pb->next;
            }
    }
    while (pa)   //A链表后几项多出来时
    {
        S = (Polynomial )malloc(sizeof(PolyNode ));
        S->coef = pa->coef;
        S->exp = pa->exp;
        S->next = NULL;
        pc->next = S;
        pc = S;
        pa = pa->next;
    }
    while (pb)   //B链表后几项多出来时
    {
        S = (Polynomial )malloc(sizeof(PolyNode ));
        S->coef = pb->coef;
        S->exp = pb->exp;
        S->next = NULL;
        pc->next = S;
        pc = S;
        pb = pb->next;
    }
    return C;
}

int main()
{
    Polynomial A, B, C, pc;
    char f;
    printf("输入多项式A：\n");
    A = CreateList();
    printf("输入多项式B：\n");
    B = CreateList();
    C = (Polynomial )malloc(sizeof(PolyNode ));
    C->next = NULL;
    C = Add(A , B);
    pc = C->next;
    while(pc != NULL)
    {
        printf("链表C为：%.2fX^%d " ,pc->coef, pc->exp);
        pc = pc->next;
    }
    printf("\n");
    return 0;
}

