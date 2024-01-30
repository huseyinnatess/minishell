# minishell
SEX ON THE BEACH ALWAYS MORE AMUSING THAN CODING !


1-) argc ve argv sayıları kontrol edildi.

2-) init_envp fonksiyonunda environmentler data -> env dizisine kopyalandı.

3-) ft_split_envp fonksiyonunda environmentler split ile '=' karakterine göre (('=') dahil değil) split[0] ve split[1] olarak ayrıldı.
```sh
Örneğin:
      USER=huates
      split[0] = USER
      split[1] = huates
      split[2] = NULL
```
4-) Ayrılan splitleri ft_envpnew fonksiyonu içerisinde *str structına split[0] id, split[1] ise value olarak atanıyor.

5-) Ardından init_term ile terminal ayarları kaydediliyor. (Gereksiz).

6-) init_term_fd ile data struct'ındaki std_in ve std_out değişkenlerine input ve output değerleri veriliyor. Direk 0 ve 1 olarak'da verilebilir. Bu şekilde daha sağlıklı.

7-) Gelen sinyalleri yakalamak için ft_signal_handler fonksiyonunu kullanılıyoruz. Eğer gelen sinyal Ctrl+c ise if (sig == SIGINT) bloğu çalışıyor, program bir alt satıra geçip mevcut satırı temizliyor ve boş bir satırı ekrana yazdırıyor.

8-) Eğer gelen sinyal SIGQUIT ise else if (sig == SIGQUIT) bloğu çalışıp, mevcut satırı temizler ve "Quit: 3" mesajını ekrana yazdırır. Ancak PDF'de SIGQUIT sinyali geldiğinde hiçbir şey yapılmaması isteniyor bunu engellemek için signal(SIGQUIT, SIG_IGN); fonksiyonu kullanılıyor (Signal ignore).

9-) display_prompt_msg fonksiyonu ile program adı yazılıp input alımı yapıyoruz. PDF'de komut geçmişi istendiği add_history fonksiyonu ile girilen inputları geçmişe ekliyoruz (İnput'un doğru veya yanlış olduğu farketmiyor).
Not: İnput'un uzunluğunun ft_strlen ile hesaplanmasında program ismi hesaplanmıyor.

10-) Girilen input'ta hata oluşup NULL gelmesi durumunda ft_ctrl_d fonksiyonu çalışıp isatty hazır fonksiyonu ile gelen hatanın terminal'den gelme durumuna göre exit yazdırıp çıkış yapıyoruz.

11-) Girilen input'un yazdırılamaz karakter içerip içermediğini, tamamen boşluk ve tab benzeri karakterlerden oluşup oluşmadığını kontrol ediliyor.

12-) ft_commands ile girilen komutlar veya alıntılar (quotations) belirleniyor. Eğer girilen input içerisinde (" ", veya ' ') var ise ilgili değişkenleri arttırıyoruz.

13-) Eğer gelen input içerisindeki tırnak karakterlerinin içide pipe (|) yok ise bir sonraki karakterin pipe olma durumunu kontrol ediyoruz.

14-) Bulunan komut sayıları data -> nbr_of_cmds değişkenine aktarıp ft_write_syntax_errors fonksiyonu ile olası syntax hatalarını kontrol ediyoruz.

15-) ft_write_syntax_errors fonksiyonunda, ft_has_valid_quotes fonksiyonu ile iç içe tırnak olup olmadığı kontrol ediyoruz. Bulduğumuz tırnak karakterlerini sayıp en son tek ve çift olma durumlarını kontrol ediyoruz.

16-) ft_check_pipe_sytax fonksiyonu ile girilen komut sayısına göre pipe (|) karakterinin başta veya sonda olup olmadığını kontrol ediyoruz.

17-) ft_check_redir_sytax fonksiyonu ile yönlendirme ('<', '>', '<<', '>>') işaretlerinin sayısını, doğru kullanımını ve sonda olup olmadığını kontrol ediyoruz. (Tırnak içerisinde verilmiş iseler sayıya dahil etmiyoruz).

18-) ft_strchr_variable fonksiyonuna girilen inputu gönderiyoruz. Bu fonksiyon eğer ortam değişkeni varsa ($, $?) bu değişkenleri ft_parse_variables fonksiyonuna gönderiyor.

19-) ft_parse_variables fonksiyonu ise tekrardan ft_strchr_variable fonksiyonuna girilen inputu gönderip dönen değeri variable değişkeninde tutar. (Dönüş değeri ortam değişkeninin input'taki başlangıç adresidir.)

20-) Dönen değer eğer "?" ise (örnek: echo $??? input'unun çıktısı 0??'dir. "?" önceki komutun başarılı olma durumunda 0 başarısız olma durumunda 0 return eder) ft_status_variable fonksiyonuna gönderilir.

21-) ft_status_variable ise terminal çıktısında gösterilecek 0 ve input'un tamamı ile beraber ft_replace_string fonksiyonuna gönderir.

22-) ft_replace_string ise gelen input'tan ortam değişkenine kadar olan kısmın uzunluğunu, ilk "?" karakternden sonraki kısmın uzunluğunu ve string biçimlerini ayrı ayrı değişkenlerde tutar. (İlk "?" yerine 0 gelecek hesaplamaya dahil edilmiyor). Ardından ft_alloc_replacer'a parametre olarak string'leri gönderiyor.

23-) ft_alloc_replacer fonksiyonunda ilk olarak ortam değişkenine kadar olan kısım ile eklenecek olan 0 karakteri birleştiriliyor. Ardından ilk soru işaretinden sonraki kısım birleştiriliyor.

```sh
Örneğin:
      echo $???

      before_rp = echo (boşluk da dahil)
      replacer = 0
      after_rp = ??

      new_str = echo 0??
```
