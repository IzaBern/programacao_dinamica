#include <bits/stdc++.h>
using namespace std;

int corte(int *so, int *peso, int k){
    //caso ainda não tenha calculado
    if (so[k] == -1){ 
        int lucro = -1, valor;
        for(int i=1; i<=k; i++){
            //compara se vale a pena pegar o corte menor
            //mais seu peso ou manter o lucro anterior
            //para cada soluçao otima de corte inferior
            valor = peso[i] + corte(so, peso, k-i);
            if(valor > lucro){
                lucro = valor;
            }
        }
        so[k] = lucro;
    }
    //caso já tenha sido calculado
    return so[k];
}
int main(){
    int n, t; //t é o tamanho do cano
    cin >> n >> t;
    int solucao[t+1], peso[t+1];
    solucao[0] = 0;
    peso[0] = 0;
    for(int i=1; i<=t; i++){
        solucao[i] = -1;
        peso[i] = 0;
    }
    //leitura de N valores de corte
    for(int i=0; i<n; i++){
        //comprimento e valor correspondente
        int comp, valor; 
        cin >> comp >> valor;
        //se o corte for maior que o tamanho T
        //do cano, é descartado
        if(comp > t) continue;
        //caso já exista esse valor para esse
        //comprimento, substitua só se for maior
        if(peso[comp] != 0){
            if(valor > peso[comp])
            peso[comp] = valor;
        }else{
            peso[comp] = valor;
        }
    }
    //faz a chamada da funçao corte que devolve
    //a solucao ótima para cano de tamanho T
    int tamanho = corte(solucao, peso, t);
    cout << tamanho << endl;
}