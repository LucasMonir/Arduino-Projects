function ativar(opcao) {

    switch (opcao) {
        case 'lancaChama':

            lancaChamas();
            break;

        case 'facada':
            facada();
            break;

        case 'alarme':
            alarme()
            break;
        default:
            throw "Opção inválida, CÓD: DP";
    }
}

$("button").on('click', function (e) {
    e.preventDefault();
    let opcao = $('select option:selected').val();
    let text = $(this).text();

    if (text == 'Ativar') {
        $(this).html('Desativar');
        ativar(opcao);
    } else if (text == 'Desativar') {
        $(this).html('Ativar');
    }
});

// ler novo parametro
//  trocar o estado

function lancaChamas(e) {
    if(!document.location.href.includes('?')){
        window.location.replace(document.location.href  + "?param=l");
    }
    
    e.preventDefault();
}

function facada(e) {
    if(!document.location.href.includes('?')){
        window.location.replace(document.location.href  + "?param=f");
    }
    e.preventDefault();
}

function alarme(e) {
    if(!document.location.href.includes('?')){
        window.location.replace(document.location.href  + "?param=a");
    }
    e.preventDefault();
}