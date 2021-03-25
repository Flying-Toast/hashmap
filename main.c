#include <string.h>
#include <stdio.h>
#include "hashmap.h"

#define ARRAY_SIZE(array) (sizeof(array) / sizeof(array[0]))

struct person {
	unsigned age;
	unsigned height;
	char *name;
};

void print_person(const struct person *p)
{
	printf("%s:\n\tage: %u\n\theight: %u\n", p->name, p->age, p->height);
}

int main(void)
{
	//key: char *, value: struct person *
	struct hashmap hm;
	init_hashmap(&hm, 1000);

	struct person bob = {
		.age = 12,
		.height = 160,
		.name = "Bob Jones",
	};
	struct person alex = {
		.age = 36,
		.height = 153,
		.name = "Alex Johnson",
	};
	struct person peter = {
		.age = 68,
		.height = 130,
		.name = "Peter Peterson",
	};

	hashmap_set(&hm, hash_bytes(bob.name, strlen(bob.name)), &bob);
	hashmap_set(&hm, hash_bytes(alex.name, strlen(alex.name)), &alex);
	hashmap_set(&hm, hash_bytes(peter.name, strlen(peter.name)), &peter);

	const char *names[] = {
		"Bob Jones",
		"Alex Johnson",
		"Peter Peterson",
	};

	for (size_t i = 0; i < ARRAY_SIZE(names); i++) {
		struct person *p = hashmap_get(&hm, hash_bytes(names[i], strlen(names[i])));
		if (!p) {
			printf("Oops\n");
			continue;
		}
		print_person(p);
	}

	release_hashmap(&hm);
}
