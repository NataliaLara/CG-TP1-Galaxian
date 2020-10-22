
// NOVIDADE: callback para o evento "reshape"
void redimensionada(int width, int height) {
   glViewport(0, 0, width, height);

   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(0, 800, 0, 2000, -1, 1);

   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

// NOVIDADE: callback de "keyboard"
void teclaPressionada(unsigned char key, int x, int y) {
    // vê qual tecla foi pressionada
    switch(key) {

    case 27:      // Tecla "ESC"
        exit(0);  // Sai da aplicação
        break;

    case 32://espaço
        if(confirmaTiro==0){
            confirmaTiro = 1;
            tiro.x = nav.x;
            tiro.y=100;
            glutPostRedisplay();
        }
        break;
    case 100: //d
            blockesq = 0;
            if(blockdir!=1){
                if(gameover_conferir!=1)
                    nav.x += 10;
            }else
                blockdir = 0;

            glutPostRedisplay();
        break;
    case 97: //a

            blockdir = 0;
            if(blockesq!=1){
                if(gameover_conferir!=1)
                    nav.x -= 10;
            }else
                blockesq = 0;

            glutPostRedisplay();
            break;
        break;

    case 112://p
        if(pause == 0){
            pause = 1;
        }else{
            pause = 0;
        }
        break;
    case 114://r
        reiniciar = 1;
        break;
    
    case 115://s
        iniciar = 1;
        break;

    case 105: //i
        iniciar =1;
        break;
    
    case 99: //c
        creditos =1;
        break;
    case 118: //v
        voltar=1;
        break;

    default:

        break;
    }
}

void tecladoEspecial(GLint tecla, GLint x, GLint y){
    switch(tecla){
    case GLUT_KEY_LEFT:

                blockdir = 0;
                if(blockesq!=1){
                    if(gameover_conferir!=1)
                        nav.x -= 10;
                }else
                    blockesq = 0;

                glutPostRedisplay();
                break;
        case GLUT_KEY_RIGHT:

                blockesq = 0;
                if(blockdir!=1){
                    if(gameover_conferir!=1)
                        nav.x += 10;
                }else
                    blockdir = 0;

                glutPostRedisplay();
                break;

        default:

            break;
    }
}

// callback de desenho (display)
void desenhaMinhaCena() {
    desenhaFundo();

    if(creditos==1){
        telaCreditos();
        if (voltar==1){
            creditos=0;
            voltar=0;
        }
    }
    if(iniciar==0 && creditos==0){
        telaInicial();
    }
    if(iniciar==1){

        if(score==n_inimigos ||inimigos_mortos==n_inimigos){
                telaVencedor();
        }    
        else
        {     
            if (pause!=1){        
                for (int i=0;i<n_inimigos;i++){   
                    if((inimigos[i].y<=0 && inimigos[i].ataque_agressivo==0)||vidas<0 ||gameover_conferir==1){        
                        gameover_conferir = 1;
                        telaGameOver();
                    }
                }
                
                if((gameover_conferir!=1)&&(score<10)){
                    desenhaPlacar();
                    desenhaVidas();

                    desenhaNave();                    
                    
                    acertoTiroNave(); //metodo para verificar se a nave acertou o inimigo / colisao

                    tempo_milisegundos=(clock()/(CLOCKS_PER_SEC/1000));
                    
                    realizarAtaqueAgressivo();//realizar Ataque mais agressivo                    

                    acertoAtaqueAgressivo();//Detectando acerto de ataque mais agressivo                    
                    
                    realizarTiroInimigo();//Lançar tiro do inimigo                              

                    acertoTiroInimigo(); //Detectando acerto de tiro do inimigo  
                                             
                    //reseta tiro da nave
                    if(tiro.y >=2000){ 
                        tiro.y = 0;
                        confirmaTiro = 0;
                        tiro.x = 1000;
                    }

                    //resetando tiro inimigo
                    if(tiro_inimigo.y<=0 ){
                        confirmTiro_inimigo=0;
                    }
                    //resetando ataque agressivo
                    if(inimigos[ataAgr_inimigo].y<=0 &&confirmAtaqueAgr==1){
                        confirmAtaqueAgr=0;
                        //inimigo_morto[ataAgr_inimigo]=1;                        
                        inimigos[ataAgr_inimigo]=inimigoAtaqueAgr;
                        inimigos[ataAgr_inimigo].ataque_agressivo=0;
                        //inimigos_mortos++;
                    }
                    
                    desenhaTiro();
                }
                    
            }else{

                telaPause(); 
            }
        }
    }
    glutSwapBuffers();
}