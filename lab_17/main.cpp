#include <iostream>
#include <cstring>

struct node
{
    int field;
    node* next;
    node* prev;
};

void append(node** first, node** last, const int num)
{
    node* newNode = new node;
    newNode->next = NULL;
    newNode->prev = (*last);
    newNode->field = num;

    if (*first == NULL)
    {
        *first = newNode;
    }
    if (*last != NULL)
    {
        (*last)->next = newNode;
    }
    *last = newNode;
}

void printList(node* tmp)
{
    while (tmp != NULL)
    {
        std::cout << tmp->field << std::endl;
        tmp = tmp->next;
    }
    std::cout << std::endl;
}

void printReverseList(node* tmp)
{
    while (tmp != NULL)
    {
        std::cout << tmp->field << std::endl;
        tmp = tmp->prev;
    }
    std::cout << std::endl;
}

int main()
{
    node* first_1 = NULL;
    node* last_1 = NULL;
    node* first_2 = NULL;
    node* last_2 = NULL;

    char buffer[100];
    FILE* in = fopen("test.txt", "r");
    fgets(buffer, 100, in);
    
    char* p = strtok(buffer, " \0");
    while (p != NULL)
    {
        append (&first_1, &last_1, atoi(p));
        p = strtok(NULL, " \0");
    }
    std::cout << "Input List\n";
    printList(first_1);

    int num = 0;
    node* tmp = first_1;
    while (tmp->next != NULL)
    {
        num = tmp->next->field - tmp->field;
        append (&first_2, &last_2, num);
        tmp = tmp->next;
    }
    std::cout << "Output List\n";
    printList(first_2);

    int counter = 0;
    std::cout << "chisla kratnix 3\n";
    tmp = first_2;
    while (tmp != NULL)
    {
        if (tmp->field % 3 == 0) {
            std::cout << tmp->field << std::endl;
            counter++;
        }
        tmp = tmp->next;
    }
    std::cout << std::endl;

    if (!counter) {
        std::cout << "nums not found\n";
    }

    return 0;
}