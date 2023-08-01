import java.time.LocalDate;
import java.util.ArrayList;

public class User {
    private static long contId = 0;
    private final long id;
    private String name;
    private LocalDate birth;
    private ArrayList<Book> bookLoan;

    User(String name, int d, int m, int y){
        this.setNameUser(name);
        this.setBirthUser(d, m, y);
        id = ++contId;
    }

    // ########## SETTERS AND GETTERS ##########
    // ########## SETTERS ##########
    public void setNameUser(String name) {this.name = name;}

    public void setBirthUser(int d, int m, int y) {
        try{
            this.birth = LocalDate.of(y, m, d);
        }
        catch (Exception e){
            System.out.println("Invalid Date");
            this.birth = LocalDate.of(1900, 1, 1);
        }
    }

    // ########## GETTERS ##########
    public String getNameUser(){ return this.name; }
    public LocalDate getBirthUser(){ return this.birth; }
    public long getIdUser() { return this.id; }


    // ########## OTHERS ##########
    public void addBookUser(Book book){
        this.bookLoan.add(book);
    }

    public int sizeOfLoanBookUser(){
        return this.bookLoan != null ? this.bookLoan.size() : 0;
    }

    public String toString(){
        return  "Id..........: " + this.getIdUser() + "\n" +
                "Name........: " + this.getNameUser() + "\n" +
                "Birthday....: " + this.getBirthUser() + "\n" +
                "Loaned Book.: " + this.sizeOfLoanBookUser();
    }
}
