#include <stdio.h>
#include <io.h>
#include <stdlib.h>
#include <windows.h>
#include <ctype.h>
#include <string.h>


void create_dir();
void file_in();
void remove_file();
void alter_file();

int main() {
    char entrada[100]; 

    printf("Digite o que deseja: Criar, Entrar, Renomear ou Remover: ");
    fgets(entrada, sizeof(entrada), stdin);

    for (int i = 0; entrada[i] != '\0'; i++){
        if(entrada[i] == '\n'){
            entrada[i] = '\0';
            break;
        }        
    }

    for(int i = 0; entrada[i]; i++){
        entrada[i] = tolower(entrada[i]);
    }

    if (strcmp(entrada, "criar") == 0) {
        create_dir();
    } else if (strcmp(entrada, "entrar") == 0) {
        file_in();
    } else if (strcmp(entrada, "renomear") == 0) {
        alter_file();
    } else if (strcmp(entrada, "remover") == 0) {
        remove_file();
    } else {
        printf("Informação inválida:\n");
    }
    
    return 0;
}

void create_dir() {
    char folderName[256]; 

    printf("Digite o nome da pasta que será criada:\n");
    scanf(" %[^\n]", folderName); 
    if (mkdir(folderName) == 0) {
        printf("Pasta criada com sucesso.\n");
    } else {
        printf("Falha ao criar a pasta.\n");
    }
}

void file_in() {
    char folderPath[256];

    printf("Insira o caminho da pasta:\n");
    scanf(" %[^\n]", folderPath);

    printf("Abrindo a pasta no explorador de arquivos...\n");
    char command[512];
    sprintf(command, "explorer.exe \"%s\"", folderPath);
    system(command);
}

void remove_file (){
    char folderPath[256]; 

    printf("Digite o Caminho da pasta que deseja apagar:\n");
    scanf(" %[^\n]", folderPath);

    if(RemoveDirectory(folderPath) != 0){
        printf("Pasta removida com sucesso.\n");
    } else{
        printf("Falha ao remover a pasta.\n");
    }
}

void alter_file() {
    char oldName[256];
    char newName[256];

    printf("Digite o caminho da pasta que você deseja alterar o nome:\n");
    scanf(" %[^\n]", oldName);

    printf("Digite o caminho da pasta que foi alterada e acrescente o novo nome da pasta:\n");
    scanf(" %[^\n]", newName);

    if (rename(oldName, newName) == 0){
        printf("Pasta renomeada com sucesso.\n");
    } else {
        printf("Falha ao renomear pasta.\n");
    }
}
