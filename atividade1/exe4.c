#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *arq;
  char texto[200];
  char arquivo[20];
  char ler[200];
  int escolha;

  printf("Digite o arquivo que deseja criar ou ler.\n");
  scanf("%[^\n]s", arquivo);

  if ((arq = fopen(arquivo, "a")) == NULL) {
    printf("Arquivo não pôde ser aberto!");
    return 1;
  }
  printf("Digite texto para ser colocado no arquivo ['0' para sair]\n");
  scanf("%[^0]s", texto);
  fputs(texto, arq);
  // fputs("\n", arq);
  fclose(arq);

  if ((arq = fopen(arquivo, "r")) == NULL) {
    printf("Arquivo não pôde ser aberto!");
    return 1;
  }

  int c = getc(arq);
  while (c != EOF) {
    printf("%c", c);
    c = getc(arq);
  }
  getchar();

  fclose(arq);

  if (remove(arquivo) != 0)
    printf("Não foi possivel deletar o arquivo!");

  return 0;
}