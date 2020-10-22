GLuint carregaTextura(const char* arquivo) {
    GLuint idTextura = SOIL_load_OGL_texture(
                           arquivo,
                           SOIL_LOAD_AUTO,
                           SOIL_CREATE_NEW_ID,
                           SOIL_FLAG_INVERT_Y
                       );

    if (idTextura == 0) {
        printf("Erro do SOIL: '%s'\n", SOIL_last_result());
    }

    return idTextura;
}

// Inicia algumas variáveis de estado do OpenGL
void inicializa() {
    // define qual é a cor do fundo
    glClearColor(1, 1, 1, 1); // branco

    nav.alt= 300;
    nav.larg = 100;
    nav.x = 300;
    nav.y = 0;
    inimigos_mortos=0;
    score=0;
    blockdir=0;
    blockesq;

    tiro.x = 1000;//fora da tela
    tiro.y = nav.y;

    inicializaInimigos(); 

    inicializaTexturas();
    vidas =3;
}

void inicializaInimigos(){   
    
    int incre_x = 0;
    int y=1600;
    for(int i =0; i< n_inimigos; i++){
        inimigo_morto[i]=0; // declara q os inimigos n estao mortos
        inimigos[i].x = incre_x;
        inimigos[i].y = y;
        inimigos[i].larg = inimigo_larg;
        inimigos[i].alt = inimigo_alt ;
        inimigos[i].ataque_agressivo = 0 ; 
        incre_x +=150;
        if(i==2){
            incre_x=75;
            y-=200;
        }
        if(i==5){
            incre_x=0;
            y-=300;
        }        
    }
}

void inicializaTexturas(){

    texturaTitulo = carregaTextura("Imagens/Titulos/titulo3.png");
    glEnable( GL_BLEND );
    glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
    if (texturaTitulo == 0) {
        printf("Erro do SOIL fundo de Titulo: '%s'\n", SOIL_last_result());
    }

    texturaCreditos = carregaTextura("Imagens/Botoes/Opcao1/botaoCreditos.png");
    glEnable( GL_BLEND );
    glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
    if (texturaCreditos== 0) {
        printf("Erro do SOIL fundo de Creditos: '%s'\n", SOIL_last_result());
    }

    texturaTituloCreditos = carregaTextura("Imagens/Titulos/creditos1.png");
    glEnable( GL_BLEND );
    glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
    if (texturaTituloCreditos== 0) {
        printf("Erro do SOIL fundo de Titulo de Creditos: '%s'\n", SOIL_last_result());
    }

    texturaAutores = carregaTextura("Imagens/Titulos/Autores.png");
    glEnable( GL_BLEND );
    glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
    if (texturaAutores== 0) {
        printf("Erro do SOIL fundo de Autores: '%s'\n", SOIL_last_result());
    }

    texturaVoltar = carregaTextura("Imagens/Botoes/Opcao1/botaoVoltar.png");
    glEnable( GL_BLEND );
    glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
    if (texturaVoltar== 0) {
        printf("Erro do SOIL fundo de Voltar: '%s'\n", SOIL_last_result());
    }

    texturaIniciar = carregaTextura("Imagens/Botoes/Opcao1/botaoIniciar.png");
    glEnable( GL_BLEND );
    glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
    if (texturaIniciar== 0) {
        printf("Erro do SOIL fundo de Start: '%s'\n", SOIL_last_result());
    }

    texturaEsc = carregaTextura("Imagens/Botoes/Opcao1/botaoSair.png");
    glEnable( GL_BLEND );
    glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
    if (texturaEsc == 0) {
        printf("Erro do SOIL fundo de Sair: '%s'\n", SOIL_last_result());
    }
    texturaPause = carregaTextura("Imagens/Botoes/Opcao1/botaoPausar.png");
    glEnable( GL_BLEND );
    glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
    if (texturaPause == 0) {
        printf("Erro do SOIL fundo de Pausar: '%s'\n", SOIL_last_result());
    }
    texturaReiniciar = carregaTextura("Imagens/Botoes/Opcao1/botaoReiniciar.png");
    glEnable( GL_BLEND );
    glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
    if (texturaReiniciar == 0) {
        printf("Erro do SOIL fundo de Iniciar: '%s'\n", SOIL_last_result());
    }
    texturaPausado =  carregaTextura("Imagens/Titulos/pause3.png");
    glEnable( GL_BLEND );
    glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
    if (texturaPausado == 0) {
        printf("Erro do SOIL fundo de Pausado: '%s'\n", SOIL_last_result());
    }

    texturaGameOver = carregaTextura("Imagens/Titulos/gameover.png");
    glEnable( GL_BLEND );
    glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
    if (texturaGameOver == 0) {
        printf("Erro do SOIL fundo de Game Over: '%s'\n", SOIL_last_result());
    }

    texturaNave = carregaTextura("Imagens/Nave/sprite.png");
    //texturaNave = carregaTextura("Imagens/Nave/nave.png");
    glEnable( GL_BLEND );
    glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
    if (texturaNave == 0) {
        printf("Erro do SOIL fundo da Nave: '%s'\n", SOIL_last_result());
    }

    texturaInimigo = carregaTextura("Imagens/Inimigos/twitch1.png");
    glEnable( GL_BLEND );
    glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

    if (texturaInimigo == 0) {
        printf("Erro do SOIL fundo do Inimigo Twitch: '%s'\n", SOIL_last_result());
    }

    texturaInimigo2 = carregaTextura("Imagens/Inimigos/youtube.png");
    glEnable( GL_BLEND );
    glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

    if (texturaInimigo == 0) {
        printf("Erro do SOIL fundo do Inimigo Youtube: '%s'\n", SOIL_last_result());
    }

    texturaInimigo3 = carregaTextura("Imagens/Inimigos/insta.png");
    glEnable( GL_BLEND );
    glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

    if (texturaInimigo == 0) {
        printf("Erro do SOIL fundo do Inimigo Insta: '%s'\n", SOIL_last_result());
    }

    texturaTiro = carregaTextura("Imagens/Nave/tiro.png");
    glEnable( GL_BLEND );
    glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

    if (texturaTiro == 0) {
        printf("Erro do SOIL fundo do Tiro da Nave: '%s'\n", SOIL_last_result());
    }

    texturaBack[0] = carregaTextura("Imagens/Back2/1.png");
    glEnable( GL_BLEND );
    glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

    if (texturaBack[0] == 0) {
        printf("Erro do SOIL fundo: '%s'\n", SOIL_last_result());
    }

    texturaBack[1] = carregaTextura("Imagens/Back2/2.png");
    glEnable( GL_BLEND );
    glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

    if (texturaBack[1] == 0) {
        printf("Erro do SOIL fundo: '%s'\n", SOIL_last_result());
    }

    texturaBack[2] = carregaTextura("Imagens/Back2/3.png");
    glEnable( GL_BLEND );
    glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

    if (texturaBack[2] == 0) {
        printf("Erro do SOIL fundo: '%s'\n", SOIL_last_result());
    }

    texturaBack[3] = carregaTextura("Imagens/Back2/4.png");
    glEnable( GL_BLEND );
    glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

    if (texturaBack[3] == 0) {
        printf("Erro do SOIL fundo: '%s'\n", SOIL_last_result());
    }

    texturaBack[4] = carregaTextura("Imagens/Back2/5.png");
    glEnable( GL_BLEND );
    glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

    if (texturaBack[4] == 0) {
        printf("Erro do SOIL fundo: '%s'\n", SOIL_last_result());
    }
    texturaBack[5] = carregaTextura("Imagens/Back2/6.png");
    glEnable( GL_BLEND );
    glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

    if (texturaBack[5] == 0) {
        printf("Erro do SOIL fundo: '%s'\n", SOIL_last_result());
    }
    texturaBack[6] = carregaTextura("Imagens/Back2/7.png");
    glEnable( GL_BLEND );
    glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

    if (texturaBack[6] == 0) {
        printf("Erro do SOIL fundo: '%s'\n", SOIL_last_result());
    }
    texturaBack[7] = carregaTextura("Imagens/Back2/8.png");
    glEnable( GL_BLEND );
    glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

    if (texturaBack[7] == 0) {
        printf("Erro do SOIL fundo: '%s'\n", SOIL_last_result());
    }

    texturaBack[8] = carregaTextura("Imagens/Back2/9.png");
    glEnable( GL_BLEND );
    glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

    if (texturaBack[8] == 0) {
        printf("Erro do SOIL fundo: '%s'\n", SOIL_last_result());
    }
    texturaBack[9] = carregaTextura("Imagens/Back2/10.png");
    glEnable( GL_BLEND );
    glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

    if (texturaBack[9] == 0) {
        printf("Erro do SOIL fundo: '%s'\n", SOIL_last_result());
    }
    texturaBack[10] = carregaTextura("Imagens/Back2/11.png");
    glEnable( GL_BLEND );
    glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

    if (texturaBack[10] == 0) {
        printf("Erro do SOIL fundo: '%s'\n", SOIL_last_result());
    }
    texturaBack[11] = carregaTextura("Imagens/Back2/12.png");
    glEnable( GL_BLEND );
    glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

    if (texturaBack[11] == 0) {
        printf("Erro do SOIL fundo: '%s'\n", SOIL_last_result());
    }

    texturaWin = carregaTextura("Imagens/Titulos/youwin.png");
    glEnable( GL_BLEND );
    glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

    if (texturaBack[11] == 0) {
        printf("Erro do SOIL fundo de Vencedor: '%s'\n", SOIL_last_result());
    }
}