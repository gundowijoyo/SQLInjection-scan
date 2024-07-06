## Tools SQL Injection Scanner CLI
## Deskripsi
Program ini merupakan sebuah aplikasi CLI (Command-Line Interface) sederhana untuk mendeteksi kerentanan SQL Injection pada sebuah URL target. Program menggunakan libcurl untuk mengambil respons dari server, kemudian menganalisis respons tersebut menggunakan regular expression (regex) untuk mencari pola-pola yang mencurigakan terkait SQL Injection.

## Fitur
- Meminta input URL target dari pengguna.
- Mengambil respons HTML dari URL target menggunakan libcurl.
- Menganalisis respons HTML untuk mendeteksi SQL Injection menggunakan regex.
- Menyimpan respons HTML ke dalam file response.html.
- Menyimpan pesan kerentanan (detected atau not detected) ke dalam file vulnerability.txt.

## Penggunaan
1. Pastikan komputer Anda terhubung ke internet.
2. Jalankan program dengan menjalankan executable yang telah dikompilasi (jika belum dikompilasi, Anda dapat mengompilasinya menggunakan g++).
3. Pilih opsi dari menu:
   - **1. Mulai scan**: Program akan meminta Anda untuk memasukkan URL target. Setelah mendapatkan respons dari URL tersebut, program akan menyimpan respons HTML ke file `response.html` dan menyimpan pesan kerentanan ke file `vulnerability.txt`.
   - **2. Berhenti scan**: Mematikan program.

## Instalasi dengan Skrip Bash
1. Clone repository ini:
   ```bash
   git clone https://github.com/gundowijoyo/SQLInjection-scan.git
   cd SQLInjection-scan
   ```
 - Jalanlan skrip instalasi 
   ```
   bash install.sh
   ```
- Mulai menjalankan program
- ```
  ./sql_injection_scanner
  ```
## Kontribusi
- Jika Anda ingin berkontribusi pada pengembangan program ini, silakan lakukan fork dari repository ini, lakukan perubahan, dan ajukan pull request.
- Masukkan kritik dan saran konstruktif melalui isu (issue) untuk membantu perbaikan program.

## Donate
- <a href="https://saweria.co/Gundo">visit saweria me</a>

- Thank you for your support and donate.🙏🤩

- Terimakasih atas dukungan dan support kalian semuanya. Nantikan program-program terbaru yang akan saya buat dan saya berusaha semaksimal mungkin untuk membuat program yang sangat bermanfaat bagi anda semua.

---
© 2024 Gundo Wijoyo.Sangat Berbahagia🤩 untuk menjaga keamanan web.

