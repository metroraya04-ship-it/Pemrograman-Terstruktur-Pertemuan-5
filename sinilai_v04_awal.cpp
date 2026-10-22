#include <iostream>
#include <iomanip>
#include <string>
#include <limits>

using namespace std;

int main() {
    int jumlah_mahasiswa;

    do {
        cout << "Masukkan jumlah mahasiswa (minimal 1): ";
        cin >> jumlah_mahasiswa;

        if (jumlah_mahasiswa < 1) {
            cout << "Jumlah mahasiswa harus minimal 1!\n";
        }

    } while (jumlah_mahasiswa < 1);

    double total_nilai = 0;
    int jumlah_lulus = 0;

    for (int i = 1; i <= jumlah_mahasiswa; i++) {

        string nama;
        double nilai_tugas, nilai_uts, nilai_uas;
        double nilai_akhir;
        char huruf;
        double mutu;
        string keterangan;
        bool lulus;

        cout << "Mahasiswa ke-" << i << '\n';

        cout << "Masukkan nama mahasiswa: ";
        getline(cin >> ws, nama);

        cout << "Masukkan nilai tugas: ";
        cin >> nilai_tugas;

        cout << "Masukkan nilai UTS: ";
        cin >> nilai_uts;

        cout << "Masukkan nilai UAS: ";
        cin >> nilai_uas;

        nilai_akhir =
            (0.30 * nilai_tugas) +
            (0.30 * nilai_uts) +
            (0.40 * nilai_uas);

        if (nilai_akhir >= 85) {
            huruf = 'A';
            mutu = 4.0;
        } else if (nilai_akhir >= 80) {
            huruf = 'B';
            mutu = 3.5;
        } else if (nilai_akhir >= 75) {
            huruf = 'B';
            mutu = 3.0;
        } else if (nilai_akhir >= 70) {
            huruf = 'C';
            mutu = 2.5;
        } else if (nilai_akhir >= 60) {
            huruf = 'C';
            mutu = 2.0;
        } else if (nilai_akhir >= 50) {
            huruf = 'D';
            mutu = 1.0;
        } else {
            huruf = 'E';
            mutu = 0.0;
        }

        lulus = (nilai_akhir >= 60);

        if (lulus) {
            keterangan = "Lulus";
        } else {
            keterangan = "Belum lulus";
        }

        cout << fixed << setprecision(2);

        cout << "\nKARTU NILAI\n";
        cout << "Nama          : " << nama << '\n';
        cout << "Nilai tugas   : " << nilai_tugas << '\n';
        cout << "Nilai UTS     : " << nilai_uts << '\n';
        cout << "Nilai UAS     : " << nilai_uas << '\n';
        cout << "Nilai akhir   : " << nilai_akhir << '\n';
        cout << "Nilai huruf   : " << huruf << '\n';
        cout << "Nilai mutu    : " << mutu << '\n';
        cout << "Keterangan    : " << keterangan << '\n';

        total_nilai += nilai_akhir;

        if (lulus) {
            jumlah_lulus++;
        }

    }

    int jumlah_belum_lulus = jumlah_mahasiswa - jumlah_lulus;

    double rata_rata = total_nilai / jumlah_mahasiswa;

    cout << fixed << setprecision(3);

    cout << "           REKAP KELAS\n";

    cout << "Jumlah mahasiswa : " << jumlah_mahasiswa << '\n';
    cout << "Lulus            : " << jumlah_lulus << '\n';
    cout << "Belum lulus      : " << jumlah_belum_lulus << '\n';
    cout << "Rata-rata kelas  : " << rata_rata << '\n';

    return 0;
}