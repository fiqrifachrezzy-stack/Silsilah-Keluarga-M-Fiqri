#include <iostream>
#include <vector>
#include <string>
using namespace std;

// ================= NODE N-ARY TREE =================
struct Node {
    string nama;
    vector<Node*> children;
    Node(string n) : nama(n) {}
};

// ================= TRAVERSAL =================
void preorder(Node* root) {
    if (!root) return;
    cout << root->nama << ", ";
    for (auto c : root->children)
        preorder(c);
}

void inorder(Node* root) {
    if (!root) return;
    int n = root->children.size();
    int mid = n / 2;

    for (int i = 0; i < mid; i++)
        inorder(root->children[i]);

    cout << root->nama << ", ";

    for (int i = mid; i < n; i++)
        inorder(root->children[i]);
}

void postorder(Node* root) {
    if (!root) return;
    for (auto c : root->children)
        postorder(c);
    cout << root->nama << ", ";
}

int main() {
    // ================= VARIABEL =================
    string kamu, ayah, ibu, kakek, nenek;
    int jmlAdik;
    string Adik;

    int jmlSaudaraIbu;
    string ot1, pas1, ot2, pas2;
    int ja1, ja2;
    string c1, c2, c3;

    // ================= INPUT =================
    cout << "Masukan nama Kamu : ";
    getline(cin, kamu);

    cout << "Masukan nama Ayah : ";
    getline(cin, ayah);

    cout << "Masukan nama Ibu : ";
    getline(cin, ibu);

    cout << "Masukan Jumlah Kakak/Adik : ";
    cin >> jmlAdik; cin.ignore();
    if (jmlAdik >= 1) {
        cout << "Masukan nama Kakak/Adik : ";
        getline(cin, Adik);
    }

    cout << "\nMasukan Jumlah saudara Ibu (Om/Tante) : ";
    cin >> jmlSaudaraIbu; cin.ignore();

    // ===== Om/Tante 1 =====
    cout << "\nMasukan nama Om/Tante 1 : ";
    getline(cin, ot1);

    cout << "Masukan nama Pasangan Om/Tante 1 : ";
    getline(cin, pas1);

    cout << "Masukan Jumlah Anak Om/Tante 1 : ";
    cin >> ja1; cin.ignore();

    if (ja1 >= 1) {
        cout << "Masukan nama Anak 1 (Sepupu) : ";
        getline(cin, c1);
    }
    if (ja1 >= 2) {
        cout << "Masukan nama Anak 2 (Sepupu) : ";
        getline(cin, c2);
    }

    // ===== Om/Tante 2 =====
    if (jmlSaudaraIbu >= 2) {
        cout << "\nMasukan nama Om/Tante 2 : ";
        getline(cin, ot2);

        cout << "Masukan nama Pasangan Om/Tante 2 : ";
        getline(cin, pas2);

        cout << "Masukan Jumlah Anak Om/Tante 2 : ";
        cin >> ja2; cin.ignore();

        if (ja2 >= 1) {
            cout << "Masukan nama Anak 1 (Sepupu) : ";
            getline(cin, c3);
        }
    }

    cout << "\nMasukan nama Kakek : ";
    getline(cin, kakek);

    cout << "Masukan nama Nenek : ";
    getline(cin, nenek);

    // ================= KONSTRUKSI N-ARY TREE =================
    // ROOT = KAKEK (GARIS DARAH)
    Node* root = new Node(kakek);

    Node* ibuNode = new Node(ibu);
    root->children.push_back(ibuNode);

    Node* om1Node = new Node(ot1);
    root->children.push_back(om1Node);

    Node* om2Node = new Node(ot2);
    root->children.push_back(om2Node);

    // Anak Ibu
    ibuNode->children.push_back(new Node(kamu));
    if (jmlAdik >= 1)
        ibuNode->children.push_back(new Node(Adik));

    // Anak Om/Tante 1
    if (ja1 >= 1) om1Node->children.push_back(new Node(c1));
    if (ja1 >= 2) om1Node->children.push_back(new Node(c2));

    // Anak Om/Tante 2
    if (ja2 >= 1) om2Node->children.push_back(new Node(c3));

    // ================= BAGAN SILSILAH (TIDAK DIHILANGKAN) =================
    cout << "\n\n==========================================================================\n";
    cout << "                SILSILAH KELUARGA M FIQRI FACHREZZY HIDAYAT                \n";
    cout << "==========================================================================\n\n";

    cout << "                           +---------+       +---------+\n";
    cout << "                           | " << kakek << " |-------| " << nenek << " |\n";
    cout << "                           +---------+       +---------+\n";
    cout << "                                         |\n";
    cout << "       ------------------------------------------------------------------\n";
    cout << "       |                                 |                              |\n";
    cout << "+---------+ +--------+              +------+ +--------+           +---------+ +------+\n";
    cout << "| " << ibu << " |-| " << ayah << " |              | " << ot1 << " |-| " << pas1 << " |           | " << ot2 << " |-| " << pas2 << " |\n";
    cout << "+---------+ +--------+              +------+ +--------+           +---------+ +------+\n";
    cout << "       |                                |                              \n";
    cout << "     ---------                      ----------                    \n";
    cout << "    |         |                    |          |                     \n";
    cout << "+-------+  +----+               +----+     +------+                \n";
    cout << "|"<<kamu<<"|  |"<<Adik<<"|               |"<<c1<<"|     |"<<c2<<"|\n";
    cout << "+-------+  +----+               +----+     +------+               \n";

    // ================= TRAVERSAL =================
    cout << "\n====================== TRAVERSAL ======================\n";
    cout << "Preorder  : "; preorder(root); cout << endl;
    cout << "Inorder   : "; inorder(root); cout << endl;
    cout << "Postorder : "; postorder(root); cout << endl;

    return 0;
}
