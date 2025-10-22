#include <stdio.h>


//definir os dois tipos de cliente
enum tipoCliente
{
	PESSOA, EMPRESA
};
typedef enum tipoCliente tipoCliente;


//structs usadas em pessoa ou empresa
struct data
{
	int dia, mes, ano;
};
typedef struct data data;

struct endereco
{
	char logradouro[61];
	char complemento[21];
	char bairro[31];
	char cidade[21];
	char cep[9];
	char estado[3];
};
typedef struct endereco endereco;


//structs para tipo pessoa e empresa
struct pessoa
{
	char nome[41];
	char CPF[15];
	char RG[15];
	char sexo;
	data dataNasc;
};
typedef struct pessoa pessoa;

struct empresa
{
	char razao[51];
	char CNPJ[19];
	char inscricaoEst[15];
};
typedef struct empresa empresa;


//uniao (ou é struct tipo pessoa ou struct tipo empresa)
union dadosCliente
{
	pessoa pessoa;
	empresa empresa;
};
typedef union dadosCliente dadosCliente;


//struct cliente em si
struct cliente
{
	tipoCliente tipo;
	endereco endereco;
	dadosCliente dados;
	float limiteCredito;
	data dataCadast;
};
typedef struct cliente cliente;

//interface
int main (void)
{
	cliente c;
	char tipo;
	
	printf ("Informe o tipo de cliente (P - pessoa, E - empresa): ");
	scanf (" %c", &tipo);
	
	if (tipo == 'p' || tipo == 'P')
	{
		c.tipo = PESSOA;
	}
	else
	{
		if (tipo == 'e' || tipo == 'E')
		{
			c.tipo = EMPRESA;
		}
		else
		{
			printf ("\nTipo de cliente invalido");
			return 1;
		}
	}
	
	if (c.tipo == PESSOA)
	{
		printf ("Nome: ");
		scanf ("%s", c.dados.pessoa.nome);
		
		printf ("CPF: ");
		scanf ("%s", c.dados.pessoa.CPF);
		
		printf ("RG: ");
		scanf ("%s", c.dados.pessoa.RG);
		
		printf ("Sexo: ");
		scanf (" %c", c.dados.pessoa.sexo);
		
		printf ("Data de nascimento: ");
		scanf ("%d %d %d", &c.dados.pessoa.dataNasc.dia, &c.dados.pessoa.dataNasc.mes, &c.dados.pessoa.dataNasc.ano);
	}
	else
	{
		printf ("Razao social: ");
		scanf ("%s", c.dados.empresa.razao);
		
		printf ("CNPJ: ");
		scanf ("%s", c.dados.empresa.CNPJ);
		
		printf ("Inscricao estadual: ");
		scanf ("%s", c.dados.empresa.inscricaoEst);
	}
	
	printf ("----Endereco----");
	printf ("\nLogradouro: ");
	scanf ("%s", c.endereco.logradouro);
	
	printf ("Complemento: ");
	scanf ("%s", c.endereco.complemento);
	
	printf ("Bairro: ");
	scanf ("%s", c.endereco.bairro);
	
	printf ("Cidade: ");
	scanf ("%s", c.endereco.cidade);
	
	printf ("CEP: ");
	scanf ("%s", c.endereco.cep);
	
	printf ("Estado (sigla): ");
	scanf ("%s", c.endereco.estado);
	
	printf ("Limite de credito: ");
	scanf ("%f", c.limiteCredito);
	
	printf ("Data de cadastro: ");
	scanf ("%d %d %d", &c.dataCadast.dia, &c.dataCadast.mes, &c.dataCadast.ano);
	
	//exibicao
	printf ("\n\nExibicao dos dados");
	
	if (c.tipo == PESSSOA)
	{
		printf ("\n\nTipo de cliente: Pessoa");
		printf ("\nNome: %s", c.dados.pessoa.nome);
		printf ("\nCPF: %s", c.dados.pessoa.CPF);
		printf ("\nRG: %s", c.dados.pessoa.RG);
		printf ("\nSexo: %c", c.dados.pessoa.sexo);
		printf ("\nData de nascimento: %d/%d/%d", c.dados.pessoa.dataNasc.dia, c.dados.pessoa.dataNasc.mes, c.dados.pessoa.dataNasc.ano);
	}
	else
	{
		printf ("\n\nTipo de cliente: Empresa");
		printf ("\nRazao social: %s", c.dados.empresa.razao);
		printf ("\nCNPJ: %s", c.dados.empresa.CNPJ);
		printf ("\nInscricao estadual: %s", c.dados.empresa.inscricaoEst);
	}
	
	printf ("\n\n----Endereco----");
	printf ("\nLogradouro: %s", c.endereco.logradouro);
	printf ("\nComplemento: %s", c.endereco.complemento);
	printf ("\nBairro: %s", c.endereco.bairro);
	printf ("\nCidade: %s", c.endereco.cidade);
	printf ("\nCEP: %s", c.endereco.cep);
	printf ("\nEstado: %s", c.endereco.estado);
	printf ("\n\nLimite de credito: %f", c.limiteCredito);
	printf ("\nData de cadastro: %d/%d/%d", c.dataCadast.dia, c.dataCadast.mes, c.dataCadast.ano);
	
	return 0;
}
