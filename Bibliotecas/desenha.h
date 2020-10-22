void desenhaFundo(){
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texturaBack[b_cont]);
        glBegin(GL_POLYGON);
            glTexCoord2f(0, 0);
            glVertex3f(0, 0,  0);
            glTexCoord2f(1, 0);
            glVertex3f( 800,  0,  0);
            glTexCoord2f(1, 1);
            glVertex3f( 800,  2000,  0);
            glTexCoord2f(0, 1);
            glVertex3f(0, 2000,  0);
        glEnd();
    glDisable(GL_TEXTURE_2D);
}

void desenhaNomes(){

}

void desenhaVidas(){
    glColor3f(0, 0, 0);
    glRasterPos2f(20, projecao_alt-200);
                        
    char* vidasRestantes = concatenar("Vidas: ",vidas);
    while (*vidasRestantes  != '\0') {
        //FONTES do Texto
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, *vidasRestantes ++);
        //glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *placar++);
        //glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *placar++);
        //glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *placar++);
    }
    glColor3f(1, 1, 1);
}

void desenhaPlacar(){
    glColor3f(0, 0, 0);
        glRasterPos2f(20, projecao_alt-100);
                            
        char* placar = concatenar("Score: ",score);
        while (*placar != '\0') {
            //FONTES do Texto
            glutBitmapCharacter(GLUT_BITMAP_9_BY_15, *placar++);
            //glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *placar++);
            //glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *placar++);
            //glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *placar++);
        }
    glColor3f(1, 1, 1);
}

void desenhaTiro(){
    //tiro da nave
    if(confirmaTiro==1){
        glPushMatrix(); // Importante!!
        glTranslatef(tiro.x, tiro.y, 0);
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, texturaTiro);
        glBegin(GL_TRIANGLE_FAN);
            glTexCoord2f(0, 0);   glVertex3f(0, 0,  0);
            glTexCoord2f(1, 0);   glVertex3f( 100,  0,  0);
            glTexCoord2f(1, 1);   glVertex3f( 100,  300,  0);
            glTexCoord2f(0, 1);   glVertex3f(0, 300,  0);
        glEnd();
        glDisable(GL_TEXTURE_2D);
        glPopMatrix();
    }
    //tiro inimigo
    if(confirmTiro_inimigo==1){
        glPushMatrix(); // Importante!!
        glTranslatef(tiro_inimigo.x, tiro_inimigo.y, 0);
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, texturaTiro);
        glBegin(GL_TRIANGLE_FAN);
            glTexCoord2f(0, 0); glVertex3f(0, 0,  0);
            glTexCoord2f(1, 0); glVertex3f( tiro_inimigo.larg,  0,  0);
            glTexCoord2f(1, 1); glVertex3f( tiro_inimigo.larg,  tiro_inimigo.alt,  0);
            glTexCoord2f(0, 1);glVertex3f(0, tiro_inimigo.alt,  0);
        glEnd();
        glDisable(GL_TEXTURE_2D);
        glPopMatrix();
    }
}

void desenhaInimigos(int i){
     if(inimigo_morto[i] ==0){
        glPushMatrix(); // Importante!!
        glTranslatef(inimigos[i].x, inimigos[i].y, 0);
        if(confirmAtaqueAgr==1){
            if(inimigoAtaqueAgr.x<15) inimigoAtaqueAgr.alterar_sentido = 1;
            if(inimigoAtaqueAgr.x>680) inimigoAtaqueAgr.alterar_sentido = 0;
        }
        if(inimigos[i].x<15) inimigos[i].alterar_sentido = 1;
        if(inimigos[i].x>680) inimigos[i].alterar_sentido = 0;
        glEnable(GL_TEXTURE_2D);
        if(i<=2)
            glBindTexture(GL_TEXTURE_2D, texturaInimigo);
        if(i>2 && i<=5)
            glBindTexture(GL_TEXTURE_2D, texturaInimigo2);
        if(i>5)
            glBindTexture(GL_TEXTURE_2D, texturaInimigo3);
        glBegin(GL_TRIANGLE_FAN);
            glTexCoord2f(0, 0);
            glVertex3f(0, 0,  0);
            glTexCoord2f(1, 0);
            glVertex3f( 64,  0,  0);
            glTexCoord2f(1, 1);
            glVertex3f( 64,  160,  0);
            glTexCoord2f(0, 1);
            glVertex3f(0, 160,  0);
        glEnd();
        glDisable(GL_TEXTURE_2D);
        glPopMatrix();
    }
}

void desenhaNave(){
    float comprimentoDaTextura = 751;
    float larguraDatextura = 381;
    int numeroDeQuadros = 5;
    float quadroDaTextura = comprimentoDaTextura / numeroDeQuadros;

    // coordenadas da textura
    float tamanhoDoQuadro = 1.f / numeroDeQuadros;
    float c0 = quadroAtual * tamanhoDoQuadro;
    glPushMatrix(); // Importante!!
    glTranslatef(nav.x, nav.y, 0);
    if(nav.x<15) blockesq = 1;
    if(nav.x>680) blockdir = 1;
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texturaNave);
    glBegin(GL_TRIANGLE_FAN);
        glTexCoord2f(c0, 0);
        glVertex3f(0, 0,  0);
        glTexCoord2f(c0 + tamanhoDoQuadro, 0);
        glVertex3f( 100,  0,  0);
        glTexCoord2f(c0 + tamanhoDoQuadro, 1);
        glVertex3f( 100,  300,  0);
        glTexCoord2f(c0, 1);
        glVertex3f(0, 300,  0);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
}