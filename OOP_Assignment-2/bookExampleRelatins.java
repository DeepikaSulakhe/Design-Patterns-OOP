// Book class
public class Book {
    private String name;
    private String author;
    private String isbn;

    // Constructors
    public Book(String name, String author, String isbn) {
        this.name = name;
        this.author = author;
        this.isbn = isbn;
    }

    // Getters and setters
    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getAuthor() {
        return author;
    }

    public void setAuthor(String author) {
        this.author = author;
    }

    public String getIsbn() {
        return isbn;
    }

    public void setIsbn(String isbn) {
        this.isbn = isbn;
    }
}

// Library class
public class Library {
    // Dependency on Book class
    public Book findBook(String name, String author, String isbn) {
        // Creating and returning a new Book object
        return new Book(name, author, isbn);
    }
}

// Main class for testing
public class Main {
    public static void main(String[] args) {
        // Creating a Library instance
        Library library = new Library();

        // Using the Library class to find a book
        Book foundBook = library.findBook("The Art of Programming", "John Doe", "123456789");

        // Displaying information about the found book
        System.out.println("Found Book:");
        System.out.println("Name: " + foundBook.getName());
        System.out.println("Author: " + foundBook.getAuthor());
        System.out.println("ISBN: " + foundBook.getIsbn());
    }
}
