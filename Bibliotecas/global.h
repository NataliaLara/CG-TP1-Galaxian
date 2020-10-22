//#include "metodos.h"
#define n_inimigos 10
#define max_score 10
#define window_width 700
#define window_height 600

GLuint carregaTextura(const char* arquivo);

void desenhaFundo();
void desenhaPlacar();
void desenhaVidas();
void desenhaTiro();
void desenhaInimigos(int i);
void desenhaNave();

void telaPause();
void telaGameOver();
void telaVencedor();
void telaInicial();
void telaCreditos();

void inicializaInimigos();
void inicializaTexturas();
void inicializa();

char * concatenar(char *original, int score);

void redimensionada(int width, int height);
void teclaPressionada(unsigned char key, int x, int y);
void tecladoEspecial(GLint tecla, GLint x, GLint y);
void desenhaMinhaCena();

void atualiza();

void acertoTiroNave();
void acertoTiroInimigo();
void acertoAtaqueAgressivo();
void realizarTiroInimigo();
void realizarAtaqueAgressivo();

GLuint texturaBack[12];
GLuint texturaInimigo,texturaInimigo2,texturaInimigo3,texturaTiroInimigo,texturaGameOver, texturaNave;
GLuint texturaTiro, texturaPausado, texturaEsc,texturaReiniciar,texturaPause,texturaWin, texturaIniciar;
GLuint texturaTitulo, texturaCreditos, texturaVoltar;
GLfloat pos_x;
GLfloat pos_y;
GLint confirmaTiro=0;
GLint movTiro=0;
GLint pause=0;
GLint reiniciar=0;
GLint iniciar=0;
GLint creditos=0;
GLint voltar=0;
char String[1000];

GLint e_cont=0;
GLint d_cont=0;
GLint b_cont=0;
GLint countInimigo=0;

float inimigo_larg = 64;
float inimigo_alt = 160;
int projecao_larg = 800;
int projecao_alt = 2000;
int vidas =3;

int tempo_milisegundos;

char String[1000];
typedef struct cordenada {
    float x, y;
}cord;

typedef struct  tamanho {
    float largura, altura;
}tam;

typedef struct Objeto{
    float x,y;
    float larg, alt;
    int velocidade;//=rand()%20;
    int alterar_sentido;
    int ataque_agressivo;
    float x1,x2,x3,x4;
    float y1, y2, y3,y4; 
}obj;


obj inimigos[n_inimigos];
int inimigo_morto[n_inimigos];
int inimigos_mortos = 0;
int score;
obj nav;
obj tiro;
obj tiro_inimigo;
obj inimigoAtaqueAgr;
int confirmAtaqueAgr = 0;
int confirmTiro_inimigo=0;
int inimigos_vivos;
int quadroAtual = 0;
int blockesq;
int blockdir;
int gameover_conferir = 0;
int tempE=0;
int tempD=0;
int temp =0;
int temp2 = 0;
int ataAgr_inimigo;