import java.util.ArrayList;
import java.util.Collections;

public class Main {
    public static void main(String[] args) {
        ArrayList<String> colors = new ArrayList<>();
        colors.add("Red");
        colors.add("Green");
        colors.add("Blue");

        /*
        System.out.println(colors.get(2));
        colors.set(1, "White");
        colors.remove(1);
        System.out.println("Size: " + colors.size());
        System.out.println(colors);
         */
        System.out.println("Before sort: ");
        for (String color : colors) {
            System.out.println(color);
        }
        System.out.println("\nAfter sort: ");
        
        Collections.sort(colors);
        for(String color : colors){
            System.out.println(color);
        }
    }
}