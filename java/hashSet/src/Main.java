import java.util.HashSet;

public class Main {
    public static void main(String[] args) {
        HashSet<String> users = new HashSet<>();
        users.add("j.baera");
        users.add("dadChima");
        users.add("me@!you");

        System.out.println(users.contains("j.baera15"));
        System.out.println(users);
    }
}