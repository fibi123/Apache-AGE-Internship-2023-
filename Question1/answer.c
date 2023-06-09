#include <stdio.h>
#include <stdlib.h>

typedef enum TypeTag {
    ADD,
    MUL,
    SUB,
    DIV
} TypeTag;

typedef struct Node {
    TypeTag type;
    int value;
    struct Node* left;
    struct Node* right;
} Node;

Node* makeFunc(TypeTag type, Node* left, Node* right) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->type = type;
    newNode->left = left;
    newNode->right = right;
    return newNode;
}

Node* makeNumber(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->type = -1; 
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int fibonacci(int n) {
    if (n <= 1)
        return n;

    int* fib = (int*)malloc((n + 1) * sizeof(int));
    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i <= n; i++)
        fib[i] = fib[i - 1] + fib[i - 2];

    int result = fib[n];
    free(fib);

    return result;
}

void calc(Node* node) {
    if (node->type == -1) { 
        printf("Number: %d\n", node->value);
    } else if (node->type == ADD) {
        calc(node->left);
        calc(node->right);
        node->value = node->left->value + node->right->value;
        printf("add: %d\n", node->value);
    } else if (node->type == MUL) {
        calc(node->left);
        calc(node->right);
        node->value = node->left->value * node->right->value;
        printf("mul: %d\n", node->value);
    } else if (node->type == SUB) {
        calc(node->left);
        calc(node->right);
        node->value = node->left->value - node->right->value;
        printf("sub: %d\n", node->value);
    } else if (node->type == DIV) {
        calc(node->left);
        calc(node->right);
        node->value = node->left->value / node->right->value;
        printf("div: %d\n", node->value);
    } else {
        calc(node->left);
        calc(node->right);
        node->value = fibonacci(node->value);
        printf("fibo: %d\n", node->value);
    }
}

int main() {
    Node* add = makeFunc(ADD, makeNumber(10), makeNumber(6));
    Node* mul = makeFunc(MUL, makeNumber(5), makeNumber(4));
    Node* sub = makeFunc(SUB, mul, add);
    Node* fibo = makeFunc(SUB, sub, NULL);
    printf("Output:\n");
    calc(add);
    calc(mul);
    calc(sub);
    calc(fibo);

    return 0;
}
