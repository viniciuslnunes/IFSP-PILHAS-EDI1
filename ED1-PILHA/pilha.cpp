#include <iostream>
using  namespace std;

#define MAX 30 //Constante para o numero de elementos

struct No { //Criando no para a pilha
	int num;
	struct No *prox;
};

struct PilhaEnc { //Criando uma pilha com lista encadeada
	No *topo;
};

PilhaEnc* initenc(){ //Iniciando pilha com lista encadeada
	PilhaEnc *p = new PilhaEnc;
	p->topo = NULL;
	return p;
}

void pushenc(PilhaEnc *p, float v) { //Adicionando a pilha com lista encadeada
	No *no = new No;
	no->num = v;
	no->prox = p->topo;
	p->topo = no;
}

int popenc(PilhaEnc *p) { //Retirando da pilha com lista encadeada
	int ret;
	No *no = p->topo;
	ret = no->num;
	p->topo = no->prox;
	free(no);
	return ret;
}

int countenc(PilhaEnc *p) { //Contando elementos na pilha com lista encadeada
	int qtde = 0;
	No *no;
	no = p->topo;
	while(no != NULL) {
        qtde++;   
		no = no->prox;
	}
	return qtde;
}

void printenc(PilhaEnc *p) { //Listando elementos da pilha com lista encadeada
	No *no;
	no = p->topo;
	while(no != NULL) {
		cout << no->num << endl;
		no = no->prox;
	}
	cout << "------------------------" << endl<<endl;
}

void freePilhaEnc(PilhaEnc *p) { //Liberando pilha com lista encadeada
	No *no = p->topo;
	while (no != NULL) {
		No *temp = no->prox;
		free(no);
		no = temp;
	}
	free(p);
}


struct PilhaVet { //Criando na pilha com vetores
	int qtde;
	int nos[MAX];
};

PilhaVet* initvet() { //Iniciando pilha com vetores
	PilhaVet *p = new PilhaVet;
	p->qtde = 0;
	return p;
}

int countvet(PilhaVet *p) { //Contando elementos na pilha com vetores
	return p->qtde;
}

int pushvet(PilhaVet *p, int v) { //Adicionando elementos na pilha com vetores
	int podeEmpilhar = (p->qtde < MAX);
	if (podeEmpilhar) {
		p->nos[p->qtde] = v;
		p->qtde++;
	}
	return podeEmpilhar;
}

int popvet(PilhaVet *p) { //Retirando elementos da pilha com vetores
	int ret;
	int podeDesempilhar = (p->qtde > 0);
	if (podeDesempilhar) {
		ret = p->nos[p->qtde - 1];
		p->qtde--;
	}
	else
	{
		ret = -1;
	}
	return ret;
}

void printvet(PilhaVet *p) { //Listando elementos da pilha com vetores
	for(int i = p->qtde-1; i >= 0; --i) {
		cout << p->nos[i] << endl;
	} 
	cout << "------------------" << endl<<endl;
}

void freePilhaVet(PilhaVet *p) //Liberando pilha com vetores
{
	free(p);
}


int main(int argc, char** argv)
{
	PilhaVet *todos; //Criando pilha com vetores para todos os numeros, com limite de 30
	todos=initvet();
	PilhaEnc *par; //Criando pilha com lista encadeada para os numeros pares, sem limite minimo ou maximo
	par=initenc();
	PilhaEnc *impar; //Criando pilha com lista encadeada para os numeros pares, sem limite minimo ou maximo
	impar=initenc();
	
	int num=0, max=0, ver=0; //Criando variaveis de apoio
	
	while (max<MAX) //Contador para o numero maximo de elementos (constante)
	{
		cout<<"Digite o "<<max+1<<" numero: "<<endl;
		cin>>num;
		max++;
		cout<<endl;
	while(!cin||num<=ver) //Verificador de erro de digitação, garante o numero sempre crescente
	{
		cin.clear();
		cin.ignore();
		cout<<"Numero invalido! Digite um numero inteiro a partir de "<<ver+1<<": ";
		cin>>num;
	}
	ver=num;
	if(num%2==0) //Verificador para par ou impar, acrescentando na respectiva estrutura
	{
		pushenc(par,num);
	}
	else
	{
		pushenc(impar,num);
	}
	pushvet(todos,num); //Acrescentando no vetor total
	}
	
	cout<<"-Numeros pares-"<<endl; //Contando e listando os numeros pares
	cout<<"Quantidade de numeros pares: "<<countenc(par)<<endl;
	cout<<"Pilha de numeros pares:"<<endl;
	printenc(par);
	
	cout<<"-Numeros impares-"<<endl; //Contando e listando os numeros impares
	cout<<"Quantidade de numeros impares: "<<countenc(impar)<<endl;
	cout<<"Pilha de numeros impares:"<<endl;
	printenc(impar);
		
	while(todos->qtde>0) //Desempilhando e mostrando os elementos da pilha total
	{
	cout<<"Retirando o numero maior da pilha: "<<popvet(todos)<<endl;		
	}
	
	cout<<"Total de numeros apos desempilhar: "<<countvet(todos)<<endl; //Garantindo que não há nenhum numero na pilha
	
	freePilhaVet(todos); //Liberando memoria
	freePilhaEnc(par); //Liberando memoria
	freePilhaEnc(impar); //Liberando memoria
	
	return 0;
}