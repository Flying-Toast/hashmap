#include <stdlib.h>
#include <stdint.h>
#include "hashmap.h"

void init_hashmap(struct hashmap *hm, size_t arraysize)
{
	hm->size = arraysize;
	hm->entries = calloc(arraysize, sizeof(void *));
}

void release_hashmap(struct hashmap *hm)
{
	if (hm->entries) {
		free(hm->entries);
		hm->entries = NULL;
	}
}

void *hashmap_get(const struct hashmap *hm, hash_t key_hash)
{
	return hm->entries[key_hash % hm->size];
}

void hashmap_set(struct hashmap *hm, hash_t key_hash, void *value)
{
	hm->entries[key_hash % hm->size] = value;
}

hash_t hash_bytes(const void *bytes, size_t nbytes)
{
	hash_t hash = 5381;
	for (size_t i = 0; i < nbytes; i++)
		hash = ((hash << 5) + hash) + ((uint8_t *) bytes)[i];
	return hash;
}
