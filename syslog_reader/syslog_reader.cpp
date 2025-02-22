#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LOG_FILE "syslog.txt" // Windows ortamýnda test için dosya adýný deðiþtirdim
#define MAX_LINE_LENGTH 1024

// Baðlý liste düðüm yapýsý
typedef struct LogNode {
    char logEntry[MAX_LINE_LENGTH];
    struct LogNode *next;
} LogNode;

// Yeni bir düðüm oluþturur
LogNode* createNode(const char *logEntry) {
    LogNode *newNode = (LogNode*)malloc(sizeof(LogNode));
    if (newNode) {
        strncpy(newNode->logEntry, logEntry, MAX_LINE_LENGTH);
        newNode->logEntry[MAX_LINE_LENGTH - 1] = '\0'; 
        newNode->next = NULL;
    }
    return newNode;
}

// Baðlý listeye düðüm ekler (sona ekleme yöntemi)
void appendLog(LogNode **head, const char *logEntry) {
    LogNode *newNode = createNode(logEntry);
    if (!newNode) return;

    if (*head == NULL) {
        *head = newNode;
    } else {
        LogNode *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Baðlý listeyi ekrana yazdýrýr
void printLogs(LogNode *head) {
    LogNode *temp = head;
    while (temp != NULL) {
        printf("%s", temp->logEntry);
        temp = temp->next;
    }
}

// Baðlý listeyi temizler (bellek yönetimi için)
void freeLogs(LogNode *head) {
    LogNode *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    FILE *file = fopen(LOG_FILE, "r");
    if (!file) {
        perror("Dosya açýlamadý");
        return 1;
    }
    
    LogNode *logList = NULL;
    char line[MAX_LINE_LENGTH];
    
    while (fgets(line, sizeof(line), file)) {
        appendLog(&logList, line);
    }
    
    fclose(file);
    
    printf("Sistemdeki Syslog Kayýtlarý:\n");
    printLogs(logList);
    
    freeLogs(logList);
    
    return 0;
}

