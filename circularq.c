#include <stdio.h>

int main() {
    int a[10];
    int i, m;
    int front = -1, rear = -1;
    int item, choice;

    printf("Enter the number of elements (max 10): ");
    scanf("%d", &m);
    if (m <= 0 || m > 10) {
        printf("Invalid size!\n");
        return 1;
    }

    printf("Enter the elements:\n");
    for (i = 0; i < m; i++) {
        scanf("%d", &a[i]);
    }

    if (m > 0) {
        front = 0;
        rear = m - 1;
    }

    while (1) {
        printf("\nMenu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            if ((rear + 1) % 10 == front) {
                printf("Queue is full. Cannot enqueue.\n");
            }
            if (!((rear + 1) % 10 == front)) {
                printf("Enter item to enqueue: ");
                scanf("%d", &item);
                rear = (rear + 1) % 10;
                a[rear] = item;
                if (front == -1) {
                    front = 0;
                }
                printf("Item enqueued: %d\n", item);
            }
        }

        if (choice == 2) {
            if (front == -1) {
                printf("Queue is empty. Cannot dequeue.\n");
            }
            if (!(front == -1)) {
                item = a[front];
                printf("Item dequeued: %d\n", item);
                if (front == rear) {
                    front = rear = -1;
                } else {
                    front = (front + 1) % 10;
                }
            }
        }

        if (choice == 3) {
            if (front == -1) {
                printf("Queue is empty.\n");
            }
            if (!(front == -1)) {
                printf("Queue elements: ");
                i = front;
                while (1) {
                    printf("%d ", a[i]);
                    if (i == rear)
                        break;
                    i = (i + 1) % 10;
                }
                printf("\n");
            }
        }

        if (choice == 4) {
            printf("Exiting program.\n");
            break;
        }

        if (choice < 1 || choice > 4) {
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}

