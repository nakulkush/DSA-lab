#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* createNode(int data) {
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    ptr->next = NULL;
    ptr->data = data;
    return ptr;
}

void traversal(struct node* ptr) {
    if (ptr == NULL) {
        printf("List is empty\n");
    } else {
        while (ptr != NULL) {
            printf("Element: %d\n", ptr->data);
            ptr = ptr->next;
        }
    }
}

struct node* insertB(struct node* head, int data) {
    struct node* ptr = createNode(data);
    ptr->next = head;
    head = ptr;
    return head;
}

struct node* insertI(struct node* head, int pos, int data) {
    if (pos == 1) {
        struct node* ptr = createNode(data);
        ptr->next = head;
        head = ptr;
        return head;
    } else {
        int i = 1;
        struct node* ptr = createNode(data);
        struct node* p = head;
        while (i != pos - 1) {
            p = p->next;
            i++;
        }
        ptr->next = p->next;
        p->next = ptr;
        return head;
    }
}

struct node* insertE(struct node* head, int data) {
    struct node* ptr = createNode(data);
    struct node* p = head;
    while (p->next != NULL) {
        p = p->next;
    }
    ptr->next = NULL;
    p->next = ptr;
    return head;
}

struct node* deleteB(struct node* head) {
    struct node* ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

struct node* deleteI(struct node* head, int position) {
    if (position == 1) {
        struct node* ptr = head;
        head = head->next;
        free(ptr);
        return head;
    } else {
        struct node* p = head;
        struct node* q = head->next;
        int i = 0;
        while (i != position - 2) {
            q = q->next;
            p = p->next;
            i++;
        }
        p->next = q->next;
        free(q);
        return head;
    }
}

struct node* deleteE(struct node* head) {
    struct node* p = head;
    struct node* q = head->next;
    while (q->next != NULL) {
        q = q->next;
        p = p->next;
    }
    p->next = NULL;
    free(q);
    return head;
}

struct node* concatenate(struct node* head1, struct node* head2) {
    if (head1 == NULL) {
        return head2;
    }
    struct node* temp = head1;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = head2;
    return head1;
}

struct node* reverse(struct node* head) {
    struct node* prev = NULL;
    struct node* current = head;
    struct node* next;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}

int main() {
    struct node* head = NULL;
    struct node* head2 = NULL;
    int choice, data, position;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at the beginning\n");
        printf("2. Insert at a specific position\n");
        printf("3. Insert at the end\n");
        printf("4. Delete at the beginning\n");
        printf("5. Delete at a specific position\n");
        printf("6. Delete at the end\n");
        printf("7. Concatenate two lists\n");
        printf("8. Reverse the list\n");
        printf("9. Display the list\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert at the beginning: ");
                scanf("%d", &data);
                head = insertB(head, data);
                break;
            case 2:
                printf("Enter the value to insert: ");
                scanf("%d", &data);
                printf("Enter the position to insert: ");
                scanf("%d", &position);
                head = insertI(head, position, data);
                break;
            case 3:
                printf("Enter the value to insert at the end: ");
                scanf("%d", &data);
                head = insertE(head, data);
                break;
            case 4:
                head = deleteB(head);
                break;
            case 5:
                printf("Enter the position to delete: ");
                scanf("%d", &position);
                head = deleteI(head, position);
                break;
            case 6:
                head = deleteE(head);
                break;
            case 7:
                printf("Creating a new list for concatenation...\n");
                struct node* head2 = createNode(25);
                struct node* second2 = createNode(32);
                struct node* third2 = createNode(45);
                head2->next = second2;
                second2->next = third2;
                third2->next = NULL;
                head = concatenate(head, head2);
                break;
            case 8:
                head = reverse(head);
                break;
            case 9:
                printf("List elements:\n");
                traversal(head);
                break;
            case 10:
                exit(0);
            default:
                printf("Invalid choice. Please select a valid option.\n");
        }
    }

    return 0;
}
