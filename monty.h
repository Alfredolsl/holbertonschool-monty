#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct argument_s - decleration
 * @buffer: store line temporarily
 * @token: string buffer for strok
 * @fd: file descriptor
 * @f: function to handle opcode
 * @top: stack
 */
typedef struct arg_s
{
	char *buffer, *token;
	FILE *fd;
	void (*f)(stack_t **stack, unsigned int line_number);
	stack_t *top;
} arg_t;
extern arg_t arguments;
arg_t arguments;

/* parsing functions */
void validate_args(int ac, char **av);
void tokenize_line(void);
void free_stack(void);
int is_digit(char *number);
void (*get_op(char *str, unsigned int line_number))(stack_t **, unsigned int);

/* error functions */
void push_error(unsigned int line_number);
void instruction_error(char *tokenizer, unsigned int line_number);


/* command functions */
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);

#endif
