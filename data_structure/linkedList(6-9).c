#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode{
    int coef;
    int expon;
    struct ListNode * link;
} ListNode;

typedef struct ListType{
    int size;
    ListNode *head;
    ListNode *tail;
} ListType;

ListType * create(){
    ListType *p = (ListType*)malloc(sizeof(ListType));
    p->size = 0; // int type이니깐 null이 아닌 0으로 초기화 해야 됨
    p->head = NULL;
    p->tail = NULL;
    return p;

};

void insert_node(ListType *plist, int coef, int expon){
    // 동적으로 할당
    ListNode * temp = (ListNode*)malloc(sizeof(ListNode)); // 메모리 할당 받음
    temp -> coef = coef;
    temp -> expon = expon;
    temp -> link = NULL;
    if(plist->tail == NULL){
        plist->head = plist->tail = temp;
    }else{
        plist->tail->link = temp;
        plist -> tail = temp;
    }
    plist->size++;
}

void poly_add(ListType * plist1, ListType *plist2, ListType *plist3){
    ListNode *a = plist1->head;
    ListNode *b = plist2->head;

    int sum;

    while(a != NULL && b != NULL){ // a&&b 랑 똑같음
        if(a->expon == b->expon){
        sum = a->coef + b->coef;
        insert_node(plist3, sum, a->expon);
        a = a->link; b = b->link;
        }
        else if(a->expon < b->expon){
            insert_node(plist3, b->coef, b->expon);
            b = b->link;
        }
        else{
            insert_node(plist3, a->coef, a->expon);
            a = a->link;
        }
    } // end while => 수식이 다른 쪽에는 남아있을 수 있음
    for(; a != NULL; a = a->link)
        insert_node(plist3, a->coef, a->expon);
    for(; b != NULL; b = b->link)
        insert_node(plist3, b->coef, b->expon);

}

void poly_print(ListType* plist){
    ListNode *p = plist -> head;

    printf("polynominal = ");
    for(; p; p=p->link){
        printf("%d^%d + ", p->coef, p->expon);
    }
    printf("\n");

}

int main(){
    ListType *list1, *list2, *list3;

    list1 = create();
    list2 = create();
    list3 = create();

    insert_node(list1, 3, 12);
    insert_node(list1, 2, 8);
    insert_node(list1, 1, 0);

    insert_node(list2, 8, 12);
    insert_node(list2, -3, 10);
    insert_node(list2, 10, 6);

    poly_add(list1, list2, list3);

    poly_print(list1);
    poly_print(list2);
    poly_print(list3);
}
