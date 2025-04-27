---
title: Ferramentas
icon: fontawesome/solid/computer
author:
 - José W. R. Pereira
tags:
 - Ciência de Dados
 - Inteligência Artificial
 - Aprendizado de Máquina
---

![JuPyteR](img/jupyter_julia_python_r.png)

# Ferramentas para Análise de Dados e Machine Learning

**Linguagem de Programação**

A linguagem de programação mais comum para a análise de dados é [Python](https://www.python.org/). De fácil aprendizado, versátil e com vasta diversidade de bibliotecas para as mais diversas aplicações. 

A instalação pode ser realizada baixando o instalador diretamente do site oficial [Python.org](https://www.python.org/downloads/).

Outra forma de instalar o python é através do gerenciador de instalação winget via `Powershell`:

```ps
winget install Python.Python.3.13
```

No momento da elaboração deste material, a versão corrente do Python é a 3.13. 


**Python Installer Package - [PIP](https://pypi.org/project/pip/)**

Instalador de pacotes python, geralmente já vem na [instalação](https://pip.pypa.io/en/stable/installation/) padrão do `Python` e seu modo de [uso](https://pip.pypa.io/en/stable/) será abordado superficialmente, apenas na aplicação do que for necessário;

Como o próprio nome descreve, a ferramenta `pip` serve para realizar a instalação de pacotes indexados no repositório de software para python o [Python Package Index - PyPI](https://pypi.org/).

Como exemplo de utilização comum, para a instalação do framework [`Pandas`](https://pandas.pydata.org/)para manipulação de *dataframes*, temos:

```bash
pip install pandas
```


**Virtual Environment - [venv](https://docs.python.org/3/library/venv.html)**

`venv` é um módulo que suporta a criação de ambientes virtuais isolados, de forma simples e prática. O ambiente criado é para ser descartável e facilmente recriável em um outro local. 

É criado sobre a instalação Python existente. 



```ps1
# Criando um ambiente virtual 
python -m venv nome-venv


# Ativando o ambiente virtual

# Linux
source nome-venv/bin/activate

# Windows
nome-venv\Scripts\activate
```

**Jupyter notebook**


O [Jupyter](https://jupyter.org/) é um projeto de código aberto sem fins lucrativos, nascido em 2014, que busca oferecer suporte à ciência de dados de forma interativa e à computação científica em todas as linguagens de programação. 

Existem algumas [interfaces](https://jupyter.org/install) para o Jupyter, como o `JupyterLab`, `Voilà`  e o clássico `Jupyter Notebook`.


Instalando o Jupyter Notebook via pip:

```ps1
pip install notebook
``` 

Executando o Jupyter notebook:

```ps1
jupyter notebook
```


## Criando um Ambiente de Desenvolvimento

Para a criação de um ambiente de desenvolvimento é necessário que o Python esteja instalado no computador, bem como o Jupyter Notebook.

0) Criar/Acessar o diretório do projeto. 

```ps1
PS C:\Users\...\projeto> 
```

1) Criando o ambiente virtual 

```ps1
python -m venv venv_projeto
```

2) Acessando o ambiente virtual 

```ps1
venv_projeto\Scripts\activate
```

Após o acesso ao ambiente virtual, no início do prompt aparece entre parênteses o nome da venv:

```ps1
(venv_projeto) PS C:\Users\...\projeto> 
```

Obs: Para sair do ambiente de desenvolvimento (venv), basta executar o comando `deactivate`:

```ps1
(venv_projeto) PS C:\Users\...\projeto> deactivate
PS C:\Users\...\projeto>
```



3) Instalando kernel para Jupyter Notebook 

```ps1
pip install ipykernel
```

4) Adicionando o ambiente virtual à lista de kernels do Jupyter Notebook

```ps1
python -m ipykernel install --user --name=venv_projeto
```

Obs: Quando o kernel não for mais necessário, pelo fim do desenvolvimento do projeto, por exemplo, pode-se excluir este kernel da lista no Jupyter Notebook:

```ps1
jupyter-kernelspec uninstall venv_projeto
```

5) Executando o Jupyter notebook

```ps1
jupyter notebook
```

6) O Jupyter Notebook será aberto no navegador em `localhost:8888\tree`

![JupyterNotebook](img/ad01-jupyter_notebook.png)


7) Para criar um `notebook`, clique em `File`, `New` e selecione `Notebook`:

![file_new_notebook](img/ad01-file_new_notebook.png)

8) Selecione o kernel deste projeto, dentro da lista disponível:

![select_kernel](img/ad01-select_kernel.png)


9) Verifique no canto superior direito que o kernel selecinado foi carregado:

![kernel](img/ad01-kernel.png)

O ambiente está pronto para o projeto ser desenvolvido. 


## Google Colab

![BuscaGoogleColab](img/ad01-buscaGoogleColab.png)


![GoogleColab](img/ad01-googleColab.png)


![NovoNotebookDrive](img/ad01-novoNotebook.png)


![ConectandoCPU](img/ad01-conectandoCPU.png)


