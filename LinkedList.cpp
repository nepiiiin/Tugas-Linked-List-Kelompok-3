#include <iostream>
using namespace std;

struct Node {
    string produk;
    int harga;
    int jumlah;
    Node *next;
};

Node *head=NULL;

//bagian beginning node
void tambahAwal(string produk, int harga, int jumlah){
    Node *baru = new Node;

    baru->produk = produk;
    baru->harga = harga;
    baru->jumlah = jumlah;
    baru->next = head;
    head = baru;

    cout<<"Produk berhasil ditambahkan"<<endl;
}

//bagian last node
void tambahAkhir(string produk, int harga, int jumlah){
    Node *baru = new Node;

    baru->produk = produk;
    baru->harga = harga;
    baru->jumlah = jumlah;
    baru->next = NULL;

    if(head == NULL){
        head = baru;
    }
    else{
        Node *temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = baru;
    }
    cout<<"Produk berhasil ditambahkan di akhir"<<endl;
}