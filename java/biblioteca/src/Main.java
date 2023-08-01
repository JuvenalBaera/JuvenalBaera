import java.util.InputMismatchException;
import java.util.Scanner;

public class Main {
    static Scanner scanner = new Scanner(System.in);
    public static void main(String[] args){
        Book book;
        User user;
        Library library = new Library();
        int option;
        long bookid, userid;

        System.out.println("##### WELCOME TO MY LIBRARY #####\n");

        do{
            option = mainMenu();
            switch (option) {
                case 0 -> System.out.println("\nBYE, THANK YOU!!!");
                case 1 -> {
                    System.out.println("\nENTER INFORMATION OF BOOK");
                    book = readBook();
                    library.addBook(book);
                }
                case 2 -> {
                    System.out.println("\nENTER INFORMATION OF USER");
                    user = readUser();
                    library.addUser(user);
                }
                case 3 -> {
                    userid = readInt("Enter a user id: ");
                    bookid = readInt("Enter a book id: ");
                }
                case 4 -> {
                    System.out.println("Return");
                }
                case 5 -> {
                    System.out.println("Show all users");
                    for(User u : library.getUsers()){
                        System.out.println();
                        System.out.println(u);
                    }
                }
                case 6 -> {
                    for(Book b : library.getBooks()){
                        System.out.println();
                        System.out.println(b);
                    }
                }
                default -> System.out.println("INVALID OPTION");
            }
        }while(option != 0);
    }

    public static int mainMenu(){
        int option, size;
        String[] displayOptions = {"Exit", "Add book", "Add user", "Borrow Book", "Return Book", "Show all users", "Show all Books"};
        size = displayOptions.length;
        do {
            for(int i = 0; i < size; i++) {
                System.out.println(i + " - " + displayOptions[i]);
            }
            System.out.println();
            option = readInt("Choose an option: ");
            if(option < 0 || option > size-1){
                System.out.println("\nINVALID OPTION\n");
                continue;
            }
            break;
        }while(true);
        return option;
    }

    // ################ AUXILIARY ###############
    public static int readInt(String msg){
        Integer number = null;
        do {
            System.out.print(msg);
            try {
                number = scanner.nextInt();
            }
            catch (InputMismatchException e){
                System.out.println("PLEASE, TYPE A NUMBER");
                scanner.next();
            }
            catch (Exception e) {
                System.out.println("SOMETHING WENT WRONG" + e);
                scanner.next();
            }
        }while(number == null);
        scanner.nextLine();
        return  number;
    }

    // ################ FUNCTIONALITY #################
    public static User readUser(){
        String name;
        int day, month, year;
        System.out.print("\tName: ");
        name = scanner.nextLine();
        day = readInt("\tDay: ");
        month = readInt("\tMonth: ");
        year = readInt("\tYear: ");
        return new User(name, day, month, year);
    }

    public static Book readBook(){
        String title, author;
        int releasedYear, numPages;
        System.out.print("\tTitle: ");
        title = scanner.nextLine();
        System.out.print("\tAuthor: ");
        author = scanner.nextLine();
        releasedYear = readInt("\tReleased year: ");
        numPages = readInt("\tNumber of pages: ");
        return new Book(title, author, releasedYear, numPages);
    }
}
