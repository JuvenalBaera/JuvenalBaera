public class Main {
    public static void main(String[] args) {
        /*ArrayList<Integer> numbers = new ArrayList<>();
        numbers.add(1);
        numbers.add(2);
        numbers.add(4);

        try {
            System.out.println(numbers.get(4));
        } catch (Exception e){
            System.out.println("Something went wrong");
        }
        finally {
            System.out.println("You successfully did it");
        }*/
        try {
            checkAge(19);
            checkAge(12);
        } catch (ArithmeticException e){
            System.out.println("Error in calculus");
        }
        catch (Exception e){
            System.out.println(e);
        }
    }
    static void checkAge(int age){
        if(age < 18)
            throw new ArithmeticException("Access denied. You're not old");
        else
            System.out.println("Access granted. You're old enough");
    }
}