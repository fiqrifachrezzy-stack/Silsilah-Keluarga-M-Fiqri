# Program Silsilah Keluarga Menggunakan C++

## Deskripsi
Program ini dibuat menggunakan bahasa pemrograman C++ dengan tujuan untuk merepresentasikan
silsilah keluarga dalam bentuk struktur data pohon (tree). Konsep utama yang digunakan
dalam program ini adalah **N-ary Tree**, yaitu struktur pohon di mana setiap node dapat
memiliki lebih dari dua anak. Konsep ini dipilih karena dalam silsilah keluarga, satu orang
seperti kakek atau orang tua dapat memiliki lebih dari dua anak, sehingga penggunaan
binary tree tidak sesuai untuk menggambarkan kondisi keluarga secara nyata. Dengan
menggunakan N-ary Tree, hubungan antar anggota keluarga dapat direpresentasikan secara
lebih fleksibel dan mendekati struktur keluarga sebenarnya.

Program ini menerima input data anggota keluarga secara interaktif, kemudian menyusun
hubungan antar anggota keluarga tersebut ke dalam struktur N-ary Tree. Selain menampilkan
bagan silsilah keluarga dalam bentuk teks ASCII, program ini juga menampilkan hasil
penelusuran tree menggunakan metode traversal preorder, inorder, dan postorder.

## Fitur Program
- Menerima input data anggota keluarga secara dinamis menggunakan cin dan getline
- Membangun struktur silsilah keluarga menggunakan konsep N-ary Tree
- Menampilkan bagan silsilah keluarga dalam bentuk teks (ASCII)
- Mengimplementasikan traversal tree:
  - Preorder (root – children)
  - Inorder (pembagian anak kiri, root, dan anak kanan pada N-ary Tree)
  - Postorder (children – root)

## Struktur Data
Program ini menggunakan sebuah struktur bernama `Node` sebagai dasar pembentuk N-ary Tree.
Setiap node menyimpan nama anggota keluarga dalam bentuk string dan daftar anak dalam bentuk
vector yang berisi pointer ke node lain. Penggunaan vector memungkinkan setiap node memiliki
jumlah anak yang tidak terbatas sesuai dengan kondisi silsilah keluarga.

Node paling atas (root) pada tree ditetapkan sebagai kakek, karena kakek merupakan garis
keturunan tertinggi dalam silsilah keluarga. Anak-anak dari node kakek terdiri dari ibu
dan saudara-saudara ibu (om/tante). Selanjutnya, node ibu memiliki anak berupa pengguna program dan kakak/adik, sedangkan node om/tante memiliki anak berupa sepupu.

## Contoh Output Program
Berikut adalah contoh hasil output program setelah dijalankan dengan memasukkan data
anggota keluarga, di mana program akan menampilkan bagan silsilah keluarga serta hasil
traversal preorder, inorder, dan postorder berdasarkan struktur N-ary Tree yang terbentuk:


![Hasil_Output_Program_Silsilah_Keluarga](https://github.com/user-attachments/assets/150e1687-0856-4760-92bc-9079eaa99d92)

## Bahasa Pemrograman
- C++

## Author
M Fiqri Fachrezzy Hidayat
