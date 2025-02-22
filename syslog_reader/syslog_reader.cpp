#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LOG_FILE "syslog.txt" // Windows ortam�nda test i�in dosya ad�n� de�i�tirdim
#define MAX_LINE_LENGTH 1024

// Ba�l� liste d���m yap�s�
typedef struct LogNode {
    char logEntry[MAX_LINE_LENGTH];
    struct LogNode *next;
} LogNode;

// Yeni bir d���m olu�turur
LogNode* createNode(const char *logEntry) {
    LogNode *newNode = (LogNode*)malloc(sizeof(LogNode));
    if (newNode) {
        strncpy(newNode->logEntry, logEntry, MAX_LINE_LENGTH);
        newNode->logEntry[MAX_LINE_LENGTH - 1] = '\0'; 
        newNode->next = NULL;
    }
    return newNode;
}

// Ba�l� listeye d���m ekler (sona ekleme y�ntemi)
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

// Ba�l� listeyi ekrana yazd�r�r
void printLogs(LogNode *head) {
    LogNode *temp = head;
    while (temp != NULL) {
        printf("%s", temp->logEntry);
        temp = temp->next;
    }
}

// Ba�l� listeyi temizler (bellek y�netimi i�in)
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
        perror("Dosya a��lamad�");
        return 1;
    }
    
    LogNode *logList = NULL;
    char line[MAX_LINE_LENGTH];
    
    while (fgets(line, sizeof(line), file)) {
        appendLog(&logList, line);
    }
    
    fclose(file);
    
    printf("Sistemdeki Syslog Kay�tlar�:\n");
    printLogs(logList);
    
    freeLogs(logList);
    
    return 0;
}

