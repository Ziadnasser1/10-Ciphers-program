/*
program name: 10 cipher program.
last modification date: 25/3/2022
Authors: Ziad Nasser Shaaban
         Asem Emad
         Yehia Mohamed
Institution: Faculty of computer and Artificial intelligence (FCAI)
Description:this is a program that contain 10 different ciphers that inside each one it allow
you to choose to encrypt or decrypt an input message from the user.


*/

#include <iostream>
using namespace std;
#include <string>
#include<cstring>
#include <cmath>
#include <ctype.h>
#include<map>
#include<algorithm>
#include <cstdlib>

//Affine Cipher program.
string alphabet_lower;
string alphabet_upper;
string user_input;
string final_message;
void prepare_encyption(){
    for (int i = 97; i <= 122; i++)
    {
        alphabet_lower+=char(i);//alphabet_lower = abc...... and every letter's index from 0 to 25 (a to z)
    }
    for (int i = 65; i <= 90; i++)
    {
        alphabet_upper+=char(i);//alphabet_upper = ABC...... and every letter's index from 0 to 25 (A to Z)
    }
    cout<<"Enter ur message"<<endl;
    getline(cin,user_input);
}
void encrypt(){
    for (int i = 0; i < user_input.length(); i++){
        if (int(char(user_input[i])) == 32)// if user entered white space accept it
        {
            final_message+=" ";
        }
        if (int(char(user_input[i]))<=90 && int(char(user_input[i]))>=65) // if user enterd word in upper case
        {
            for (int j = 0; j <=25; j++)
            {
                if (user_input[i] == alphabet_upper[j]){
                    final_message+=alphabet_upper[(5*j+8)%26];// J = NUMVER VALUE = LATTERS INDEX
                    break;
                }
            }
        }
        else if (int(char(user_input[i]))>=97 && int(char(user_input[i]))<=122)// if user enterd word in lower case
        {
            for (int l = 0; l <=25; l++)
            {
                if (user_input[i] == alphabet_lower[l]){
                    final_message+=alphabet_lower[(5*l+8)%26]; ;// I= NUMVER VALUE = LATTERS INDEX
                    break;
                }
            }
        }
    }
    cout<<final_message;
}
void decrypt(){
    for (int i = 0; i < user_input.length(); i++){
        if (int(char(user_input[i])) == 32)
        {
            final_message+=" "; // if user entered white space accept it
        }
        if (int(char(user_input[i]))<=90 && int(char(user_input[i]))>=65) // if user enterd word in upper case
        {
            for (int m = 0; m <=25; m++)
            {
                if (user_input[i] == alphabet_lower[m]){
                    if (abs((21*(m-8))) <26) //AVOIDING NEGATIVE AND MODE PROBLEM
                    {
                        final_message+=alphabet_lower[26%abs((21*(m-8)))];
                        break;
                    }
                    else{
                        final_message+=alphabet_lower[abs((21*(m-8)))%26];
                        break;}
                }
        }
        }
        else if (int(char(user_input[i]))>=97 && int(char(user_input[i]))<=122) // if user enterd word in LOWER case
        {
            for (int k = 0; k <=25; k++)
            {
                if (user_input[i] == alphabet_lower[k]){
                    if (abs((21*(k-8))) <26) //AVOIDING NEGATIVE AND MODE PROBLEM
                    {
                        final_message+=alphabet_lower[26%abs((21*(k-8)))];
                        break;
                    }
                    else{
                        final_message+=alphabet_lower[abs((21*(k-8)))%26];
                        break;}
                }
            }
        }
    }
    cout<<final_message;
}
void choice(){
    cout<<"if u want to encrypt press 1 "<<endl;
    cout<<"if u want to decrypt press 2 "<<endl;
    int user_choice;
    while (!(cin>>user_choice)) {
        cout<<"write a valid number"<<endl;
        cin.clear();
        cin.ignore(132,'\n');
    }
    if (user_choice ==1)
    {
        encrypt();
    }
    else if (user_choice ==2) {
        decrypt();
    }
    else{
        cout<<"write a valid number"<<endl;
        choice();
    }
}

//Caesar Cipher program.
string user_message;
void ceaser_cipher_encryption(){
    for (int i = 0; i < user_message.length(); i++)
    {
        char encrypting;
        encrypting = user_message[i];/* getting the value of letters in asci*/
        if(int(encrypting) == 120){/* if the letter = x it must be replaced by a*/
            cout<<"a";
        }
        else if (int(encrypting) == 121)/* if the letter = y it must be replaced by b*/
        {
            cout<<"b";
        }
        else if (int(encrypting) == 122)/* if the letter = z it must be replaced by c*/
        {
            cout<<"c";
        }
        else if (int(encrypting) == 88)/* if the letter = X it must be replaced by A*/
        {
            cout<<"A";
        }
        else if (int(encrypting) == 89)/* if the letter = Y it must be replaced by B*/
        {
            cout<<"B";
        }
        else if (int(encrypting) == 90)/* if the letter = Z it must be replaced by C*/
        {
            cout<<"C";
        }
        else if (int(encrypting) == 32)/* if the letter = " " it must be  " " C*/
        {
            cout<<" ";
        }
        else
        {cout<<char(int(encrypting)+3);}/*adding the previous value to 3 and getting the letter of the new asci number*/
    }
}
void ceaser_cipher_decryption(){
    for (int i = 0; i < user_message.length(); i++)
    {
        char decrypting= user_message[i];
        if(int(decrypting) == 97){/*if the letter == a it must be replaced by x*/
            cout<<"x";
        }
        else if (int(decrypting) == 98)/*if the letter == b it must be replaced by y*/
        {
            cout<<"y";
        }
        else if (int(decrypting) == 99)/*if the letter == c it must be replaced by z*/
        {
            cout<<"z";
        }
        else if (int(decrypting) == 65)/*if the letter == A it must be replaced by X*/
        {
            cout<<"X";
        }
        else if (int(decrypting) == 66)/*if the letter == B it must be replaced by Y*/
        {
            cout<<"Y";
        }
        else if (int(decrypting) == 67)/*if the letter == C it must be replaced by Z*/
        {
            cout<<"Z";
        }
        else if (int(decrypting) == 32)/* if the letter = " " it must be  " " C*/
        {
            cout<<" ";
        }
        else
        {cout<<char(int(decrypting)-3);}/*adding the previous value to -3 and getting the letter of the new asci number*/
    }
}
void user_choice(){
    cout<<"if u want encrypt press 1"<<endl;
    cout<<"if u want decrypt press 2"<<endl;
    int choice;
    while (!(cin>>choice)) {
    cout<<"write a valid number"<<endl;
    cin.clear();
    cin.ignore(132,'\n');
    }
    if(choice == 1){
        ceaser_cipher_encryption();
    }
    else if(choice == 2){
        ceaser_cipher_decryption();
    }
    else{
        cout<<"enter a valid message"<<endl;
        user_choice();
    }
}

//Atbash Cipher program.
string users_message;
void Atbash_cipher_encrypt_or_decrypt(){/*in this kind of encrypting encryption = decryption*/
    int asci;
    int subtracting;
    for (int i = 0; i < users_message.length(); i++)
    {
        char converting_to_asci=users_message[i];
        asci = converting_to_asci;/* getting the value of letters in asci*/
        if(asci ==32){/* if the letter = " " it must be  " " C*/
            cout<<" ";
        }
        if (asci >=97 && asci<=122){
            if((122-asci)>(asci-97)){/*If the letter is closer to a than z*/
                subtracting=122-(asci-97);/*calculate the diffefence between a and this latter and sustract this difference from z to get the decryption*/
                cout<<char(subtracting);
            }
            else{
                subtracting=97+(122-asci);/*If the letter is closer to z than a*/
                cout<<char(subtracting);/*calculate the diffefence between z and this latter and sustract this difference from a to get the decryption*/
            }
        }
        if (asci >=65 && asci<=90){
            if((90-asci)>(asci-65)){/*If the letter is closer to A than Z*/
                subtracting=90-(asci-65);/*calculate the diffefence between A and this latter and sustract this difference from Z to get the decryption*/
                cout<<char(subtracting);
            }
            else{
                subtracting=65+(90-asci);/*If the letter is closer to Z than A*/
                cout<<char(subtracting);/*calculate the diffefence between z and this latter and sustract this difference from a to get the decryption*/
            }
        }
    }
}
void users_choice(){
    cout<<"if u want encrypt press 1"<<endl;
    cout<<"if u want decrypt press 2"<<endl;
    int choice;
    while (!(cin>>choice)) {
        cout<<"write a valid number"<<endl;
        cin.clear();
        cin.ignore(132,'\n');
    }
    if(choice == 1){
        Atbash_cipher_encrypt_or_decrypt();
    }
    else if(choice == 2){
        Atbash_cipher_encrypt_or_decrypt();
    }
    else{
        cout<<"enter a valid message"<<endl;
        user_choice();
    }
}

// Vignere cipher program.
char message[80];
string check_message(){
    // checking that the input message from the user is fulfilling the conditions.
    cout<<"enter your message   : ";
    cin.getline(message,80);

    //turning all the small letters in the message to a capital letters/
    for(int i=0; i<strlen(message); i++)
        {
            if(message[i] >= 'a' && message[i] <= 'z')
                message[i] = char(message[i] - 32);
        }

    return message;
}
string check_keyword(){
    //checking if the keyword fulfill the conditions.
    char key_word[8];
    cout<<"enter your keyword   : ";
    cin.getline(key_word,8);

    //turning all small letters to capital letters.
    for(int i=0; i<strlen(key_word); i++)
        {
            if(key_word[i] >= 'a' && key_word[i] <= 'z')
                key_word[i] = char(key_word[i] - 32);
        }
    return key_word;
}
string repeated_kw(string n_message,string kw){
//generating the keyword for encrypting or decrypting.
    if (kw.length()>= n_message.length())
       return kw;
    else{
        int k = n_message.length();

        //repeating the keyword till it reach the message length.
        for(int i = 0;  ;i++)
        {
            if(k == i)
                i = 0;
            if(kw.length() == n_message.length())
                break;
            kw.push_back(kw[i]);
        }
        return kw;
    }
   }
string encryption(string mess,string rep_kw ){
    string enc_message;
    int encode;
    for (int i=0;i <=mess.length(); i++){

        //check if the character is an alphabet or not.
        if (isalpha(mess[i]))
        {
            //the algorithm made to encrypt the message.
            encode = ((char(mess[i]) + char(rep_kw[i])) % 26) +65;
            enc_message += char(encode);

            if(enc_message.length() == mess.length())
                break;
        }
        else
             enc_message += mess[i];


    }

    return enc_message;
}
string decryption(string mess, string rep_kw){
    string dec_message;
    int decode;
    for (int i=0; i<=mess.length(); i++)
    {
        if(isalpha(mess[i]))
        {
            //the algorithm made to decode the message.
            decode = (((char(mess[i]) - char(rep_kw[i]) + 26) % 26) + 65);
            dec_message += char(decode);

            if (dec_message.length() == mess.length())
                break;
        }
        else
            dec_message += mess[i];
    }

    return dec_message;
}

// Baconian cipher
string encrypt(string word){
    string big_word;
    //loop to change every letter to upper
    for (int i = 0; i < word.length(); i++){
        int ascii = word [i];
        if (ascii == 32)
        {
            big_word.push_back(' ');
        }
        else{
            char ch = toupper(word[i]);
            big_word.push_back(ch);
        }
    }
    map <char,string> ENCODE_MAP;
    ENCODE_MAP.insert(pair<char,string>('A',"aaaaa"));
    ENCODE_MAP.insert(pair<char,string>('B',"aaaab"));
    ENCODE_MAP.insert(pair<char,string>('C',"aaaba"));
    ENCODE_MAP.insert(pair<char,string>('D',"aaabb"));
    ENCODE_MAP.insert(pair<char,string>('E',"aabaa"));
    ENCODE_MAP.insert(pair<char,string>('F',"aabab"));
    ENCODE_MAP.insert(pair<char,string>('G',"aabba"));
    ENCODE_MAP.insert(pair<char,string>('H',"aabbb"));
    ENCODE_MAP.insert(pair<char,string>('I',"abaaa"));
    ENCODE_MAP.insert(pair<char,string>('J',"abaab"));
    ENCODE_MAP.insert(pair<char,string>('K',"ababa"));
    ENCODE_MAP.insert(pair<char,string>('L',"ababb"));
    ENCODE_MAP.insert(pair<char,string>('M',"abbaa"));
    ENCODE_MAP.insert(pair<char,string>('N',"abbab"));
    ENCODE_MAP.insert(pair<char,string>('O',"abbba"));
    ENCODE_MAP.insert(pair<char,string>('P',"abbbb"));
    ENCODE_MAP.insert(pair<char,string>('Q',"baaaa"));
    ENCODE_MAP.insert(pair<char,string>('R',"baaab"));
    ENCODE_MAP.insert(pair<char,string>('S',"baaba"));
    ENCODE_MAP.insert(pair<char,string>('T',"baabb"));
    ENCODE_MAP.insert(pair<char,string>('U',"babaa"));
    ENCODE_MAP.insert(pair<char,string>('V',"babab"));
    ENCODE_MAP.insert(pair<char,string>('W',"babba"));
    ENCODE_MAP.insert(pair<char,string>('X',"babbb"));
    ENCODE_MAP.insert(pair<char,string>('Y',"bbaaa"));
    ENCODE_MAP.insert(pair<char,string>('Z',"bbaab"));
    char big_ch;
    int num = 1;
    string encoded_word ="";
    for (int let = 0; let < big_word.length() ; let++){
        big_ch = big_word[let];
        for (auto iter = ENCODE_MAP.begin(); iter != ENCODE_MAP.end(); ++iter){
            char key = iter->first;
            string value = iter->second;
            if (ENCODE_MAP.find(big_ch) != ENCODE_MAP.end()){
                if (big_ch == key)
                {
                    encoded_word.append(value);
                }
            }
            else if (int(key) == 90 and int(big_ch)!=90){
                encoded_word+=big_ch;
            }
        }
    }
    return encoded_word;
}
string decrypt(string word){
    // map of decoding
    map <string,char> DECODE_MAP{
        {"aaaaa",'A'},
        {"aaaab",'B'},
        {"aaaba",'C'},
        {"aaabb",'D'},
        {"aabaa",'E'},
        {"aabab",'F'},
        {"aabba",'G'},
        {"aabbb",'H'},
        {"abaaa",'I'},
        {"abaab",'J'},
        {"ababa",'K'},
        {"ababb",'L'},
        {"abbaa",'M'},
        {"abbab",'N'},
        {"abbba",'O'},
        {"abbbb",'P'},
        {"baaaa",'Q'},
        {"baaab",'R'},
        {"baaba",'S'},
        {"baabb",'T'},
        {"babaa",'U'},
        {"babab",'V'},
        {"babba",'W'},
        {"babbb",'X'},
        {"bbaaa",'Y'},
        {"bbaab",'Z'}
    };
    string decoded_word;
    string shift;
    decode_loop:
        for (int i = 0; i < word.length(); i++){
                for (int i = 0; i < 5; i++){
                    if(int(word[i])==32){
                        decoded_word.push_back(' ');
                        word.erase(0,1);
                        goto decode_loop;
                    }
                    shift.push_back(word[i]);
                    if (i ==4){
                        word.erase(0,5);
                        for (auto iter = DECODE_MAP.begin(); iter != DECODE_MAP.end(); ++iter){
                            string key = iter->first;
                            char value = iter->second;
                            if (DECODE_MAP.find(shift) != DECODE_MAP.end()){
                                if (shift == key){
                                decoded_word.push_back(value);
                                shift.clear();
                                goto decode_loop;
                            }
                        }
                    }
                }
            }
        }
    return decoded_word;
}

//simple substitution cipher program.
string user_messages;
string cipher;
string cipher2;
string user_message_cpy;
string final_encryption;
string finall_message;
int mess;
void encrypts(){
    cout<<"Enter ur encryption pattern"<<endl;
    getline(cin,user_messages);
    if (user_messages.length()!=5)
    {
        cout<<"You Must Write Only 5 latters"<<endl;
        encrypt();
    }
    for (int del_repeted = 0; del_repeted < user_messages.length(); del_repeted++)
    {
        for (int i = del_repeted+1; i < user_messages.length(); i++)
        {
            if (user_messages[del_repeted]== user_messages[i])
            {
                user_message.erase(user_messages.begin() + i);
                del_repeted = 0;
                i=0;
            }
        }
    }
    user_message_cpy=user_messages;
    for(int letter =97; letter<=122; letter++){
        cipher+= char(letter);
    }
    for(int letter =65; letter<=90; letter++){
        cipher2+= char(letter);
    }
    for (int returning_letter = 0; returning_letter<= 25; returning_letter++){
        for(int i =0; i < user_message_cpy.length(); i++){
            if (user_message_cpy[i] == cipher[returning_letter]||user_message_cpy[i] == cipher2[returning_letter])
            {
                break;
            }
            else{
                mess=i;
            }
        }
        if (mess==user_message_cpy.length()-1)
        {
            if (int(char(user_message_cpy[mess]))>90)
            {
                user_message_cpy+=cipher[returning_letter];
            }
            else{
                user_message_cpy+=cipher2[returning_letter];
            }
        }
    }
    }
void encrypt_message(){
    cout<<"write your message"<<endl;
    cin.ignore();
    getline(cin,final_encryption);
    for (int msg  = 0; msg < final_encryption.length(); msg++)
    {
        for (int enc = 0; enc <= 25; enc++)
        {
            if (final_encryption[msg]==cipher[enc]||final_encryption[msg]==cipher2[enc])
            {
                finall_message+=user_message_cpy[enc];
            }
            if (int(char(final_encryption[msg])) == 32){
                finall_message+=" ";
                msg+=1;
                }

        }
    }
    cout<<finall_message<<endl;
}
void decrypt_message(){
    cout<<"write your message"<<endl;
    cin.ignore();
    getline(cin,final_encryption);
    for (int msg  = 0; msg < final_encryption.length(); msg++)
    {
        for (int enc = 0; enc <= 25; enc++)
        {
            if (final_encryption[msg]==user_message_cpy[enc])
            {
                finall_message+=cipher[enc];
            }
            if (int(char(final_encryption[msg])) == 32){
                finall_message+=" ";
                msg+=1;
            }

        }
    }
    cout<<finall_message<<endl;
}
void choices(){
    cout<<"if u want to encrypt press 1 "<<endl;
    cout<<"if u want to decrypt press 2 "<<endl;
    int user_choice;
    while (!(cin>>user_choice)) {
        cout<<"write a valid number"<<endl;
        cin.clear();
        cin.ignore(132,'\n');
    }
    if (user_choice ==1)
    {
        encrypt_message();
    }
    else if (user_choice ==2) {
        decrypt_message();
    }
    else{
        cout<<"write a valid number"<<endl;
        choice();
    }
}


// polybius square cipher program.
char n1,n2,n3,n4,n5;
string encrypttt(string word){
    string big_word;
    //loop to change every letter to upper
    for (int i = 0; i < word.length(); i++){
        int ascii = word [i];
        if (ascii == 32)
        {
            big_word.push_back(' ');
        }
        else if (ascii==106){
            big_word.push_back('I');
        }
        else{
            char ch = toupper(word[i]);
            big_word.push_back(ch);
        }
    }
    cout<<"enter the first number:";
    cin>>n1;
    cout<<"enter the second number:";
    cin>>n2;
    cout<<"enter the third number:";
    cin>>n3;
    cout<<"enter the fourth number:";
    cin>>n4;
    cout<<"enter the fifth number:";
    cin>>n5;
    char ALPHABET[6][6]={
        {' ',n1,n2,n3,n4,n5},
        {n1,'A','B','C','D','E'},
        {n2,'F','G','H','I','K'},
        {n3,'L','M','N','O','P'},
        {n4,'Q','R','S','T','U'},
        {n5,'V','W','X','Y','Z'}
    };
    string encrypted_word="";
        for (int i = 0; i < big_word.length(); i++){
            for (int j = 1; j < 6; j++){
                for (int k = 1; k < 6; k++){
                    if(big_word[i]==ALPHABET[j][k]){
                        encrypted_word += ALPHABET[j][0];
                        encrypted_word += ALPHABET[0][k];
                    }
                }
            }
        }
    return encrypted_word;
}
string decrypttt(string word){
    cout<<"enter the first number:";
    cin>>n1;
    cout<<"enter the second number:";
    cin>>n2;
    cout<<"enter the third number:";
    cin>>n3;
    cout<<"enter the fourth number:";
    cin>>n4;
    cout<<"enter the fifth number:";
    cin>>n5;
    char ALPHABET[6][6]={
        {' ',n1,n2,n3,n4,n5},
        {n1,'A','B','C','D','E'},
        {n2,'F','G','H','I','K'},
        {n3,'L','M','N','O','P'},
        {n4,'Q','R','S','T','U'},
        {n5,'V','W','X','Y','Z'}
    };
    string decrypted_word="";
    for (int i = 0; i < word.length(); i+=2){
        for (int j = 0; j < 6; j++){
            for (int k = 0; k < 6; k++){
                if(word[i]==ALPHABET[j][0]){
                    int row=j;
                    if(word[i+1]==ALPHABET[0][k]){
                        int column = k;
                        decrypted_word+=ALPHABET[row][column];
                    }
                }
            }
        }
    }
    return decrypted_word;
}


//Morse cipher program.
 string encryptt(string word){
    string big_word;
    //loop to change every letter to upper
    for (int i = 0; i < word.length(); i++){
        int ascii = word [i];
        if (ascii == 32)
        {
            big_word+="  ";
        }
        else{
            char ch = toupper(word[i]);
            big_word.push_back(ch);
        }
    }
    map <char,string> ENCODE_MAP;
    ENCODE_MAP.insert(pair<char,string>('A',".-"));
    ENCODE_MAP.insert(pair<char,string>('B',"-..."));
    ENCODE_MAP.insert(pair<char,string>('C',"-.-."));
    ENCODE_MAP.insert(pair<char,string>('D',"-.."));
    ENCODE_MAP.insert(pair<char,string>('E',"."));
    ENCODE_MAP.insert(pair<char,string>('F',"..-."));
    ENCODE_MAP.insert(pair<char,string>('G',"--."));
    ENCODE_MAP.insert(pair<char,string>('H',"...."));
    ENCODE_MAP.insert(pair<char,string>('I',".."));
    ENCODE_MAP.insert(pair<char,string>('J',".---"));
    ENCODE_MAP.insert(pair<char,string>('K',"-.-"));
    ENCODE_MAP.insert(pair<char,string>('L',".-.."));
    ENCODE_MAP.insert(pair<char,string>('M',"--"));
    ENCODE_MAP.insert(pair<char,string>('N',"-."));
    ENCODE_MAP.insert(pair<char,string>('O',"---"));
    ENCODE_MAP.insert(pair<char,string>('P',".--."));
    ENCODE_MAP.insert(pair<char,string>('Q',"--.-"));
    ENCODE_MAP.insert(pair<char,string>('R',".-."));
    ENCODE_MAP.insert(pair<char,string>('S',"..."));
    ENCODE_MAP.insert(pair<char,string>('T',"-"));
    ENCODE_MAP.insert(pair<char,string>('U',"..-"));
    ENCODE_MAP.insert(pair<char,string>('V',"...-"));
    ENCODE_MAP.insert(pair<char,string>('W',".--"));
    ENCODE_MAP.insert(pair<char,string>('X',"-..-"));
    ENCODE_MAP.insert(pair<char,string>('Y',"-.--"));
    ENCODE_MAP.insert(pair<char,string>('Z',"--.."));
    char big_ch;
    int num = 1;
    string encoded_word ="";
    for (int let = 0; let < big_word.length() ; let++){
        big_ch = big_word[let];
        for (auto iter = ENCODE_MAP.begin(); iter != ENCODE_MAP.end(); ++iter){
            char key = iter->first;
            string value = iter->second;
            if (ENCODE_MAP.find(big_ch) != ENCODE_MAP.end()){
                if (big_ch == key)
                {
                    encoded_word.append(value);
                    encoded_word.append(" ");
                }
            }
            else if (int(key) == 90 and int(big_ch)!=90){
                encoded_word+=big_ch;
            }
        }
    }
    return encoded_word;
}
string decryptt(string word){
    // map of decoding

    map <string,char> DECODE_MAP{
        {".-",'A'},
        {"-...",'B'},
        {"-.-.",'C'},
        {"-..",'D'},
        {".",'E'},
        {"..-.",'F'},
        {"--.",'G'},
        {"....",'H'},
        {"..",'I'},
        {".---",'J'},
        {"-.-",'K'},
        {".-..",'L'},
        {"--",'M'},
        {"-.",'N'},
        {"---",'O'},
        {".--.",'P'},
        {"--.-",'Q'},
        {".-.",'R'},
        {"...",'S'},
        {"-",'T'},
        {"..-",'U'},
        {"...-",'V'},
        {".--",'W'},
        {"-..-",'X'},
        {"-.--",'Y'},
        {"--..",'Z'}
    };
    string decoded_word;
    string shift;
    decode_loop:
        for (int i = 0; i < word.length(); i++){
            if (word[i]!=' '){
                shift.push_back(word[i]);
            }
            else if(word[i]==' '){
                for (auto iter = DECODE_MAP.begin(); iter != DECODE_MAP.end(); ++iter){
                string key = iter->first;
                char value = iter->second;
                if (DECODE_MAP.find(shift) != DECODE_MAP.end()){
                    if (shift == key){
                    decoded_word.push_back(value);
                    shift.clear();
                    break;
                        }
                    }
                }
                if (int(char(word[i])) ==32 &&int(char(word[i+1])) ==32)
                {
                    decoded_word+=" ";
                }

            }
        }
    return decoded_word;
}

// XOR cipher program.
string encryption(string text,char key){
    for (int i =0;i<=text.length();i++)
        text[i] = text[i] ^ key;
    return text;
}
string decryption(string text,char key){
    for(int j=0;j<=text.length();j++)
        text[j] = text[j] ^ key;
    return text;
}
string hex_transform(string enc_or_dec_message){
    for (int i=0;i<=enc_or_dec_message.length();i++)
       cout<< hex <<int(enc_or_dec_message[i]);
}


// Rail Fence cipher program.
string decryptions(string message, int keyy){
    //creating the matrix.
    char fence[keyy][message.length()];

    //filling the matrix by space to make it easy to move later.
    for (int i=0; i< keyy; i++)
        for(int j=0; j<message.length();j++)
            fence[i][j] = '\n';
    //variables made to go through the matrix easy.
    int row = 0, col = 0;
    bool go_down;
    //filling stars in a zigzag manner to mark the places to put the letter later.
    for(int i =0; i<message.length();i++)
    {
        if(row == 0)
            go_down = true;
        if (row == keyy-1)
            go_down = false;

        fence[row][col++] ='*';

        if(go_down == true)
            row++;
        else
            row--;
    }
    int cell=0;
    //replacing the '*' with a letter from the message in a horizontal manner.
    for(int i=0; i<keyy;i++)
        for(int j=0; j<message.length();j++)
            if(fence[i][j] == '*' && cell < message.length() )
                fence[i][j] = message[cell++];

    //placing the letter placed in a zigzag manner in the new message.
    string result;
    row = 0,col = 0;
    for(int i=0;i<message.length();i++)
    {
        if(row == 0)
            go_down = true;
        if (row == keyy-1)
            go_down = false;
        if(fence[row][col] != '*')
            result.push_back(fence[row][col++]);
        if(go_down == true)
            row++;
        else
            row--;
    }

    return result;
}
string encryptions(string message, int keys){
    //creating the matrix.
    char fence[keys][message.length()];

    //filling the matrix by space so we can later go through the matrix.
    for (int i=0; i< keys; i++)
        for(int j=0; j<message.length();j++)
            fence[i][j] = '\n';

    //variable declared to move up and down in the matrix.
    bool go_down = false;
    int row=0, col=0;

    //filling the matrix in a zigzag manner.
    for(int i =0; i<message.length();i++)
    {
        if(row == 0 || row == keys-1)
            go_down = !go_down;

        fence[row][col++] = message[i];

        if(go_down == true)
            row++;
        else
            row--;
    }

    //adding the letters in a horizontal manner to new message.
    string result;
    for(int i=0; i<keys;i++)
        for(int j=0; j<message.length();j++)
            if(fence[i][j] != '\n')
                result.push_back(fence[i][j]);

    return result;
}


int main()
{
   int num;

   cout<<"Enter the number of the required cipher"<<endl;
   cout<<"---------------------------------------------------------"<<endl;
   cout<<"Aiffine cipher             ||                        1"<<endl;
   cout<<"Caesar cipher              ||                        2"<<endl;
   cout<<"Atbash cipher              ||                        3"<<endl;
   cout<<"Vignere cipher             ||                        4"<<endl;
   cout<<"Baconian cipher            ||                        5"<<endl;
   cout<<"Simple Substitution cipher ||                        6"<<endl;
   cout<<"Polybius cipher            ||                        7"<<endl;
   cout<<"Morse cipher               ||                        8"<<endl;
   cout<<"XOR cipher                 ||                        9"<<endl;
   cout<<"Rail Fence cipher          ||                        10"<<endl;
   cout<<"---------------------------------------------------------"<<endl;
   cout<<"Enter the Number:";
   cin>>num;
   cin.ignore();
   switch(num)
   {
   case 1:
    prepare_encyption();
    choice();
    break;
   case 2:
    cout<<"enter your message"<<endl;
    getline(cin,user_message);
    user_choice();
    break;

   case 3:
    cout<<"enter your message"<<endl;
    getline(cin,users_message);
    users_choice();
    break;

   case 4:
       {
    string new_message, key_word,repeated_keyword, encrypted_message, deccrypted_message;
    int n;
    bool isOk = true;

    while(isOk){
        cout<<"1-Encrypt!\n";
        cout<<"2-Decrypt!\n";
        cout<<"3-Exit!\n";
        cin>>n;
        cin.ignore();
        switch(n)
        {
            case 1:
                {
                new_message = check_message();
                key_word = check_keyword();
                cout<<"----------------------------------------------------"<<endl;
                cout<<"the message          :"<<message<< endl;

                repeated_keyword = repeated_kw(new_message,key_word);
                cout<<"the repeated keyword :"<< repeated_keyword<<"\n";

                encrypted_message = encryption(new_message, repeated_keyword);
                cout<<"the encrypted message:"<<encrypted_message<<"\n";
                cout<<"--------------------------------------------------------\n";
                break;
                }
            case 2:
                {
                new_message = check_message();
                key_word = check_keyword();
                cout<<"----------------------------------------------------"<<endl;
                cout<<"the message          :"<<message<< endl;

                repeated_keyword = repeated_kw(new_message,key_word);
                cout<<"the repeated keyword :"<< repeated_keyword<<"\n";

                deccrypted_message = decryption(new_message, repeated_keyword);
                cout<<"the decrypted message:"<<deccrypted_message<<"\n";
                cout<<"--------------------------------------------------------\n";
                break;
                }
            default:
                isOk = false;
                break;

                }
            }
        break;
       }

    case 5:
        int opp;
        cout<<"for encrypting choose 1\nfor decrypting choose 2\nto exit choose 3: ";
        cin>>opp;
        if(opp ==1){
            cout<<"enter statment to encode:";
            cin.ignore();
            string statments;
            getline(cin,statments);
            string encrypted = encrypt(statments);
            cout<<"the encrypted text is "<< encrypted;
                }
        else if (opp==2){
            cout<<"enter statment to decode:";
            cin.ignore();
            string statments;
            getline(cin,statments);
            string decrypted = decrypt(statments);
            cout<<"the decrypted text is "<<decrypted;
                }
        else if (opp==3){
            exit(0);
                }
        break;
    case 6:
        encrypts();
        choices();
        break;

    case 7:
            int opption;
            cout<<"for encrypting choose 1\nfor decrypting choose 2\nto exit choose 3: ";
            cin>>opption;

            if(opption ==1){
                cout<<"enter statment to encode:";
                cin.ignore();
                string statment;
                getline(cin,statment);
                string encrypted = encrypttt(statment);
                cout<<"the encrypted statment is: "<<encrypted;
            }
            else if (opption==2){
                cout<<"enter statment to decode:";
                cin.ignore();
                string statment;
                getline(cin,statment);
                string decrypted = decrypttt(statment);
                cout<<"the decrypted text is "<<decrypted;
            }
            else if (opption==3){
                exit(0);
            }
    case 8:
        int opps;
        cout<<"for encrypting choose 1\nfor decrypting choose 2\nto exit choose 3: ";
        cin>>opps;
        if(opps ==1){

            cout<<"enter statment to encode:";
            cin.ignore();
            string statment;
            getline(cin,statment);
            string encrypted = encryptt(statment);
            cout<<"the encrypted text is "<< encrypted;
            }
        else if (opps==2){

            cout<<"enter statment to decode:";
            cin.ignore();
            string statment;
            getline(cin,statment);
            string decrypted = decryptt(statment);
            cout<<"the decrypted text is "<<decrypted;
            }
        else if (opps==3){
            exit(0);
            }
         break;
    case 9:
        {
            string mesage,encoded_message,decoded_message;
           char s_key;
           bool is_ok;
           int nm;
           is_ok = true;

           while(is_ok)
           {
               cout<<"1-Encryption"<<endl;
               cout<<"2-Decryption"<<endl;
               cout<<"3-Exit"<<endl;
               cin>>nm;
               cin.ignore();

               switch(nm)
               {
               case 1:
                {
                cout<<"enter your message to encrypt:";
                getline(cin,mesage);
                cout<<"enter the secret key:";
                cin>>s_key;
                cin.ignore();
                encoded_message = encryption(mesage,s_key);
                cout<<"encoded message is "<<encoded_message<<",";
                cout<<"   hexadecimal representation is :"<<hex_transform(encoded_message)<<endl;
                break;
                }
               case 2:
                {
                    cout<<"enter your message to decrypt:";
                    getline(cin,mesage);
                    cout<<"enter the secret key:";
                    cin>>s_key;
                    cin.ignore();

                    decoded_message = decryption(mesage,s_key);
                    cout<<"decoded message is "<<decoded_message<<",";
                    cout<<"   hexadecimal representation is :"<<hex_transform(decoded_message)<<endl;
                    break;
                }
               default :

                    cout<<"thanks for using this cipher!"<<endl;
                    is_ok = false;
                    break;
                }
            }
            break;
        }
    case 10:
          {
              bool isOk = true;

              cout<<"choose an operation from the next three operations!!\n";
    while (isOk){
            string text;
            int key, n;

            cout<<"1-Encryption!"<<endl;
            cout<<"2-Decryption!"<<endl;
            cout<<"3-Exit!"<<endl;
            cin>>n;

            cin.ignore();

            switch(n)
            {
                case 1:
                    {
                    cout<<"enter your text:";
                    getline(cin, text);

                    cout<<"enter the number of rails :";
                    cin>>key;
                    cin.ignore();

                    cout<<"the encrypted text is :"<<encryptions(text,key)<<"\n";
                    cout<<"------------------------------------------------------"<<"\n";
                    break;
                    }
               case 2:
                   {
                    cout<<"enter your text:";
                    getline(cin, text);

                    cout<<"enter the number of rails :";
                    cin>>key;
                    cin.ignore();

                    cout<<"the decrypted text is :"<<decryptions(text,key)<<"\n";
                    cout<<"------------------------------------------------------"<<"\n";
                    break;
                   }
               default:
                    isOk = false;
                    break;
                }
            }
            break;
          }
    }
    cout<<"Thank you for using our cipher!";
}
