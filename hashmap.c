#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define INITIAL_SIZE 100

// The value of a hashmap key can be any type
typedef void *any_t;

// The type of the map is abstracted from the client - it is an internally maintained data structure
typedef any_t map_t;

// A hashmap_item is a key-value type. Defined as a pointer to not accidentally pass by value and inefficiently use memory
typedef struct _hashmap_item {
	char *key;
	any_t data;
} *hashmap_item;

// A hashmap is an array of hashmap_items + variables to hold the current size and max size
typedef struct _hashmap {
	unsigned int size;
	unsigned int map_size;
	hashmap_item items;
} *hashmap;

// Allocates memory for a new hashmap with INITIAL_SIZE
map_t hashmap_new() {
	hashmap map = malloc(sizeof(hashmap));
	if(map == NULL) return NULL;

	map->items = calloc(INITIAL_SIZE, sizeof(hashmap_item));
	if(map->items == NULL) return NULL;

	map->map_size = INITIAL_SIZE;

	return map;
}

// Frees the hashmap from memory
void hashmap_free(map_t map) {
	// need to cast to access items, since map_t is a void pointer
	hashmap m = (hashmap) map;
	free(m->items);
	free(m);
}

int main() {
	map_t map = hashmap_new();
	assert(map != NULL);
	hashmap_free(map);

	return 0;
}