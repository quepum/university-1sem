#pragma one

typedef struct Element {
    int value;
    struct Element* next;
} Element;

//function that adds a new element to the stack
Element* push(Element* head, int value);

//function that removes the first element of the stack
Element* pop(Element* head);

//function that returns the value of the first element in the stack
int peek(Element* head);

//function that outputs the current contents of the stack
void show(Element* head);

//function that counts the stack size
int sizeStack(Element * head);