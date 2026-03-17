public class Estudiantes {
    // Registro como clase
    static class Student {
        int id;
        String name;
        String lastname;
        int number;
        String address;
        
        Student(int id, String name, String lastname, int number, String address) { this.id = id; this.name = name; this.lastname = lastname; this.number = number; this.address = address; }
    }

    static class Node {
        Student data;
        Node next;
        Node(Student data) { this.data = data; }
    }

    static Node pushFront(Node head, Student s) {
        Node n = new Node(s);
        n.next = head;
        return n;
    }

    static void print(Node head) {
        Node cur = head;
        while (cur != null) {
            System.out.println(cur.data.id + " - " + cur.data.name + " - " + cur.data.lastname + " - " + cur.data.number + " - " + cur.data.address);
            cur = cur.next;
        }
    }

    public static void main(String[] args) {
        Node head = null;
        head = pushFront(head, new Student(101, "Ana", "Martinez", 31205451, "Trasversal 51a #12 - 5"));
        head = pushFront(head, new Student(102, "Luis", "Oviedo", 32011103, "Carrera 22 - 1"));
        head = pushFront(head, new Student(200, "Laura", "Pastrana", 3155213, "Calle 61a - 14"));

        System.out.println("Estudiantes:");
        print(head);
    }
}