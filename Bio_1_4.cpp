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
vector<string> break_codon(string gen_code) {
  vector<string> conc_mRna;
  string current_str;//* new string */
  int j; 
  for (int i = 3;i<=(gen_code.size()-1);i=i+3) {
    if (gen_code.substr(i-3,3) == "AUG"){      
    j = i-3;
     
    break; 
    }
  }
  for (int a = j;a <= (gen_code.size() - j);a=a+3) { 
     current_str = gen_code.substr(a,3); 
    // cout << current_str; 
     conc_mRna.push_back(current_str); 

  }
    
    return conc_mRna;
    
  
}

vector<string> polypeptide(vector<string> codons){ 
vector<string> Polypeptide; 

for (string i: codons) {
  

   if (i.at(0) == 'A'){  //Start base A 
      if (i[1] == 'C')    // AC   
        Polypeptide.push_back("Thr");
      if (i[1] == 'U'){     //AU
          if (i[2] == 'G')
            Polypeptide.push_back("Met");
          else 
            Polypeptide.push_back("Ile");}
      if (i[1] == 'A'){ //AA
          if (i[2] == 'U' || i[2] == 'C') //AAU or AAC
            Polypeptide.push_back("Asn"); 
          else 
            Polypeptide.push_back("Lys");} //AAA or AAG
      if (i[1] == 'G') {//AG 
          if (i[2] == 'U' || i[2] == 'C') //AGU or AGC
            Polypeptide.push_back("Ser");
          else 
            Polypeptide.push_back("Arg");}}//AGA or AGG }
  if (i[0] == 'U') {
      if (i[1] == 'C') 
        Polypeptide.push_back("Ser");
      if (i[1] == 'U') {
          if (i[2] == 'U' || i[2] == 'C') //UUU and UUC
            Polypeptide.push_back("Phe");
          else 
            Polypeptide.push_back("Leu");} //UUA and UUG
      if (i[1] == 'A') {
          if (i[2] == 'U' || i[2] == 'C')//UAU and UAC
            Polypeptide.push_back("Tyr");
          else 
            Polypeptide.push_back("STOP");}//UAA and UAG
      if (i[1] == 'G'){//UG 
          if (i[2] == 'U' || i[2] == 'C') //UGU and UGC
            Polypeptide.push_back("Cys"); 
          if (i[2] == 'A') //UGA
            Polypeptide.push_back("Stop");
          if (i[2] == 'G') //UGG
            Polypeptide.push_back("Trp");}}
  if (i[0] == 'G') {
      if (i[1] == 'U') 
        Polypeptide.push_back("Val");
      if (i[1] == 'C')
        Polypeptide.push_back("Ala");
      if (i[1] == 'G')
        Polypeptide.push_back("Gly");
      if (i[1] == 'A') {
        if (i[2] == 'U' || i[2] == 'C') //GAU or GAC
            Polypeptide.push_back("Asp");
        else  //GAA or GAG
            Polypeptide.push_back("Glu");}}
  if (i[0] == 'C') {
     if (i[1] == 'U') 
         Polypeptide.push_back("Leu");
     if (i[1] == 'C')
        Polypeptide.push_back("Pro"); 
     if (i[1] == 'G') 
          Polypeptide.push_back("Arg"); 
     if (i[1] == 'A'){//CA
        if (i[2] == 'U' || i[2] == 'C') //CAC or CAU
          Polypeptide.push_back("His");
        else
          Polypeptide.push_back("Gln");}} 

     }
return Polypeptide; } 

int main(){
std::string mRna; 
string mRna_tot; 
ifstream myfile_mRna;
myfile_mRna.open("lambda_RNA.txt");
while (getline(myfile_mRna,mRna)){
 mRna_tot += mRna; 
}
myfile_mRna.close();
    

vector<string> conc_mRna = break_codon(mRna_tot);   

vector<string> my_polypeptide = polypeptide(conc_mRna);  

for (int a = 0; a <=50; a++){  
    cout << my_polypeptide[a]<<";";
}
for (int b = 0; b<=50; b++) {
  cout << conc_mRna[b]<<";";}

cout << "Size of Polypeptide is " << my_polypeptide.size() << endl;
cout << "Size of conc mRna is " << conc_mRna.size() << endl; 
return 0;
} 
