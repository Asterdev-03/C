#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 3

int mutex = 1, full = 0, empty = MAX_SIZE, buff[50], item = 1, front = -1, rear = -1;

int wait(int s) {
	while( s <= 0);
	return --s;
}

int signal(int s) {
	return ++s;
}

void producer() {
	mutex = wait(mutex);
	empty = wait(empty);
	
	if(front == -1 && rear == -1) {
		front = 0;
		buff[++rear] = item;
	} else {
		rear = (rear + 1) % MAX_SIZE;
		buff[rear] = item;
	}
	printf("%d added to Buffer", buff[rear]);
	item++;
	
	full = signal(full);
	mutex = signal(mutex);
}

void consumer() {
	mutex = wait(mutex);
	full = wait(full);
	
	printf("%d removed to Buffer", buff[front]);
	if (front == rear) {
        front = -1;
        rear = -1;
    } else {
		front = (front + 1) % MAX_SIZE;
	}
	
	empty = signal(empty);
	mutex = signal(mutex);
}

int main() {
	while(1) {
		printf("\n1.Producer 2. Consumer 3.Exit");
		printf("\nYour choice: ");
		int choice;
		scanf("%d", &choice);
		
		switch(choice) {
			case 1:
				if(mutex == 1 && empty != 0)
					producer();
				else printf("Buffer Full");
				break;
			case 2:
				if(mutex == 1 && full != 0)
					consumer();
				else printf("Buffer Empty");
				break;
			case 3:
				exit(0);

		}
	}
	return 0;
}
