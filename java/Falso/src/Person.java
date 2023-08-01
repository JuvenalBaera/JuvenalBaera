import java.time.DateTimeException;
import java.time.LocalDate;

public class Person {
    private String name;
    private LocalDate birth;

    Person(String name, int day, int month, int year){
        this.setDate(day, month, year);
        this.name = name;
    }

    public void setDate(int day, int month, int year){
        try{
            this.birth = LocalDate.of(year, month, day);
        }
        catch (DateTimeException e){
            this.birth = LocalDate.now();
            System.out.println("Invalid  Date");
        }
    }

    public String getName(){return this.name;}
}
