let colors = [
    {id: 0, nome: "Verde-Cipreste", src: "./imagens/opcoes-cores/imagens-verde-cipreste/"},
    {id: 1, nome: "Azul-Inverno", src: "./imagens/opcoes-cores/imagens-azul-inverno/"},
    {id: 2, nome: "Meia-Noite", src: "./imagens/opcoes-cores/imagens-meia-noite/"},
    {id: 3, nome: "Estelar", src: "./imagens/opcoes-cores/imagens-estelar/"},
    {id: 4, nome: "Rosa-Claro", src: "./imagens/opcoes-cores/imagens-rosa-claro/"}
];

let trocaCor = () => {
    let color_button = document.querySelector('input[name="opcao-cor"]:checked');

    // gets element id number
    let button_id = color_button.id;
    let id_splitted = button_id.split("-");
    let id_number = id_splitted[0];

    // changes color title
    let color_title = document.getElementById("nome-cor-selecionada");
    color_title.innerHTML = "Cor-" + colors[id_number].nome.toString(); 

    // changes product title
    let product_title = document.getElementById("titulo-produto");
    let product_title_content = product_title.innerHTML;
    let box_size = product_title_content.substring(product_title_content.length - 5);
    product_title.innerHTML = "Pulseira loop esportiva " + colors[id_number].nome.toString() + " para caixa de " + box_size;

    //changes visualization img 
    let visu_img = document.getElementById("imagem-visualizacao");
    let visu_img_src = visu_img.src;
    let visu_img_number = visu_img_src.substring(visu_img_src.length - 6);

    visu_img.src = colors[id_number].src + "imagem-" + visu_img_number.toString();

    // changes miniature imgs
    let photos = document.querySelectorAll('.miniature-img');

    photos.forEach((photo, index) => {
        photo.src = colors[id_number].src + "imagem-" + index.toString() + ".jpeg";
    })
}

let trocarImagem = () => {
    // change visualization image by miniature
    let min_imgs = document.querySelector('input[name="opcao-imagem"]:checked');
    let img_id = min_imgs.id;
    let img_id_splitted = img_id.split("-");
    let img_id_number = img_id_splitted[0];

    let visu_img = document.getElementById("imagem-visualizacao");
    let visu_img_src = visu_img.src;
    let visu_img_nonumber = visu_img_src.slice(0, -6);

    visu_img.src = visu_img_nonumber + img_id_number.toString() + ".jpeg";
}

let trocarTamanho = () => {
    let size_button = document.querySelector('input[name="opcao-tamanho"]:checked');
    let size_btn_id = size_button.id;
    let sizebtn_number = size_btn_id.slice(0, -8);
    
    let product_title = document.getElementById("titulo-produto");
    let product_title_content = product_title.innerHTML;
    let nobox_size = product_title_content.slice(0, -5);
    
    let visu_img = document.getElementById("imagem-visualizacao");
    if(sizebtn_number == 0) {
        visu_img.style.scale = 0.7;
        product_title.innerHTML = nobox_size + " 41 mm";
    }
    else {
        visu_img.style.scale = 1;
        product_title.innerHTML = nobox_size + " 45 mm";
    }

}