#include <GL/glew.h>      // glew.h deve vir antes
#include <GL/freeglut.h>  // do freeglut.h
#include <stdio.h>
#include <SOIL/SOIL.h>
#include <string.h>
#include <time.h>
#include "Bibliotecas/global.h"
#include "Bibliotecas/inicializacao.h"
#include "Bibliotecas/callbacks.h"
#include "Bibliotecas/desenha.h"
#include "Bibliotecas/calculos.h"
#include "Bibliotecas/ataques.h"
#include "Bibliotecas/telas.h"

// função principal
void atualiza() {

    if (reiniciar ==1){
        vidas =3;
        gameover_conferir = 0;
        score = 0;
        pause = 0;
        nav.alt= 300;
        nav.larg = 100;
        nav.x = 300;
        nav.y = 0;
        inimigos_mortos=0;

        tiro.x = 1000;//fora da tela
        tiro.y = nav.y;
        inicializaInimigos();
        reiniciar = 0;
        creditos=0;
        voltar=0;
    }

    if(pause!=1 && iniciar!=0){

        if(gameover_conferir!=1){
            if(confirmaTiro==1)
                tiro.y+=8;
            if(confirmTiro_inimigo==1)
                tiro_inimigo.y-=8;

            for(int i =0; i<n_inimigos;i++){
                if(inimigo_morto[i]!=1){
                    if(inimigos[i].ataque_agressivo==1){
                        inimigos[i].y -=1;
                        inimigoAtaqueAgr.y-=0.3;
                        if(inimigoAtaqueAgr.alterar_sentido==0) //continua o movimento para o inimigo de ataque agressivo
                            inimigoAtaqueAgr.x -=1;
                        else inimigoAtaqueAgr.x +=1;
                    }else{
                        if(inimigos[i].alterar_sentido==0)
                            inimigos[i].x -=1;
                        else inimigos[i].x +=1;
                        inimigos[i].y -=0.3;
                    }
                }
            }    
        }
    }
    temp +=5;
    if (temp>200){
    temp  = 0;
        quadroAtual = (quadroAtual + 1) % 5;
    }
    temp2 +=5;
    if (temp2>60){
    temp2  = 0;
        b_cont = (b_cont + 1) % 12;
    }
    glutPostRedisplay();
    glutTimerFunc(5, atualiza, 0);
}

int main(int argc, char** argv) {
   glutInit(&argc, argv);

   glutInitContextVersion(1, 1);
   glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
   glutInitWindowSize(window_width, window_height);
   //glutInitWindowPosition(300, 100);
   glutInitWindowPosition(300, 10);

   glutCreateWindow("A Guerra contras as plataformas de video");

   // registra callbacks para alguns eventos
   glutDisplayFunc(desenhaMinhaCena);
   glutReshapeFunc(redimensionada);
   glutTimerFunc(0, atualiza, 0);
   glutKeyboardFunc(teclaPressionada);
   glutSpecialFunc(tecladoEspecial);
   // configura valor inicial de algumas
   // variáveis de estado do OpenGL
   inicializa();

   glutMainLoop();
   return 0;
}