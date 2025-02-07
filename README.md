# VeriYapilariVeAlgoritmalar

===========================================
🕒 TOPLANTI HATIRLATICI - EPOCH ZAMAN HESAPLAMA
===========================================

Bu uygulama, kullanıcıdan alınan tarih ve saat bilgilerini sistem saatiyle karşılaştırarak 
toplantıya kalan süreyi saniye cinsinden hesaplar. Epoch zamanına dayalı olarak çalışır 
ve kalan süreye göre kullanıcıya uyarı mesajları gösterir.

-------------------------------
⚙️ 1. KULLANILAN BİLEŞENLER
-------------------------------
- Programlama Dili: C
- Kullanılan Kütüphaneler:
  - stdio.h  : Girdi/çıktı işlemleri
  - time.h   : Tarih ve saat hesaplamaları için

-------------------------------
🗂️ 2. VERİ YAPILARI
-------------------------------
struct DateTime:
  - Yıl (year)
  - Ay (month)
  - Gün (day)
  - Saat (hour)
  - Dakika (minute)
  - Saniye (second)

struct DateTime kullanılarak tarih/saat verileri gruplandırılır.

-------------------------------
📌 3. FONKSİYONLAR
-------------------------------
1️⃣ convertToEpoch(struct DateTime dt):
   - struct tm yapısını doldurarak mktime() ile epoch zamanına dönüştürür.
   - Epoch zamanı, 1 Ocak 1970'ten itibaren geçen saniye sayısını temsil eder.

2️⃣ Ana Program:
   - Kullanıcıdan toplantı tarihi alınır.
   - time() ile sistemin mevcut epoch zamanı elde edilir.
   - difftime() fonksiyonu ile iki zaman arasındaki fark hesaplanır.

-------------------------------
🚦 4. KOŞUL KONTROLLERİ
-------------------------------
- Fark < 0 ise: "❌ Bu toplantı tarihi geçti."
- Fark ≤ 3600 saniye ise: "🚨 Toplantıya az kaldı!"
- Fark > 3600 saniye ise: "⏳ Toplantıya daha zaman var."

-------------------------------
🛠️ 5. DERLEME VE ÇALIŞTIRMA
-------------------------------
1. Derleme Komutu:
   gcc -o meeting_reminder meeting_reminder.c

2. Çalıştırma:
   ./meeting_reminder

3. Girdi Formatı:
   YYYY MM DD HH MM SS
   Örn: 2025 03 01 14 00 00

-------------------------------
✅ 6. ÖRNEK SENARYOLAR
-------------------------------
1️⃣ Geçerli Tarih:
   Girdi: 2025 03 01 14 00 00
   Çıktı: ⏳ Toplantıya daha zaman var: 259200 saniye

2️⃣ Toplantıya Az Kaldı:
   Girdi: 2025 02 06 23 30 00
   Çıktı: 🚨 Toplantıya az kaldı! (1800 saniye)

3️⃣ Geçmiş Tarih:
   Girdi: 2024 12 01 10 00 00
   Çıktı: ❌ Bu toplantı tarihi geçti.

-------------------------------
📖 7. EPOCH ZAMANI NEDİR?
-------------------------------
Epoch zamanı, 1 Ocak 1970, 00:00:00 UTC’den itibaren geçen toplam saniye sayısıdır.
- Epoch "0" zamanı: 1 Ocak 1970 UTC
- Örnek epoch değeri: 1700000000 (bu sayı kadar saniye geçmiş demektir)

-------------------------------
🗃️ 8. GITHUB’A YÜKLEME ADIMLARI
-------------------------------
1. GitHub hesabı oluşturun: https://github.com
2. Yeni bir repository oluşturun (ör: meeting-reminder).
3. Terminalde şu komutları çalıştırın:
   git init
   git add .
   git commit -m "Initial commit"
   git branch -M main
   git remote add origin https://github.com/kullaniciadi/meeting-reminder.git
   git push -u origin main

-------------------------------
🎥 9. VİDEO İÇERİĞİ ÖNERİLERİ
-------------------------------
- Kod yapısını ve dosya organizasyonunu gösterin.
- Fonksiyonların nasıl çalıştığını teknik olarak açıklayın.
- Programı farklı senaryolarla çalıştırarak sonuçları gösterin.

-------------------------------
📜 10. LİSANS
-------------------------------
Bu proje eğitim amaçlı geliştirilmiştir. Katkılara açıktır. 🚀
