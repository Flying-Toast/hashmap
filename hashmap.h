#ifndef __HAVE_HASHMAP_H
#define __HAVE_HASHMAP_H

#include <sys/types.h>

struct hashmap {
	void **entries;
	size_t size;
};

typedef unsigned long hash_t;

void init_hashmap(struct hashmap *, size_t);
void release_hashmap(struct hashmap *);
void *hashmap_get(const struct hashmap *, hash_t);
void hashmap_set(struct hashmap *, hash_t, void *);
hash_t hash_bytes(const void *, size_t);

#endif
