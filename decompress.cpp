
#include <bits/stdc++.h>
using namespace std;

int main() {

    ifstream nimoo;
    nimoo.open("com.txt");

    unordered_map<string, string> mp;

    
    while (nimoo) {
        string s;
        nimoo >> s;

        if (s == "khatm") {
            break; 
        }

        string s1;
        nimoo >> s1;

        mp[s1] = s;
    }

  
    // for (auto it : mp) {
    //     cout << it.first << " " << it.second << endl;
    // }

    // Reset the input stream to read again
    nimoo.clear();            // Clear the EOF flag
    nimoo.seekg(0, ios::beg); // Seek to the beginning of the file

    // Skip to the "decode" part
    while (nimoo) {
        string s;
        nimoo >> s;
        if (s == "decode") {
            break; // Stop at "decode"
        }
    }

    string temp = "";
    
    fstream ans;
    ans.open("decoded.txt", ios::out); 

   
    while (nimoo) {
        char c;
        nimoo >> c;

        // Check if we've reached EOF
        if (nimoo.eof()) {
            break;
        }

        temp += c; 

        // Check if accumulated string matches a Huffman code
        if (mp.find(temp) != mp.end()) {
            ans << mp[temp]; // Write the decoded character
            ans << " "; // Add a space
            temp = ""; // Reset to empty string
        }
    }

   
    nimoo.close();
    ans.close();

    return 0;
}
