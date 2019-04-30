#include<iostream>
#include<cmath> 
#include<string>
#include<fstream>
#include<sstream>
#include<vector>
#include<iomanip>

using std::ofstream;
using std::cin;
using std::cout;
using std::string;
using std::endl;
using std::stringstream; 
using std::ifstream;
using std::vector;
vector<string> break_codon(string gen_code) {
  vector<string> conc_mRna;
  string current_str;//* new string */
  for (int i = 3;i<=gen_code.size();i=i+3) {
     
    current_str = gen_code.substr(i-3,3); 
    conc_mRna.push_back(current_str);
  }
  
   return conc_mRna;
 }


int main(){
std::string mRna; 
string mRna_tot;
ifstream myfile_mRna;
myfile_mRna.open("lambda_RNA.txt");
while (getline(myfile_mRna,mRna)){
 mRna_tot += mRna; 
}
myfile_mRna.close();
//string conc_mRna = break_codon(mRna_tot);    

vector<string> conc_mRna_a = break_codon(mRna_tot);  
for(string i : conc_mRna_a) {
  cout << i << endl; 

}
return 0;
} 
