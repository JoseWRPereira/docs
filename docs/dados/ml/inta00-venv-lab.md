---
title: Lab00 - Virtual Environment
icon: fontawesome/solid/flask
author:
 - José W. R. Pereira
tags:
 - Ciência de Dados
 - Inteligência Artificial
 - Aprendizado de Máquina
 - SLTINTA
---

SLTINTA - [Ementa](../../ifsp-slt/dados/sltinta_ementa.md) - [Plano de Aula](../../ifsp-slt/dados/sltinta_plano_aula.md) 

---


#

#

## Ambiente Virtual - *Virtual Environment*

Um **Virtual Environment** (Ambiente Virtual) é uma ferramenta que permite a criação de um **espaço isolado** para o desenvolvimento de projetos em Python, sendo uma prática fortemente recomendada na área de desenvolvimento de software e ciência de dados.

**Propósito Principal**

O objetivo central é permitir que você trabalhe em diferentes projetos na mesma máquina sem que as **versões das bibliotecas entrem em conflito**. Por exemplo, um projeto industrial pode exigir uma versão específica do *TensorFlow* que é incompatível com a versão necessária para outro estudo; o ambiente virtual resolve isso isolando as dependências de cada um.

**Funcionamento**

*   **Isolamento:** Quando um ambiente virtual está ativo, qualquer pacote instalado via `pip` será instalado apenas dentro daquela pasta específica.
*   **Acesso Restrito:** O interpretador Python passará a ter acesso apenas às bibliotecas contidas naquele ambiente, ignorando os pacotes instalados globalmente no sistema (a menos que seja configurado de outra forma).
*   **Ciclo de Uso:** Geralmente, o usuário cria o ambiente, ativa-o (usando comandos como `source env/bin/activate` no Linux/macOS ou `.\env\Scripts\activate` no Windows) para trabalhar e, ao terminar, utiliza o comando `deactivate` para sair.

**Ferramentas Comuns**

*   **virtualenv:** Uma das ferramentas mais tradicionais para criar esses ambientes isolados.
*   **Anaconda (Conda):** Outra alternativa popular que permite criar ambientes com versões específicas do Python (ex: `conda create -n meu_projeto python=3.5`) e gerenciar dependências de forma robusta.

**Alternativas em Nuvem**

Plataformas como o **Google Colab** funcionam como ambientes virtuais baseados na nuvem. Elas eliminam a necessidade de instalação e configuração local, já vindo com as principais bibliotecas de aprendizado de máquina (como *Pandas*, *NumPy* e *TensorFlow*) pré-instaladas, garantindo que diferentes usuários obtenham os mesmos resultados ao executar o código.

**Usando um ambiente virtual**

1) Criando o ambiente virtual

``` python
python3 -m venv venv_sltinta
```

2) Carregando o ambiente virtual

``` python
# GNU/Linux (Debian)
source venv_sltinta/bin/activate

# Windows (PowerShell)
Set-ExecutionPolicy -ExecutionPolicy RemoteSigned -Scope Process

.\venv_sltinta\Scripts\activate

```

3.0) Instalando bibliotecas básicas

``` python
pip install pandas numpy matplotlib seaborn
```

3.1) Listando bibliotecas (requisitos) instaladas

```python
pip freeze
```

3.1.1) Listando e salvando bibliotecas (requisitos) instaladas
```python
pip freeze > requirements.txt
```
Obs: Executar após todos os requisitos do projeto estarem instalados ou sempre que um novo requisito for instalado. 

3.1.2) Instalando requisitos de arquivo

``` python
pip install -r requirements.txt
```

3.2) Instalando kernel para Jupyter
``` python
pip install ipykernel
```

4) Adicionando o ambiente virtual à lista de kernels

``` python
python3 -m ipykernel install --user --name=venv_sltinta
```

4.1) Excluindo o ambiente virtual da lista de kernels

``` python
jupyter-kernelspec uninstall venv_sltinta
```

5) Executando Jupyter notebook

Apenas se estiver instalado no computador. 

``` python
jupyter-lab
# ou
jupyter-notebook
```

