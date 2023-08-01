import java.time.format.DateTimeFormatter;

public class Main {
    public static void main(String[] args) {
        Person p = new Person("Juvenal",31, 6, 2001);
        showPerson(p);
    }

    public static void showPerson(Person p){
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("dd/MM/yyyy");
        System.out.println("Name: " + p.name);
        if(p.birth != null)
            System.out.println("Birth: " + formatter.format(p.birth));
        else
            System.out.println("Invalid Date");
    }
}
