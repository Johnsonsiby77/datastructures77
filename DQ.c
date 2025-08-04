#include <stdio.h>
#define MAX 100

int deque[MAX];
int front = -1, rear = -1;

int isEmpty() {
    return front == -1;
}

int isFull() {
    return (front == 0 && rear == MAX - 1) || (front == rear + 1);
}

void insertFront(int val) {
    if (isFull()) {
        printf("Deque full, can't insert %d at front\n", val);
        return;
    }
    if (isEmpty())
        front = rear = 0;
    else if (front == 0)
        front = MAX - 1;
    else
        front--;

    deque[front] = val;
    printf("Inserted %d at front\n", val);
}

void insertRear(int val) {
    if (isFull()) {
        printf("Deque full, can't insert %d at rear\n", val);
        return;
    }
    if (isEmpty())
        front = rear = 0;
    else if (rear == MAX - 1)
        rear = 0;
    else
        rear++;

    deque[rear] = val;
    printf("Inserted %d at rear\n", val);
}

int deleteFront() {
    if (isEmpty()) {
        printf("Deque empty, can't delete from front\n");
        return -1;
    }
    int val = deque[front];
    if (front == rear)
        front = rear = -1;
    else if (front == MAX - 1)
        front = 0;
    else
        front++;

    printf("Deleted %d from front\n", val);
    return val;
}

int deleteRear() {
    if (isEmpty()) {
        printf("Deque empty, can't delete from rear\n");
        return -1;
    }
    int val = deque[rear];
    if (front == rear)
        front = rear = -1;
    else if (rear == 0)
        rear = MAX - 1;
    else
        rear--;

    printf("Deleted %d from rear\n", val);
    return val;
}

void displayDeque() {
    if (isEmpty()) {
        printf("Deque is empty\n");
        return;
    }
    printf("Deque: ");
    int i = front;
    while (1) {
        printf("%d ", deque[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    int choice, val;

    while (1) {
        printf("\nChoose operation:\n");
        printf("1.  Front Insertion \n2. Rear Insertion \n3. Front Deletion \n4. Rear Deletion \n5. Display DQ\n6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at front: ");
                scanf("%d", &val);
                insertFront(val);
                break;
            case 2:
                printf("Enter value to insert at rear: ");
                scanf("%d", &val);
                insertRear(val);
                break;
            case 3:
                deleteFront();
                break;
            case 4:
                deleteRear();
                break;
            case 5:
                displayDeque();
                break;
            case 6:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}

