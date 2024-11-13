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

    // ��������� �������� �� ������
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

    // ��������� ������� �������� �������� 5
    void removeFirstMultipleOfFive() {
        Node* temp = head;
        while (temp) {
            if (temp->data % 5 == 0) {
                if (temp->prev) {
                    temp->prev->next = temp->next;
                }
                else {
                    head = temp->next; // ���� ��������� ������ �������
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

    // ������� ����� 44 ����� ������ ������ ������� 7
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
                    head = newNode; // ���� ���������� ����� ������ ���������
                }
                temp->prev = newNode;
            }
            temp = temp->next;
        }
    }

    // ���� �������� ������
    void print() {
        Node* temp = head;
        while (temp) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    // ���������� ��� �������� ���'��
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

    // ������ �������� �� ������
    for (int value : arr) {
        list.append(value);
    }

    std::cout << "List: ";
    list.print();

    // ��������� ������� �������� �������� 5
    list.removeFirstMultipleOfFive();
    std::cout << "List after delete nunmbers that divide by 5: ";
    list.print();

    // ������� 44 ����� ������ ������ ������� 7
    list.insertBeforeMultiplesOfSeven();
    std::cout << "List after put 44 before 7: ";
    list.print();

    return 0;
}
