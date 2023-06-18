#ifndef VECTOR_H_
#define VECTOR_H_

#include <stddef.h>
#include <stdbool.h>

typedef struct {
    void **items;
    size_t capacity;
    size_t size;
} Vector;


/**
 * initialize vector
 * @param Vector pointer to struct vector
 * @param size_t size of desired capacity
 */
void vectorInit(Vector *vec, const size_t initialCapacity);


/**
 * Get size of vector
 * @param Vector pointer to struct vector
 */
size_t vectorGetSize(const Vector *const v);


/**
 * Check vector if it is empty
 * @param Vector pointer to struct vector
 */
bool vectorIsEmpty(const Vector *const vec);


/**
 * Realloc more memory
 * @param Vector pointer to struct vector
 * @param size_t new desired size of capacity
 */
void vectorResize(Vector *vec, const size_t capacity);


/**
 * Add element in vector on next index
 * @param Vector pointer to struct vector
 * @param Element void pointer to item
 */
void vectorPush(Vector *vec, void *item);


/**
 * Add element in vector on desired index position
 * @param Vector pointer to struct vector
 * @param Size_t desired index
 * @param Element void pointer to item
 */
void vectorSet(Vector *const vec, const size_t idx, void *item);


/**
 * Get element in vector from desired index position
 * @param Vector pointer to struct vector
 * @param Size_t desired index
 */
void* vectorGet(const Vector *const vec, const size_t idx);


/**
 * Get last element in vector
 * @param Vector pointer to struct vector
 */
void* vectorBack(const Vector *const vec);


/**
 * Delete element on wanted index
 * @param Vector pointer to struct vector
 * @param Size_t desired index
 */
void vectorDelete(Vector *const vec, const size_t idx);


/**
 * Decreise size of vector
 * @param Vector pointer to struct vector
 */
void vectorPop(Vector *const vec);


/**
 * Free allocated memory
 * @param Vector pointer to struct vector
 */
void vectorFree(Vector *vec);



#endif /* VECTOR_H_ */
