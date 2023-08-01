public class Main extends Thread{

    public static void main(String[] args) {
        Main thread = new Main();
        thread.start();
        while (thread.isAlive())
            System.out.println("Waiting...");
        System.out.println("Hello world!");
    }

    public void run(){
        System.out.println("I start thread");
    }
}