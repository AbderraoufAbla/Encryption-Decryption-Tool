#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_TEXT_LEN 1000 // maximum length of input text

// define a struct to represent a substitution cipher key
struct SubstitutionCipherKey {
    char map[26]; // maps each character to a new character
};

// function to initialize a substitution cipher key
void initializeSubstitutionCipherKey(struct SubstitutionCipherKey *key) {
    // generate a random permutation of the alphabet
    char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i = 0; i < 26; i++) {
        int j = rand() % 26;
        char temp = alphabet[i];
        alphabet[i] = alphabet[j];
        alphabet[j] = temp;
    }

    // initialize the key with the permutation
    for (int i = 0; i < 26; i++) {
        key->map[i] = alphabet[i];
    }
}

// function to encrypt a message using a substitution cipher key
void encryptMessageWithSubstitutionCipher(struct SubstitutionCipherKey key, char *message) {
    int len = strlen(message);
    for (int i = 0; i < len; i++) {
        if (isalpha(message[i])) {
            message[i] = toupper(message[i]);
            message[i] = key.map[message[i] - 'A'];
        }
    }
}

// function to decrypt a message using a substitution cipher key
void decryptMessageWithSubstitutionCipher(struct SubstitutionCipherKey key, char *message) {
    int len = strlen(message);
    for (int i = 0; i < len; i++) {
        if (isalpha(message[i])) {
            message[i] = toupper(message[i]);
            for (int j = 0; j < 26; j++) {
                if (key.map[j] == message[i]) {
                    message[i] = 'A' + j;
                    break;
                }
            }
        }
    }
}

int main() {
    char input_text[MAX_TEXT_LEN];
    struct SubstitutionCipherKey key;

    // generate a random substitution cipher key
    initializeSubstitutionCipherKey(&key);

    // get user input
    printf("Enter message to encrypt: ");
    fgets(input_text, MAX_TEXT_LEN, stdin);
    input_text[strcspn(input_text, "\n")] = 0; // remove newline character

    // encrypt the message
    encryptMessageWithSubstitutionCipher(key, input_text);

    // print the encrypted message
    printf("Encrypted message: %s\n", input_text);

    // decrypt the message
    decryptMessageWithSubstitutionCipher(key, input_text);

    // print the decrypted message
    printf("Decrypted message: %s\n", input_text);

    return 0;
}
