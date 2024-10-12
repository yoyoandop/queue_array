#include <iostream>
using namespace std;

class Queue {
private:
    int* arr;        // 動態陣列來儲存 queue 的元素
    int front;       // 指向 queue 前端的索引
    int rear;        // 指向 queue 後端的索引
    int capacity;    // queue 的最大容量
    int size;        // 當前 queue 的大小

public:
    // 建構子
    Queue(int capacity) {
        this->capacity = capacity;
        arr = new int[capacity];  // 配置陣列空間
        front = 0;
        rear = -1;
        size = 0;
    }

    // 解構子，釋放記憶體
    ~Queue() {
        delete[] arr;
    }

    // 檢查 queue 是否已滿
    bool isFull() const {
        return size == capacity;
    }

    // 檢查 queue 是否為空
    bool isEmpty() const {
        return size == 0;
    }

    // 將元素添加到 queue 後端
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue." << endl;
            return;
        }
        rear = (rear + 1) % capacity;  // 環狀邏輯
        arr[rear] = value;
        size++;
    }

    // 從 queue 前端移除元素
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return -1; // 回傳-1表示失敗
        }
        int value = arr[front];
        front = (front + 1) % capacity;  // 環狀邏輯
        size--;
        return value;
    }

    // 取得 queue 前端的元素
    int peek() const {
        if (isEmpty()) {
            cout << "Queue is empty. Nothing to peek." << endl;
            return -1;
        }
        return arr[front];
    }

    // 取得當前 queue 的大小
    int getSize() const {
        return size;
    }
};

int main() {
    Queue q(5); // 建立一個容量為5的 queue

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    cout << "Front element: " << q.peek() << endl;
    cout << "Dequeue element: " << q.dequeue() << endl;
    cout << "Front element after dequeue: " << q.peek() << endl;

    q.enqueue(60); // 再次加入元素，因為是環狀的

    while (!q.isEmpty()) {
        cout << "Dequeue element: " << q.dequeue() << endl;
    }

    return 0;
}
