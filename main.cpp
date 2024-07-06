#include <iostream>
#include <fstream>
#include <curl/curl.h>
#include <string>
#include <regex>

// Fungsi callback untuk menangani respons dari libcurl
size_t writeCallback(void *contents, size_t size, size_t nmemb, std::string *buffer) {
    buffer->append((char *)contents, size * nmemb);
    return size * nmemb;
}

// Fungsi untuk mendeteksi SQL Injection
bool detectSQLInjection(const std::string &response) {
    // Pola-pola yang mencurigakan untuk SQL Injection
    std::regex sqlInjectionRegex(R"((\b(AND|OR|SELECT|INSERT INTO|VALUES|UPDATE|DELETE FROM)\b|\b(UNION SELECT|ORDER BY|GROUP BY|FROM \s*\w* WHERE))\b)", std::regex_constants::icase);
    
    // Lakukan pencarian menggunakan regex
    if (std::regex_search(response, sqlInjectionRegex)) {
        return true;
    }
    
    return false;
}

int main() {
    CURL *curl;
    CURLcode res;
    std::string url;
    std::string input;
    bool scanning = true;

    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();

    while (scanning) {
        std::cout << "Menu:\n";
        std::cout << "1. Mulai scan\n";
        std::cout << "2. Berhenti scan\n";
        std::cout << "Pilih menu (1/2): ";
        std::getline(std::cin, input);

        if (input == "1") {
            // Meminta input URL target
            std::cout << "Masukkan URL target: ";
            std::getline(std::cin, url);

            std::string htmlFileName = "response.html";
            std::string txtFileName = "vulnerability.txt";

            std::ofstream htmlFile(htmlFileName);
            std::ofstream txtFile(txtFileName);

            curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallback);

            std::string responseData;
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &responseData);

            res = curl_easy_perform(curl);
            if (res != CURLE_OK) {
                std::cerr << "Failed to perform curl request: " << curl_easy_strerror(res) << std::endl;
            } else {
                // Simpan respons HTML ke file
                htmlFile << responseData << std::endl;
                std::cout << "Respons HTML telah disimpan di file: " << htmlFileName << std::endl;

                // Deteksi SQL Injection
                if (detectSQLInjection(responseData)) {
                    std::string vulnerabilityMessage = "Detected SQL Injection vulnerability!";
                    txtFile << vulnerabilityMessage << std::endl;
                    std::cout << "Pesan kerentanan telah disimpan di file: " << txtFileName << std::endl;
                } else {
                    std::string noVulnerabilityMessage = "No SQL Injection detected.";
                    txtFile << noVulnerabilityMessage << std::endl;
                    std::cout << "Pesan kerentanan telah disimpan di file: " << txtFileName << std::endl;
                }
            }

            htmlFile.close();
            txtFile.close();
        } else if (input == "2") {
            scanning = false;
        } else {
            std::cout << "Pilihan tidak valid. Silakan pilih 1 atau 2." << std::endl;
        }
    }

    curl_easy_cleanup(curl);
    curl_global_cleanup();
    return 0;
}
