package trem;

public class Trem {
    Vagao primeiro;

    public Trem(Vagao x){
        primeiro = x;
    }

    public Trem(Vagao x, Vagao y){
        primeiro = x;
        x.setProximo(y);
    }

    public Integer count(String conteudo){
        Vagao aux = primeiro;
        Integer count = 0;

        while(aux.getProximo() != null){
            if(aux.getConteudo().equals(aux.getProximo().getConteudo())){
                count++;
                aux = aux.getProximo();
            }
            else{
                continue;
            }
        }

        return count;
    }

    public void add(Vagao x, Vagao ultimo, Vagao proximo){
        x.setAnterior(ultimo);
        x.setProximo(proximo);
    }
}
