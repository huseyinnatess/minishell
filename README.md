### [EN]

## About the Project

`minishell` is a project aimed at creating a simple Unix shell. This project will help you understand and implement basic shell functionalities and system calls. The goal is to build a shell that can execute commands, manage processes, handle signals, and support basic features such as pipes and redirection.

## Project Requirements

- **Language**: C
- **Standard**: POSIX compliant
- **Dependencies**: No external libraries allowed; only standard libraries can be used.
- **System Calls**: You need to implement system calls such as `fork`, `execve`, `wait`, and others as required.

## Features

The following core features must be implemented in this project:

- **Command Execution**:
  - **Basic Commands**: Ability to execute basic Unix commands like `ls`, `cat`, `grep`, `cp`, `mv`, `rm`, `touch`, etc.
  - **Built-in Commands**:
    - `cd [directory]`: Change the current working directory.
    - `exit [code]`: Exit the shell. Optionally, specify an exit code.
    - `pwd`: Print the current working directory.
    - `echo [text]`: Print text to the screen. Supports environment variable expansion.

- **Process Management**:
  - **New Processes**: Create new processes using the `fork` system call and run commands in these processes using `execve`.
  - **Process Termination**: Wait for child processes to terminate and retrieve their status codes using the `wait` call.

- **Pipes and Redirection**:
  - **Pipes (`|`)**: Redirect the output of one command to the input of another.
  - **Input Redirection (`<`)**: Provide input to a command from a file.
  - **Output Redirection (`>`)**: Redirect the output of a command to a file. Overwrite existing files.

- **Signal Handling**:
  - **Signal Catching**: Handle signals like `SIGINT` (Ctrl+C) and `SIGQUIT` (Ctrl+\) to manage interruptions and terminations appropriately.

- **Environment Variables**:
  - **Expansion**: Use and expand environment variables (`$VAR`) within commands.
  - **Management**: Set (`export`) and unset (`unset`) environment variables.

## Installation and Usage

### Installation

1. Clone the repository:

   ```bash
   git clone https://github.com/huseyinnatess/minishell.git

2. Navigate to the project directory:
   
    ```bash
    cd minishell

3. Compile the project:
  
    ```bash
    make

### Usage

1. Start the minishell application:
   
    ```bash
    ./minishell

2. Inside minishell, you can execute commands as you would in a standard Unix shell. For example:

    ```bash
    ls -la
    cd /path/to/directory

3. You can include commands in pipes and redirections:

   ```bash
    cat file.txt | grep "search_term" > output.txt

4. Work with environment variables:

   ```bash
    export VAR=value
    echo $VAR
    unset VAR

5. To exit minishell, use the `exit` command or press `Ctrl+D`.

### [TR]

## Proje Hakkında

`minishell`, basit bir Unix kabuğu oluşturmayı amaçlayan bir projedir. Bu proje, temel kabuk işlevlerini ve sistem çağrılarını anlamanızı ve uygulamanızı sağlayacaktır. Amaç, komutları çalıştırabilen, süreçleri yönetebilen, sinyalleri işleyebilen ve temel özellikleri (pipeler ve yönlendirme gibi) destekleyen bir kabuk oluşturmaktır.

## Proje Gereksinimleri

- **Dil**: C
- **Standart**: POSIX uyumlu
- **Bağımlılıklar**: Harici kütüphaneler kullanılmamalıdır; sadece standart kütüphaneler kullanılabilir.
- **Sistem Çağrıları**: `fork`, `execve`, `wait` ve diğer gerekli sistem çağrılarını uygulamanız gerekmektedir.

## Özellikler

Bu projede implemente edilmesi gereken temel özellikler şunlardır:

- **Komut Çalıştırma**:
  - **Temel Komutlar**: `ls`, `cat`, `grep`, `cp`, `mv`, `rm`, `touch`, vb. gibi temel Unix komutlarını çalıştırabilme.
  - **Yerleşik Komutlar**:
    - `cd [dizin]`: Geçerli çalışma dizinini değiştirme.
    - `exit [kod]`: Kabuktan çıkış yapma. Opsiyonel olarak çıkış kodu belirleyebilir.
    - `pwd`: Mevcut çalışma dizinini yazdırma.
    - `echo [metin]`: Ekrana metin yazdırma. Çevre değişkenlerinin genişletilmesini destekler.

- **Süreç Yönetimi**:
  - **Yeni Süreçler**: `fork` sistemi çağrısını kullanarak yeni süreçler oluşturma ve `execve` ile komutları bu süreçlerde çalıştırma.
  - **Süreç Sonlanması**: `wait` çağrısı ile çocuk süreçlerin sonlanmasını bekleme ve durum kodlarını alma.

- **Pipeler ve Yönlendirme**:
  - **Pipeler (`|`)**: Bir komutun çıktısını diğer bir komutun girdisine yönlendirme.
  - **Giriş Yönlendirme (`<`)**: Bir komutun girişini bir dosyadan sağlama.
  - **Çıkış Yönlendirme (`>`)**: Bir komutun çıktısını bir dosyaya yönlendirme. Var olan dosyanın üzerine yazma.

- **Sinyal Yönetimi**:
  - **Sinyal Yakalama**: `SIGINT` (Ctrl+C) ve `SIGQUIT` (Ctrl+\) sinyallerini işleyerek kesintilere ve sonlanmalara uygun tepki verme.

- **Çevre Değişkenleri**:
  - **Genişletme**: Çevre değişkenlerinin (`$VAR`) komutlar içinde kullanılması ve genişletilmesi.
  - **Yönetim**: Çevre değişkenlerini ayarlama (`export`) ve silme (`unset`).

## Kurulum ve Kullanım

### Kurulum

1. Depoyu klonlayın:

   ```bash
   git clone https://github.com/huseyinnatess/minishell.git

2. Proje dizinine gidin:
   
    ```bash
    cd minishell

3. Projeyi derleyin:
  
    ```bash
    make

### Kullanım

1. minishell uygulamasını başlatın:
   
    ```bash
    ./minishell

2. minishell içinde, standart bir Unix kabuğunda olduğu gibi komutları çalıştırabilirsiniz. Örneğin:

    ```bash
    ls -la
    cd /path/to/directory

3. Komutları pipelere ve yönlendirmelere dahil edebilirsiniz:

   ```bash
    cat file.txt | grep "search_term" > output.txt

4. Çevre değişkenleri ile çalışabilirsiniz:

   ```bash
    export VAR=value
    echo $VAR
    unset VAR

5. minishell'den çıkmak için `exit` komutunu kullanabilir veya `Ctrl+D` tuşlarına basabilirsiniz.
  
