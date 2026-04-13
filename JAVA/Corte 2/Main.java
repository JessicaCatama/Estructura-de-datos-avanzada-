package com.mycompany.student;

public class Main {

    //Registro como clase
    static class Student {
        int id;
        String name;

        Student(int id, String name) { 
            this.id = id; 
            this.name = name; 
        }
    }

    //Nodo para lista doble
    static class Node {
        Student data;
        Node next;
        Node prev;

        Node(Student data) { 
            this.data = data; 
        }
    }

    static Node pushFront(Node head, Student s) {
        Node n = new Node(s);
        n.next = head;

        if (head != null) {
            head.prev = n;
        }

        return n;
    }

    static Node pushBack(Node head, Student s) {
        Node n = new Node(s);

        if (head == null) return n;

        Node cur = head;
        while (cur.next != null) cur = cur.next;

        cur.next = n;
        n.prev = cur;

        return head;
    }

    static void printForward(Node head) {
        System.out.print("[");
        Node cur = head;
        while (cur != null) {
            System.out.print(cur.data.id + "-" + cur.data.name);
            if (cur.next != null) System.out.print(", ");
            cur = cur.next;
        }
        System.out.println("]");
    }

    static Node getTail(Node head) {
        if (head == null) return null;
        Node cur = head;
        while (cur.next != null) cur = cur.next;
        return cur;
    }

    static void printBackward(Node head) {
        Node cur = getTail(head);
        System.out.print("[");
        while (cur != null) {
            System.out.print(cur.data.id + "-" + cur.data.name);
            if (cur.prev != null) System.out.print(", ");
            cur = cur.prev;
        }
        System.out.println("]");
    }

    static void print(Node head) {
        Node cur = head;
        while (cur != null) {
            System.out.println(cur.data.id + " - " + cur.data.name);
            cur = cur.next;
        }
    }

    public static void main(String[] args) {
        Node head = null;

        head = pushFront(head, new Student(101, "Ana"));
        head = pushFront(head, new Student(102, "Luis"));
        head = pushBack(head, new Student(103, "Carlos"));

        System.out.print("Adelante: ");
        printForward(head);

        System.out.print("Atras: ");
        printBackward(head);
    }
}