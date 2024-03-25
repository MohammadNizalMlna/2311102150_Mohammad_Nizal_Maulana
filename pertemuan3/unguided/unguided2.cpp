/*
Mohammad Nizal Maulana - 2311102150
*/
#include<iostream>
using namespace std;

// Deklarasi Class node
class node {
    public:
        string barang_150;
        int harga_150;
        node* prev;
        node* next;
};
// Deklarasi class DoublyLinkedList
class DoublyLinkedList{
    public:
    node* head;
    node* tail;
    DoublyLinkedList(){
        head = nullptr;
        tail = nullptr;
    }
    // Menambahkan data lewat prosedur push
    void push_150 (int harga_150, string barang_150){
        node* baru = new node;
        baru->harga_150 = harga_150;
        baru->barang_150 = barang_150;
        baru->prev = nullptr;
        baru->next = head;
        if (head != nullptr){
            head->prev = baru;
        }  
        else{
            tail = baru;
        }
        head = baru;
    }
};
