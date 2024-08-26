🚢 Amiral Battı Oyunu 🎯
Amiral Battı (veya Bilgisayar Destekli Deniz Savaşı), iki oyuncunun strateji ve şans kullanarak birbirlerinin gemilerini bulup batırdığı klasik bir tahta oyunudur. Bu oyun, C dilinde geliştirilmiştir ve terminal üzerinde çalışacak şekilde tasarlanmıştır.

🕹️ Başlangıç 🚀
Kurulum
C derleyici (gcc gibi) kurulu olduğundan emin olun.
Kaydedilen dosya adını kullanarak terminalde derleyin:

gcc -o amiral_batti amiral_batti.c
Oluşan amiral_batti dosyasını çalıştırarak oyunu başlatın:

./amiral_batti
Oyun Kuralları
Tahta Boyutu Seçimi: Oyun başladığında, tahta boyutunu seçmeniz istenecek. Seçenekler:

10x10
16x16
20x20
Gemi Yerleştirme: Her oyuncu, gemilerini rastgele olarak tahtaya yerleştirecek. Gemiler boyutlarına göre 2, 3 ve 5 birim uzunluğundadır.

Saldırı Yapma: Sıra sizdeyken, rakip oyuncunun tahtasına saldırmak için koordinatları girin. Koordinatlar, örneğin "3 B" şeklinde olmalıdır.

Hedefleme ve İstatistikler: Atışlarınızın başarılı olup olmadığını öğrenin ve her iki oyuncunun da isabetli atışlarını takip edin.

Oyun Bitimi: Her iki oyuncunun da gemileri yok edildiğinde oyun biter ve kazanan ilan edilir.

📜 Fonksiyonlar
tahtayaAta(Player *player, int boardSize): Oyuncuların tahtasını başlatır.
tahtayiYaz(Player *player, int boardSize): Tahtayı ekrana yazdırır.
kontrolEt(Player *player, int x, int y, int direction, int size, int boardSize): Gemi yerleşimi için geçerliliği kontrol eder.
gemiYerlestir(Player *player, int boardSize): Gemileri tahtaya rastgele yerleştirir.
vurus(Player *player, int x, int y, int currentPlayer, int boardSize): Atış yapar ve isabet durumunu kontrol eder.
oyunBitisi(): Oyunun bitip bitmediğini kontrol eder.
oyunDurumuGoster(Player *player1, Player *player2, int boardSize): Oyun durumunu ekrana yazdırır.
serbestBirak(Player *player, int boardSize): Bellek temizliği yapar.
🛠️ Geliştirme ve Katkıda Bulunma
Bu oyunu geliştirmek veya katkıda bulunmak isterseniz, kod üzerinde değişiklikler yapabilir ve iyileştirmeler sağlayabilirsiniz. Her türlü geri bildirim ve katkı için teşekkür ederiz!
