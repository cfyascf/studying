package trem;

public class Vagao {
    private Vagao anterior = null;
    private Vagao proximo = null;
    private String conteudo;

    public Vagao(Conteudo algo){
        if(algo == Conteudo.VAZIO){
            conteudo = "vazio";
        }
        else if(algo == Conteudo.COMBUSTIVEL){
            conteudo = "combustivel";
        }
        else if(algo == Conteudo.TRIGO){
            conteudo = "trigo";
        }
        else if(algo == Conteudo.ANIMAIS){
            conteudo = "animais";
        }
        else if(algo == Conteudo.PASSAGEIROS){
            conteudo = "passageiros";
        }
    }

    public void setAnterior(Vagao x){
        anterior = x;
    }

    public void setProximo(Vagao x){
        proximo = x;
    }

    public Vagao getAnterior(){
        return anterior;
    }

    public Vagao getProximo(){
        return proximo;
    }

    public String getConteudo(){
        return conteudo;
    }
}
