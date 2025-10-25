#include <stdio.h>
#include <stdlib.h>

// implementazione di linked list tramite struct
// questo codice non e' da intendersi come libreria, 
//   e' solo un test delle mie conoscenza di DS e C

struct node {
    int val;
    struct node* next;
};

typedef struct node Nodo;

Nodo* ll_nuovo_elem(int val);
void ll_print(Nodo* head);
void ll_push(Nodo* head, Nodo* elem);

int main(){
    // creo la testa della LL, solamento come riferimento
    Nodo* head = NULL;

    Nodo elem;
    elem.val = 1;
    elem.next = NULL;
    
    // assegno alla testa il riferimento del primo elemento
    head = &elem;

    printf("La lista, dopo aver inserito il primo elemento: \n");
    ll_print(head);

    Nodo elem2;
    elem2.val = 2;
    elem2.next = NULL;
    ll_push(head, &elem2);

    Nodo* elem3 = ll_nuovo_elem(3);
    ll_push(head, elem3);

    printf("La lista, dopo aver inserito due elementi: \n");
    ll_print(head);

    free(elem3);
    elem3 = NULL;
    return 0;
}

Nodo* ll_nuovo_elem(int val){
    Nodo* elem = malloc(sizeof(Nodo));
    elem->val = val;
    elem->next = NULL;
    return elem;
}

void ll_print(Nodo* head){
    // controllo che la lista non sia vuota
    if(head == NULL){
        printf("La lista e\' vuota.");
    }
    while(head != NULL){
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

void ll_push(Nodo* head, Nodo* elem){
    // scorro la lista fino all'ultimo elemento
    while(head->next != NULL){
        head = head->next;
    }
    
    // aggiungo il nuovo elemento in coda
    head->next = elem;
}
