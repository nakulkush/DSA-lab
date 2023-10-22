#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* createNode(int data) {
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = ptr; // Points to itself initially
    return ptr;
}

void traversal(struct node* head) {
    if (head == NULL) {
        printf("List is empty\n");
    } else {
        struct node* current = head;
        do {
            printf("Element: %d\n", current->data);
            current = current->next;
        } while (current != head);
    }
}

struct node* insert(struct node* head, int data) {
    struct node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
    } else {
        struct node* last = head;
        while (last->next != head) {
            last = last->next;
        }
        last->next = newNode;
        newNode->next = head;
    }
    return head;
}

struct node* deleteNode(struct node* head, int key) {
    if (head == NULL) {
        printf("List is empty\n");
        return head;
    }

    struct node* current = head;
    struct node* prev = NULL;

    while (current->data != key) {
        if (current->next == head) {
            printf("Element %d not found in the list\n", key);
            return head;
        }
        prev = current;
        current = current->next;
    }

    if (current == head && current->next == head) {
        free(current);
        head = NULL;
    } else if (current == head) {
        struct node* last = head;
        while (last->next != head) {
            last = last->next;
        }
        head = head->next;
        last->next = head;
        free(current);
    } else {
        prev->next = current->next;
        free(current);
    }

    printf("Element %d deleted from the list\n", key);
    return head;
}

struct node* reverse(struct node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return head;
    }

    struct node* prev = NULL;
    struct node* current = head;
    struct node* next = NULL;

    do {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    } while (current != head);

    head->next = prev;
    head = prev;

    return head;
}

struct node* concatenate(struct node* head1, struct node* head2) {
    if (head1 == NULL) {
        return head2;
    }
    if (head2 == NULL) {
        return head1;
    }

    struct node* last1 = head1;
    while (last1->next != head1) {
        last1 = last1->next;
    }

    struct node* last2 = head2;
    while (last2->next != head2) {
        last2 = last2->next;
    }

    last1->next = head2;
    last2->next = head1;

    return head1;
}

int main() {
    struct node* head = NULL;
    int choice, data, key;

    while (1) {
        printf("\nCircular Linked List Menu:\n");
        printf("1. Create\n");
        printf("2. Insert\n");
        printf("3. Delete\n");
        printf("4. Reverse\n");
        printf("5. Concatenate\n");
        printf("6. Display\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data for the first node: ");
                scanf("%d", &data);
                head = createNode(data);
                break;
            case 2:
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                head = insert(head, data);
                break;
            case 3:
                printf("Enter the data to delete: ");
                scanf("%d", &key);
                head = deleteNode(head, key);
                break;
            case 4:
                head = reverse(head);
                printf("List reversed\n");
                break;
            case 5:
                printf("Creating a new list for concatenation...\n");
                struct node* head2 = NULL;
                int data2;
                printf("Enter the data for the first node in the second list: ");
                scanf("%d", &data2);
                head2 = createNode(data2);
                head = concatenate(head, head2);
                break;
            case 6:
                printf("Circular Linked List elements:\n");
                traversal(head);
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice. Please select a valid option.\n");
        }
    }

    return 0;
}
