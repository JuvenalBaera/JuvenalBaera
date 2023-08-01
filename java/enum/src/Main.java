public class Main {
    public static void main(String[] args) {
        days d = days.MON;
        switch (d){
            case SUN:
                System.out.println("Let's go to beach");
                break;
            case MON:
                System.out.println("Lazy day");
                break;
            default:
                System.out.println("Idk about it");
        }
    }

    enum days{
        SUN,
        MON,
        TUE,
        WED,
        THU,
        FRI,
        SAT
    }
}