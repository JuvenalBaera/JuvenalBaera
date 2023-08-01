import java.time.LocalDate;

public class Book {
    private String title = null;
    private String author = null;
    private int releasedYear = 0;
    private int numOfPages = 0;
    private final long idBook;
    private static long contIdBook = 1;

    Book(String title, String author, int ano, int numOfPages){
        this.idBook = contIdBook++;
        this.setTitle(title);
        this.setAuthor(author);
        this.setReleasedYear(ano);
        this.setNumOfPages(numOfPages);
    }

    // ########## SETTERS AND GETTERS ##########
    // ########## SETTERS ##########
    void setTitle(String title){ this.title = title; }
    void setAuthor(String author){ this.author = author; }
    void setReleasedYear(int releasedYear){
        final int MAX_ANO = 30;
        int ano = LocalDate.now().getYear();
        if((releasedYear >= ano - MAX_ANO) && (releasedYear <= ano)){
            this.releasedYear = releasedYear;
        }
        else {
            System.out.println("Invalid Year");
            this.releasedYear = ano - MAX_ANO;
        }
    }

    public void setNumOfPages(int numOfPages){
        if(this.title != null && numOfPages >= 10 && numOfPages <= 1500){
            this.numOfPages = numOfPages;
        }
        else
            this.numOfPages = 0;
    }

    // ########## GETTERS ##########
    public String getTitleBook(){ return this.title; }
    public String getAuthorBook(){ return this.author; }
    public int getReleasedYearBook(){ return this.releasedYear; }
    public int getNumOfPagesBook(){ return this.numOfPages; }

    public long getIdBook() {return this.idBook;}

    public String toString(){
        return  "Book Id: " + this.getIdBook() +
                "Title...........: " + this.getTitleBook() + "\n" +
                "Author..........: " + this.getAuthorBook() + "\n" +
                "Released Year...: " + this.getReleasedYearBook() + "\n" +
                "Number of Pages.: " + this.getNumOfPagesBook();
    }
}
