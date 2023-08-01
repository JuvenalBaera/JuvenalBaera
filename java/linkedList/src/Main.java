import java.util.LinkedList;

public class Main {
    public static void main(String[] args) {
        LinkedList<String> cars = new LinkedList<>();
        cars.addLast("BMW X6");
        cars.addLast("Ford Mustang");
        cars.addLast("Lamborghini");

        System.out.println(cars);

        for(String car : cars)
            System.out.println(car);
    }
}