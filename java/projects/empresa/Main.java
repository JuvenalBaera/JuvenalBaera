import cidadao.Morada;

public class Main {
    public static void main(String[] args) {
        try{
            Morada m = new Morada("285-513");
            Morada m1 = new Morada("28513");
        }
        catch(Exception ex){
            System.out.println(ex);
        }
    }
}
