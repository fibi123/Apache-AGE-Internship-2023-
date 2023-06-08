#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    enum TypeTag {
        ADD,
        MUL,
        SUB,
        FIBO
    } type;

    int value;
    struct Node* left;
    struct Node* right;
} Node;

Node* makeNode(enum TypeTag type) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->type = type;
    newNode->value = 0;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* makeNumberNode(int value) {
    Node* newNode = makeNode(FIBO);
    newNode->value = value;
    return newNode;
}

Node* makeFNode(enum TypeTag type, Node* left, Node* right) {
    Node* newNode = makeNode(type);
    newNode->left = left;
    newNode->right = right;
    return newNode;
}

int fibonacci(int n) {
    int fib[n + 1];
    fib[0] = 0;
    fib[1] = 1;
  
    for (int i = 2; i <= n; i++)
        fib[i] = fib[i - 1] + fib[i - 2];
  
    return fib[n];
}

void calc(Node* node) {
    if (node->type == FIBO) {
        node->value = fibonacci(node->value);
        printf("fibo: %d\n", node->value);
    } else {
        calc(node->left);
        calc(node->right);
        
        switch (node->type) {
            case ADD:
                node->value = node->left->value + node->right->value;
                printf("add: %d\n", node->value);
                break;
            case MUL:
                node->value = node->left->value * node->right->value;
                printf("mul: %d\n", node->value);
                break;
            case SUB:
                node->value = node->left->value - node->right->value;
                printf("sub: %d\n", node->value);
                break;
            default:
                break;
        }
    }
}

int main() {
    Node* add = makeFNode(ADD, makeNumberNode(10), makeNumberNode(6));
    Node* mul = makeFNode(MUL, makeNumberNode(5), makeNumberNode(4));
    Node* sub = makeFNode(SUB, mul, add);
    Node* fibo = makeFNode(SUB, sub, NULL);
    printf("Output");
    calc(add);
    calc(mul);
    calc(sub);
    calc(fibo);

    return 0;
}
