#pragma once
#include <stdio.h>

#define HASH_TABLE_SIZ 100
#define MAX_VARS 200
#define MAX_VAR_NAME_LEN 100

struct hash_table{
  double values[HASH_TABLE_SIZ];
  char** keys;
  int table_size_;
};

struct hash_table* new_hash_table();
void destructor_(struct hash_table* map);


void insert(struct hash_table* map, char* key, double value);

double get_key(struct hash_table* map, char* key);
