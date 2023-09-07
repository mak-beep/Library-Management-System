#include <iostream>
#include <string>
#include "Book.h"
using namespace std;

const int MAX_BOOKS = 100;

void menu()
{
    cout << "Library Management System" << endl;
    cout << "1. Add a book" << endl;
    cout << "2. Search for a book" << endl;
    cout << "3. Display all books" << endl;
    cout << "4. Quit" << endl;
}

int take_choice()
{
    cout << "Enter your choice: ";
    int x;
    cin >> x;
    cout << "---------------" << endl;
    return x;

}

void add_book(Book library[], int index)
{
    string title, author;
    int year;
    cout << "Enter the title of the Book : ";
    cin.ignore();
    getline(cin, title);
    cout << "Enter the Author' name : ";
    cin.ignore();
    getline(cin, author);
    cout << "Enter the publication year : ";
    cin >> year;
    Book new_book;
    new_book.title = title;
    new_book.author = author;
    new_book.year = year;

    library[index] = new_book;
    cout << "Book Added.\n";
}

void dispaly_books(Book library[], int size)
{
    for (int index = 0; index < size; index++)
    {
        cout << index + 1 << endl;
        cout << "Book Title = " << library[index].title<<endl;
        cout << "Book Author = " << library[index].author << endl;
        cout << "Published = " << library[index].year << endl;
        cout << "-----------------------" << endl;
    }
}

void search_book(string title, Book library[], int size)
{
    bool found = false;
    for (int index = 0; index < size; index++)
    {
        if (library[index].title == title)
        {
            found = true;
            cout << "Book is in library at position " << index + 1 << endl;
        }
    }
    if (!found)
    {
        cout << "Book is not available in the library.\n";
    }
}

int main()
{
    int book_index = 0;
    Book library[MAX_BOOKS];
    string book_title;
    while (true)
    {
        menu();

        switch (take_choice())
        {
        case 1:
            add_book(library, book_index);
            book_index++;
            break;
        case 2:
            cout << "Enter the title of the book you are looking for : ";
            cin.ignore();
            getline(cin, book_title);
            search_book(book_title, library, book_index);
            break;
        case 3:
            dispaly_books(library, book_index);
            break;
        case 4:
            cout << "Exiting.\n";
            exit(0);
        default:
            cout << "Invalid option. Try again.\n";
            break;
        }
        cout << "-------------------\n";
    }
	return 0;
}