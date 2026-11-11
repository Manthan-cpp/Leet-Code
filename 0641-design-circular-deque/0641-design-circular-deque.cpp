class MyCircularDeque {
    int *arr;
    int size;
    int front, rear;

public:
    MyCircularDeque(int k) {
        size = k;
        arr = new int[size];
        front = rear = -1;
    }

    bool insertFront(int value) {
        if (isFull()) return false;

        if (front == -1) {
            front = rear = 0;
        }
        else if (front == 0) {
            front = size - 1;
        }
        else {
            front--;
        }

        arr[front] = value;
        return true;
    }

    bool insertLast(int value) {
        if (isFull()) return false;

        if (rear == -1) {
            front = rear = 0;
        }
        else if (rear == size - 1) {
            rear = 0;
        }
        else {
            rear++;
        }

        arr[rear] = value;
        return true;
    }

    bool deleteFront() {
        if (isEmpty()) return false;

        if (front == rear) {
            front = rear = -1;
        }
        else if (front == size - 1) {
            front = 0;
        }
        else {
            front++;
        }

        return true;
    }

    bool deleteLast() {
        if (isEmpty()) return false;

        if (front == rear) {
            front = rear = -1;
        }
        else if (rear == 0) {
            rear = size - 1;
        }
        else {
            rear--;
        }

        return true;
    }

    int getFront() {
        if (isEmpty()) return -1;
        return arr[front];
    }

    int getRear() {
        if (isEmpty()) return -1;
        return arr[rear];
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return (rear + 1) % size == front;
    }
};