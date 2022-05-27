#include <iostream>
#include <cstring>

struct node {
    char field [100];
    int key;
    node* left;
    node* right;
};

void insert (node** root, const char* word) {
    node* newNode = new node;
    //(*root)->field = new char [strlen(word)];
    strcpy(newNode->field, word);
    newNode->key = 1;
    newNode->left = NULL;
    newNode->right = NULL;

    if ((*root) != NULL)
    {
        if (strcmp ((*root)->field, newNode->field) > 0) {
            insert(&(*root)->left, word);
        }
        else if (strcmp ((*root)->field, newNode->field) < 0) {
            insert(&(*root)->right, word);
        } 
        else 
            (*root)->key++;
    } 
    else 
        (*root) = newNode;
}

void preorder (node* tmp, int level) {
    if (tmp == NULL) return;

    preorder (tmp->right, level + 5);
    for (int i = 0; i < level; i++)
        std::cout << " ";
    std::cout << tmp->field << std::endl;
    preorder (tmp->left, level + 5);
}

int main() {
    node* root = NULL;
    char buffer[100];
    gets (buffer);
    char* p = strtok (buffer, " \0");
    while (p != NULL) {
        insert(&root, p);
        p = strtok (NULL, " \0");
    }

    preorder(root, 0);

    return 0;
}