#include <iostream>
#include <string>

/**
 * A morse code decoder.
 */
//_| ..

using namespace std;
string morseCode[36] = {"._", "_...", "_._.", "_..", ".", ".._.", "__.", "....", "..", ".___", "_._", "._..", "__", "_.", "___", ".__.", "__._", "._.", "...", "_", ".._", "..._", ".__", "_.._", "_.__", "__..", ".___", "..___", "...__", "...._", ".....", "_....", "__...", "___..", "____.", "______" }; //dictionary for morsecode patterns

string alphabets[36]= {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", "1", "2", "3", "4", "5", "6", "7", "8", "9", "0"}; //dictonary for alphabets + numbers

// IMPORTANT:  Do NOT change any of the function headers
//             It means that you will need to use the function headers as is
//             You may add other functions wherever appropriate


/**
 * Decode the morse code `s` and return the text character
 */
string morseCodeToText(string s) {
	string text = "";
    string pattern = ""; //to add a pattern
    for (int i = 0; i < s.size(); i++){
        if(s[i]=='|'){
            for (int j = 0; j < 36; j++){
                if(string(pattern) == morseCode[j]){ //check whether the input pattern matched with the dictionary
                    text+=alphabets[j]; //add the word into the final text
                    break;
                }
            }
            if(s[i+1]=='|'){ //check whether it is a space
                text+=" "; 
                i+=1;
            }
            pattern="";
        }
        else{
            pattern+=s[i]; 
        }
    }
    for (int j = 0; j < 36; j++){
        if(string(pattern) == morseCode[j]){
            text+=alphabets[j];
            break;
        }
    }
	return text;
}


int main()
{
	string s;
	cin >> s;
	cout << morseCodeToText(s) << '\n';
    return 0;
}
