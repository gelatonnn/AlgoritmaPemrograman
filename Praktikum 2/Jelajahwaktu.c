#include <stdio.h>
#include <string.h>

typedef struct {
    int day; //Menyimpan hari
    int month; //Menyimpan bulan
    int year; //Menyimpan tahun
} Date;

int isLeapYear(int year) { //Berfungsi untuk memeriksa apakah tahun yang dimasukan kabisat atau bukan
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
    //Jika habis dibagi 4, tetapi bukan kelipatan 100 atau habis dibagi 400, maka tahun tersebut adalah kabisat
        return 1;
    }
    return 0;
}

int getDaysInMonth(int month, int year) { //Mendapatkan jumlah hari dalam setiap bulan
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};//Array untuk menyimpan jumlah hari dalam setiap bulan
    if (month == 2 && isLeapYear(year)) {
        return 29; //Jika tahun kabisat, februari memiliki 29 hari
    }
    return daysInMonth[month - 1]; //Jika bukan, maka 28 hari (29-1)
}

Date addDays(Date date, int n) {
    while (n > 0) { //Loop yg akan terus berjalan hingga semua n (hari) telah ditambahkan
        int daysInCurrentMonth = getDaysInMonth(date.month, date.year);
        //date.month untuk mendapatkan jumlah hari di bulan saat ini
        if (date.day + n <= daysInCurrentMonth) {
            date.day += n; //Jika jumlah hari yg ditambah masih dalam range bulan ini, maka langsung ditambahkan dan keluar dari loop
            break;
        } else { //Jika melebihi jumlah hari dalam bulan inputan
            n -= (daysInCurrentMonth - date.day + 1); //mengurangi n (hari) dengan sisa hari di bulan ini
            date.day = 1; //mereset hari 
            date.month++; //pindah ke bulan berikutnya
            if (date.month > 12) { //jika bulan lebih dari Desember
                date.month = 1; //reset ke januari 
                date.year++; //menambahkan 1 tahun
            }
        }
    }
    return date;
}

int getDayOfWeekAsIndex(Date date) { //Fungsi untuk menghitung indeks (hari) dalam 1 minggu
    int totalDays = 0; //variabel utk menyimpan jumlah hari sejak 1 januari tahun 1
    for (int y = 1; y < date.year; y++) { //Loop untuk menghitung jumlah hari dari 1 tahun hingga tahun input
        totalDays += isLeapYear(y) ? 366 : 365; //menambahkan 366 hari jika kabisat, dan 365 hari jika tidak
    }
    for (int m = 1; m < date.month; m++) { //Loop untuk menambahkan jumlah hari dalam bulan sebelum bulan saat ini
        totalDays += getDaysInMonth(m, date.year);
    }
    totalDays += date.day - 1; //menambahkan jumlah hari dalam bulan saat ini
    return (totalDays + 1) % 7; //menghitung hari dalam 1 minggu
}


static const char *months[] = {"Januari",   "Februari", "Maret",    "April",
                               "Mei",       "Juni",     "Juli",     "Agustus",
                               "September", "Oktober",  "November", "Desember"};
static const char *days[] = {"Minggu", "Senin", "Selasa", "Rabu",
                             "Kamis",  "Jumat", "Sabtu"};

const char *getDayOfWeek(Date date) {
    int dayIndex = getDayOfWeekAsIndex(date);
    return days[dayIndex];
}
/*Array untuk menyimpan nama hari*/

void printDate(Date date) {
    printf("%s, %d %s %d\n", getDayOfWeek(date), date.day,
           months[date.month - 1], date.year);
}
/*Array untuk menyimpan nama bulan dan mencetak tanggal dalam format 
Hari, Tanggal, Bulan, Tahun*/


int getMonthNumber(const char *monthStr) {//Loop untuk mencocokan monthStr dengan bulan dalam array months[]
    for (int i = 0; i < 12; i++) {
        if (strcmp(monthStr, months[i]) == 0) {
            return i + 1;
        }
    }
    return -1; //jika bulan tidak valid
}

Date parseDate(const char *dateStr) {
    Date date;
    char monthStr[10]; //Variabel untuk menyimpan nama bulan yg akan dikonversi
    sscanf(dateStr, "%d %s %d", &date.day, monthStr, &date.year);
    date.month = getMonthNumber(monthStr); //mengkonversi monthStr ke angka bulan

    if (date.month == -1) {
        printf("Bulan tidak valid!\n");
    }
    return date;
}

int main() {
    char inputDate[30];//menyimpan input tanggal
    int n; //menyimpan jumlah hari yg akan ditambah

    fgets(inputDate, sizeof(inputDate), stdin);
    inputDate[strcspn(inputDate, "\n")] = 0;
    scanf("%d", &n); //membaca input tanggal dan jumlah hari dari pengguna

    Date date; //mengkonversi input ke struct date
    date = parseDate(inputDate);

    date = addDays(date, n); //menambahkan "n" hari
    printDate(date); //print hasil

    return 0;
}
