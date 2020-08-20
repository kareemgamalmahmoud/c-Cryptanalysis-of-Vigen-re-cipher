#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

/*
	this function repeted the key to make its
	length as long as the plainText of (message)
*/
string length_key_function(string message, string key_word)
{
	int size = message.size();
	for (int i = 0; true; i++) {
		if (size == i)
			i = 0;
		if (key_word.size() == message.size())
			break;
		key_word.push_back(key_word[i]);
	}
	return key_word;
}

/*	
	this function take the message and the key as parameters
	and return cipherText. 
*/
string encryption_function(string message, string keyword)
{
	string cipher_text;
	for (int i = 0; i < message.size(); i++) {
		char c = (message[i] + keyword[i]) % 26;
		/*A = 65  (i push it back) to make sure the range from 0 to 25 */
		c += 'A';
		cipher_text.push_back(c);
	}
	return cipher_text;
}

/*	
	this function take the cipherText and the key as parameters
	and return original message again. 
*/
string decryption_function(string cipher_text, string keyword) {
	string original_message;
	for (int i = 0; i < cipher_text.size(); i++) {
		char m = (cipher_text[i] - keyword[i] + 26) % 26;
		/*A = 65  (i push it back) to make sure the range from 0 to 25 */
		m += 'A';
		original_message.push_back(m);
	}
	return original_message;
}
/*
	this function takes some letters from the message , there corresponding of the cipherText and the length of the key as parameters
	and return the keyword. 
*/
string keyword_function(string message, string cipherText, int length_of_key) {
	string keyword;
	for (int i = 0; i < length_of_key; i++) {
		char e = (cipherText[i] - message[i] + 26) % 26;
		/*A = 65  (i push it back) to make sure the range from 0 to 25 */
		e += 'A';
		keyword.push_back(e);
	}
	return keyword;
}
void main(){
	do {
		int x;
		cout << "==>Press (1) to see a ready example . \n";
		cout << "==>Press (2) if you want to use known plain text attack to get the key.\n";
		cout << "==>Press (0) if you want to exit . \n";
		cin >> x;
		if (x == 1)
		{
			string message = "TOMORROWATTHESUNSET";
			string keyword = "CFBKU";

			string long_key = length_key_function(message, keyword);
			string cipher_text = encryption_function(message, long_key);
			string keyword_2 = keyword_function(message, cipher_text, keyword.length());

			cout << "\n The plain text we will encrypte it : ( " << message << " ) " << "and the length of the key : " << keyword.length() << " ( " << keyword << " ).";

			cout << "\n\n* the encryption ==> Ciphertext : " << cipher_text << "\n\n";
			cout << "* the decryption ==> old message : " <<
				decryption_function(cipher_text, long_key) << "\n\n";
			cout << "* by using known plain text ,the key :" << keyword_2 << "\n\n";
		}
		else if (x == 2)
		{
			string message =" ";
			string cipherText =" ";
			int key_length;

			cout << "===>Note , the message and the keyword that you will enter \n"
				 << "    those will be with capital letters with out any spaces .\n\n";

			cout << "\n===>Please , Enter your message : ";
			cin >> message;
			
			//This algorithm allow you to ignore any space
			remove_if(message.begin(), message.end(), isspace);
			//This (for loop) allow you to convert any small letters to capital letters
			for (auto & c : message) c = toupper(c);

			cout << "\n===>Please , Enter the ciphet text : ";
			cin >> cipherText;

			remove_if(cipherText.begin(), cipherText.end(), isspace);			
			for (auto & e : cipherText) e = toupper(e);

			cout << "\n===>Please , Enter the length of the key : ";
			cin >> key_length;
			
			while (key_length > 26)
			{
				key_length = key_length % 26;
			}

			if (key_length <= message.length())
			{
				string keyword = keyword_function(message, cipherText, key_length);

				cout << "\n* by using known plain text ,the key is :" << keyword << "\n\n";
			}
			else
			{
				cout << "\n note : the length of the key must be equal or less than the length of the message. please, try again ! \n" << endl;
			}			
		}
		else if (x == 0){
			break;
		}
		else{
			cout << "==>Please, Enter a correct number .";
		}
	} while (true);

	system("pause");
}
