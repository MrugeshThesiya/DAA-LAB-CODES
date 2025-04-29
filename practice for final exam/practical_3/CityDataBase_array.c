#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX_CITIES 100

typedef struct {
    char city_name[100];
    int x, y;
} City;

City city_db[MAX_CITIES];
int city_count = 0;

void insert_record(char* name, int x, int y) {
    if (city_count < MAX_CITIES) {
        strcpy(city_db[city_count].city_name, name);
        city_db[city_count].x = x;
        city_db[city_count].y = y;
        city_count++;
    } else {
        printf("Database full. Cannot insert more records.\n");
    }
}

void delete_record_by_name(char* name) {
    int i, found = 0;
    for (i = 0; i < city_count; i++) {
        if (strcmp(city_db[i].city_name, name) == 0) {
            found = 1;
            break;
        }
    }
    if (found) {
        for (int j = i; j < city_count - 1; j++) {
            city_db[j] = city_db[j + 1];
        }
        city_count--;
        printf("Record for %s deleted.\n", name);
    } else {
        printf("City not found.\n");
    }
}

void delete_record_by_coordinates(int x, int y) {
    int i, found = 0;
    for (i = 0; i < city_count; i++) {
        if (city_db[i].x == x && city_db[i].y == y) {
            found = 1;
            break;
        }
    }
    if (found) {
        for (int j = i; j < city_count - 1; j++) {
            city_db[j] = city_db[j + 1];
        }
        city_count--;
        printf("Record with coordinates (%d, %d) deleted.\n", x, y);
    } else {
        printf("City with the given coordinates not found.\n");
    }
}

void search_by_name(char* name) {
    for (int i = 0; i < city_count; i++) {
        if (strcmp(city_db[i].city_name, name) == 0) {
            printf("City found: %s, Coordinates: (%d, %d)\n", city_db[i].city_name, city_db[i].x, city_db[i].y);
            return;
        }
    }
    printf("City not found.\n");
}

void search_by_coordinates(int x, int y) {
    for (int i = 0; i < city_count; i++) {
        if (city_db[i].x == x && city_db[i].y == y) {
            printf("City found: %s, Coordinates: (%d, %d)\n", city_db[i].city_name, city_db[i].x, city_db[i].y);
            return;
        }
    }
    printf("City with the given coordinates not found.\n");
}

void list_within_distance(int x, int y, int distance) {
    printf("Cities within %d distance from point (%d, %d):\n", distance, x, y);
    for (int i = 0; i < city_count; i++) {
        int dist = sqrt(pow(city_db[i].x - x, 2) + pow(city_db[i].y - y, 2));
        if (dist <= distance) {
            printf("%s, Coordinates: (%d, %d)\n", city_db[i].city_name, city_db[i].x, city_db[i].y);
        }
    }
}

int main() {
    insert_record("City A", 5, 5);
    insert_record("City B", 10, 10);
    insert_record("City C", 15, 15);

    search_by_name("City A");
    search_by_coordinates(10, 10);

    printf("\n");

    delete_record_by_name("City B");
    delete_record_by_coordinates(15, 15);

    printf("\n");

    list_within_distance(0, 0, 10);

    return 0;
}
