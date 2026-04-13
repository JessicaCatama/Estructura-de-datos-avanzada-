#include <iostream>
#include <string>
using namespace std;

// Un registro: varios campos juntos
struct Student {
    int id;
    string name;
    string age;
    int phonenumber;

};

struct Node {
    Student data;
    Node* prev;
    Node* next;
};

// Insertar al inicio: el nodo guarda un Student completo
void pushFront(Node*& head, Student s) {
    Node* n = new Node{s, nullptr, head};

    if (head != nullptr) {
        head->prev = n;
    }

    head = n;
}

void pushBack(Node*& head, Student s) {
    Node* n = new Node{s, nullptr, nullptr};

    if (head == nullptr) {
        head = n;
        return;
    }

    Node* cur = head;
    while (cur->next != nullptr) {
        cur = cur->next;
    }

    cur->next = n;
    n->prev = cur;
}

void printForward(Node* head) {
    cout << "Adelante:\n";
    Node* cur = head;

    while (cur != nullptr) {
        cout << cur->data.id << " - " << cur->data.name << " - " << cur->data.age << " - " << cur->data.phonenumber << endl;
        cur = cur->next;
    }
}

Node* getTail(Node* head) {
    if (head == nullptr) return nullptr;

    Node* cur = head;
    while (cur->next != nullptr) {
        cur = cur->next;
    }
    return cur;
}

void printBackward(Node* head) {
    cout << "Atras:\n";
    Node* cur = getTail(head);

    while (cur != nullptr) {
        cout << cur->data.id << " - " << cur->data.name << " - " << cur->data.age << " - " << cur->data.phonenumber << endl;
        cur = cur->prev;
    }
}

void clear(Node*& head) {
    while (head != nullptr) {
        Node* tmp = head;
        head = head->next;
        delete tmp;
    }
}

int main() {
    Node* head = nullptr;

    pushFront(head, {101, "Ana", "12 años", 32032542});
    pushFront(head, {102, "Luis", "15 años", 32032542});
    pushFront(head, {103, "Laura", "15 años", 32032542});
    pushFront(head, {104, "Andrés", "17 años", 310564641});
    pushFront(head, {104, "Alejandro", "20 años", 301164646});
    pushBack(head, {105, "Jessica", "16 años", 2116411});

    printForward(head);
    printBackward(head);

    clear(head);
    return 0;
}