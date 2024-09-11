# minishell

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

4. Projeyi derleyin:
  
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

5. minishell'den çıkmak için exit komutunu kullanabilir veya Ctrl+D tuşlarına basabilirsiniz.
  
