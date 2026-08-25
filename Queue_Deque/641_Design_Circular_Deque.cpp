// LeetCode 641
// Design Circular Deque

class MyCircularDeque {
public:
    vector<int> dq;
    int front, rear, size, capacity;

    MyCircularDeque(int k) {
        capacity = k;
        dq.resize(k);
        front = 0;
        rear = -1;
        size = 0;
    }
    
    bool insertFront(int value) {
        if (size == capacity)
            return false;

        front = (front - 1 + capacity) % capacity;
        dq[front] = value;
        size++;

        if (size == 1)
            rear = front;

        return true;
    }
    
    bool insertLast(int value) {
        if (size == capacity)
            return false;

        rear = (rear + 1) % capacity;
        dq[rear] = value;
        size++;

        if (size == 1)
            front = rear;

        return true;
    }
    
    bool deleteFront() {
        if (size == 0)
            return false;

        front = (front + 1) % capacity;
        size--;

        return true;
    }
    
    bool deleteLast() {
        if (size == 0)
            return false;

        rear = (rear - 1 + capacity) % capacity;
        size--;

        return true;
    }
    
    int getFront() {
        if (size == 0)
            return -1;

        return dq[front];
    }
    
    int getRear() {
        if (size == 0)
            return -1;

        return dq[rear];
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == capacity;
    }
};
