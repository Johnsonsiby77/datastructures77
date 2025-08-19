#include <stdio.h>

int main() {
    int array[10];
    int i, m;
    int rear = -1, front = -1;

    printf("Enter the number of elements (max 5): ");
    scanf("%d", &m);

    if (m < 0 || m > 5) {
        printf("Invalid number of elements!\n");
        return 1;
    }

    printf("Enter the elements of the array:\n");
    for (i = 0; i < m; i++) {
        scanf("%d", &array[i]);
    }

    if (m == 0) {
        front = -1;
        rear = -1;
    } 
    else {
        front = 0;
        rear = m - 1;
    }

    if (rear == 4) {
        printf("Overflow: Queue is full, cannot enqueue.\n");
    } 
    else {
        rear++;
        int item;
        printf("Enter the item to be added: ");
        scanf("%d", &item);
        array[rear] = item;

        printf("Queue after enqueue:\n");
        for (i = front; i <= rear; i++) {
            printf("%d ", array[i]);
        }
        printf("\n");
    }

    if (front == -1 || front > rear) {
        printf("Underflow: Queue is empty, cannot dequeue.\n");
    } 
    else {
        int item = array[front];
        printf("Deleted item is: %d\n", item);
        front++;
        if (front > rear) {
            front = -1;
            rear = -1;
        }

        if (front != -1) {
            printf("Queue after dequeue:\n");
            for (i = front; i <= rear; i++) {
                printf("%d ", array[i]);
            }
            printf("\n");
        } else {
            printf("Queue is now empty.\n");
        }
    }

    return 0;
}

