#include "album.h"

void CreateEmptyAlbum(Album *A){
    A->Count = Nil;
}

boolean IsEmptyAlbum(Album A){
    return A.Count == Nil;
}

boolean IsFullAlbum(Album A){
    return A.Count == MaxElSong;
}

boolean IsSongInAlbum(Album A, char SongTitle[]){
    for (int i = 0; i < A.Count; i++) {
        if (strcmp(A.Songs[i], SongTitle) == 0) {
            return true;
        }
    }
    return false;
}

int cmpstr(const void *a, const void *b){
    const char *sa = (const char *)a;
    const char *sb = (const char *)b;
    return strcmp(sa, sb);
}

void SortAlbum(Album *A){
    qsort((*A).Songs, (*A).Count, sizeof((*A).Songs[0]), cmpstr);
}

void InsertSong(Album *A, char SongTitle[]) {
    if (!IsFullAlbum(*A) && !IsSongInAlbum(*A, SongTitle)) {
        strcpy(A->Songs[A->Count], SongTitle);
        A->Count++;
        SortAlbum(A);
    }
}

void DeleteSong(Album *A, char SongTitle[]){
    for (int i = 0; i < A->Count; i++) {
        if (strcmp(A->Songs[i], SongTitle) == 0) {
            for (int j = i; j < A->Count - 1; j++) {
                strcpy(A->Songs[j], A->Songs[j + 1]);
            }
            A->Count--;
            break;
        }
    }
}

Album UnionAlbum(Album A1, Album A2){
    Album hasil;
    CreateEmptyAlbum(&hasil);

    for (int i = 0; i < A1.Count; i++) {
        InsertSong(&hasil, A1.Songs[i]);
    }
    for (int i = 0; i < A2.Count; i++) {
        InsertSong(&hasil, A2.Songs[i]);
    }
    return hasil;
}

Album IntersectionAlbum(Album A1, Album A2){
    Album hasil;
    CreateEmptyAlbum(&hasil);

    for (int i = 0; i < A1.Count; i++) {
        if (IsSongInAlbum(A2, A1.Songs[i])) {
            InsertSong(&hasil, A1.Songs[i]);
        }
    }
    return hasil;
}

Album DifferenceAlbum(Album A1, Album A2){
    Album hasil;
    CreateEmptyAlbum(&hasil);

    for (int i = 0; i < A1.Count; i++) {
        if (!IsSongInAlbum(A2, A1.Songs[i])) {
            InsertSong(&hasil, A1.Songs[i]);
        }
    }
    return hasil;
}

void PrintAlbum(Album A){
    SortAlbum(&A);
    printf("{");
    for (int i = 0; i < A.Count; i++) {
        printf("%s", A.Songs[i]);
        if (i < A.Count - 1) {
            printf(", ");
        }
    }
    printf("}\n");
}
