#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct PolyNode  // �ṹ��
{
    float coef;  //ϵ��
    int exp;     //ָ��
    struct PolyNode * next;
}PolyNode;
typedef PolyNode * Polynomial;   // ��������
Polynomial  CreateList()    //��������
{
    Polynomial L,p,r;
    r = L = (Polynomial )malloc(sizeof(PolyNode ));   //ͷ�ڵ���L�����ƶ�
    L->next = NULL;
    float x;
    int y;
    scanf("%f %d",&x,&y);
    while(x && y)   //�ж��������������Ϊ( x!=0 && y!=0 )
    {
        p = (Polynomial )malloc(sizeof(PolyNode ));
        p->coef = x;
        p->exp = y;
        p->next = NULL;
        r->next = p;
        r = p;
        scanf("%f %d",&x,&y);
        getchar();  //���� 0 0 ֮��Ļس�
    }
    return L;  // �������������
}
Polynomial Add(Polynomial A, Polynomial B)  //�ӷ�
{
    Polynomial C,S;
    Polynomial pa,pb,pc;
    float x;
    pa = A->next;
    pb = B->next;
    C = (Polynomial )malloc(sizeof(PolyNode ));  // ����ͷ�ڵ�
    pc = C;   // ����ʱʹ��pcָ��
    pc->next = NULL;
    while (pa && pb)
    {
        if(pa->exp == pb->exp)  // ָ�����ʱ
        {
            x = pa->coef + pb->coef;
            if (x)     // ������ϵ����Ϊ0ʱ
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
            if(pa->exp < pb->exp)   //ָ���������A��ָ��С��B��ָ��ʱ
            {
                S = (Polynomial )malloc(sizeof(PolyNode ));
                S->coef = pa->coef;
                S->exp = pa->exp;
                S->next = NULL;
                pc->next = S;
                pc = S;
                pa = pa->next;
            }
            else   //ָ���������A��ָ������B��ָ��ʱ
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
    while (pa)   //A�����������ʱ
    {
        S = (Polynomial )malloc(sizeof(PolyNode ));
        S->coef = pa->coef;
        S->exp = pa->exp;
        S->next = NULL;
        pc->next = S;
        pc = S;
        pa = pa->next;
    }
    while (pb)   //B�����������ʱ
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
    printf("�������ʽA��\n");
    A = CreateList();
    printf("�������ʽB��\n");
    B = CreateList();
    C = (Polynomial )malloc(sizeof(PolyNode ));
    C->next = NULL;
    C = Add(A , B);
    pc = C->next;
    while(pc != NULL)
    {
        printf("����CΪ��%.2fX^%d " ,pc->coef, pc->exp);
        pc = pc->next;
    }
    printf("\n");
    return 0;
}

