#include <iostream>
#include <sstream> 
#include <vector> 
#include <bitset>

using namespace std;


vector<string> split(string s, char delimiter=' '){

   stringstream ss(s); 

   string token; 
   vector<string> tokens; 

   while (getline(ss, token, delimiter)){ 
      tokens.push_back(token); 
   } 

   return tokens;
}


unsigned char invertLastTwoBits(unsigned char byte){
   return (byte ^ 0b00000011);
}


unsigned char swapFourBitChunks(unsigned char byte){
   return ((byte & 0b11110000) >> 4) | ((byte & 0b00001111) << 4);
}


void decrypt_message(string message){

   vector<string> bytes = split(message,' ');
   
   for(int i=0; i < bytes.size(); i++){
      unsigned char bit = static_cast<unsigned char>(bitset<8>(bytes[i]).to_ulong());
      unsigned char character = swapFourBitChunks(invertLastTwoBits(bit));
      cout << character;
   }
   cout << "\n";
}


int main(){

   string message = "10010110 11110111 01010110 00000001 00010111 00100110 01010111 00000001 00010111 01110110 01010111 00110110 11110111 11010111 01010111 00000011";

   decrypt_message(message);

   return 0;
}