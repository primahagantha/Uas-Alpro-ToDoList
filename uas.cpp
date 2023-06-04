#include <iostream>
#include <vector>

using namespace std;

struct toDoList // struct / objek
{
    string deskripsi;
    bool selesai;
};

class DaftarToDoList
{
private:
    vector<toDoList> taskList; // menggunakan / sync ke struct untuk vector

public:
    void tambahTask()
    {
        string deskripsi;
        cout << "============" << endl;
        cout << "Masukkan task yang ingin anda tambahkan: ";
        cin.ignore();
        getline(cin, deskripsi); // Mengambil input deskripsi task dari pengguna menggunakan getline()
        toDoList task;           // sync ke struct dan namai objek menjadi task
        task.deskripsi = deskripsi;
        task.selesai = false;     // untuk menandakan task belum selesai
        taskList.push_back(task); // memasukan task berdasarkan deskirpsi di input (line 24) ke dalam array / vector
        cout << "Task berhasil ditambahkan.\n"
             << endl;
        cout << "============" << endl;
    }

    void lihatTask()
    {
        cout << "============" << endl;
        cout << "Daftar Task:\n"
             << endl;
        for (size_t i = 0; i < taskList.size(); i++) // mengunakan for untuk melihat semua task yang ada di isi vector taskList.size
        {
            cout << i + 1 << ". ";
            if (taskList[i].selesai)
                cout << "[DONE] "; // menambahkan done jika ada sebuah tasklist yang di tandai = true sesuai function tandaiTask
            cout << taskList[i].deskripsi << endl;
        }
        cout << "============" << endl;
        cout << endl;
    }

    void hapusTask()
    {
        int index;
        cout << "============" << endl;
        cout << "Masukkan nomor task yang ingin dihapus: ";
        cin >> index;
        if (index >= 1 && index <= taskList.size()) // memeriksa semua task list di isi array
        {
            taskList.erase(taskList.begin() + index - 1); // jika task yang di input ada akan di hapus sesuai index di pilih
            cout << "Task berhasil dihapus.\n"
                 << endl;
            cout << "============" << endl;
        }
        else
        { // jika task yang di input tidak ada maka dianggap invalid / tidak valid
            cout << "Nomor task tidak valid.\n"
                 << endl;
            cout << "============" << endl;
        }
    }

    void tandaiTask()
    {
        int index;
        cout << "============" << endl;
        cout << "Masukkan nomor task yang ingin ditandai sebagai selesai: ";
        cin >> index; //
        if (index >= 1 && index <= taskList.size())
        {
            taskList[index - 1].selesai = true;                 // jika task yang di input ada, otomatis membuat taskList.selesai default false menjadi true
            cout << "Task berhasil ditandai sebagai selesai.\n" // dan akan ada [done] menandakan sebagai selesai tasknya.
                 << endl;
            cout << "============" << endl;
        }
        else
        {
            cout << "Nomor task tidak valid.\n"
                 << endl;
            cout << "============" << endl;
        }
    }

    void hapusTandaTask()
    {
        int index;
        cout << "============" << endl;
        cout << "Masukkan nomor task yang ingin dihapus tandanya: "; // jika task yang di input ada, otomatis membuat taskList.selesai true menjadi false
        cin >> index;
        if (index >= 1 && index <= taskList.size())
        {
            taskList[index - 1].selesai = false;
            cout << "Tanda task berhasil dihapus.\n"; // dan akan hilang [done] menandakan sebagai belum di tandai tasknya.
            cout << "============" << endl;
        }
        else
        {
            cout << "Nomor task tidak valid.\n"
                 << endl;
            cout << "============" << endl;
        }
    }
};

int main()
{
    DaftarToDoList toDoList;
    int pilih;
    while (true) // gunakan while jika memasukkan pilihan selain 1-6 akan ngulang hingga input 6 untuk selesaikan
    {
        cout << "Program ToDoList berbasis CLI\n"; // tampilan menu ToDoList
        cout << "Silahkan pilih menu di bawah ini:\n";
        cout << "1. Tambah Task\n";
        cout << "2. Hapus Task\n";
        cout << "3. Lihat Task\n";
        cout << "4. Tandai Task yang sudah selesai\n";
        cout << "5. Menghapus tanda task yang sudah selesai\n";
        cout << "6. Keluar dari program\n";
        cout << "Silahkan masukkan pilihan anda: ";
        cin >> pilih;
        switch (pilih) // penggunaan switch untuk menentukan kondisi
        {
        case 1:
            toDoList.tambahTask(); // berisi setiap fungsi class di atas
            break;
        case 2:
            toDoList.hapusTask();
            break;
        case 3:
            toDoList.lihatTask();
            break;
        case 4:
            toDoList.tandaiTask();
            break;
        case 5:
            toDoList.hapusTandaTask();
            break;
        case 6:
            cout << "Terima kasih telah menggunakan program ini.\n"; // jika sudah selesai menggunakan program, akan muncul pesan seperti ini
            cout << "------------------------------------------\n";  // dan exit
            cout << "|         T  H  A  N  K     Y  O  U       |\n";
            cout << "------------------------------------------\n";
            return 0;
        default:
            cout << "Pilihan tidak valid.\n"; // jika salah memasukkan input selain angka 1-6 akan keluar seperti ini.
        }
    }
    return 0;
}
