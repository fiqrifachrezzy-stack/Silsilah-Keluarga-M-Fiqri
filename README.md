# Program Silsilah Keluarga Menggunakan C++

## Deskripsi
Program ini dibuat menggunakan bahasa pemrograman C++ dengan tujuan untuk merepresentasikan
silsilah keluarga dalam bentuk struktur data pohon (tree). Konsep utama yang digunakan pada
program ini adalah N-ary Tree, yaitu struktur pohon di mana setiap node dapat memiliki lebih
dari dua anak. Konsep ini dipilih karena dalam silsilah keluarga, satu orang (misalnya kakek
atau orang tua) dapat memiliki lebih dari dua anak, sehingga penggunaan binary tree tidak
cocok untuk merepresentasikan kondisi keluarga secara nyata.

Pada bagian awal program digunakan beberapa library standar C++. Library `<iostream>`
digunakan untuk keperluan input dan output data ke layar. Library `<vector>` digunakan untuk
menyimpan daftar anak dari setiap node, karena jumlah anak tidak ditentukan dan bisa
berubah-ubah. Library `<string>` digunakan untuk menyimpan nama anggota keluarga dalam bentuk
teks. Seluruh program menggunakan `using namespace std;` agar pemanggilan fungsi dan tipe data
dari library standar menjadi lebih sederhana.

Selanjutnya dibuat sebuah struktur bernama `Node` yang berfungsi sebagai dasar pembentuk
N-ary Tree. Di dalam struktur ini terdapat dua bagian utama. Pertama adalah variabel `string
nama` yang digunakan untuk menyimpan nama anggota keluarga. Kedua adalah `vector<Node*> children`
yang berfungsi sebagai menyimpan daftar anak dari node tersebut. Karena menggunakan vector,
maka satu node bisa memiliki satu, dua, atau bahkan lebih anak sesuai kebutuhan. Constructor
`Node(string n)` digunakan agar setiap kali sebuah node dibuat, nilai nama langsung terisi,
sehingga memudahkan proses pembuatan pohon keluarga.

## Konsep Traversal Tree
Setelah struktur node dibuat, program mendefinisikan tiga fungsi traversal, yaitu preorder,
inorder, dan postorder. Ketiga traversal ini digunakan untuk menelusuri struktur pohon keluarga
dengan urutan yang berbeda-beda. Meskipun traversal ini lebih sering digunakan pada binary
tree, pada program ini traversal disesuaikan agar dapat bekerja pada N-ary Tree.

Fungsi `preorder(Node* root)` bekerja dengan urutan root – children. Artinya, nama pada node
induk akan ditampilkan terlebih dahulu, kemudian dilanjutkan dengan seluruh anak-anaknya secara
berurutan. Pada awal fungsi terdapat kondisi `if (!root) return;` yang berfungsi sebagai
penghentian rekursi jika node kosong. Setelah itu `cout << root->nama` digunakan untuk
menampilkan nama node yang sedang dibaca. Selanjutnya fungsi memanggil dirinya sendiri untuk
setiap anak yang terdapat pada `root->children`. Karena itulah traversal preorder selalu
dimulai dari node paling atas, yaitu kakek sebagai akar silsilah keluarga.

Fungsi `inorder(Node* root)` pada N-ary Tree tidak memiliki aturan baku seperti pada binary
tree, sehingga pada program ini inorder didefinisikan dengan cara membagi anak menjadi dua
bagian. Nilai `mid` diperoleh dari `n / 2`, di mana `n` adalah jumlah anak. Traversal dilakukan
dengan membaca setengah anak pertama, kemudian node induk, lalu sisa anak berikutnya. Dengan
pendekatan ini, traversal inorder tetap memiliki makna urutan kiri – akar – kanan meskipun
digunakan pada N-ary Tree.

Fungsi `postorder(Node* root)` bekerja dengan urutan children – root. Artinya, seluruh anak
dari suatu node akan ditampilkan terlebih dahulu, kemudian diakhiri dengan node induknya.
Seperti fungsi lainnya, terdapat pengecekan node kosong di awal untuk mencegah error dan
menghentikan rekursi.

## Proses Input dan Pembentukan Tree
Pada fungsi `main()`, program mulai dengan mendeklarasikan berbagai variabel bertipe string
dan integer yang digunakan untuk menyimpan input nama anggota keluarga, seperti nama diri
sendiri, ayah, ibu, kakek, nenek, kakak/adik, om, tante, serta sepupu. Program kemudian meminta
input dari pengguna secara interaktif menggunakan `getline` dan `cin`. Penggunaan `getline`
sangat penting agar input berupa nama lengkap yang mengandung spasi tetap terbaca dengan
benar.

Setelah seluruh data keluarga dimasukkan, program mulai membangun struktur N-ary Tree. Node
paling atas atau root ditetapkan sebagai kakek, karena kakek merupakan garis keturunan tertinggi
dalam silsilah ini. Dari node kakek, ditambahkan beberapa anak, yaitu ibu dan saudara-saudara
ibu (om/tante). Kemudian pada node ibu ditambahkan anak-anak berupa pengguna program dan
kakak/adik. Pada node om/tante ditambahkan anak-anak berupa sepupu. Dengan struktur ini,
hubungan keluarga dapat direpresentasikan secara hierarkis dan jelas.

Selain menampilkan traversal, program juga menampilkan bagan silsilah keluarga dalam bentuk
teks ASCII. Bagan ini berfungsi sebagai visualisasi sederhana agar hubungan antar anggota
keluarga lebih mudah dipahami. Nama kakek dan nenek ditampilkan di bagian atas, diikuti oleh
ibu, ayah, om, dan tante, lalu anak-anak di bagian paling bawah.

## Contoh Input dan Hasil Traversal
Sebagai contoh, jika dimasukkan data sebagai berikut:  
Nama kamu adalah M Fiqri, ayah Taufiq, ibu Haryati, memiliki satu adik bernama Reza, kakek
Bastari, nenek Wartiah, om pertama Rudi dengan pasangan Marini dan dua anak Raka serta Raisha,
serta tante kedua Nurmala dengan pasangan Aris dan tanpa anak. Maka struktur pohon yang
terbentuk memiliki kakek Bastari sebagai root dengan tiga anak utama, yaitu Haryati, Rudi, dan
Nurmala.

Berdasarkan struktur tersebut, hasil traversal yang dihasilkan oleh program adalah sebagai
berikut. Traversal preorder menghasilkan urutan Bastari, Haryati, M Fiqri, Reza, Rudi, Raka,
Raisha, Nurmala. Traversal inorder menghasilkan urutan M Fiqri, Haryati, Reza, Bastari, Raka,
Rudi, Raisha, Nurmala. Traversal postorder menghasilkan urutan M Fiqri, Reza, Haryati, Raka,
Raisha, Rudi, Nurmala, Bastari. Traversal ini menunjukkan bahwa semua anak dibaca terlebih
dahulu sebelum node induknya ditampilkan, dan kakek sebagai root muncul di bagian paling akhir.

Dengan demikian, program ini berhasil mengimplementasikan konsep N-ary Tree untuk memodelkan
silsilah keluarga secara logis dan fleksibel, sekaligus menampilkan hasil traversal preorder,
inorder, dan postorder sebagai bentuk penerapan struktur data pohon dalam kehidupan nyata.

## Contoh Output Program

![Hasil_Output_Program_Silsilah_Keluarga](https://github.com/user-attachments/assets/184c7783-8cb7-48c8-ad5d-ba6fda3bb4ff)

## Bahasa Pemrograman
C++

## Author
M Fiqri Fachrezzy Hidayat
