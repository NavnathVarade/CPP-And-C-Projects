# Library Management System

This is a simple Library Management System implemented in C++. The system allows users to perform basic operations such as adding books, deleting books, editing book details, searching for a book, viewing all books, and quitting the system. The data is stored in a file (library_data.txt) to persist across different program runs.

## Table of Contents

- [Features](#features)
- [Getting Started](#getting-started)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)
- [Acknowledgments](#Acknowledgments)

## Features

- **Add Book**: Users can add a new book to the library by providing ISBN, title, author, edition, and publication details.
- **Delete Book**: Users can delete a book from the library by entering its ISBN.
- **Edit Book**: Users can edit the details of an existing book, including ISBN, title, author, edition, and publication.
- **Search Book**: Users can search for a book by its ISBN and view its details.
- **View All Books**: Display details of all books in the library.
- **Quit**: Exit the application.
- **Save and Load**: The system supports saving the library data to a file (library_data.txt) and loading it back when the program starts.

## Getting Started

### Prerequisites

- C++ compiler (e.g., GCC)
- MySQL server (if connecting to a database)

### Installation

1. Clone the repository:

   ```bash
   git clone https://github.com/NavnathVarade/CPP-And-C-Projects.git -b main --single-branch Library-Management-System

2. Navigate to the project directory:

    ```bash
    cd library-management-system
3. Compile the code:

    ```bash
    g++ main.cpp -o library_management_system

## Usage

1. Run the compiled executable:

    ```bash
    ./library_management_system

2. Follow the on-screen instructions to perform actions such as adding, deleting, or editing books.

3. Quit the application when done.

## Contribution
Contributions are welcome! If you find a bug or have an enhancement in mind, please open an issue or create a pull request.

## License 
This project is licensed under the MIT License - see the LICENSE file for details.

## Acknowledgments
Inspired by the need for a simple and effective library management system.
Built with C++ to showcase basic programming concepts.
