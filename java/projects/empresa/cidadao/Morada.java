package cidadao;
import java.util.regex.*;

public class Morada {
    private int     numero;
    public  String  rua;
    public  String  bairro;
    public  String  cidade;
    public  String  pais;
    private String  codigo_postal;

    // Construtor
    public Morada(String rua, int numero, String bairro, String cidade, String pais, String codigo_postal) throws Exception{
        this.setNumero(numero);
        this.setCodigoPostal(codigo_postal);
        this.rua = rua;
        this.bairro = bairro;
        this.cidade = cidade;
        this.pais = pais;
    }

    // Setter
    public void setNumero(int numero) throws Exception{
        if(numero <= 0){
            throw new Exception("Numero de rua invalido");
        }
        this.numero = numero;
    }

    public void setCodigoPostal(String codigo) throws Exception{
        Pattern padrao = Pattern.compile("\\d\\d\\d-\\d\\d\\d");
        Matcher achado = padrao.matcher(codigo);

        if(!achado.find()){
            throw new Exception("Formato de codigo postal invalido");
        }
        this.codigo_postal = codigo;
    }

    // Getter
    public int getNumero(){return this.numero;}
    public String getRua(){return this.rua;}
    public String getBairro(){return this.bairro;}
    public String getCidade(){return this.cidade;}
    public String getPais(){return this.pais;}
    public String getCodigoPostal(){return this.codigo_postal;}
}
