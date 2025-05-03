//jangan dicopy plek ketiplek ya ges

#include "map.h"

Map *create_map(int capacity) {
    if (capacity <= 0){
        return NULL;
    }

    Map *map = (Map *)malloc(sizeof(Map));
    if (!map) {
        return NULL;
    }

    map->entries = (MapEntry *)malloc(sizeof(MapEntry) * capacity);
    if (!map->entries) {
        free(map);
        return NULL;
    }

    map->capacity = capacity;
    map->size = 0;
    return map;
}

bool map_insert(Map *map, int key, const char *value) {
    if (!map || !value || map->size >= map->capacity) {
        return false;
    }

    int kiri = 0;
    int kanan = map->size - 1;
    while (kiri <= kanan) {
        int tengah = (kiri + kanan) / 2;
        if (map->entries[tengah].key == key) {
            free(map->entries[tengah].value);
            map->entries[tengah].value = strdup(value);
            return map->entries[tengah].value != NULL;

        }else if (map->entries[tengah].key < key){
            kiri = tengah + 1;
        }else{
            kanan = tengah - 1;
        }
    }

    for (int i = map->size; i > kiri; --i) {
        map->entries[i] = map->entries[i - 1];
    }
    map->entries[kiri].key = key;
    map->entries[kiri].value = strdup(value);
    if (!map->entries[kiri].value){
        return false;
    }

    map->size++;
    return true;
}

char *map_get(const Map *map, int key) {
    if (!map) {
        return NULL;
    }

    int kiri = 0;
    int kanan = map->size - 1;
    while (kiri <= kanan) {
        int tengah = (kiri + kanan) / 2;
        if (map->entries[tengah].key == key){
            return map->entries[tengah].value;
        }else if (map->entries[tengah].key < key){
            kiri = tengah + 1;
        }else{
            kanan = tengah - 1;
        }
    }
    return NULL;
}

bool map_delete(Map *map, int key) {
    if (!map){
        return false;
    }

    int kiri = 0;
    int kanan = map->size - 1;
    while (kiri <= kanan) {
        int tengah = (kiri + kanan) / 2;
        if (map->entries[tengah].key == key) {
            free(map->entries[tengah].value);
            for (int i = tengah; i < map->size - 1; ++i) {
                map->entries[i] = map->entries[i + 1];
            }
            map->size--;
            return true;

        }else if (map->entries[tengah].key < key){
            kiri = tengah + 1;
        }else{
            kanan = tengah - 1;
        }
    }
    return false;
}

int map_size(const Map *map) {
    if (!map) {
        return NULL;
    }
    return map->size;
}

bool map_contains_key(const Map *map, int key) {
    if (!map) {
        return false;
    }

    int kiri = 0;
    int kanan = map->size - 1;
    while (kiri <= kanan) {
        int tengah = (kiri + kanan) / 2;
        if (map->entries[tengah].key == key){
            return true;
        }else if (map->entries[tengah].key < key){
            kiri = tengah + 1;
        }else{
            kanan = tengah - 1;
        }
    }
    return false;
}
