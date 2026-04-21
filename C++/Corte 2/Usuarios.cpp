#include <iostream>
#include <string>

using namespace std;

struct Usuarios {
    string nombre;
    int edad;
    string turno;
};

struct Node {
    Usuarios data;
    string novedad;
    Node* next;
};

struct Queue {
    Node* front;
    Node* rear;
};

struct Stack {
    Node* top;
};

void createQueue(Queue &q) {
    q.front = NULL;
    q.rear = NULL;
}

void enqueue(Queue &q, Usuarios u) {
    Node* n = new Node;
    n->data = u;
    n->next = NULL;

    if (q.front == NULL) {
        q.front = n;
        q.rear = n;
    } else {
        q.rear->next = n;
        q.rear = n;
    }
}

bool dequeue(Queue &q, Usuarios &u) {
    if (q.front == NULL) return false;

    Node* tmp = q.front;
    u = tmp->data;
    q.front = q.front->next;

    if (q.front == NULL) q.rear = NULL;

    delete tmp;
    return true;
}

void printQueue(Queue q) {
    Node* aux = q.front;
    while (aux != NULL) {
        cout << aux->data.nombre << " [" << aux->data.turno << "]" << endl;
        aux = aux->next;
    }
}

void createStack(Stack &s) {
    s.top = NULL;
}

void push(Stack &s, string value) {
    Node* n = new Node;
    n->novedad = value;
    n->next = s.top;
    s.top = n;
}

bool pop(Stack &s, string &removed) {
    if (s.top == NULL) return false;

    Node* tmp = s.top;
    removed = tmp->novedad;
    s.top = s.top->next;

    delete tmp;
    return true;
}

void printStack(Stack s) {
    Node* aux = s.top;
    while (aux != NULL) {
        cout << aux->novedad << endl;
        aux = aux->next;
    }
}

string Turnos(char letra, int num) {
    string t = "";
    t += letra;

    if (num < 10) t += "0";

    int d = num / 10;
    int u = num % 10;

    if (d > 0) t += char(d + '0');
    t += char(u + '0');

    return t;
}

int main() {
    Queue cola1, cola2;
    Stack novedades;

    createQueue(cola1);
    createQueue(cola2);
    createStack(novedades);

    int A = 1, D = 1;
    int opcion = 0;

    while (opcion != 8) {
        cout << "1. Atender una persona de la cola de 0 a 59 años" << endl;
        cout << "2. Atender una persona de la cola de 60 a 120 años" << endl;
        cout << "3. Imprimir las colas pendientes por atender: " << endl;
        cout << "4. Registrar un nuevo usuario y asignarle turno según su edad" << endl;
        cout << "5. Registrar una nueva novedad en la pila" << endl;
        cout << "6. Atender una novedad de la pila" << endl;
        cout << "7. Imprimir las novedades pendientes" << endl;
        cout << "8. Salir" << endl;
        
        cin >> opcion;
       
    switch (opcion) {

        case 1: {
            Usuarios u;
            if (dequeue(cola1, u))
                cout << "Atendido/a: " << u.nombre << " [" << u.turno << "]\n";
            else
                cout << "Está vacía\n";
            break;
        }

        case 2: {
            Usuarios u;
            if (dequeue(cola2, u))
                cout << "Atendido/a: " << u.nombre << " [" << u.turno << "]\n";
            else
                cout << "Está vacía\n";
            break;
        }

        case 3: {
            cout << "\nCola de 0 a 59:\n";
            printQueue(cola1);
            cout << "\nCola de 60 a 120:\n";
            printQueue(cola2);
            break;
        }

        case 4: {
            Usuarios u;
            cout << "Nombre: ";
            cin >> u.nombre;
            cout << "Edad: ";
            cin >> u.edad;

            if (u.edad >= 0 && u.edad <= 59) {
                u.turno = Turnos('A', A++);
                enqueue(cola1, u);
            } else if (u.edad >= 60 && u.edad <= 120) {
                u.turno = Turnos('D', D++);
                enqueue(cola2, u);
            } else {
                cout << "Edad inválida\n";
            }
            break;
        }

        case 5: {
            string nov;
            cout << "Novedad: ";
            cin >> nov;
            push(novedades, nov);
            break;
        }

        case 6: {
            string nov;
            if (pop(novedades, nov))
                cout << "Atendido/a: " << nov << endl;
            else
                cout << "No hay novedades\n";
            break;
        }

        case 7: {
            cout << "\nNovedades:\n";
            printStack(novedades);
            break;
        }

        case 8:
            cout << "Fuera del sistema\n";
            break;

        default:
            cout << "Opción inválida\n";
        }
    }

    return 0;
}