#include <iostream>

struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
public:
    Node* head;

    DoublyLinkedList() : head(nullptr) {}

    // Додавання елементів до списку
    void append(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }

    // Видалення першого елемента кратного 5
    void removeFirstMultipleOfFive() {
        Node* temp = head;
        while (temp) {
            if (temp->data % 5 == 0) {
                if (temp->prev) {
                    temp->prev->next = temp->next;
                }
                else {
                    head = temp->next; // Якщо видаляємо перший елемент
                }
                if (temp->next) {
                    temp->next->prev = temp->prev;
                }
                delete temp;
                return;
            }
            temp = temp->next;
        }
    }

    // Вставка числа 44 перед кожним числом кратним 7
    void insertBeforeMultiplesOfSeven() {
        Node* temp = head;
        while (temp) {
            if (temp->data % 7 == 0) {
                Node* newNode = new Node(44);
                newNode->next = temp;
                newNode->prev = temp->prev;
                if (temp->prev) {
                    temp->prev->next = newNode;
                }
                else {
                    head = newNode; // Якщо вставляємо перед першим елементом
                }
                temp->prev = newNode;
            }
            temp = temp->next;
        }
    }

    // Вивід елементів списку
    void print() {
        Node* temp = head;
        while (temp) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    // Деструктор для очищення пам'яті
    ~DoublyLinkedList() {
        Node* temp = head;
        while (temp) {
            Node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
    }
};

int main() {
    DoublyLinkedList list;
    int arr[] = { 10, 22, 35, 44, 57, 70, 85 };

    // Додаємо елементи до списку
    for (int value : arr) {
        list.append(value);
    }

    std::cout << "List: ";
    list.print();

    // Вилучення першого елемента кратного 5
    list.removeFirstMultipleOfFive();
    std::cout << "List after delete nunmbers that divide by 5: ";
    list.print();

    // Вставка 44 перед кожним числом кратним 7
    list.insertBeforeMultiplesOfSeven();
    std::cout << "List after put 44 before 7: ";
    list.print();

    return 0;
}
