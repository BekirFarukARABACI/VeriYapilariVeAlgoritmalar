# Syslog Bağlı Liste Uygulaması

## Açıklama
Bu proje, Windows ortamında **C dili** kullanılarak **syslog günlüklerini** okuyan ve bağlı liste (**linked list**) veri yapısıyla yöneten bir uygulamadır.

## Özellikler
- `syslog.txt` dosyasını okur ve içindeki günlük kayıtlarını işler.
- **Tek yönlü bağlı liste (singly linked list)** kullanarak logları dinamik olarak saklar.
- Log kayıtlarını ekrana yazdırır.
- Bellek sızıntısını önlemek için kullanılan düğümleri serbest bırakır.

## Kullanım
### 1. **Gerekli Dosyalar**
- `syslog_reader.c`: Ana program dosyası
- `syslog.txt`: Test için kullanılacak log dosyası

### 2. **Kodun Derlenmesi**
Aşağıdaki komutu kullanarak kodu derleyebilirsiniz:
```bash
gcc syslog_reader.c -o syslog_reader
```

### 3. **Programın Çalıştırılması**
```bash
./syslog_reader
```

## Dosya İçeriği
**syslog.txt** örnek içeriği:
```
Feb 14 10:15:23 mypc systemd[1]: Started Session 1 of user admin.
Feb 14 10:16:10 mypc kernel: Linux version 5.15.0-91-generic
Feb 14 10:17:42 mypc sudo: admin : TTY=pts/0 ; PWD=/home/admin ; USER=root ; COMMAND=/bin/journalctl
```

## Fonksiyon Açıklamaları
### 1. `createNode(const char *logEntry)`
- Yeni bir düğüm oluşturur ve log kaydını içerisine kopyalar.

### 2. `appendLog(LogNode **head, const char *logEntry)`
- Yeni log kaydını bağlı listenin sonuna ekler.

### 3. `printLogs(LogNode *head)`
- Bağlı listedeki tüm log kayıtlarını ekrana yazdırır.

### 4. `freeLogs(LogNode *head)`
- Bağlı listedeki tüm düğümleri serbest bırakır ve belleği temizler.

## Gereksinimler
- Windows 11 işletim sistemi
- `gcc` veya `MinGW` derleyicisi

## Notlar
- `syslog.txt` dosyasının program ile aynı dizinde bulunması gerekmektedir.
- Program çalıştırılmadan önce `syslog.txt` içeriğinin uygun şekilde oluşturulduğundan emin olunmalıdır.


