import cidadao.Cidadao;
import cidadao.Morada;
import java.time.LocalDate;

public class Main {
    public static void main(String[] args) {
        try{
            Morada m = new Morada("rua", 8, "bairro 1", "lisboa", "pt", "2134-234");
            Cidadao cid = new Cidadao("Juvenal", "Baera", 'M', LocalDate.of(2001, 5, 2), "Mz", false, m);
        }
        catch(Exception ex){
            System.out.println(ex);
        }
    }
}
