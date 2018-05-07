# Basic data structures in C

## Linked lists

The idea is simple, we can have a struct containing data and a pointer to the next element if it exists.

![pointer structure](images/linked01.png)

We can declare a simple C structure for this, let's imagine it is designed to hold integers:

```c
typedef struct node {
    int num;
    struct node *next;
} Node, *NodePtr;
```

Because C doesn't have constructors for structs, we can create a helper function `makeNode` to do so, passing the element we want to put in the list:

```c
#include <stdlib.h>

NodePtr makeNode(int num) {
    NodePtr node = (Node *)malloc(sizeof(Node));
    node->num = num;
    node->next = NULL;
    return node;
}
```

We can declare a list similar to the illustration like this:

```c
NodePtr node = makeNode(12);
node->next = makeNode(99);
node->next->next = makeNode(37);
```

### Counting elements

To get the total elements in a linked list, it will be matter of just loop through all of them until we reach an element with next is `NULL`

```c
int length(NodePtr node) {
    if (node == NULL) { return 0; }
    int count = 1;
    while (node->next != NULL) {
        node = node->next;
        count++;
    }
    return count;
}
```

### Searching an element

This is a boring one, in the same way as counting it, we loop through it until we find the element.

```c
NodePtr search(NodePtr top, const int num) {
    NodePtr node = top; // We actually can reuse top
    while (node != NULL) {
        if (node->num == num) { return node; }
        node = node->next;
    }
    return NULL;
}
```

### Finding the last element

As the previous operation, this is matter of looping through the structure until there is no next.

```c
NodePtr last(NodePtr top) {
    while (top != NULL) {
        if (top->next == NULL) { return top; }
        top = top->next;
    }
    return NULL;
}
```

### Removing element at index

This is a little more difficult, what you basically do is finding the index of the element - 1 and the element at that index, we just change the `next` from prev to next.

```c
#include <stdbool.h>

bool remove_at(NodePtr *top, const int index) {
    if (index < 0 || top == NULL || *top == NULL) {
        return false;
    }
    
    NodePtr node = *top;
    if (index == 0) {
        *top = node->next;
    } else {
        NodePtr prev;
        for (int n = 0; n < index; n++) {
            if (node == NULL) { return false; }
            if (n == index - 1) { prev = node; }
            
            node = node->next;
        }
        prev->next = node->next;
    }
    
    free(node);
    return true;
}
```

Here, we need to pass a pointer to our top pointer, why? because there is the possibility we will have to change it. The first case is for our guard clauses, when the index is negative or the pointer is NULL we have nothing to do, so we return just `false` to indicate we did nothing.

The first interesting case is when we remove the node at the beginning of the list, in this case _we have to change_ the pointer (hence the usage of a pointer to the pointer). In this case it is easy, we just point the top to the next element, done.

The second case, the _normal_ or more common case, we need to grab not only the element we want to remove, but the element _before_ it, of course, this covers as well the case when the index is beyond the last element of our linked list.

### Inserting element at index

Similar to remove element at certain index, we need to find the previous item to the index, so the loop is until `index - 1`.

```c
bool insert_at(NodePtr *top, const int index, int value) {
    if (index < 0 || top == NULL || *top == NULL) { return false; }
    
    NodePtr node = makeNode(value);
    if (index == 0) {
        node->next = *top;
        *top = node;
    } else {
        NodePtr prev = *top;
    	for (int i = 0; i < index - 1; i++) {
        	if (prev == NULL) { return false; }
            prev = prev->next;
    	}
        node->next = prev->next;
        prev->next = node;
    }
    return true;
}
```

