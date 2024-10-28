bool valid = false;
S = pilha vazia;
char valor[MAX_VALOR];

printf("Digite os caracteres: ");
scanf("%s", &valor);

for (começando do começo da variável valor e terminando no seu fim){
    char valor_atual = valor[posição da leitura do for];
		if(valor_atual != '1' && valor_atual != '0' && valor_atual != '+'){
			printf("ERRO: So podem existir caracteres '0', '1' e '+'.");
			return 1;
		}
		if(valor_atual == '+'){
			if(empty(&S)){
				printf("ERRO: Devem existir caracteres antes do '+' para ser comparado.");
				return 1;
			}
			if(valid){
				printf("ERRO: So pode existir um '+'.");
				return 1;
			}
			valid = true;
		} else {
			if(valid){
				if(top(&S) != valor_atual || empty(&S)){
					printf("ERRO: Nao e o inverso.");
					printf("\nItens comparados: %c %c", valor_atual, top(&S));
					return 1;
				}
				pop(&S);
			} else {
				push(valor_atual, &S);
			}
		}
	}
	if(valid == false){
		printf("ERRO: Só deve existir '+' para ser comparado.");
		return 1;
	}
	if(!empty(&S)){
		printf("ERRO: Os valores nao sao inversos.");
		printf("Quantidade de valores restantes: %i %c", S.top, top(&S));
		return 1;
	}
	
	printf("Os valores de fato sao inversos.");
	
	return 0;
}
