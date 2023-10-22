#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
    struct node* prev;

};

struct node* createNode(int data) {
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    ptr->data = data;
    ptr->next = NULL;
    ptr->prev = NULL;
    return ptr;
}

struct node* traversal(struct node*head){
    struct node* p = head;
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
    
    return head;
}

struct node* insertFirst(struct node* head, int data) {
    struct node* ptr = createNode(data);
    ptr->next = head;
    if (head != NULL) {
        head->prev = ptr;
    }
    return ptr;
}

struct node* insertLast(struct node*head,int data){
    struct node*ptr = createNode(data);
    struct node*p = head;
    while(p->next!=NULL){
        p = p->next;
    }
    ptr->prev = p;
    ptr->next = NULL;

    p->next = ptr;
    return head;
    
}

struct node* deleteFirst(struct node*head){

    if(head==NULL){
        printf("Empty List\n");
        return NULL;
    }

    struct node* p = head;
    struct node* q = head->next;
    if(q!=NULL){
        q->prev = NULL;

    }
    
    free(p);
    return q;

}

struct node* deleteLast(struct node* head) {
    if (head == NULL) {
        printf("empty list\n");
        return NULL;
    }

    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    struct node* p = head;
    
    while (p ->next!= NULL) {
        p = p->next;
    }
    struct node* q = p->next;

    free(q);
    p->next = NULL;

    return head;
}


struct node* bubbleSort(struct node* head) {
    if (head == NULL) {
        return NULL;
    }
    int swapped;
    struct node* ptr1;
    struct node* lptr = NULL;
    do {
        swapped = 0;
        ptr1 = head;
        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
    return head;
}

struct node* concatenateLists(struct node* head, struct node* head1) {
    if (head == NULL) {
        return head1;
    }
    if (head1 == NULL) {
        return head;
    }

    struct node* p = head;
    while (p->next != NULL) {
        p = p->next;
    }

    p->next = head1;
    head1->prev = p;

    return head;
}

// Function to perform union of two sorted lists
struct node* unionLists(struct node* head, struct node* head2) {
    struct node* result = NULL;
    struct node* last = NULL;

    while (head != NULL || head2 != NULL) {
        struct node* newNode = createNode(0); // Create a dummy node

        if (head != NULL && head2 != NULL) {
            if (head->data < head2->data) {
                newNode->data = head->data;
                head = head->next;
            } else if (head->data > head2->data) {
                newNode->data = head2->data;
                head2 = head2->next;
            } else {
                newNode->data = head->data;
                head = head->next;
                head2 = head2->next;
            }
        } else if (head != NULL) {
            newNode->data = head->data;
            head = head->next;
        } else if (head2 != NULL) {
            newNode->data = head2->data;
            head2 = head2->next;
        }

        if (result == NULL) {
            result = newNode;
        } else {
            last->next = newNode;
            newNode->prev = last;
        }

        last = newNode;
    }

    return result;
}


struct node* intersectLists(struct node* head, struct node* head2) {
    struct node* result = NULL;
    struct node* last = NULL;

    while (head != NULL && head2 != NULL) {
        if (head->data == head2->data) {
            struct node* newNode = createNode(head->data);
            if (result == NULL) {
                result = newNode;
            } else {
                last->next = newNode;
                newNode->prev = last;
            }
            last = newNode;

            head = head->next;
            head2 = head2->next;
        } else if (head->data < head2->data) {
            head = head->next;
        } else {
            head2 = head2->next;
        }
    }

    return result;
}





int main(){
    struct node* head = createNode(35);
    struct node* second = createNode(98);
    struct node* third = createNode(45);

    head->prev = NULL;
    head->next = second;

    second->prev = head;
    second->next = third;

    third->prev = second;
    third->next = NULL;
    
    
    printf("Traversal of linked list: ");
    head = traversal(head);

    printf("\nInsertion at first: ");
    head = insertFirst(head,56);
    head = traversal(head);




    struct node* head1 = createNode(48);
    struct node* second1 = createNode(45);
    struct node* third1 = createNode(65);

    head1->prev = NULL;
    head1->next = second1;

    second1->prev = head1;
    second1->next = third1;

    third1->prev = second1;
    third1->next = NULL;



    printf("\nInsetion at last: ");
    head = insertLast(head,150);
    head = traversal(head);

    printf("\nDeletion at first: ");
    head = deleteFirst(head);
    head = traversal(head);

    printf("\nDeletion at last: ");
    head = deleteLast(head);
    head = traversal(head);

    head=concatenateLists(head,head1);
    head=traversal(head);








    
}