#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int MCDEuclide(int,int);
int Euclide(int);
void MCDMain(int);
int kprivata(int,int,int);
int i,r;
int main(int argc, char *argv[]){
	int p,q,n,phi,kpub,kpriv,resto;
	printf("RSA\n\nInserisci p = "); scanf("%d",&p); //inserisco p
	printf("Inserisci q = "); scanf("%d",&q);// inserisco q
	n= p*q; printf("n = %d\n",n); // calcolo e print n
	phi = Euclide(n); printf("phi = %d\n",phi); //calcolo e print phi
	MCDMain(phi);
	printf("chiave pubblica = "); scanf("%d",&kpub);
	/*trovo kpriv*/
	i=1;//metto i = 1 prima di intrare nel do-while
	printf("cercando la chiave privata, aspettare qualche secondo...\n");
	do{
		i++;
		resto = kprivata(i,phi,kpub);
	
	}while(resto != 0);
	kpriv = (i*phi+1)/kpub; printf("chaive privata = %d\n",kpriv);//resto = 0 quindi kpriv = resto + print di kpriv
	int lun,let; //inizializzo lun e let
	printf("inserisci lunghezza parola = "); scanf("%d",&lun); //chiedo all'utente la lunghezza della parola
	for(i=0;i<lun;i++){
		printf("metti il numero della lettera nell' alfabeto = "); scanf("%d",&let);
		int m=1;//imposto m = 1
		int j;
		for(j=1;j<=kpub;j++){
			m= (m*let)%n;
			//printf("%d\t",m);   //print di controllo 
		}
		//m=pow(let,kpriv);	
		printf("lettera codificata: %d\n\n\n",m);
		int scelta;
		printf("DECIFRARE LA LETTERA NUMERO %d ? 1 = si / 0 = no \n",m); scanf("%d",&scelta); //scelta se decifrare, se l'utente mette 1 vuol dire si se mette 0 vuol dire no
		if(scelta == 1){
			let = 1;//imposto let = 1
				for(j=1;j<=kpriv;j++){
					let= (let*m)%n;
				}
			printf("lettera decifrata: %d\n",let);
		}
		printf("RITORNO ALLA CODIFICA\n\n\n");
	}
	return 0;
}
int Euclide(n){
	int somma = 0;
	for(i=1;i<=n;i++){
		int MCDE = MCDEuclide(n,i);
		if(MCDE == 1){
			somma++;
			//printf("%d ",i);//ogni passo per arrivare al risultato
		}
	}
	return somma;
}
int MCDEuclide(b,a){
	do{
	r=a%b;//calcolo resto
	a=b;
	b=r;
	}while(b!=0);
	return a;
	//printf("mcd di %d e %d = %d",A,B,a);
}
void MCDMain(phi){
	for(i=2;i<=10;i++){
	if(phi%i==0){
		printf("il numero %d non e' coprimo con phi\n",i);
	}else
		printf("il numero %d e' coprimo con phi\n",i);
	}
}
int kprivata(i,phi,kpub){
	return (i*phi+1)%kpub;
}
