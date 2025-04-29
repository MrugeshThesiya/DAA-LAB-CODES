#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct City {
    char city_name[100];
    int x, y;
    struct City* next;
} City;

City* city_db = NULL;

void insert_record(char* name, int x, int y) {
    City* new_city = (City*)malloc(sizeof(City));
    strcpy(new_city->city_name, name);
    new_city->x = x;
    new_city->y = y;
    new_city->next = city_db;
    city_db = new_city;
}

void delete_record_by_name(char* name) {
    City* current = city_db;
    City* prev = NULL;
    while (current != NULL) {
        if (strcmp(current->city_name, name) == 0) {
            if (prev == NULL) {
                city_db = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            printf("Record for %s deleted.\n", name);
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("City not found.\n");
}

void delete_record_by_coordinates(int x, int y) {
    City* current = city_db;
    City* prev = NULL;
    while (current != NULL) {
        if (current->x == x && current->y == y) {
            if (prev == NULL) {
                city_db = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            printf("Record with coordinates (%d, %d) deleted.\n", x, y);
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("City with the given coordinates not found.\n");
}

void search_by_name(char* name) {
    City* current = city_db;
    while (current != NULL) {
        if (strcmp(current->city_name, name) == 0) {
            printf("City found: %s, Coordinates: (%d, %d)\n", current->city_name, current->x, current->y);
            return;
        }
        current = current->next;
    }
    printf("City not found.\n");
}

void search_by_coordinates(int x, int y) {
    City* current = city_db;
    while (current != NULL) {
        if (current->x == x && current->y == y) {
            printf("City found: %s, Coordinates: (%d, %d)\n", current->city_name, current->x, current->y);
            return;
        }
        current = current->next;
    }
    printf("City with the given coordinates not found.\n");
}

void list_within_distance(int x, int y, int distance) {
    printf("Cities within %d distance from point (%d, %d):\n", distance, x, y);
    City* current = city_db;
    while (current != NULL) {
        int dist = sqrt(pow(current->x - x, 2) + pow(current->y - y, 2));
        if (dist <= distance) {
            printf("%s, Coordinates: (%d, %d)\n", current->city_name, current->x, current->y);
        }
        current = current->next;
    }
}

int main() {
    insert_record("City A", 25, 25);
    insert_record("City B", 10, 10);
    insert_record("City C", 15, 15);

    search_by_name("City C");
    search_by_coordinates(10, 10);

    printf("\n");

    delete_record_by_name("City B");
    delete_record_by_coordinates(25, 25);

    printf("\n");

    list_within_distance(0, 0, 50);

    return 0;
}
