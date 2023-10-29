#include <stdio.h>
#include <stdlib.h>

// Definir un struct para los nodos
struct Node {
    int data;
    struct Node* next;
};

// Funcion para crear un nodo
struct Node* crearNodo(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Funcion para añadir un nodo al final de la lista
void agregarNodoFinal(struct Node** head, int data) {
    struct Node* newNode = crearNodo(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

// Funcion para añadir un nodo al principio de la lista
void agregarNodoInicio(struct Node** head, int data) {
    struct Node* newNode = crearNodo(data);
    newNode->next = *head;
    *head = newNode;
}

// Funcion para eliminar un nodo por valor
void eliminarNodo(struct Node** head, int key) {
    struct Node* current = *head;
    struct Node* prev = NULL;
    if (current != NULL && current->data == key) {
        *head = current->next;
        free(current);
        return;
    }
    while (current != NULL && current->data != key) {
        prev = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("Nodo con el valor  %d no fue encontrado\n", key);
        return;
    }
    prev->next = current->next;
    free(current);
}

// Funcion para buscar un nodo por valor
void buscarNodo(struct Node* head, int key) {
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == key) {
            printf("El nodo con el valor %d fue encontrado\n", key);
            return;
        }
        current = current->next;
    }
    printf("Nodo con el valor %d no fue encontrado\n", key);
}

// Funcion para mostrar la lista
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Funcion para buscar el elemento enesimo 
void elementoenesimo(struct Node* head, int index) {
    int count = 0;
    struct Node* current = head;
    while (current != NULL) {
        if (count == index) {
            printf("Indice del elemento %d: %d\n", index, current->data);
            return;
        }
        count++;
        current = current->next;
    }
    printf("El elemento con el indice %d no fue encotrado\n", index);
}

// Funcion para liberar memoria 
void freeList(struct Node* head){
    struct Node* current = head;
    struct Node* next;

    while(current != NULL){
        next = current->next;
	free(current);
        current = next;
    }
}


int main() {
    struct Node* head = NULL;
    int valor;
    int indice;
    printf("Se agregan distintos valores a la lista\n");
    agregarNodoFinal(&head, 1);
    agregarNodoFinal(&head, 2);
    agregarNodoFinal(&head, 3);
    agregarNodoInicio(&head, 0);

    printf("Lista enlazada: ");
    printList(head);

    printf("Ingrese un valor a buscar en la lista:");
    scanf("%d",&valor);
    buscarNodo(head, valor);
    

    printf("Ingrese un valor para eliminarlo en la lista:");
    scanf("%d",&valor);
    eliminarNodo(&head, valor);
    printf("Lista enlazada actualizada: ");
    printList(head);


    printf("Ingrese un indice a buscar en la lista:");
    scanf("%d",&indice);
    elementoenesimo(head, indice);
    freeList(head);
    return 0;
}

