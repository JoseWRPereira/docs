---
title: Ambiente de Desenvolvimento
icon: fontawesome/solid/computer
author:
 - José W. R. Pereira
tags:
 - Ciência de Dados
 - Inteligência Artificial
 - Aprendizado de Máquina
---

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

Instalador de pacotes python;


**Virtual Environment - [venv](https://docs.python.org/3/library/venv.html)**

```bash
# criando um ambiente virtual 
python -m venv nome-venv


# ativando o ambiente virtual
# linux
source nome-venv/bin/activate
# windows
nome-venv\Scripts\activate
```

**Jupyter notebook**

O software/plataforma para desenvolvimento [Jupyter Notebook](https://jupyter.org/)

Instalando o Jupyter notebook via `PowerShell`:

```ps
python -m venv venv
```

Acessando ambiente virtual

```ps
venv\Scripts\activate
```

# 3.2 Instalando kernel para Jupyter
pip install ipykernel

# 4. Adicionando o ambiente virtual à lista de kernels
python3 -m ipykernel install --user --name=venv_ftc

# 5. Excluindo o ambiente virtual da lista de kernels
jupyter-kernelspec uninstall venv_ftc




**Preparando ambiente para desenvolvimento - Exemplo**

Para criar um ambiente de desenvolvimento, é pré-requisito que o computador possua python e jupyter instalados. 

Após o python e o jupyter instalados, é o momento de acessar um diretório de trabalho e criar um ambiente de desenvolvmiento:

```ps
pip install 
```

