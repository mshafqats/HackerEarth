/*
=====================
|  ID: mshafqats    |
|  LANG: C          |
=====================
Mohammad Shafqat Siddiqui
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CHAR 26

struct TrieNode {
    struct TrieNode* children[MAX_CHAR];
    int weight;
};
 
struct TrieNode* createNode() {
    struct TrieNode* newNode = (struct TrieNode*)malloc(sizeof(struct TrieNode));
    for (int i = 0; i < MAX_CHAR; i++) {
        newNode->children[i] = NULL;
    }
    newNode->weight = 0;
    return newNode;
}

void insertWord(struct TrieNode* root, char* word, int weight) {
    struct TrieNode* node = root;
    int length = strlen(word);
 
    for (int i = 0; i < length; i++) {
        int index = word[i] - 'a';
        if (!node->children[index]) {
            node->children[index] = createNode();
        }
        node = node->children[index];
        node->weight = (node->weight > weight) ? node->weight : weight;
    }
}
 
int searchWeight(struct TrieNode* root, char* query) {
    struct TrieNode* node = root;
    int length = strlen(query);
 
    for (int i = 0; i < length; i++) {
        int index = query[i] - 'a';
        if (!node->children[index]) {
            return -1;
        }
        node = node->children[index];
    }
    return node->weight;
}
 
int main() {
    int n, q;
    scanf("%d %d", &n, &q);
 
    struct TrieNode* root = createNode();
 
    for (int i = 0; i < n; i++) {
        char entry[106];
        int weight;
        scanf("%s %d", entry, &weight);
        insertWord(root, entry, weight);
    }
 
    for (int i = 0; i < q; i++) {
        char query[106];
        scanf("%s", query);
        int result = searchWeight(root, query);
        printf("%d\n", result);
    }
    return 0;
}
