#include<iostream>
#include<cmath>
#include<string>
#include<fstream>
#include<sstream>
#include<vector>
#include<iomanip>
#include<typeinfo>
using std::ofstream;
using std::cin;
using std::cout;
using std::string;
using std::endl;
using std::stringstream;
using std::ifstream;
using std::vector;
//This is the corrected version Sarah
bool Where_is_the_Match(string my_string,string matched){
int i;
int j;

bool myBool;
for (i = 0; i <= matched.size()-1; i++) { // The reference string index
  myBool = true;
  
  for (j = 0; j <= my_string.size()-1; j++) {
    int a = i + j;
    if (matched[a] != my_string[j]){
         myBool = false;
         break;     }}
if (myBool == true){break;} 
}
//if (myBool == true)
  //cout << "The indicies of match are " << i << "," << i + my_string.size() << endl; 
return myBool; }

int main() {

string matched = "ImisstheoldKanye";
string my_string = "Kanye"; 

bool is_match = Where_is_the_Match(my_string,matched); 
cout << is_match << endl; 
if (is_match) { cout << "Perfect Match!" << endl;} 

return 0; 
} 
