#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int value) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        return newNode(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}

void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void breadthFirstSearch(struct Node* root) {
    if (root == NULL)
        return;

    // Create a queue for BFS
    struct Node* queue[100]; // Assuming a maximum of 100 nodes in the tree
    int front = 0, rear = 0;

    // Enqueue the root node
    queue[rear++] = root;

    while (front < rear) {
        // Dequeue a node and print its data
        struct Node* currentNode = queue[front++];
        printf("%d ", currentNode->data);

        // Enqueue the left child if it exists
        if (currentNode->left)
            queue[rear++] = currentNode->left;

        // Enqueue the right child if it exists
        if (currentNode->right)
            queue[rear++] = currentNode->right;
    }
}

struct Node* search(struct Node* root, int target) {
    
    if (root == NULL || root->data == target) {
        return root;
    }

    
    if (target < root->data) {
        return search(root->left, target);
    }

    
    return search(root->right, target);
}

int main() {
    
    struct Node* root = NULL;
    int choice, value, target;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert a value\n");
        printf("2. Inorder traversal\n");
        printf("3. Breadth-First Search (Level Order Traversal)\n");
        printf("4. Search for a value\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;
            case 2:
                printf("Inorder traversal of the BST: ");
                inorder(root);
                printf("\n");
                break;
            case 3:
                printf("Breadth-First Search (Level Order Traversal): ");
                breadthFirstSearch(root);
                printf("\n");
                break;
            case 4:
                printf("Enter the value to search for: ");
                scanf("%d", &target);
                struct Node* result = search(root, target);
                if (result)
                    printf("Value %d found in the tree.\n", target);
                else
                    printf("Value %d not found in the tree.\n", target);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please select a valid option.\n");
        }
    }

    return 0;
}
