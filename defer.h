/*
** About this library:
**  A C library to solve memory-leaks problems. Most of the time we allocate memory and later forget to deallocate it. These creates 
**  memory leaks. To solve this, other languages have `destructors` or `defer` that gets executed while a blocks ends or function returns.
**  To emulate such memory-leaks this library provides an `defer` like solution.
**
**  After allocating memory, an user can call `deferg()` function to appends the memory address into a inbuilt linked list. 
**  Now while using `deferg()`, calling a `deferg_free()` will deallocate all the memories in inbuilt linked list.
**  `deferg()` is used for global level variables.
**  whereas `deferl()` can be used for local-scope level varibales.
**
**  It is always easy to add the pointers during allocation and calling one fucntion to free all rather than freeing then later manually.
**  
** Author: xunicatt
** Github: https://github.com/xunicatt
*/

#ifndef __C_DEFER_H__
#define __C_DEFER_H__
#define C_DEFER_VER "1.0.0"
#define C_DEFER_VER_MAJ 1
#define C_DEFER_VER_MIN 0
#define C_DEFER_VER_PATCH 0

#include <stdlib.h>

/*
** @brief Abstracted Defer Struct
*/
typedef struct defer_data_t defer_data_t;

/*
** @brief free_function_t
*/
typedef void (free_function_t)(void*);

/*
** @brief deferg stands for defer-global used for global variables. 
** @brief Add all pointers to deferg and call `deferg_free` to unallocate all space at once.
** @param pointer_to_free Pass the pointer to free while calling `deferg_free`
** @param function_to_call Pass the function to call to free the pointer. Pass `NULL` to use `free()` from `stdlib.h` by default.
*/
void deferg(void*, free_function_t *);

/*
** @brief deferl stands for defer-local used for local variables. Use `defer_data_t*` to append pointers to it.
** @brief Add all pointers to deferl and call `deferl_free` to unallocates all space at once.
** @param defer_data_t* Pass the `defer_data_t*` to append all the pointer t free while calling `deferl_free`. Pass `NULL` to get and initialised defer-list.
** @param pointer_to_free Pass the pointer to free while calling `deferl_free`
** @param function_to_call Pass the function to call to free the pointer. Pass `NULL` to use `free()` from `stdlib.h` by default.
*/
defer_data_t* deferl(defer_data_t*, void*, free_function_t *);

/*
** @brief use deferg_free to deallocate all the globally appended pointers using `deferg`. 
*/
void deferg_free(void);

/*
** @brief use deferl_free to deallocate all the locally appended pointers using `deferg`.
** @param defer_data_t* Pass the defer-list to deallocate.
*/
void deferl_free(defer_data_t*);

/*
** @brief a macro same as `deferg` but uses `free()` function from `stdlib.h` as default. 
** @param pointer_to_free Pass the pointer to free while calling `deferg_free`
*/
#define defergd(ptr) deferg((ptr), NULL)

/*
** @brief a macro same as `deferl` but uses `free()` function from `stdlib.h` as default. 
** @param defer_data_t* Pass the `defer_data_t*` to append all the pointer t free while calling `deferl_free`. Pass `NULL` to get and initialised defer-list.
** @param pointer_to_free Pass the pointer to free while calling `deferg_free`
*/
#define deferld(d, ptr) deferl((d), (ptr), NULL)

#endif
