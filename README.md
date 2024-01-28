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

7-) Gelen sinyalleri yakalamak için ft_signal_handler fonksiyonu kullanılıyor. Eğer gelen sinyal Ctrl+c ise if (sig == SIGINT) bloğu çalışıyor, program bir alt satıra geçip mevcut satırı temizliyor ve boş bir satırı ekrana yazdırıyor.
