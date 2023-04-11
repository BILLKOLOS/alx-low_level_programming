#include "hash_tables.h"

/**
 * hash_table_set - Add or update an element in a hash table.
 * @ht: A pointer to the hash table.
 * @key: The key to add - cannot be an empty string.
 * @value: The value associated with key.
 *
 * Return: Upon failure - 0.
 *         Otherwise - 1.
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
    if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
        return 0;

    /* Calculate hash value using a simple hash function */
    unsigned long int hash_value = 0;
    unsigned int i = 0;
    while (key[i] != '\0')
    {
        hash_value += key[i];
        i++;
    }

    /* Calculate index within the hash table */
    unsigned long int index = hash_value % ht->size;

    /* Check if key already exists in the hash table */
    hash_node_t *node = ht->array[index];
    while (node != NULL)
    {
        if (strcmp(node->key, key) == 0)
        {
            /* Update value for existing key */
            free(node->value);
            node->value = strdup(value);
            if (node->value == NULL)
                return 0;
            return 1;
        }
        node = node->next;
    }

    /* Create a new hash node */
    hash_node_t *new_node = malloc(sizeof(hash_node_t));
    if (new_node == NULL)
        return 0;
    new_node->key = strdup(key);
    if (new_node->key == NULL)
    {
        free(new_node);
        return 0;
    }
    new_node->value = strdup(value);
    if (new_node->value == NULL)
    {
        free(new_node->key);
        free(new_node);
        return 0;
    }
    new_node->next = ht->array[index];
    ht->array[index] = new_node;

    return 1;
}

