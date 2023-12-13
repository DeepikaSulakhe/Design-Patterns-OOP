#include <iostream>
#include <string>

// Book class
class Book {
private:
    std::string name;
    std::string author;
    std::string isbn;

public:
    // Constructors
    Book(std::string name, std::string author, std::string isbn)
        : name(name), author(author), isbn(isbn) {}

    // Getters and setters
    std::string getName() const {
        return name;
    }

    void setName(const std::string& newName) {
        name = newName;
    }

    std::string getAuthor() const {
        return author;
    }

    void setAuthor(const std::string& newAuthor) {
        author = newAuthor;
    }

    std::string getIsbn() const {
        return isbn;
    }

    void setIsbn(const std::string& newIsbn) {
        isbn = newIsbn;
    }
};

// Library class
class Library {
public:
    // Dependency on Book class
    Book findBook(std::string name, std::string author, std::string isbn) {
        // Creating and returning a new Book object
        return Book(name, author, isbn);
    }
};

// Main function for testing
int main() {
    // Creating a Library instance
    Library library;

    // Using the Library class to find a book
    Book foundBook = library.findBook("The Art of Programming", "John Doe", "123456789");

    // Displaying information about the found book
    std::cout << "Found Book:" << std::endl;
    std::cout << "Name: " << foundBook.getName() << std::endl;
    std::cout << "Author: " << foundBook.getAuthor() << std::endl;
    std::cout << "ISBN: " << foundBook.getIsbn() << std::endl;

    return 0;
}
