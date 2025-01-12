#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro() // Função responsável por cadastrar os usuários no sistema

                { // Início da int registro
                    
                    // Início da criação de variáveis (strings)
                    char arquivo[40]; // Variável para armazenar o nome do arquivo (usando o CPF como nome)
                    char cpf[40]; // Variável para armazenar o CPF do usuário
                    char nome[40]; // Variável para armazenar o nome do usuário
                    char sobrenome [40]; // Variável para armazenar o sobrenome do usuário
                    char cargo [40]; // Variável para armazenar o cargo do usuário
                    // Final da criação de variáveis (strings)
                    
                    printf("\nDigite o CPF a ser cadastrado: "); // Coletando informação do usuário
                    scanf("%s",cpf); // %s refere-se à string
                    
                    strcpy(arquivo,cpf); // Responsável por copiar os valores das string
                    
                    // Atributos de criação do Arquivo
                    FILE *file; // Cria o arquivo
                    file = fopen(arquivo,"w"); // Cria o arquivo, 'w' vem de write
                    
                    fprintf(file,"%s", cpf); // Salva o valor da variável
                    fclose(file); // Fecha o arquivo
                    
                    if (file == NULL) // Adicionando uma valição para caso o arquivo não seja salvo
                        { // Começo do IF
                            perror("\nErro ao criar o arquivo.\n");
                            return 1; // Retorna erro
                        } // Fim do IF
                        // Fim dos atributos de criação do Arquivo
                        
                    fprintf(file, "%s", cpf); // Salva o CPF no arquivo
                    fclose(file); // Fecha o arquivo
                    
                    file = fopen(arquivo, "a"); // Abre o arquivo novamente, o "a" é de atualização
                    fprintf(file,","); // Adiciona a vírgula
                    fclose(file); // Fecha o arquivo
                    
                    // Coleta e grava o nome
                        printf("\nDigite o nome a ser cadastrado: "); // Comando pra colocar o nome
                        scanf("%s",nome); // O scanf lê dados do teclado, e o %s diz a ele que deve ler uma string e armazená-la na variável passada.
                        file = fopen(arquivo,"a"); // Abre o arquivo novamente, o "a" é de atualização
                        fprintf(file,"%s,", nome); // O scanf lê dados do teclado, e o %s diz a ele que deve ler uma string e armazená-la na variável passada.
                        fclose(file); // Fecha o arquivo
                    
                    // Coleta e grava o sobrenome
                        printf("\nDigite o sobrenome a ser cadastrado: "); // Comando pra colocar o sobrenome
                        scanf("%s",sobrenome); // O scanf lê dados do teclado, e o %s diz a ele que deve ler uma string e armazená-la na variável passada.
                        file = fopen(arquivo, "a"); // Abre o arquivo novamente, o "a" é de atualização
                        fprintf(file,"%s,",sobrenome); // Salva o sobrenome e adiciona a vírgula
                        fclose(file); // Fecha o arquivo
                    
                    // Coleta e grava o cargo
                        printf("\nDigite o cargo a ser cadastrado: "); // Comando pra colocar o cargo
                        scanf("%s",cargo); // O scanf lê dados do teclado, e o %s diz a ele que deve ler uma string e armazená-la na variável passada.
                        file = fopen(arquivo,"a"); // Abre o arquivo novamente, o "a" é de atualização
                        fprintf(file,"%s.", cargo); // Salva o cargo e adiciona um ponto final
                        fclose(file); // Fecha o arquivo
                    
                        printf("\nUsuário cadastrado com sucesso!\n"); // Confirmação de sucesso
                        
                    // Pausa antes de retornar ao menu
                        printf("\nPressione Enter para retornar ao menu principal...\n"); // Exibe instrução para retornar ao menu
                    
                    getchar(); // Espera o Enter do usuário
                    getchar(); // Captura o Enter
                    
                    return 0; // Finaliza a função
                    
                } // Fim da int registro

int consulta()
                { // Início da int consulta
                    setlocale(LC_ALL,"Portuguese"); // Define a linguagem
                    
                    char cpf[40]; // Declara uma variável para armazenar o CPF do usuário
                    char conteudo[200]; // Declara uma variável para armazenar as informações do usuário que serão lidas do arquivo
                    
                    printf("\nDigite o CPF a ser consultado: "); // Solicita ao usuário o CPF que deseja consultar
                    scanf("%s",cpf); // Lê o CPF digitado pelo usuário e armazena na variável 'cpf'
                    
                    FILE *file; // Declara um ponteiro para um arquivo
                    file = fopen(cpf,"r"); // Tenta abrir o arquivo com o nome igual ao CPF (modo 'r' para leitura - read)
                    
                        if(file == NULL) // Se o arquivo não foi aberto (por exemplo, se não existe)
                            { // Início do IF
                                printf("\nUsuário não localizado. \n"); // Informa que o usuário não foi encontrado
                                printf("\nPressione Enter para retornar ao menu principal. \n"); // Exibe instrução para retornar ao menu
                                getchar(); // Espera o Enter do usuário
                                getchar(); // Para capturar o Enter que ficou no buffer
                                return 0; // Sai da função
                            } // Fim do IF
                        
                        while(fgets(conteudo,200,file)!= NULL) // Enquanto houver conteúdo no arquivo
                            { // Início do while
                                printf("\nEssas são as informações do usuário:"); // Exibe uma mensagem antes de mostrar os dados do usuário
                                printf("%s", conteudo); // Exibe as informações lidas do arquivo
                                printf("\n\n"); // Adiciona uma linha em branco após as informações
                            } // Fim do while
    
                    // Pausa antes de retornar ao menu
                    printf("\nPressione Enter para retornar ao menu principal.\n"); // Exibe instrução para retornar ao menu
    
                    fclose(file); // Fecha o arquivo após terminar a leitura
                    getchar(); // Espera o Enter do usuário
                    getchar(); // Para capturar o Enter que ficou no buffer
                    return 0; // Finaliza a função
    
                } // Fim da int consulta

int deletar()
                { // Início da int deletar
                    setlocale(LC_ALL,"Portuguese"); // Define a linguagem
                    
                    char cpf[40]; // Declara uma variável para armazenar o CPF do usuário
                    
                    printf("\nDigite o CPF do usuário a ser deletado: "); // Solicita ao usuário o CPF do usuário a ser deletado
                    scanf("%s",cpf); // Lê o CPF digitado pelo usuário e armazena na variável 'cpf'
                    
                    FILE *file; // Declara um ponteiro para o arquivo
                    file = fopen(cpf,"r"); // Tenta abrir o arquivo com o nome igual ao CPF no modo de leitura ('r')
                    
                        if(file == NULL) // Se o arquivo não foi encontrado (ou seja, não existe mais)
                            { // Início do IF
                                printf("\nUsuário não se encontrado no sistema!\n"); // Se o arquivo não foi encontrado (ou seja, o usuário não existe no sistema)
                                getchar(); // Espera o Enter do usuário
                                getchar(); // Para capturar o Enter que ficou no buffer
                                return 0;  // Sai da função
                            } // Fim do IF
                    
                    fclose(file);  // Fecha o arquivo após verificar que ele existe
                    
                    // Tenta remover o arquivo com o nome igual ao CPF
    
                        if(remove(cpf) == 0)  // Se o arquivo for removido com sucesso
                            { // Início do IF
                                printf("\nSucesso, o usuário foi deletado.\n");  // Exibe mensagem de sucesso
                            } // Fim do IF
        
                        else  // Se não conseguir remover o arquivo
                            { // Início do else
                                printf("\nErro ao tentar deletar o usuário.\n");  // Exibe mensagem de erro
                            } // Fim do else
                        
                    getchar(); // Espera o Enter do usuário
                    getchar(); // Para capturar o Enter que ficou no buffer
                    return 0; // Finaliza a função
    
                } //Fim da int deletar

int main()
                { // Início da função principal (main)
    
                    int opcao=0; // Declara uma variável para armazenar a opção escolhida pelo usuário
                    int laço=1; // Declara uma variável para controlar o laço de repetição (não é usada no momento)
                    
                    // Laço de repetição infinito (para sempre) até o usuário escolher uma opção válida
                    for(laço=1;(laço=1);) // Dúvida: O mac não deixa simplesmente não usar parentes no segundo laço, não sei qual o impacto.
                        { // Início do laço 'for', que vai continuar executando até ser interrompido manualmente ou até a execução do programa ser finalizada
                            
                            system("clear"); // Limpa a tela para começar o menu novamente, para melhorar a experiência do usuário
                            
                            setlocale(LC_ALL,"Portuguese"); // Define a linguagem

                            // Início do menu de opções
                            printf("\n\n### Cartório da EBAC ###\n\n"); // Exibe o título do menu
                            printf("Escolha a opção desejada do menu:\n\n"); // Solicita que o usuário escolha uma opção
                            printf("\t1- Registrar nomes\n"); // Opção 1: Registrar nomes
                            printf("\t2- Consultar nomes\n"); // Opção 2: Consultar nomes
                            printf("\t3- Deletar nomes\n"); // Opção 3: Deletar nomes
                            printf("\t4- Sair do sistema\n\n"); // Opção 4: Sair do sistema
                            printf("Opção: "); // Solicita ao usuário que digite uma opção
                            // Fim do menu
                        
                            scanf("%d",&opcao); // Lê a opção escolhida pelo usuário e armazena na variável 'opcao'
                        
                            system("clear"); // Limpa a tela novamente para melhorar a apresentação do menu
                            
                            switch (opcao) // Início da estrutura de seleção para tratar as opções escolhidas pelo usuário
                            { // Começo do switch
                                case 1: // Caso a opção escolhida seja 1
                                    registro(); // Chama a função 'registro' para registrar um novo usuário
                                    break; // Encerra o caso 1 e sai do switch
                                    
                                case 2: // Caso a opção escolhida seja 2
                                    consulta(); // Chama a função 'consulta' para buscar informações de um usuário
                                    break; // Encerra o caso 2 e sai do switch
                                    
                                case 3: // Caso a opção escolhida seja 3
                                    deletar(); // Chama a função 'deletar' para excluir um usuário
                                    break; // Encerra o caso 3 e sai do switch
                                
                                case 4: // Caso a opção escolhida seja 4
                                    printf("Obrigado por utilizar o sistema!\n"); // Exibe mensagem de encerramento
                                    return 0; // Finaliza a função
                                    break; // Encerra o caso 4 e sai do switch
                                    
                                default: // Caso o usuário escolha uma opção que não esteja no menu
                                    printf("\nEssa opção não está disponível.\n"); // Exibe mensagem informando que a opção é inválida
                                    getchar(); // Captura o Enter residual no buffer
                                    getchar(); // Aguarda o Enter do usuário
                                    break; // Encerra o bloco 'default' e sai do switch
                                    
                            } // Fim do switch
                        
                        } // Fim do for
                    
                } // Fim da main
