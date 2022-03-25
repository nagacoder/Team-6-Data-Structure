#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Item
{
    int unique_id, price, stock;
    char name[50];
    struct Item *next, *prev;
} * head, *tail, *current;

void addNewItem();
void showAllItem();
void updateStock();
void updatePrice();
void deleteItem();
void cashier();

int main()
{
    int option = 0;
    printf("Tugas Structure Data Double Linked List \n");
    while (1)
    {
        printf("\n Pilih Menu : \n");
        printf("(1) : Tambahkan Data Barang \n");
        printf("(2) : Tampilkan Data Barang \n");
        printf("(3) : Kasir Penjualan \n");
        printf("(4) : Ubah Stock \n");
        printf("(5) : Ubah Harga \n");
        printf("(6) : Hapus Item \n");
        printf("--------------------------------------- \n");
        printf("Masukan pilihan anda : ");
        scanf("%d", &option);
        printf("\n");
        switch (option)
        {
        case 1:
            printf("Tambahkan Data Barang \n");
            printf("--------------------------------------- \n");
            addNewItem();
            break;
        case 2:
            printf("Tampilkan Data Barang \n");
            printf("--------------------------------------- \n");
            showAllItem();
            break;
        case 3:
            printf("Kasir Penjualan \n");
            printf("--------------------------------------- \n");
            cashier();
            break;
        case 4:
            printf("Ubah Stok  \n");
            printf("--------------------------------------- \n");
            updateStock();
            break;
        case 5:
            printf("Ubah Harga  \n");
            printf("--------------------------------------- \n");
            updatePrice();
            break;
        case 6:
            printf("Hapus Item  \n");
            printf("--------------------------------------- \n");
            deleteItem();
            break;
        default:
            break;
        }
        printf("\n");
        printf("--------------------------------------- \n");
    }
    return 0;
}
void addNewItem()
{
    int unique_id, price, stock, i;
    char name[50];
    bool is_unique_id_taken = false;

    current = (struct Item *)malloc(sizeof(struct Item));
    // masukan data barang
    printf("Masukan data barang\n");
    printf("Nama Barang : ");
    scanf("%s", name);

    printf("Kode Barang : ");
    scanf("%d", &unique_id);
    if (unique_id == 0)
    {
        printf("Kode Barang harus berupa angka");
        exit(0);
    }

    while (head != NULL && head->unique_id == unique_id)
    {
        is_unique_id_taken = true;
        break;
    };
    if (is_unique_id_taken)
    {
        printf("Kode barang Sudah dipakai ");
    }
    else
    {
        printf("Harga Barang : ");
        scanf("%d", &price);
        if (price == 0)
        {
            printf("harga Barang harus berupa angka");
            exit(0);
        }

        printf("Stok Barang : ");
        scanf("%d", &stock);
        if (stock == 0)
        {
            printf("Stok Barang harus berupa angka");
            exit(0);
        }

        printf("\n");
        printf("--------------------------------------- \n");
        current->unique_id = unique_id;
        current->price = price;
        current->stock = stock;
        strcpy(current->name, name);
        if (head == NULL)
        {
            head = tail = current;
        }
        else
        {
            current->next = head;
            head = current;
        }

        printf("Kode Barang | Nama Barang | Harga Barang | Stok Barang\n");
        printf("%d | %s | %d | %d ", current->unique_id, current->name, current->price, current->stock);
        printf("\n");
        printf("--------------------------------------- \n");
    }
}
void showAllItem()
{
    current = head;
    printf("Kode Barang | Nama Barang | Harga Barang | Stock Barang\n");
    while (current != NULL)
    {
        printf("%d | %s | %d | %d \n", current->unique_id, current->name, current->price, current->stock);
        current = current->next;
    }
}
void cashier()
{
    int totalItem, unique_id;
    int totalPrice = 0;
    printf("++****************************************************++\n");
    printf("           KASIR TOKO SEBELAH\n");
    printf("++****************************************************++n\n");
    printf("   - Masukkan kode barang dan jumlahnya\n");
    printf("   - Contoh: 1 2\n");
    printf("   - Ketik 0 0jika sudah selesai\n");
    printf("++---------------------------------------------------++n\n");
    do
    {
        printf("Masukan kode barang dan jumlah : ");
        scanf("%d %d", &unique_id, &totalItem);
        current = head;

        while ((current != NULL) && (current->unique_id != unique_id))
        {
            current = current->next;
        }
        if (current != NULL && current->unique_id == unique_id)
        {
            totalPrice = totalPrice + (current->price) * totalItem;
        }

    } while (unique_id != 0 && totalItem != 0);
    printf("=======================================\n");
    printf("\nTOTAL BAYAR: %d\n\n", totalPrice);
    printf("=======================================\n");
}

void updateStock()
{
    int unique_id, new_stock;
    current = head;
    printf("Kode Barang : ");
    scanf("%d", &unique_id);
    if (unique_id == 0)
    {
        printf("Kode Barang harus berupa angka");
        exit(0);
    }

    while (current->unique_id != unique_id)

    {
        current = head->next;
    }

    printf("Masukkan Stok Baru : ");
    scanf("%d", &new_stock);
    if (new_stock == 0)
    {
        printf("Stok harus berupa angka");
        exit(0);
    }

    current->stock = new_stock;

    printf("Stok Berhasil Dirubah");
};

void updatePrice()
{
    int unique_id, new_price;
    current = head;
    printf("Kode Barang : ");
    scanf("%d", &unique_id);
    if (unique_id == 0)
    {
        printf("Kode Barang harus berupa angka");
        exit(0);
    }

    while (current->unique_id != unique_id)

    {
        current = head->next;
    }

    printf("Masukkan Harga Baru : ");
    scanf("%d", &new_price);
    if (new_price == 0)
    {
        printf("Stok harus berupa angka");
        exit(0);
    }

    current->price = new_price;

    printf("Harga Berhasil Dirubah");
};

void deleteItem()
{
    int unique_id;
    struct Item *temp = head;
    printf("Kode Barang : ");
    scanf("%d", &unique_id);
    if (unique_id == 0)
    {
        printf("Kode Barang harus berupa angka");
        exit(0);
    }

    if (head == NULL)
    {
        printf("Node Kosong!\n");
    }

    while (temp->unique_id != unique_id)
        temp = temp->next;
    if (head->price == temp->price)
    {

        head = NULL;
    };

    if (temp->prev != NULL)
    {
        printf("Node prev %d \n!", temp->prev->price);
        temp->prev->next = temp->prev;
    }

    if (temp->next != NULL)
    {
        temp->next->prev = temp->next;
    }

    free(temp);
    printf("Item  Berhasil Hapus");
};