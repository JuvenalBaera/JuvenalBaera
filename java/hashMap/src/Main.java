import java.util.HashMap;

public class Main {
    public static void main(String[] args) {
        HashMap<String, String> capitalCities = new HashMap<>();

        capitalCities.put("Portugal", "Lisbon");
        capitalCities.put("England", "London");
        capitalCities.put("USA", "Washington DC");

        //System.out.println(capitalCities.get("USA"));
        //capitalCities.remove("England");
        //System.out.println(capitalCities);

        for(String cities : capitalCities.keySet())
            System.out.println(cities);

        for(String country : capitalCities.values())
            System.out.println(country);
    }
}