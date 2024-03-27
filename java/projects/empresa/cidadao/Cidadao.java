package cidadao;
import java.time.LocalDate;

public class Cidadao {
    private int         id;
    private char        sexo;
    private String      nome;
    private String      apelido;
    private String      local_nascimento;
    private boolean     casado;
    private LocalDate   data_nascimento;
    private Morada      endereco;

    private static int countId = 0;

    public Cidadao(String nome, String apelido, char sexo, LocalDate nasci, String local_nas, boolean casado, Morada endereco) throws Exception{
        this.setSexo(sexo);
        this.setDataNascimento(nasci);
        this.nome = nome;
        this.apelido = apelido;
        this.endereco = endereco;
        this.id = ++countId;
    }

    // setter
    public void setSexo(char sexo) throws Exception{
        if(!(sexo == 'm' || sexo == 'M' || sexo == 'f' || sexo == 'F')){
            throw new Exception("Sexo inválido");
        }
        this.sexo = sexo;
    }

    public void setDataNascimento(LocalDate nascimento) throws Exception{
        if((LocalDate.now().getYear() - nascimento.getYear()) < 18){
            throw new Exception("Menor de idade");
        }
        this.data_nascimento = nascimento;
    }

    // Getter
    public int          getId(){return this.id;}
    public char         getSexo(){return this.sexo;}
    public String       getNome(){return this.nome;}
    public String       getApelido(){return this.apelido;}
    public String       getLocalNascimento(){return this.local_nascimento;}
    public Morada       getMorada(){return this.endereco;}
    public LocalDate    getDataNascimento(){return this.data_nascimento;}
    public String       getEstadoCivil(){
        if(casado) return "Casado";
        return "Solteiro";
    }
}
