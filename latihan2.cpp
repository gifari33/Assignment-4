#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

// Fungsi utama untuk membaca file CSV, memodifikasi kolom tokens, dan menyimpan ke file baru
void modifyAndSaveCSV(const string &inputPath, const string &outputPath) {
    ifstream inputFile(inputPath);
    ofstream outputFile(outputPath);

    if (!inputFile.is_open()) {
        cerr << "Gagal membuka file input: " << inputPath << endl;
        return;
    }
    if (!outputFile.is_open()) {
        cerr << "Gagal membuka file output: " << outputPath << endl;
        return;
    }

    string line;
    bool isHeader = true;

    // Membaca file baris per baris
    while (getline(inputFile, line)) {
        stringstream ss(line);
        string userName, content, score, at, appVersion, tokens;

        // Parse setiap kolom berdasarkan delimiter ','
        getline(ss, userName, ',');
        getline(ss, content, ',');
        getline(ss, score, ',');
        getline(ss, at, ',');
        getline(ss, appVersion, ',');

        // Karena kolom `tokens` bisa mengandung tanda koma, baca seluruh sisa baris sebagai tokens
        getline(ss, tokens);

        if (isHeader) {
            // Tulis header tanpa perubahan
            outputFile << line << endl;
            isHeader = false;
            continue;
        }

        // Tambahkan tanda kutip ganda di sekitar kolom tokens
        tokens = "\"" + tokens + "\"";

        // Tulis data ke file output
        outputFile << userName << "," << content << "," << score << "," << at << "," << appVersion << "," << tokens << endl;
    }

    inputFile.close();
    outputFile.close();
    cout << "Proses selesai! Hasil disimpan ke: " << outputPath << endl;
}

int main() {
    // Path ke file CSV input dan output
    string inputPath = R"(J:\Drive Saya\analisa sentimen git\percobaan 12\tokens.csv)";
    string outputPath = R"(J:\Drive Saya\analisa sentimen git\percobaan 12\tokens_modified.csv)";

    // Proses file CSV dan simpan hasil
    modifyAndSaveCSV(inputPath, outputPath);

    return 0;
}
