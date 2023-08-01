import java.util.ArrayList;
import java.util.Iterator;

public class Main {
    public static void main(String[] args) {
        ArrayList<String> cars = new ArrayList<>();
        Iterator<String> iterCars;
        
        cars.add("Ford Mustang");
        cars.add("Mazda BT50");
        cars.add("Ferrari");

        iterCars = cars.iterator();
        
        while(iterCars.hasNext()){
            System.out.println(iterCars.next());
        }
    }
}