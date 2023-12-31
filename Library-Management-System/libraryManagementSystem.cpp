// Library Management System is a simple console-based application that allows users to 
// manage a library's book inventory. It utilizes Object-Oriented Programming (OOP) 
// concepts such as classes and objects to organize and manipulate book data.


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;

class Book {
	private:
		string isbn, title, author, edition, publication;

	public:
		// Setter methods to set book details
		void setIsbn(string a) { isbn = a; }
		void setTitle(string b) { title = b; }
		void setAuthor(string c) { author = c; }
		void setEdition(string d) { edition = d; }
		void setPublication(string e) { publication = e; }

		// Getter methods to retrieve book details
		string getIsbn() const { return isbn; }
		string getTitle() const { return title; }
		string getAuthor() const { return author; }
		string getEdition() const { return edition; }
		string getPublication() const { return publication; }
};

class Library {
	private:
		vector<Book> books;

	public:
		// Function prototypes for various library operations
		void addBook();
		void deleteBook();
		void editBook();
		void searchBook();
		void viewAllBooks();
		void saveLibraryToFile() const;
		void loadLibraryFromFile();
};

// Function prototype for displaying the main menu
void displayMenu();

int main() {
    Library library;
    string choice;

    library.loadLibraryFromFile(); // Load library data from file

    while (true) {
        system("CLS");
		displayMenu();
        cout << "Enter choice : ";
        getline(cin, choice);

        system("CLS");

        if (choice == "1") {
            library.addBook();
        } else if (choice == "2") {
            library.deleteBook();
        } else if (choice == "3") {
            library.editBook();
        } else if (choice == "4") {
            library.searchBook();
        } else if (choice == "5") {
            library.viewAllBooks();
        } else if (choice == "6") {
            library.saveLibraryToFile(); // Save library data to file
            break;
        }
    }

    return 0;
}

// Function to display the main menu
void displayMenu(){
      cout << "-----Library Management System-----\n\n";
        cout << "1.Add book\n";
        cout << "2.Delete book\n";
        cout << "3.Edit book\n";
        cout << "4.Search book\n";
        cout << "5.View all books\n";
        cout << "6.Quit\n\n";
}

// Function to add a book in the library
void Library::addBook() {
    Book book;
    cout << "---Add Book---\n\n";
    
    string isbn, title, author, edition, publication;

    cout << "Enter ISBN: ";
    getline(cin, isbn);
    book.setIsbn(isbn);

    cout << "Enter Title: ";
    getline(cin, title);
    book.setTitle(title);

    cout << "Enter Author: ";
    getline(cin, author);
    book.setAuthor(author);

    cout << "Enter Edition: ";
    getline(cin, edition);
    book.setEdition(edition);

    cout << "Enter Publication: ";
    getline(cin, publication);
    book.setPublication(publication);

    books.push_back(book);
    cout << "\nBook added successfully!\n\nPress any key to continue . . .";
    cin.ignore();
}

// Function to delete a book from the library
void Library::deleteBook() {
    string isbn;
    int choice;
    cout << "---Delete book---\n\n";

    if (books.empty()) {
        cout << "There is no book to delete!\n\nPress any key to continue . . .";
        cin.ignore();
        return;
    }

    cout << "Enter the ISBN: ";
    getline(cin, isbn);

    auto it = find_if(books.begin(), books.end(), [isbn](const Book& book) {
        return book.getIsbn() == isbn;
    });

    if (it != books.end()) {
        cout << "Book found\n";
        cout << "Do you want to delete?\n1.Yes\n2.No\n\nEnter choice : ";
        cin >> choice;

        if (choice == 1) {
            books.erase(it);
            cout << "\nBook deleted successfully!\n\nPress any key to continue . . .";
        }
    } else {
        cout << "\nBook not found!\n\nPress any key to continue . . .";
    }

    cin.ignore();
}

// Function to edit details of a book in the library
void Library::editBook() {
    string editIsbn, choice;
    cout << "---Edit Book---\n\n";

    if (books.empty()) {
        cout << "There is no book to edit!\n\nPress any key to continue . . .";
        cin.ignore();
        return;
    }

    cout << "Enter ISBN: ";
    getline(cin, editIsbn);

    auto it = find_if(books.begin(), books.end(), [editIsbn](const Book& book) {
        return book.getIsbn() == editIsbn;
    });

    if (it != books.end()) {
        cout << "\nBook found to be edited\n\n";
        cout << "Isbn : " << it->getIsbn() << endl;
        cout << "Title : " << it->getTitle() << endl;
        cout << "Author : " << it->getAuthor() << endl;
        cout << "Edition : " << it->getEdition() << endl;
        cout << "Publication : " << it->getPublication() << endl;
        cout << "\nDo you want to edit?\n1.Yes\n2.No\n\nEnter choice: ";
        cin >> choice;

        if (choice == "1") {
            cin.ignore(); // Consume newline character left by cin >>
            
            Book newBook;
            cout << "Enter Isbn: ";
            getline(cin, editIsbn);
            newBook.setIsbn(editIsbn);
            cout << "Enter Title: ";
            getline(cin, choice);
            newBook.setTitle(choice);
            cout << "Enter Author: ";
            getline(cin, choice);
            newBook.setAuthor(choice);
            cout << "Enter Edition: ";
            getline(cin, choice);
            newBook.setEdition(choice);
            cout << "Enter Publication: ";
            getline(cin, choice);
            newBook.setPublication(choice);

            *it = newBook;
            cout << "\nBook edited successfully!\n\nPress any key to continue . . .";
        }
    } else {
        cout << "\nBook not found!\n\nPress any key to continue . . .";
    }

    cin.ignore(); // Consume newline character after entering data
}

// Function to search for a book in the library by ISBN
void Library::searchBook() {
    string isbn;
    cout << "---Search Book---\n\n";

    if (books.empty()) {
        cout << "There is no book to search!\n\nPress any key to continue . . .";
        cin.ignore();
        return;
    }

    cout << "Enter Isbn: ";
    getline(cin, isbn);

    auto it = find_if(books.begin(), books.end(), [isbn](const Book& book) {
        return book.getIsbn() == isbn;
    });

    if (it != books.end()) {
        cout << "\nBook Found!\n\n";
        cout << "Isbn : " << it->getIsbn() << endl;
        cout << "Title : " << it->getTitle() << endl;
        cout << "Author : " << it->getAuthor() << endl;
        cout << "Edition : " << it->getEdition() << endl;
        cout << "Publication : " << it->getPublication() << endl;
    } else {
        cout << "\nBook not found!\n";
    }

    cout << "\nPress any key to continue . . .";
    cin.ignore();
}

// Function to display details of all books in the library
void Library::viewAllBooks() {
    cout << "---View all books---\n\n";
    if (books.empty()) {
        cout << "There are no books in the library!\n\nPress any key to continue . . .";
        cin.ignore();
    } else {
        for (size_t i = 0; i < books.size(); i++) {
            cout << "Book no - " << i + 1 << "\n\n";
            cout << "Isbn : " << books[i].getIsbn() << endl;
            cout << "Title : " << books[i].getTitle() << endl;
            cout << "Author : " << books[i].getAuthor() << endl;
            cout << "Edition : " << books[i].getEdition() << endl;
            cout << "Publication : " << books[i].getPublication() << endl
                 << endl;
        }
        cout << "Press any key to continue . . .";
        cin.ignore();
    }
}

// Function to save library data to a file
void Library::saveLibraryToFile() const {
    ofstream file("library_data.txt");
    if (file.is_open()) {
        for (const auto& book : books) {
            file << book.getIsbn() << "," << book.getTitle() << "," << book.getAuthor() << "," << book.getEdition() << "," << book.getPublication() << "\n";
        }
        file.close();
    }
}

// Function to load library data from a file
void Library::loadLibraryFromFile() {
    ifstream file("library_data.txt");
    if (file.is_open()) {
        books.clear(); // Clear existing books
        while (!file.eof()) {
            Book book;
            string isbn, title, author, edition, publication;

            getline(file, isbn, ',');
            book.setIsbn(isbn);

            getline(file, title, ',');
            book.setTitle(title);

            getline(file, author, ',');
            book.setAuthor(author);

            getline(file, edition, ',');
            book.setEdition(edition);

            getline(file, publication);
            book.setPublication(publication);

            if (!book.getIsbn().empty()) {
                books.push_back(book);
            }
        }
        file.close();
    }
}
