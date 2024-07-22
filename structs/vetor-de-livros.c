#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _book
{
    char title[100];
    unsigned int num_pages;
    float price;
} Book;

Book *create_book(
    const char *title,
    unsigned int num_pages,
    float price
) {
    Book *book = (Book*) calloc(1, sizeof(Book));
    strcpy(book->title, title);
    book->num_pages = num_pages;
    book->price = price;

    return book;
}

Book *copy_book(const Book *book) {
    return create_book(book->title, book->num_pages, book->price);
}

void destroy_book(Book **book_ref) {
    Book *book = *book_ref;
    free(book);
    *book_ref = NULL;
}

void print_book(const Book *book) {
    printf("Title: %s\n", book->title);
    printf("Number of pages: %d\n", book->num_pages);
    printf("Price: $ %.2f\n\n", book->price);
}

int main() {
    Book **books_list = (Book**) calloc(3, sizeof(Book*));
    books_list[0] = create_book(
        "Harry Potter and the Philosopher's Stone",
        352,
        16.92
    );
    books_list[1] = create_book(
        "Harry Potter and the Chamber of Secrets",
        400,
        37.99
    );
    books_list[2] = create_book(
        "Harry Potter and the Prisoner of Azkaban",
        336,
        39.99
    );

    for (int i = 0; i < 3; i++)
    {
        print_book(books_list[i]);
    }

    for (int i = 0; i < 3; i++)
    {
        destroy_book(&books_list[i]);
    }
    free(books_list);
    books_list = NULL;
    
    return 0;
}
