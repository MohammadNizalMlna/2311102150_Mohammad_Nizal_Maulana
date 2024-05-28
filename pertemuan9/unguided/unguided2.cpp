#include <iostream>
#include <iomanip>
using namespace std;

struct Pohon
{
    char data;
    Pohon *left, *right, *parent;
};
Pohon *root, *baru;

void init()
{
    root = NULL;
}

bool isEmpty()
{
    return root == NULL;
}

void buatNode(char data)
{
    if (isEmpty())
    {
        root = new Pohon();
        root->data = data;
        root->left = NULL;
        root->right = NULL;
        root->parent = NULL;
        cout << "\n Node " << data << " berhasil dibuat sebagai root." << endl;
    }
    else
    {
        cout << "\n Tree sudah ada!" << endl;
    }
}

Pohon *insertLeft(char data, Pohon *node)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
        return NULL;
    }
    else
    {
        if (node->left != NULL)
        {
            cout << "\n Node " << node->data << " sudah ada child kiri!" << endl;
            return NULL;
        }
        else
        {
            Pohon *baru = new Pohon();
            baru->data = data;
            baru->left = NULL;
            baru->right = NULL;
            baru->parent = node;
            node->left = baru;
            cout << "\n Node " << data << " berhasil ditambahkan ke child kiri " << baru->parent->data << endl;
            return baru;
        }
    }
}

Pohon *insertRight(char data, Pohon *node)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
        return NULL;
    }
    else
    {
        if (node->right != NULL)
        {
            cout << "\n Node " << node->data << " sudah ada child kanan!" << endl;
            return NULL;
        }
        else
        {
            Pohon *baru = new Pohon();
            baru->data = data;
            baru->left = NULL;
            baru->right = NULL;
            baru->parent = node;
            node->right = baru;
            cout << "\n Node " << data << " berhasil ditambahkan ke child kanan " << baru->parent->data << endl;
            return baru;
        }
    }
}

void update(char data, Pohon *node)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
        {
            cout << "\n Node yang ingin diganti tidak ada!!" << endl;
        }
        else
        {
            char temp = node->data;
            node->data = data;
            cout << "\n Node " << temp << " berhasil diubah menjadi " << data << endl;
        }
    }
}

void retrieve(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
        {
            cout << "\n Node yang ditunjuk tidak ada!" << endl;
        }
        else
        {
            cout << "\n Data node: " << node->data << endl;
        }
    }
}

void find(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
        {
            cout << "\n Node yang ditunjuk tidak ada!" << endl;
        }
        else
        {
            cout << "\n Data Node: " << node->data << endl;
            cout << " Root: " << root->data << endl;

            if (!node->parent)
                cout << " Parent: (tidak punya parent)" << endl;
            else
                cout << " Parent: " << node->parent->data << endl;

            if (node->parent != NULL && node->parent->left != node && node->parent->right == node)
                cout << " Sibling: " << node->parent->left->data << endl;
            else if (node->parent != NULL && node->parent->right != node && node->parent->left == node)
                cout << " Sibling: " << node->parent->right->data << endl;
            else
                cout << " Sibling: (tidak punya sibling)" << endl;

            if (!node->left)
                cout << " Child Kiri: (tidak punya Child kiri)" << endl;
            else
                cout << " Child Kiri: " << node->left->data << endl;

            if (!node->right)
                cout << " Child Kanan: (tidak punya Child kanan)" << endl;
            else
                cout << " Child Kanan: " << node->right->data << endl;
        }
    }
}

void preOrder(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (node != NULL)
        {
            cout << " " << node->data << ", ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }
}

void inOrder(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (node != NULL)
        {
            inOrder(node->left);
            cout << " " << node->data << ", ";
            inOrder(node->right);
        }
    }
}

void postOrder(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (node != NULL)
        {
            postOrder(node->left);
            postOrder(node->right);
            cout << " " << node->data << ", ";
        }
    }
}

void deleteTree(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (node != NULL)
        {
            if (node != root)
            {
                node->parent->left = NULL;
                node->parent->right = NULL;
            }
            deleteTree(node->left);
            deleteTree(node->right);
            if (node == root)
            {
                delete root;
                root = NULL;
            }
            else
            {
                delete node;
            }
        }
    }
}

void deleteSub(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }
    else
    {
        deleteTree(node->left);
        deleteTree(node->right);
        cout << "\n Node subtree " << node->data << " berhasil dihapus." << endl;
    }
}

void clear()
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }
    else
    {
        deleteTree(root);
        cout << "\n Pohon berhasil dihapus." << endl;
    }
}

int size(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
        return 0;
    }
    else
    {
        if (!node)
        {
            return 0;
        }
        else
        {
            return 1 + size(node->left) + size(node->right);
        }
    }
}

int height(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
        return 0;
    }
    else
    {
        if (!node)
        {
            return 0;
        }
        else
        {
            int heightKiri = height(node->left);
            int heightKanan = height(node->right);
            if (heightKiri >= heightKanan)
            {
                return heightKiri + 1;
            }
            else
            {
                return heightKanan + 1;
            }
        }
    }
}

void characteristic()
{
    cout << "\n ukuran pohon: " << size(root) << endl;
    cout << " tinggi pohon: " << height(root) << endl;
    cout << " Rata-rata node pohon: " << size(root) / height(root) << endl;
}

void displayChildren(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }
    else if (!node)
    {
        cout << "\n Node yang ditunjuk tidak ada!" << endl;
    }
    else
    {
        if (node->left)
            cout << " Child Kiri: " << node->left->data << endl;
        else
            cout << " Child Kiri: (tidak punya Child kiri)" << endl;

        if (node->right)
            cout << " Child Kanan: " << node->right->data << endl;
        else
            cout << " Child Kanan: (tidak punya Child kanan)" << endl;
    }
}

void displayDescendants(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }
    else if (!node)
    {
        cout << "\n Node yang ditunjuk tidak ada!" << endl;
    }
    else
    {
        cout << " Keturunan dari " << node->data << ": ";
        preOrder(node);
        cout << endl;
    }
}

Pohon *findNode(Pohon *node, char data)
{
    if (node == NULL)
        return NULL;
    if (node->data == data)
        return node;

    Pohon *leftNode = findNode(node->left, data);
    if (leftNode != NULL)
        return leftNode;

    return findNode(node->right, data);
}

int main()
{
    init();
    int pilih_2311102150;
    char data_2311102150;
    Pohon *node = nullptr;

    do
    {
        cout << "\nMenu:\n";
        cout << "1. Buat Pohon\n";
        cout << "2. Tambah kiri\n";
        cout << "3. Tambah kanan\n";
        cout << "4. Perbarui Node\n";
        cout << "5. mengambil Node\n";
        cout << "6. Temukan Node\n";
        cout << "7. Tampilkan node\n";
        cout << "8. Tampilkan keturunan (child)\n";
        cout << "9. Sifat\n";
        cout << "10. PreOrder Traversal\n";
        cout << "11. InOrder Traversal\n";
        cout << "12. PostOrder Traversal\n";
        cout << "13. Hapus pohon\n";
        cout << "14. keluar\n";
        cout << "Masukkan pilihan : ";
        cin >> pilih_2311102150;

        switch (pilih_2311102150)
        {
        case 1:
            cout << "Masukkan root: ";
            cin >> data_2311102150;
            buatNode(data_2311102150);
            break;

        case 2:
            cout << "Masukkan data node baru: ";
            cin >> data_2311102150;
            cout << "Masukkan data parent baru: ";
            char parentDataLeft;
            cin >> parentDataLeft;
            node = findNode(root, parentDataLeft);
            if (node != nullptr)
                insertLeft(data_2311102150, node);
            break;

        case 3:
            cout << "Masukkan data node baru: ";
            cin >> data_2311102150;
            cout << "Masukkan data parent baru: ";
            char parentDataRight;
            cin >> parentDataRight;
            node = findNode(root, parentDataRight);
            if (node != nullptr)
                insertRight(data_2311102150, node);
            break;

        case 4:
            cout << "Masukan data yang ingin diubah: ";
            cin >> data_2311102150;
            cout << "Masukkan node baru: ";
            char newData;
            cin >> newData;
            node = findNode(root, data_2311102150);
            if (node != nullptr)
                update(newData, node);
            break;

        case 5:
            cout << "Masukan data yang akan diambil: ";
            cin >> data_2311102150;
            node = findNode(root, data_2311102150);
            retrieve(node);
            break;

        case 6:
            cout << "Masukkan data yang akan ditemukan: ";
            cin >> data_2311102150;
            node = findNode(root, data_2311102150);
            find(node);
            break;

        case 7:
            cout << "Masukan data untuk yang ingin ditampilkan: ";
            cin >> data_2311102150;
            node = findNode(root, data_2311102150);
            displayChildren(node);
            break;

        case 8:
            cout << "Masukkan data untuk menampilkan keturunan(child): ";
            cin >> data_2311102150;
            node = findNode(root, data_2311102150);
            displayDescendants(node);
            break;

        case 9:
            characteristic();
            break;

        case 10:
            cout << "PreOrder Traversal: ";
            preOrder(root);
            cout << endl;
            break;

        case 11:
            cout << "InOrder Traversal: ";
            inOrder(root);
            cout << endl;
            break;

        case 12:
            cout << "PostOrder Traversal: ";
            postOrder(root);
            cout << endl;
            break;

        case 13:
            clear();
            break;

        case 14:
            cout << "Keluar program" << endl;
            break;

        default:
            cout << "pilihan tidak tersedia" << endl;
        }
    } while (pilih_2311102150 != 14);

    return 0;
}
