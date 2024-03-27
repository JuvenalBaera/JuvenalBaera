package cidadao;
import java.time.LocalDate;

public class Cidadao {
    private String      nome;
    private String      apelido;
    private char        sexo;
    private LocalDate   data_nascimento;

    private String      local_nascimento;
    private boolean     casado;
    private int         id;
    private static int countId = 0;

    Morada endereco;

    public Cidadao(String nome, String apelido, char sexo, LocalDate nasci, String local_nas, boolean casado, Morada endereco) throws Exception{
        this.id = ++countId;
        this.nome = nome;
        this.apelido = apelido;
        setSexo(sexo);
        this.endereco = endereco;
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
}
