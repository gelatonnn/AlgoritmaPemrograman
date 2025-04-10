#include "NimonsCafe.h"

PesananMinuman BuatPesanan(char *nama, char ukuran, TipeGula tGula, TipeEs tEs) {
    PesananMinuman p;
    strcpy(p.namaMinuman, nama);
    p.ukuran = ukuran;
    p.tipeGula = tGula;
    p.tipeEs = tEs;
    return p;
}

char *getNamaMinuman(PesananMinuman *p) {
    return p->namaMinuman;
}

void setNamaMinuman(PesananMinuman *p, char *nama) {
    strcpy(p->namaMinuman, nama);
}

char getUkuran(PesananMinuman p) {
    return p.ukuran;
}

void setUkuran(PesananMinuman *p, char ukuran) {
    p->ukuran = ukuran;
}

TipeGula getTipeGula(PesananMinuman p) {
    return p.tipeGula;
}

void setTipeGula(PesananMinuman *p, TipeGula tGula) {
    p->tipeGula = tGula;
}

TipeEs getTipeEs(PesananMinuman p) {
    return p.tipeEs;
}

void setTipeEs(PesananMinuman *p, TipeEs tEs) {
    p->tipeEs = tEs;
}

void TulisPesanan(PesananMinuman p) {
    char *gula;
    if (p.tipeGula == LESS_SUGAR) gula = "less sugar";
    else if (p.tipeGula == NORMAL_SUGAR) gula = "normal sugar";
    else gula = "extra sugar";

    char *es;
    if (p.tipeEs == LESS_ICE) es = "less ice";
    else if (p.tipeEs == NORMAL_ICE) es = "normal ice";
    else es = "no ice";

    printf("%s - %c - %s, %s\n", p.namaMinuman, p.ukuran, gula, es);
}

int TotalKalori(PesananMinuman p) {
    int kaloriGelas = 0;
    if (p.ukuran == 'S') kaloriGelas += 100;
    else if (p.ukuran == 'M') kaloriGelas += 150;
    else if (p.ukuran == 'L') kaloriGelas += 200;

    if (p.tipeGula == LESS_SUGAR) kaloriGelas += 10;
    else if (p.tipeGula == NORMAL_SUGAR) kaloriGelas += 20;
    else if (p.tipeGula == EXTRA_SUGAR) kaloriGelas += 40;

    return kaloriGelas;
}

int VolumeBersih(PesananMinuman p) {
    int volumeGelas = 0;
    if (p.ukuran == 'S') volumeGelas = 240;
    else if (p.ukuran == 'M') volumeGelas = 360;
    else if (p.ukuran == 'L') volumeGelas = 480;

    float persentaseEs = 0.0;
    if (p.tipeEs == NORMAL_ICE) persentaseEs = 0.25;
    else if (p.tipeEs == LESS_ICE) persentaseEs = 0.10;
    else if (p.tipeEs == NO_ICE) persentaseEs = 0.0;

    int volumeBersih = volumeGelas - (int)(volumeGelas * persentaseEs);
    return volumeBersih;
}
