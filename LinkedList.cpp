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

//bagian delete first node
void hapusAwal(){
    if(head == NULL){
        cout<<"List kosong, tidak ada yang bisa dihapus"<<endl;
        return;
    }
    Node *temp = head;
    head = head->next;
    delete temp;
    cout<<"Produk pertama berhasil dihapus"<<endl;
}

//bagian delete middle node
void hapusTengah(string produk){
    if(head == NULL){
        cout<<"List kosong, tidak ada yang bisa dihapus"<<endl;
        return;
    }

    Node *temp = head;
    Node *prev = NULL;

    while(temp != NULL && temp->produk != produk){
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL){
        cout<<"Produk tidak ditemukan"<<endl;
        return;
    }

    if(prev == NULL){       
        head = temp->next;
    }
    else{
        prev->next = temp->next;
    }

    delete temp;

    cout<<"Produk tengah berhasil dihapus"<<endl;
}


//bagian delete last node
void hapusAkhir(){
    if(head == NULL){
        cout<<"List kosong, tidak ada yang bisa dihapus"<<endl;
        return;
    }
    if(head->next == NULL){
        delete head;
        head = NULL;
        cout<<"Produk terakhir berhasil dihapus"<<endl;
        return;
    }
    Node *temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
    cout<<"Produk terakhir berhasil dihapus"<<endl;
}

//bagian menampilkan semua produk
void tampilkanProduk(){
    if(head == NULL){
        cout<<"Keranjang kosong"<<endl;
        return;
    }

    Node *temp = head;

    while(temp != NULL){
        cout<<"Produk : "<<temp->produk<<endl;
        cout<<"Harga  : "<<temp->harga<<endl;
        cout<<"Jumlah : "<<temp->jumlah<<endl;
        cout<<"---------------------"<<endl;

        temp = temp->next;
    }
}

//bagian mencari produk
void cariProduk(string produk){

    if(head == NULL){
    cout<<"Keranjang kosong"<<endl;
    return;
}

    Node *temp = head;

    while(temp != NULL){
        if(temp->produk == produk){
            cout<<"Produk ditemukan"<<endl;
            cout<<"Harga  : "<<temp->harga<<endl;
            cout<<"Jumlah : "<<temp->jumlah<<endl;
            return;
        }

        temp = temp->next;
    }

    cout<<"Produk tidak ditemukan"<<endl;
}


