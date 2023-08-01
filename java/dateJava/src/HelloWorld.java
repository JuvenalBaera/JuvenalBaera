import java.time.LocalDate;
import java.time.LocalTime;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

public class HelloWorld {
    public static void main(String[] args){
        LocalDate myDate = LocalDate.now();
        LocalTime myTime = LocalTime.now();
        LocalDateTime myDateTime = LocalDateTime.now();
        DateTimeFormatter myFormatter = DateTimeFormatter.ofPattern("E, MMM dd yyyy HH:mm:ss");

        System.out.println(myDate);
        System.out.println(myTime);
        System.out.println(myDateTime);
        System.out.println(myDateTime.format(myFormatter));
    }
}