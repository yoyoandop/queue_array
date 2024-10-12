#include <iostream>
using namespace std;

class Queue {
private:
    int* arr;        // �ʺA�}�C���x�s queue ������
    int front;       // ���V queue �e�ݪ�����
    int rear;        // ���V queue ��ݪ�����
    int capacity;    // queue ���̤j�e�q
    int size;        // ��e queue ���j�p

public:
    // �غc�l
    Queue(int capacity) {
        this->capacity = capacity;
        arr = new int[capacity];  // �t�m�}�C�Ŷ�
        front = 0;
        rear = -1;
        size = 0;
    }

    // �Ѻc�l�A����O����
    ~Queue() {
        delete[] arr;
    }

    // �ˬd queue �O�_�w��
    bool isFull() const {
        return size == capacity;
    }

    // �ˬd queue �O�_����
    bool isEmpty() const {
        return size == 0;
    }

    // �N�����K�[�� queue ���
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue." << endl;
            return;
        }
        rear = (rear + 1) % capacity;  // �����޿�
        arr[rear] = value;
        size++;
    }

    // �q queue �e�ݲ�������
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return -1; // �^��-1��ܥ���
        }
        int value = arr[front];
        front = (front + 1) % capacity;  // �����޿�
        size--;
        return value;
    }

    // ���o queue �e�ݪ�����
    int peek() const {
        if (isEmpty()) {
            cout << "Queue is empty. Nothing to peek." << endl;
            return -1;
        }
        return arr[front];
    }

    // ���o��e queue ���j�p
    int getSize() const {
        return size;
    }
};

int main() {
    Queue q(5); // �إߤ@�Ӯe�q��5�� queue

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    cout << "Front element: " << q.peek() << endl;
    cout << "Dequeue element: " << q.dequeue() << endl;
    cout << "Front element after dequeue: " << q.peek() << endl;

    q.enqueue(60); // �A���[�J�����A�]���O������

    while (!q.isEmpty()) {
        cout << "Dequeue element: " << q.dequeue() << endl;
    }

    return 0;
}
