# Atividade Estruturada 2 - Estrutura de Dados

Atividade respondida referente à disciplina **Estrutura de Dados** do curso de **Ciência da Computação**, sob orientação do professor **Afonso Nirton**.

---

# Atividade Estruturada 2 Respondida - Parte Teórica

## Questão 1

### A) Variáveis Globais, Locais e Escopo

#### Variável Global

```c
int x = 20;
```

Variável declarada fora de qualquer função. Pode ser acessada por todas as funções do programa e permanece na memória durante toda a execução.

#### Variáveis Locais

Dentro da função `main`:

```c
int numero = 10;
int outroNumero;
```

São variáveis criadas dentro de um bloco específico de código e existem apenas durante a execução desse bloco.

#### Escopo

Escopo define a região do código onde uma variável ou função é reconhecida e pode ser acessada. Ele determina a visibilidade e o tempo de vida de um dado na memória.

No caso das variáveis declaradas dentro da função `main`, elas só existem enquanto a função estiver em execução.

---

### Dentro da função Teste1

```c
void Teste1(int numero)
```

**Variáveis locais:**

* `numero`

**Escopo:**

* Existe apenas dentro da função `Teste1`.
* Quando a função termina, a variável é destruída.

---

### Dentro da função Teste2

```c
void Teste2(int *numero)
{
    int valor = 100;
}
```

**Variáveis locais:**

* `numero` (ponteiro/parâmetro)
* `valor`

**Escopo:**

* Existem apenas dentro da função `Teste2`.
* São destruídas quando a função termina.

---

### Dentro da função Teste3

```c
int Teste3(int n)
{
    int valor = 200;
}
```

**Variáveis locais:**

* `n`
* `valor`

**Escopo:**

* Existem apenas dentro da função `Teste3`.
* São destruídas ao final da execução da função.

---

## B) Tipo de Passagem de Parâmetros

### Função Teste1

```c
void Teste1(int numero)
```

**Tipo:** Passagem por valor.

A função recebe apenas uma cópia da variável original. Alterações realizadas em `numero` não afetam a variável da função `main`.

---

### Função Teste2

```c
void Teste2(int *numero)
```

**Tipo:** Passagem por referência (utilizando ponteiros).

A função recebe o endereço da variável original.

Exemplo:

```c
*numero = *numero + valor;
```

Nesse caso, a variável original é modificada diretamente.

---

### Função Teste3

```c
int Teste3(int n)
```

**Tipo:** Passagem por valor.

A variável `n` recebe apenas uma cópia de `numero`. As alterações realizadas dentro da função não afetam a variável original da `main`.

---

## C) Passo a Passo das Variáveis

### Estado Inicial

#### Variáveis na Memória

**Global:**

```c
x = 20;
```

**Main:**

```c
numero = 10;
outroNumero = lixo de memória;
```

---

### Chamada da função Teste1(numero)

A função recebe uma cópia:

```c
numero = 10;
```

#### Dentro de Teste1

Linha executada:

```c
numero = numero + x;
```

Cálculo:

```c
numero = 10 + 20;
numero = 30;
```

Depois:

```c
x++;
```

Resultado:

```c
x = 21;
```

#### Fim de Teste1

A variável local:

```c
numero
```

é destruída.

Na função `main`:

```c
numero = 10;
```

permanece inalterado.

#### Após Teste1

```c
numero = 10;
x = 21;
```

---

### Chamada da função Teste2(&numero)

É enviado o endereço de `numero`.

#### Dentro de Teste2

Variáveis locais:

```c
valor = 100;
numero -> aponta para numero da main;
```

Linha executada:

```c
*numero = *numero + valor;
```

Cálculo:

```c
*numero = 10 + 100;
*numero = 110;
```

A variável original é modificada:

```c
numero = 110;
```

Depois:

```c
x++;
```

Resultado:

```c
x = 22;
```

#### Fim de Teste2

As variáveis locais:

```c
valor
numero
```

são destruídas.

#### Após Teste2

```c
numero = 110;
x = 22;
```

---

### Chamada da função Teste3(numero)

É enviada uma cópia de `numero`.

```c
n = 110;
```

#### Dentro de Teste3

Variáveis locais:

```c
n = 110;
valor = 200;
```

Linha executada:

```c
n = n + valor;
```

Cálculo:

```c
n = 110 + 200;
n = 310;
```

Depois:

```c
x--;
```

Resultado:

```c
x = 21;
```

Retorno:

```c
return 310;
```

#### Fim de Teste3

As variáveis locais:

```c
n
valor
```

são destruídas.

#### Após Teste3

Na função `main`:

```c
outroNumero = 310;
numero = 110;
x = 21;
```

---

## D) O que é Impresso na Tela

### Saída Final

```text
Valor de numero (apos Teste1) = 10
X = 21

Valor de numero (apos Teste2) = 110
X = 22

Valor de outro numero (apos Teste3) = 310
X = 21
```

---

