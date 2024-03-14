package trem;

public class Main {
    public static void main(String[] args){
        Vagao um = new Vagao(Conteudo.TRIGO);
        Vagao dois = new Vagao(Conteudo.TRIGO);
        Vagao tres = new Vagao(Conteudo.PASSAGEIROS);
        Vagao quatro = new Vagao(Conteudo.COMBUSTIVEL);

        Trem trem = new Trem(um, dois);

        trem.add(dois, um, tres);
        trem.add(tres, dois, quatro);
        trem.add(quatro, tres, null);

        System.out.println(trem.count("trigo"));
    }
}
