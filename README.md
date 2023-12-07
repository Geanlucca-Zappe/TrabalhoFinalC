# Dream House Gerenciamento de Locações

## Introdução
Membros: Bruno, Daniel, Geanlucca e Pablo

Este projeto consiste em um sistema de gerenciamento de locações, desenvolvido como parte de um trabalho prático utilizando os conceitos de Programação Orientada a Objetos (POO).

## Estrutura do Projeto

### Descrição das Classes

#### `Locacao`

##### Atributos

- `imovel` (string): Nome do imóvel que está sendo locado.
- `locador` (string): Nome do locador.
- `inquilino` (string): Nome do inquilino.
- `endereco` (string): Endereço do imóvel locado.
- `diaVencimento` (int): Dia de vencimento do pagamento da locação.

##### Métodos

- `Locacao(string uimovel, string ulocador, string uinquilino, string uendereco, int diaVencimento)`: Construtor.
- `getCadastro() const`: Imprime os detalhes da locação.
- `getContaAReceber() const`: Verifica se a conta está a receber e imprime detalhes.
- `getContaVigente() const`: Verifica se a conta está vigente e imprime detalhes.

### Comentários no Código

O código-fonte está devidamente comentado para explicar decisões de design, complexidades e partes críticas do código. Certifique-se de revisar os comentários para entender a implementação.
