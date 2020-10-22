void acertoTiroNave(){
    for(int i = 0; i<n_inimigos;i++){
        //Colisao
        if((tiro.x>=inimigos[i].x-inimigos[i].larg)&&(tiro.x<=inimigos[i].x)&&(tiro.y>=inimigos[i].y-inimigos[i].alt)&&(tiro.y<=inimigos[i].y)){
            if(inimigo_morto[i]!=1){
                inimigo_morto[i] = 1;
                inimigos_mortos++;
                score++;
                confirmaTiro = 0;
                tiro.y = 0;
                tiro.x = 1000;
                confirmaTiro = 0;
            }
            
        }else{
            desenhaInimigos(i);                            
        }
    } 
}

void acertoTiroInimigo(){
    if(confirmTiro_inimigo==1){
                    
        if(  ( ( tiro_inimigo.x>=nav.x  &&   tiro_inimigo.x<=nav.x+nav.larg) || 
                ( tiro_inimigo.x+ tiro_inimigo.larg>=nav.x &&  tiro_inimigo.x+ tiro_inimigo.larg<=nav.x+nav.larg))
            && (( tiro_inimigo.y>= nav.y &&  tiro_inimigo.y<=nav.y+nav.alt) ||
            ( tiro_inimigo.y+ tiro_inimigo.alt>= nav.y &&  tiro_inimigo.y+ tiro_inimigo.alt<=nav.y+nav.alt)) )   
        {
            vidas--;
            confirmTiro_inimigo=0;                    
            if(vidas<0){
                gameover_conferir=1;
            }
        }
    }
}

void acertoAtaqueAgressivo(){
    if(confirmAtaqueAgr==1){
                        
        if(  ( ( inimigos[ataAgr_inimigo].x>=nav.x  &&   inimigos[ataAgr_inimigo].x<=nav.x+nav.larg) || 
                    ( inimigos[ataAgr_inimigo].x+ inimigos[ataAgr_inimigo].larg>=nav.x &&  inimigos[ataAgr_inimigo].x+ inimigos[ataAgr_inimigo].larg<=nav.x+nav.larg))
                && ((inimigos[ataAgr_inimigo].y>= nav.y &&  inimigos[ataAgr_inimigo].y<=nav.y+nav.alt) ||
                ( inimigos[ataAgr_inimigo].y+ inimigos[ataAgr_inimigo].alt>= nav.y &&  inimigos[ataAgr_inimigo].y+ inimigos[ataAgr_inimigo].alt<=nav.y+nav.alt)) )   
            {
       
                gameover_conferir=1;          
                confirmAtaqueAgr=0;
                inimigos[ataAgr_inimigo].ataque_agressivo=0;
        }  
        
    }
}

void realizarTiroInimigo(){
    if(tempo_milisegundos%300==0){        
        int inimigo= rand()%10;
        while(inimigo_morto[inimigo] == 1){
            inimigo = inimigo+1;
            inimigo = inimigo%10;
        }
        tiro_inimigo = inimigos[inimigo];  
        tiro_inimigo.alt=nav.alt;
        tiro_inimigo.larg=nav.larg;
        confirmTiro_inimigo=1;    

        desenhaTiro();
    }  
}

void realizarAtaqueAgressivo(){
    if(tempo_milisegundos%2000==0){
        int inimigo= rand()%10;
        while(inimigo_morto[inimigo] == 1){
            inimigo = inimigo+1;
            inimigo = inimigo%10;
        }
        inimigos[inimigo].ataque_agressivo=1;
        confirmAtaqueAgr=1;
        inimigoAtaqueAgr = inimigos[inimigo]; //objeto que recebe o inimigo antes do modo ataque agressivo
        ataAgr_inimigo=inimigo;
    }
}