char * concatenar(char *original, int score) {
    char buf[10];
        // inteiro para string. Até 10 algarísmos.
        sprintf(buf, "%i", score);
    char* add =(char*)buf;

    //printf("placar:%s",original);
    char* novo,*top;
    novo= malloc (1+sizeof (original)+sizeof(add));
    top=novo;
    while (*original!='\0'){        
        *novo = *original;
        novo++;
        original++;
    }  
    
    while (*add!='\0') {
        *novo = *add;
        add++;
        novo++;
    }
    *novo = '\0';
    return top;
}

