#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>


int linhas = 20;
int colunas = 20;
char area[20][20];


int al;
int bl;
int cl;
int dl;
int ac;
int bc;
int cc;
int dc;


int nump;
char lado;
int pontuacao = 0;
int linhacomp =  1;
int acaba = 0;

int linha = 1;
int lbe = 1;
int lbd = 1;
int zte = 1;
int ztd = 1;
int tiv = 1;


void criaarea(){

    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            if(i == 0 || i == linhas - 1 || j == 0 || j == colunas - 1){
                area[i][j] = '.';
            }else{
                area[i][j] = ' ';
            }
        }
    }


}

void limpalinha(int i){
    for(int j = i; j > 1; j--){
        area[j][1] = area[j - 1][1];
        area[j][2] = area[j - 1][2];
        area[j][3] = area[j - 1][3];
        area[j][4] = area[j - 1][4];
        area[j][5] = area[j - 1][5];
        area[j][6] = area[j - 1][6];
        area[j][7] = area[j - 1][7];
        area[j][8] = area[j - 1][8];
        area[j][9] = area[j - 1][9];
        area[j][10] = area[j - 1][10];
        area[j][11] = area[j - 1][11];
        area[j][12] = area[j - 1][12];
        area[j][13] = area[j - 1][13];
        area[j][14] = area[j - 1][14];
        area[j][15] = area[j - 1][15];
        area[j][16] = area[j - 1][16];
        area[j][17] = area[j - 1][17];
        area[j][18] = area[j - 1][18];
    }
    pontuacao += 20;
}

void linhacompletatr(){
    for(int j = 0; j < linhacomp; j++){
        for(int i = linhas - 2; i >= 1; i--){
            if(area[i][1] == '*' &&
            area[i][2] == '*' &&
            area[i][3] == '*' &&
            area[i][4] == '*' &&
            area[i][5] == '*' &&
            area[i][6] == '*' &&
            area[i][7] == '*' &&
            area[i][8] == '*' &&
            area[i][9] == '*' &&
            area[i][10] == '*' &&
            area[i][11] == '*' &&
            area[i][12] == '*' &&
            area[i][13] == '*' &&
            area[i][14] == '*' &&
            area[i][15] == '*' &&
            area[i][16] == '*' &&
            area[i][17] == '*' &&
            area[i][18] == '*'){
                linhacomp++;
                limpalinha(i);
            }
        }
    }


}

void trocapeca(){
    escolhepeca();
}

void *vearea(){

    while(acaba == 0){
        system("cls");
        printf("pontuacao: %d\n", pontuacao);
        imprimearea();

    }
}

void descepecaseg(){
    al++;
    bl++;
    cl++;
    dl++;
}

void *descepeca(){

    while(acaba == 0){

        limpapeca();

        if(area[al + 1][ac] == ' ' && area[bl + 1][bc] == ' ' && area[cl + 1][cc] == ' ' && area[dl + 1][dc] == ' '){
            descepecaseg();
            criapeca();
        }else{
            criapeca();
            linhacompletatr();
            trocapeca();
        }

        sleep(1);
    }
}


void imprimearea(){
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            printf("%c", area[i][j]);
        }
        printf("\n");
    }

}

void criapeca (){
    area[al][ac] = '*';
    area[bl][bc] = '*';
    area[cl][cc] = '*';
    area[dl][dc] = '*';
    area[0][0] = '.';
}

void limpapeca(){
    area[al][ac] = ' ';
    area[bl][bc] = ' ';
    area[cl][cc] = ' ';
    area[dl][dc] = ' ';
}
void escolhepeca(){
    srand(time(0));
    nump = rand() % 7;

    if(nump == 0){ //QUADRADO
        if(area[1][9] == ' ' && area[1][10] == ' ' && area[2][9] == ' ' && area[2][10] == ' ' ){
            al = 1;
            bl = 1;
            cl = 2;
            dl = 2;
            ac = 9;
            bc = 10;
            cc = 9;
            dc = 10;
        }else{
            acaba = 1;
        }

    }else if(nump == 1){ //linha
        if(area[1][8] == ' ' && area[1][9] == ' ' && area[1][10] == ' ' && area[1][11] == ' ' ){
            al = 1;
            bl = 1;
            cl = 1;
            dl = 1;
            ac = 8;
            bc = 9;
            cc = 10;
            dc = 11;
        }else{
            acaba = 1;
        }

    }else if(nump == 2){ //L COM BASE A ESQUERDA
        if(area[1][9] == ' ' && area[2][9] == ' ' && area[2][10] == ' ' && area[2][11] == ' ' ){
            al = 1;
            bl = 2;
            cl = 2;
            dl = 2;
            ac = 9;
            bc = 9;
            cc = 10;
            dc = 11;
        }else{
            acaba = 1;
        }

    }else if(nump == 3){ // COM BASE A DIREITA
        if(area[1][11] == ' ' && area[2][9] == ' ' && area[2][10] == ' ' && area[2][11] == ' ' ){
            al = 1;
            bl = 2;
            cl = 2;
            dl = 2;
            ac = 11;
            bc = 9;
            cc = 10;
            dc = 11;
        }else{
            acaba = 1;
        }

    }else if(nump == 4){ //Z CABE�A A ESQUERDA
        if(area[1][9] == ' ' && area[1][10] == ' ' && area[2][10] == ' ' && area[2][11] == ' ' ){
            al = 1;
            bl = 1;
            cl = 2;
            dl = 2;
            ac = 9;
            bc = 10;
            cc = 10;
            dc = 11;
        }else{
            acaba = 1;
        }

    }else if(nump == 5){  //Z CABE�A A DIREITA
        if(area[1][11] == ' ' && area[1][10] == ' ' && area[2][10] == ' ' && area[2][9] == ' ' ){
            al = 1;
            bl = 1;
            cl = 2;
            dl = 2;
            ac = 11;
            bc = 10;
            cc = 10;
            dc = 9;
        }else{
            acaba = 1;
        }

    }else if(nump == 6){
        if(area[1][10] == ' ' && area[2][9] == ' ' && area[2][10] == ' ' && area[2][11] == ' ' ){
            al = 1;
            bl = 2;
            cl = 2;
            dl = 2;
            ac = 10;
            bc = 9;
            cc = 10;
            dc = 11;
        }else{
            acaba = 1;
        }

    }

    criapeca();

}

void esquerda(){

    limpapeca();

    if(area[al][ac - 1] == ' ' && area[bl][bc - 1] == ' ' && area[cl][cc - 1]== ' ' && area[dl][dc - 1] == ' '){
        ac--;
        bc--;
        cc--;
        dc--;
    }


    criapeca();

}
void direita(){

    limpapeca();

    if(area[al][ac + 1] == ' ' && area[bl][bc + 1] == ' ' && area[cl][cc + 1] == ' ' && area[dl][dc + 1] == ' '){
        ac++;
        bc++;
        cc++;
        dc++;

    }



    criapeca();

}

void girapeca(){

    limpapeca();

    if(nump == 1){

        if(linha == 1){
            if(area[al + 1][bc] == ' ' && area[al + 2][bc] == ' ' && area[al + 2][bc] == ' '){
                ac = bc;
                cc = bc;
                dc = bc;
                bl = al + 1;
                cl = al + 2;
                dl = al + 3;
            }
        }else if(linha == 2){
            if(area[al][bc - 1] == ' ' && area[al][ac + 1] == ' ' && area[al][ac + 3] == ' ' && area[al][ac + 3] == ' '){
                bl = al;
                cl = al;
                dl = al;
                ac = bc - 1;
                bc = ac + 1;
                cc = bc + 1;
                dc = bc + 2;
            }else if(area[al][ac - 1] == ' ' && area[al][ac - 2] == ' ' && area[al][ac - 3] == ' '){
                bl = al;
                cl = al;
                dl = al;
                bc = ac - 1;
                cc = ac - 2;
                dc = ac - 3;
            }else if(area[al][ac + 1] == ' ' && area[al][ac + 2] == ' ' && area[al][ac + 3] == ' '){
                bl = al;
                cl = al;
                dl = al;
                bc = ac + 1;
                cc = ac + 2;
                dc = ac + 3;
            }

        }

        if(linha == 1){
            linha = 2;
        }else{
            linha = 1;
        }

    }if(nump == 2){
        if(lbe == 1){
            if(area[al][ac + 1] == ' ' && area[al + 1][ac] == ' ' && area[al + 2][ac] == ' '){
                bl = al;
                cl = al + 1;
                dl = al + 2;
                bc = ac + 1;
                cc = ac;
                dc = ac;
            }
        }else if(lbe == 2){
            if(area[al][ac - 1] == ' ' && area[al + 1][ac + 1] == ' '){
                ac--;
                bc = ac + 1;
                cc = bc + 1;
                cl = al;
                dl = al + 1;
                dc = cc;
            }else if(area[bl][bc + 1] == ' ' && area[bl +  1][bc + 1] == ' '){
                cc = bc + 1;
                dc = bc +1;
                cl = bl;
                dl = bl + 1;
            }
        }else if(lbe == 3){
            if(area[al + 1][bc] == ' ' && area[al + 2][bc] == ' ' && area[al + 2][ac] == ' '){
                ac++;
                bl++;
                dl = bl + 1;
                dc = bc;
                cl = dl;
                cc = dc - 1;
            }
        }else if(lbe == 4){

            if(area[al][ac - 2] == ' ' && area[bl][bc - 2] == ' ' && area[bl][bc - 1] == ' '){
                ac -= 2;
                bc -= 2;
                cl--;
                dl--;
            }else if(area[al][ac - 1] == ' ' && area[bl][bc - 1] == ' ' && area[bl][bc + 1] == ' '){
                ac--;
                bc--;
                cl = bl;
                cc = bc + 1;
                dl = bl;
                dc = bc + 2;
            }

        }

        if(lbe < 4){
            lbe++;
        }else{
            lbe = 1;
        }
    }else if(nump == 3){
        if(lbd == 1){
            if(area[al][ac - 1] == ' ' && area[cl + 1][cc] == ' ' && area[dl + 1][dc] == ' '){
                ac = cc;
                bc = ac;
                cl = bl +1;
                dl = cl;
            }
        }else if(lbd == 2){
            if(area[al][ac - 1] == ' ' && area[al][ac + 1] == ' ' && area[bl][bc - 1] == ' '){
                ac = bc - 1;
                bl = al;
                cl = al;
                cc = bc + 1;
                dl = cl + 1;
                dc = ac;

            }else if(area[al][ac + 1] == ' ' && area[al][ac + 2] == ' '){
                bl = al;
                bc = ac + 1;
                cl = al;
                cc = bc + 1;
                dl = cl + 1;
                dc = ac;
            }
        }else if(lbd == 3){
            if(area[bl + 1][bc] == ' ' && area[bl + 2][bc] == ' '){
                cl = bl + 1;
                cc = bc;
                dl = cl + 1;
                dc = bc;
            }
        }else if(lbd == 4){
            if(area[bl][bc + 1] == ' ' && area[bl + 1][bc + 1] == ' ' && area[al + 1][ac] == ' '){
                ac = bc + 1;
                bc = cc - 1;
                bl = cl;
                dl = cl;
                dc = cc + 1;
            }else if(area[cl][ac - 1] == ' ' && area[cl][ac] == ' '){
                ac = bc;
                bc = ac - 2;
                bl = al + 1;
                cc = bc + 1;
                dl = al + 1;
            }
        }

        if(lbd == 4){
            lbd = 1;
        }else{
            lbd++;
        }

    }else if(nump == 4){
        if(zte == 1){
            if(area[al + 1][ac] == ' ' && area[al + 2][ac] == ' '){
                ac = bc;
                bl = al + 1;
                bc = ac - 1;
                dl = cl + 1;
                dc = cc - 1;
            }
        }else if(zte == 2){
            if(area[al][ac - 1] == ' ' && area[cl][cc + 1] == ' '){
                ac = cc - 1;
                bc = cc;
                bl = al;
                dl = cl;
                dc = cc + 1;
            }else if(area[al][ac - 1] == ' ' && area[al][ac - 2] == ' '){
                ac -= 2;
                bl = al;
                cc = bc;
                dl = cl;
                dc = cc + 1;
            }
        }

        if(zte == 2){
            zte = 1;
        }else if(zte == 1){
            zte = 2;
        }
    }else if(nump == 5){
        if(ztd == 1){
            if(area[bl + 1][bc] == ' ' && area[bl + 2][bc] == ' '){
                bc = ac;
                bl = al + 1;
                cc += 2;
                dl = cl + 1;
                dc = cc;
            }
        }else if(ztd == 2){
            if(area[al][ac + 1] == ' ' && area[bl][bc - 1] == ' '){
                bl = al;
                bc = ac + 1;
                cc = ac - 1;
                dl = cl;
                dc = ac;
            }else if(area[al][ac + 1] == ' ' && area[al][ac + 2] == ' '){
                ac++;
                bc = ac + 1;
                cc--;
                dl = cl;
                bl = al;
            }
        }

        if(ztd == 2){
            ztd = 1;
        }else if(ztd == 1){
            ztd = 2;
        }
    }else if(nump == 6){
        if(tiv == 1){
            if(area[cl + 1][cc] == ' '){
                bc++;
                cc = bc + 1;
                dl++;
                dc = cc - 1;
            }
        }else if(tiv == 2){
            if(area[al][ac - 1] == ' ' && area[al][ac + 1] == ' '){
                ac--;
                bl = al;
                cl = al;
                dl = al + 1;
            }else if(area[al][ac + 1] == ' ' && area[al][ac + 2] == ' '){
                bl = al;
                cl = al;
                bc = ac + 1;
                cc = ac + 2;
                dl = al + 1;
                dc = bc;
            }
        }else if(tiv == 3){
            if(area[dl + 1][dc] == ' ' && area[dl][dc - 1] == ' '){
                ac++;
                bc = ac - 1;
                bl = al + 1;
                cc = ac;
                cl = al + 1;
                dc = ac;
                dl = cl + 1;
            }
        }else if(tiv == 4){
            if(area[cl][cc + 1] == ' '){
                dl = cl;
                dc = cc + 1;
            }else if(area[al][ac - 1] == ' ' && area[bl][bc - 1] == ' '){
                ac--;
                bc = ac - 1;
                cc = bc + 1;
                dl = cl;
            }
        }

        if(tiv == 4){
            tiv = 1;
        }else{
            tiv++;
        }
    }

    criapeca();
}


int main(){

    criaarea();

    pthread_t thread_id;

    pthread_create(&thread_id, NULL, vearea, 0);

    pthread_create(&thread_id, NULL, descepeca, 0);

    escolhepeca();

    do{
        lado = getch();
        if(lado == 'a' || lado == 'A') esquerda();
        if(lado == 'd' || lado == 'D') direita();
        if(lado == 'w' || lado == 'W') girapeca();
    }while(acaba == 0);


    system("cls");
    printf("PERDEU!\n");
    printf("pontuacao: %d\n", pontuacao);
    imprimearea();




    return 0;
}
