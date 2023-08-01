import java.util.ArrayList;
import java.util.HashMap;

public class Library {
    private final HashMap<Long, User> users;
    private final ArrayList<Book> books;

    Library(){
        users = new HashMap<>();
        books = new ArrayList<>();
    }

    public void addUser(User user){
        this.users.put(user.getIdUser(), user);
    }

    public void addBook(Book book){
        this.books.add(book);
    }

    public int numberOfBooks(){
        return this.books.size();
    }

    public ArrayList<User> getUsers(){
        return new ArrayList<>(this.users.values());
    }

    public boolean existsUserId(long id){
        users.get(id);
    }

    public ArrayList<Book> getBooks(){
        return this.books;
    }
}
