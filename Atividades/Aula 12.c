#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* prev;
    struct node* next;
} Node;

Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;
    return new_node;
}

void insert_node(Node** head, int data) {
    Node* new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;
    } else {
        Node* current = *head;
        while (current->next != NULL) {
            if (current->data == data) {
                printf("Erro: Elemento já existe na lista.\n");
                free(new_node);
                return;
            }
            current = current->next;
        }
        if (current->data == data) {
            printf("Erro: Elemento já existe na lista.\n");
            free(new_node);
            return;
        }
        current->next = new_node;
        new_node->prev = current;
    }
}

void remove_node(Node** head, int data) {
    if (*head == NULL) {
        printf("Erro: Lista vazia.\n");
    } else {
        Node* current = *head;
        while (current != NULL) {
            if (current->data == data) {
                if (current->prev == NULL) {
                    *head = current->next;
                } else {
                    current->prev->next = current->next;
                }
                if (current->next != NULL) {
                    current->next->prev = current->prev;
                }
                free(current);
                return;
            }
            current = current->next;
        }
        printf("Erro: Elemento não encontrado na lista.\n");
    }
}

int count_even_nodes(Node* head) {
    int count = 0;
    Node* current = head;
    while (current != NULL) {
        if (current->data % 2 == 0) {
            count++;
        }
        current = current->next;
    }
    return count;
}

Node* concatenate_lists(Node* list1, Node* list2) {
    if (list1 == NULL) {
        return list2;
    } else if (list2 == NULL) {
        return list1;
    } else {
        Node* current = list1;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = list2;
        list2->prev = current;
        return list1;
    }
}

void print_list(Node* head) {
    if (head == NULL) {
        printf("Lista vazia.\n");
    } else {
        Node* current = head;
        printf("Lista: ");
        while (current != NULL) {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}

void free_list(Node* head) {
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    Node* lista = NULL; // Criando lista vazia

    int numero;
    printf("Insira os números na lista (-1 para encerrar): ");
    scanf("%d", &numero);

    while(numero != -1) { // Loop para inserir os números na lista
        insert_node(&lista, numero);
        scanf("%d", &numero);
    }

    printf("Lista:\n");
    print_list(lista);

    // Restante do código

    free_list(lista); // Liberando memória alocada
    return 0;
}

