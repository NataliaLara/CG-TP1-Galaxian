void telaPause(){
    glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, texturaEsc);
        glBegin(GL_POLYGON);
            glTexCoord2f(0, 0);
            glVertex3f(200, 400,  0);
            glTexCoord2f(1, 0);
            glVertex3f( 600,  400,  0);
            glTexCoord2f(1, 1);
            glVertex3f( 600,  600,  0);
            glTexCoord2f(0, 1);
            glVertex3f(200, 600,  0);
        glEnd();
        glDisable(GL_TEXTURE_2D);

        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, texturaReiniciar);
        glBegin(GL_POLYGON);
            glTexCoord2f(0, 0);
            glVertex3f(200, 700,  0);
            glTexCoord2f(1, 0);
            glVertex3f( 600,  700,  0);
            glTexCoord2f(1, 1);
            glVertex3f( 600,  900,  0);
            glTexCoord2f(0, 1);
            glVertex3f(200, 900,  0);
        glEnd();
        glDisable(GL_TEXTURE_2D);

        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, texturaPause);
        glBegin(GL_POLYGON);
            glTexCoord2f(0, 0);
            glVertex3f(200, 1000,  0);
            glTexCoord2f(1, 0);
            glVertex3f( 600,  1000,  0);
            glTexCoord2f(1, 1);
            glVertex3f( 600,  1200,  0);
            glTexCoord2f(0, 1);
            glVertex3f(200, 1200,  0);
        glEnd();
        glDisable(GL_TEXTURE_2D);

        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, texturaPausado);
        glBegin(GL_POLYGON);
            glTexCoord2f(0, 0);
            glVertex3f(100, 1500,  0);
            glTexCoord2f(1, 0);
            glVertex3f( 700,  1500,  0);
            glTexCoord2f(1, 1);
            glVertex3f( 700,  1800,  0);
            glTexCoord2f(0, 1);
            glVertex3f(100, 1800,  0);
        glEnd();
        glDisable(GL_TEXTURE_2D);
}

void telaGameOver(){
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texturaGameOver);
    glBegin(GL_TRIANGLE_FAN);
        glTexCoord2f(0, 0);
        glVertex3f(150, 400,  0);
        glTexCoord2f(1, 0);
        glVertex3f( 650,  400,  0);
        glTexCoord2f(1, 1);
        glVertex3f( 650,  1600,  0);
        glTexCoord2f(0, 1);
        glVertex3f(150, 1600,  0);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texturaEsc);
    glBegin(GL_POLYGON);
        glTexCoord2f(0, 0);
        glVertex3f(0, 1750,  0);
        glTexCoord2f(1, 0);
        glVertex3f( 230,  1750,  0);
        glTexCoord2f(1, 1);
        glVertex3f( 230,  1900,  0);
        glTexCoord2f(0, 1);
        glVertex3f(0, 1900,  0);
    glEnd();
    glDisable(GL_TEXTURE_2D);

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texturaReiniciar);
    glBegin(GL_POLYGON);
        glTexCoord2f(0, 0);
        glVertex3f(200, 150,  0);
        glTexCoord2f(1, 0);
        glVertex3f( 600,  150,  0);
        glTexCoord2f(1, 1);
        glVertex3f( 600,  300,  0);
        glTexCoord2f(0, 1);
        glVertex3f(200, 300,  0);
    glEnd();
    glDisable(GL_TEXTURE_2D);
}

void telaVencedor(){
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texturaWin);
    glBegin(GL_TRIANGLE_FAN);
        glTexCoord2f(0, 0);
        glVertex3f(150, 400,  0);
        glTexCoord2f(1, 0);
        glVertex3f( 650,  400,  0);
        glTexCoord2f(1, 1);
        glVertex3f( 650,  1600,  0);
        glTexCoord2f(0, 1);
        glVertex3f(150, 1600,  0);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texturaEsc);
    glBegin(GL_POLYGON);
        glTexCoord2f(0, 0);
        glVertex3f(0, 1750,  0);
        glTexCoord2f(1, 0);
        glVertex3f( 230,  1750,  0);
        glTexCoord2f(1, 1);
        glVertex3f( 230,  1900,  0);
        glTexCoord2f(0, 1);
        glVertex3f(0, 1900,  0);
    glEnd();
    glDisable(GL_TEXTURE_2D);

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texturaReiniciar);
    glBegin(GL_POLYGON);
        glTexCoord2f(0, 0);
        glVertex3f(200, 150,  0);
        glTexCoord2f(1, 0);
        glVertex3f( 600,  150,  0);
        glTexCoord2f(1, 1);
        glVertex3f( 600,  300,  0);
        glTexCoord2f(0, 1);
        glVertex3f(200, 300,  0);
    glEnd();
    glDisable(GL_TEXTURE_2D);
}

void telaInicial(){

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texturaTitulo);
    glBegin(GL_POLYGON);
        glTexCoord2f(0, 0);
        glVertex3f(100, 1200,  0);
        glTexCoord2f(1, 0);
        glVertex3f( 700,  1200,  0);
        glTexCoord2f(1, 1);
        glVertex3f( 700,  1500,  0);
        glTexCoord2f(0, 1);
        glVertex3f(100, 1500,  0);
    glEnd();
    glDisable(GL_TEXTURE_2D);

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texturaIniciar);
    glBegin(GL_POLYGON);
        glTexCoord2f(0, 0);
        glVertex3f(200, 700,  0);
        glTexCoord2f(1, 0);
        glVertex3f( 600,  700,  0);
        glTexCoord2f(1, 1);
        glVertex3f( 600,  900,  0);
        glTexCoord2f(0, 1);
        glVertex3f(200, 900,  0);
    glEnd();
    glDisable(GL_TEXTURE_2D);

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texturaCreditos);
    glBegin(GL_POLYGON);
        glTexCoord2f(0, 0);
        glVertex3f(200, 400,  0);
        glTexCoord2f(1, 0);
        glVertex3f( 600,  400,  0);
        glTexCoord2f(1, 1);
        glVertex3f( 600,  600,  0);
        glTexCoord2f(0, 1);
        glVertex3f(200, 600,  0);
    glEnd();
    glDisable(GL_TEXTURE_2D);

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texturaEsc);
    glBegin(GL_POLYGON);
        glTexCoord2f(0, 0);
        glVertex3f(200, 100,  0);
        glTexCoord2f(1, 0);
        glVertex3f( 600,  100,  0);
        glTexCoord2f(1, 1);
        glVertex3f( 600,  300,  0);
        glTexCoord2f(0, 1);
        glVertex3f(200, 300,  0);
    glEnd();
    glDisable(GL_TEXTURE_2D);
}

void telaCreditos(){
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texturaVoltar);
    glBegin(GL_POLYGON);
        glTexCoord2f(0, 0);
        glVertex3f(200, 400,  0);
        glTexCoord2f(1, 0);
        glVertex3f( 600,  400,  0);
        glTexCoord2f(1, 1);
        glVertex3f( 600,  600,  0);
        glTexCoord2f(0, 1);
        glVertex3f(200, 600,  0);
    glEnd();
    glDisable(GL_TEXTURE_2D);

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texturaEsc);
    glBegin(GL_POLYGON);
        glTexCoord2f(0, 0);
        glVertex3f(200, 100,  0);
        glTexCoord2f(1, 0);
        glVertex3f( 600,  100,  0);
        glTexCoord2f(1, 1);
        glVertex3f( 600,  300,  0);
        glTexCoord2f(0, 1);
        glVertex3f(200, 300,  0);
    glEnd();
    glDisable(GL_TEXTURE_2D);
}