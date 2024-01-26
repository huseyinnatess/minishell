# minishell
SEX ON THE BEACH ALWAYS MORE AMUSING THAN CODING !


1-) argc ve argv sayıları kontrol edildi.
2-) init_envp fonksiyonunda environmentler data -> env dizisine kopyalandı.
3-) ft_split_envp fonksiyonunda environmentler split ile '=' karakterine göre (('=') dahil değil) split[0] ve split[1] olarak ayrıldı.
Örneğin:
      USER=huates,
      split[0] = USER,
      split[1] = huates,
      split[2] = NULL

4-) Ayrılan splitleri ft_envpnew fonksiyonu içerisinde *str structına split[0] id, split[1] ise value olarak atanıyor.
