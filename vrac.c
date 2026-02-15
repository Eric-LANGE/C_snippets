// bases

int calculus_and_return(int a, int b)
{
    return (a + b);
}

void assignment(void)
{
    int     a;
    int     b;
    char    c;

    a = 44;
    b = -2;
    c = 'A';

    {
        a = calculus_and_return(a, b);
        b = (a - 2) * 2;
    }
}

void call_function(void)
{
    int forty_two;

    forty_two = 42;
}

char condition(int nb)
{
    if (nb < 10)
    {
        nb = nb + 1;
    }
    if (nb < 10)
    {
        return ('1');
    }
    else
    {
        return ('2');
    }
}

void loop(void)
{
    int i;

    i = 0;
    while (i < 10)
    {
        i = i + 1;
    }
}

/*
** THE PROGRAM ALWAYS STARTS WITH MAIN FUNCTION
*/
int main(void)
{
	call_function();
	return (0);
}

// scopes
int function_1(int variable_1, int variable_2)
{
    int variable_3;
    
    variable_3 = variable_1 + variable_2;
    return (variable_3);
}

int main(void)
{
    int a;
    int b;

    b = 5;
    a = function_1(b, 2);

    return (0);
}


// Counter-Based Loop
int i = 0;
while (i < 5) { // The condition is a comparison
    printf("i is %d\n", i);
    i++; // The variable is changed inside the loop
}

// Flag-Based Loop
#include <stdbool.h> // For using bool, true, and false

bool running = true;
while (running) { // The condition checks the boolean variable
    printf("Running...\n");
    // Some logic might change the flag
    if (/* some condition is met */) {
        running = false;
    }
}

// Pointer-Based Loop
// Assuming 'node' is a pointer to a struct in a linked list
while (node) { // Equivalent to: while (node != NULL)
    printf("Node value: %d\n", node->value);
    node = node->next;
}

// Infinite Loop
while (1) { // 1 is always true
    printf("Looping forever...\n");
    if (/* some exit condition */) {
        break; // Exit the loop
    }
}

// Type Casting and Floating-Point Division
#include <stdio.h>

int main(void) {
    int i = 3;
    int j = 2;

    printf("%f\n", (float)i / j);

    return 0;
}

// reverse_string

#include <unistd.h>
#include <stdio.h>

void    ft_rev_char_tab(char *tab, int size)
{
        int     i;
        char    temp;

        i = 0;
        // On s'arrête à la moitié, sinon on inverse la chaîne deux fois (et elle revient à son état initial)
        while (i < size / 2)
        {
                temp = tab[i];
                tab[i] = tab[size - 1 - i];
                tab[size - 1 - i] = temp;
                i++;
        }
}

int     main(void)
{
        char    str[] = "Hello 42 !";
        printf("%s\n", str);
        // La longueur de "Hello 42 !" est de 10 caractères (sans compter le '\0')
        ft_rev_char_tab(str, 10);
        printf("%s\n", str);
        return (0);
}


/* read char
usage --> ./copycat < hello.txt
*/
#include <stdio.h>

int main(void) {
    int c; // Use 'int' to correctly handle the EOF value.

    while ((c = getchar()) != EOF) {
        putchar(c);
    }

    return 0;
}

// allocate memory
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *p = NULL;

    // 1. Allocate memory
    p = (int*)malloc(sizeof(int));

    // 2. Check if allocation was successful
    if (p == NULL) {
        fprintf(stderr, "Error: Memory allocation failed.\n");
        return 1; // Exit with an error code
    }

    // 3. Use the allocated memory
    *p = 42;
    printf("Successfully allocated memory.\n");
    printf("Value stored at the address %p is: %d\n", (void*)p, *p);

    // 4. Free the memory when done
    free(p);
    p = NULL; // Good practice to nullify pointer after freeing

    return 0; // Exit successfully
}

/*
sizeof(int): This operator calculates the amount of memory (in bytes) that one integer requires. This makes the code portable, as the size of an int can vary between systems (e.g., 4 bytes on most modern systems).

malloc(...): The malloc function (which stands for "memory allocation") is called with the number of bytes calculated by sizeof(int). It finds a free block of that size in the computer's memory (specifically, on the heap) and reserves it. It returns a void* (a generic pointer) to the beginning of this newly allocated block. If it fails to find enough memory, it returns NULL.

(int*): This is a type cast. Since malloc returns a generic void* pointer, this cast explicitly converts it to the type int* (a pointer to an integer) to match the type of our pointer p. While this cast is required in C++, it is optional in C, but many programmers include it for clarity.

p = ...: The memory address returned by malloc is assigned to the pointer p. Now, p holds the address of the block of memory that was just allocated. You can now use *p to access and modify the integer value stored at that location.

Complete Program: The logic is wrapped in a standard int main(void) function, making it a fully functional program.

Error Checking: It includes a critical if (p == NULL) block. malloc returns NULL if it cannot allocate the requested memory, and a robust program must always check for this failure.

Using the Memory: The program now actually uses the allocated memory by assigning a value (*p = 42) and printing it, demonstrating that the allocation worked.

Freeing Memory: It calls free(p) to release the memory back to the operating system. For every malloc, there should be a corresponding free to prevent memory leaks.

Pointer Nullification: After freeing, p is set to NULL. This prevents accidental use of a "dangling pointer" (a pointer that no longer points to valid memory).
*/

// pointer declaration and usage
#include <stdio.h>

// 1. DECLARATION: This function says it needs an ADDRESS of an integer.
// The local pointer variable is named 'p'.

void add_five(int *p) {
    // 2. USAGE: Inside the function, 'p' holds the address of 'my_number'.
    // '*p' means "go to that address and get the value".
    // So this line becomes: value_at_p = value_at_p + 5;
    *p = *p + 5; 
}

int main(void) {
    int my_number = 10;

    printf("Before: %d\n", my_number); // Prints 10

    // We pass the ADDRESS of my_number using the '&' operator.
    add_five(&my_number);

    printf("After: %d\n", my_number); // Prints 15
    return 0;
}

/*
Declaration (int *p): The * defines p as a pointer.

Usage (*p): The * is an action that fetches the value from the pointer's address.
*/

// print integer
#include <stdio.h>

int main() {
    int my_number = 42;
    printf("%d\n", my_number);
    return 0;
}

// ft_puchar for int 42
#include <unistd.h>

// A function to write a single character to the standard output.
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(void)
{
	int	number;
	char	tens_digit;
	char	units_digit;

	// 1. Store the integer 42 in a variable.
	number = 42;

	// 2. Isolate the tens digit and convert it to its character equivalent.
	//    42 / 10 = 4
	//    '0' + 4 = '4'
	tens_digit = '0' + (number / 10);

	// 3. Isolate the units digit and convert it to its character equivalent.
	//    42 % 10 = 2
	//    '0' + 2 = '2'
	units_digit = '0' + (number % 10);

	// 4. Print the characters one by one.
	ft_putchar(tens_digit);
	ft_putchar(units_digit);
	ft_putchar('\n'); // Add a newline for cleaner terminal output

	return (0);
}

// storing strings, when C has no built-in string type
// The Character Array char[]
#include <stdio.h>
#include <string.h>

int main() {
    // Declares an array of 20 chars and copies "Hello" into it.
    // The memory layout is: H e l l o \0 ... (14 empty slots)
    char greeting[20] = "Hello";

    printf("Initial string: %s\n", greeting);

    // This is LEGAL because 'greeting' is a mutable array we own.
    strcpy(greeting, "World"); 
    
    printf("Modified string: %s\n", greeting); // Prints "World"

    return 0;
}

// The Character Pointer char *
#include <stdio.h>

int main() {
    // 'greeting_ptr' points to the address of the read-only literal "Hello".
    char *greeting_ptr = "Hello";

    printf("String: %s\n", greeting_ptr);
    
    // You can make the pointer point to a different string.
    greeting_ptr = "World";
    printf("Pointer now points to: %s\n", greeting_ptr);

    // This is ILLEGAL and will likely crash your program.
    // greeting_ptr[0] = 'J'; // CRASH! Trying to modify read-only memory.

    return 0;
}

// print string
#include <stdio.h>

// 'const' is a promise that this function will not change the string.
void print_string(const char *str) {
    printf("%s\n", str);
}

int main() {
    char my_name[] = "Gemini";
    char *my_location = "France";

    print_string(my_name);     // Works
    print_string(my_location); // Works
    
    return 0;
}

// strcpy
#include <stdio.h>
#include <string.h>

int main() {
    // Declares an array of 20 chars and copies "Hello" into it.
    // The memory layout is: H e l l o \0 ... (14 empty slots)
    char greeting[20] = "Hello";

    printf("Initial string: %s\n", greeting);

    // This is LEGAL because 'greeting' is a mutable array we own.
    strcpy(greeting, "World"); 
    
    printf("Modified string: %s\n", greeting); // Prints "World"

    return 0;
}

// Arrays decay to pointers
void print_str(char *s) {
    printf("%s\n", s);
}

char buf[] = "Hi";
print_str(buf);   // buf → &buf[0]


// Pointer arithmetic
const char *p = "Pointer";
while (*p) {
    putchar(*p++);
}
putchar('\n');


// maff_alpha
#include <unistd.h>

/**
 * @brief Prints the lowercase alphabet from 'a' to 'z'.
 *
 * This function iterates through the characters from 'a' to 'z' and
 * prints each one to the standard output using the `write` system call.
 */
void maff_alpha(void)
{
    char current_char;

    current_char = 'a';
    while (current_char <= 'z')
    {
        write(1, &current_char, 1);
        current_char++;
    }
}

int main(void)
{
    maff_alpha();
    write(1, "\n", 1); // Print a newline at the end
    return (0);
}

// ft_range
#include <stdlib.h> // Required for malloc
#include <stdio.h>  // Included for the example main function

/**
 * @brief Creates an array of integers with a range of values.
 *
 * @param min The starting integer of the range (inclusive).
 * @param max The ending integer of the range (exclusive).
 * @return A pointer to the newly allocated array, or NULL if min >= max
 * or if memory allocation fails.
 * @note The caller is responsible for freeing the memory allocated by this
 * function using `free()`.
 */
int *ft_range(int min, int max)
{
    int *array;
    int size;
    int i;

    // The range is invalid if min is greater than or equal to max.
    if (min >= max)
    {
        return (NULL);
    }

    // Calculate the number of integers in the range.
    size = max - min;

    // Allocate memory for the array.
    array = (int *)malloc(sizeof(int) * size);

    // If malloc fails, it returns NULL. We must handle this case.
    if (array == NULL)
    {
        return (NULL);
    }

    // Populate the array with values from min to max - 1.
    i = 0;
    while (i < size)
    {
        array[i] = min + i;
        i++;
    }

    return (array);
}

int main(void)
{
    int min = -5;
    int max = 5;
    int *result_array;
    int i;
    int size;

    result_array = ft_range(min, max);
    size = max - min; // Recalculate size for the loop

    // Always check if the returned pointer is not NULL before using it.
    if (result_array != NULL)
    {
        printf("Array from ft_range(%d, %d):\n", min, max);
        i = 0;
        while (i < size)
        {
            printf("%d ", result_array[i]);
            i++;
        }
        printf("\n");

        // IMPORTANT: Free the allocated memory to prevent memory leaks.
        free(result_array);
    }
    else
    {
        printf("ft_range(%d, %d) returned NULL.\n", min, max);
    }

    return (0);
}


// ft_alpha
// Include the necessary header for the 'write' system call.
#include <unistd.h>

/**
 * @brief Writes a single character to the standard output.
 * * @param c The character to be written.
 */
void	ft_putchar(char c)
{
	// write(file_descriptor, buffer, count)
	// 1 = standard output (the terminal)
	// &c = the address of the character to write
	// 1 = write 1 byte
	write(1, &c, 1);
}

/**
 * @brief Converts a lowercase character to uppercase and prints it.
 * @note This function relies on the ASCII encoding standard.
 * * @param c The character to convert and print.
 */
void	ft_maj(char c)
{
	// In ASCII, uppercase letters are exactly 32 less than their
	// lowercase counterparts (e.g., 'a' is 97, 'A' is 65).
	c -= 32;
	ft_putchar(c);
}

/**
 * @brief Prints the alphabet in the pattern: aBcDeF...yZ
 */
void	ft_alpha(void)
{
	int a; // Use an int to safely handle values beyond 'z' during checks.

	// Start with the first letter of the alphabet.
	a = 'a';
	// Loop as long as the character is less than or equal to 'z'.
	while (a <= 'z')
	{
		// Print the current lowercase character (e.g., 'a', then 'c', ...).
		ft_putchar(a);
		// Increment to the next letter (e.g., 'a' -> 'b').
		a++;
		// Print the uppercase version of this new letter (e.g., 'B', then 'D', ...).
		ft_maj(a);
		// Increment again to get to the start of the next pair (e.g., 'b' -> 'c').
		a++;
	}
}

/**
 * @brief The main entry point of the program.
 * * @return int Returns 0 on successful execution.
 */
int		main(void)
{
	// Call the function to print the pattern.
	ft_alpha();
	// Print a newline character for clean terminal output.
	ft_putchar('\n');
	// Return 0 to indicate that the program ran successfully.
	return (0);
}


// ft_swap_case
#include <unistd.h>

/**
 * @brief Iterates through a string and inverts the case of each letter.
 * Lowercase becomes uppercase, and uppercase becomes lowercase.
 * The string is modified in-place.
 * @param str The string to modify.
 */
void	ft_swap_case(char *str)
{
	int i = 0;

	// Loop through the string until the null terminator ('\0') is reached.
	while (str[i])
	{
		// Check if the character is a lowercase letter.
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			// Convert to uppercase by subtracting the ASCII difference (32).
			str[i] -= 32;
		}
		// Else, check if the character is an uppercase letter.
		else if (str[i] >= 'A' && str[i] <= 'Z')
		{
			// Convert to lowercase by adding the ASCII difference (32).
			str[i] += 32;
		}
		// Any character that is not a letter is ignored.
		i++;
	}
}

/**
 * @brief The main function checks for a command-line argument,
 * processes it, and prints the result.
 */
int		main(int argc, char **argv)
{
	// The program expects exactly one argument (in addition to the program name).
	// argc (argument count) should be 2.
	if (argc == 2)
	{
		// Pass the first argument (argv[1]) to the swap function.
		ft_swap_case(argv[1]);

		// Print the modified string character by character.
		int i = 0;
		while (argv[1][i])
		{
			write(1, &argv[1][i], 1);
			i++;
		}
	}
	// Always print a newline for clean output.
	write(1, "\n", 1);
	return (0);
}

// ft_putstr
#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}




