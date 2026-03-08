#include <iostream>
using namespace std;

struct Node {
    string produk;
    int harga;
    int jumlah;
    Node *next;
};

Node *head = NULL;

void tambahAwal(string produk, int harga, int jumlah){
    Node *baru = new Node;
    baru->produk = produk;
    baru->harga = harga;
    baru->jumlah = jumlah;
    baru->next = head;
    head = baru;
    
    cout << "Produk berhasil ditambahkan di awal\n";
}

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
    cout << "Produk berhasil ditambahkan di akhir\n";
}

void tambahTengah(string produkSebelum, string produk, int harga, int jumlah){
    if(head == NULL){
        cout << "List kosong, produk akan ditambahkan sebagai awal\n";
        tambahAwal(produk, harga, jumlah);
        return;
    }
    Node *temp = head;
    while(temp != NULL && temp->produk != produkSebelum){
        temp = temp->next;
    }
    if(temp == NULL){
        cout << "Produk acuan tidak ditemukan\n";
        return;
    }
    Node *baru = new Node;
    baru->produk = produk;
    baru->harga = harga;
    baru->jumlah = jumlah;

    baru->next = temp->next;
    temp->next = baru;

    cout << "Produk berhasil ditambahkan setelah " << produkSebelum << endl;
}

void hapusAwal(){
    if(head == NULL){
        cout << "Keranjang kosong\n";
        return;
    }
    Node *temp = head;
    head = head->next;
    delete temp;

    cout << "Produk pertama berhasil dihapus\n";
}

void hapusTengah(string produk){
    Node *temp = head;
    Node *prev = NULL;

    while(temp != NULL && temp->produk != produk){
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL){
        cout << "Produk tidak ditemukan\n";
        return;
    }

    if(prev == NULL){       
        head = temp->next;
    }
    else{
        prev->next = temp->next;
    }

    delete temp;
    cout << "Produk " << produk << " berhasil dihapus\n";
}

void hapusAkhir(){
    if(head == NULL){
        cout << "Keranjang kosong\n";
        return;
    }
    if(head->next == NULL){
        delete head;
        head = NULL;
        cout << "Produk terakhir berhasil dihapus\n";
        return;
    }
    
    Node *temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
    cout << "Produk terakhir berhasil dihapus\n";
}

void tampilkanProduk(){
    if(head == NULL){
        cout << "Keranjang kosong\n";
        return;
    }

    Node *temp = head;
    int idx = 1;

    while(temp != NULL){
        cout << idx << ". Produk : " << temp->produk << endl;
        cout << "   Harga  : " << temp->harga << endl;
        cout << "   Jumlah : " << temp->jumlah << endl;
        cout << endl;

        temp = temp->next;
        idx++;
    }
}

int main(){
    int pilih;
    string produk, produkSebelum;
    int harga, jumlah;

    do{

        cout << "\n=== MENU KERANJANG ===\n";
        cout << "1. Tambah di awal\n";
        cout << "2. Tambah di akhir\n";
        cout << "3. Tambah setelah produk\n";
        cout << "4. Hapus pertama\n";
        cout << "5. Hapus terakhir\n";
        cout << "6. Hapus produk\n";
        cout << "7. Tampilkan keranjang\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;
        cin.ignore();

        switch(pilih){
            case 1:
                cout << "Nama produk: ";
                getline(cin, produk);
                cout << "Harga: ";
                cin >> harga;
                cout << "Jumlah: ";
                cin >> jumlah;
                cin.ignore();
                tambahAwal(produk, harga, jumlah);
                break;

            case 2:
                cout << "Nama produk: ";
                getline(cin, produk);
                cout << "Harga: ";
                cin >> harga;
                cout << "Jumlah: ";
                cin >> jumlah;
                cin.ignore();
                tambahAkhir(produk, harga, jumlah);
                break;

            case 3:
                cout << "Masukkan nama produk acuan (produk yang akan didahului): ";
                getline(cin, produkSebelum);
                cout << "Nama produk yang disisipkan: ";
                getline(cin, produk);
                cout << "Harga: ";
                cin >> harga;
                cout << "Jumlah: ";
                cin >> jumlah;
                cin.ignore();
                tambahTengah(produkSebelum, produk, harga, jumlah);
                break;

            case 4:
                hapusAwal();
                break;

            case 5:
                hapusAkhir();
                break;

            case 6:
                cout << "Masukkan nama produk yang ingin dihapus: ";
                getline(cin, produk);

                hapusTengah(produk);
                break;

            case 7:
                tampilkanProduk();
                break;
        }

    } while(pilih != 0);
    return 0;
}
