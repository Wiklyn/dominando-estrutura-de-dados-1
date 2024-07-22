#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _book
{
    char title[100];
    unsigned int num_pages;
    float price;
} Book;

typedef struct _student
{
    char name[100];
    unsigned int age;
    Book *favorite_book;
} Student;


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

Student *create_student(
    const char *name,
    unsigned int age,
    const Book *favorite_book
) {
    Student *student = (Student*) calloc(1, sizeof(Student));
    strcpy(student->name, name);
    student->age = age;
    student->favorite_book = copy_book(favorite_book);

    return student;
}

void print_student(const Student *student) {
    printf("Name: %s\n", student->name);
    printf("Age: %d\n", student->age);
    puts("Favorite book:");
    print_book(student->favorite_book);
}

void destroy_student(Student **student_ref) {
    Student *student = *student_ref;
    destroy_book(&student->favorite_book);
    free(student);
    *student_ref = NULL;
}

int main() {
    Book *book_1 = create_book(
        "Harry Potter and the Philosopher's Stone",
        352,
        16.92
    );

    Student *ted = create_student("Ted", 20, book_1);
    print_student(ted);
    destroy_book(&book_1);
    destroy_student(&ted);
}
