#include<iostream>
using namespace std;

void prefix(string);
void suffix(string);
void properSuffix(string);
void properPrefix(string);
void substring(string);
void subsequences(string);
int main(){
    string str;
    int choice;

    cout<< "enter the string:" ;
    cin>>str;
      cout<<"length of the string = "<<str.length()<<endl;
    do{
      cout<<"\n1. Prefix Combination:\n2. Suffix combination:\n3. Proper Prefix combination:\n4. Proper Suffix combination:\n5. Substring combination:\n6.subsequenses Combination:";
      cin>>choice;

      switch(choice){
        case 1:
          prefix(str);
          break;
        case 2:
          suffix(str);
          break;
        case 3:
          properPrefix(str);
          break;
        case 4:
          properSuffix(str);
          break;
        case 5:
          substring(str);
          break;
        case 6:
          subsequences(str);
          break;
        default:
          choice = 0;
          cout<<"Invalid Option. Pragram exit!!!"<<endl;
          break;
        
      }
    }while(choice != 0);

}

void prefix(string s){
    int count = 0;
    cout<<"\n Prefix Combination are: "<<endl;

    string temp;
    for(int i = 0; i < s.length(); i++){
      cout<<temp<<endl;
      count++;
      temp+= s[i];
      if(i==s.length()-1)
      {
      cout<<temp<<endl;
      count++;
      }
    }
    cout<<"Number of Prefix:"<<count<<endl;
    cout<<endl<<endl;
}

void suffix(string s){
  int count=0;
  cout<<"\n Suffix combination are: "<<endl;

  string temp;
  for (int i=s.length() - 1; i>=0; i--){
    cout<<temp<<endl;
    temp = s[i] + temp;
    count++;
    if(i==0){
      cout<<temp<<endl;
      count++;
    }
  }
  cout<<"Number of suffix: "<<count<<endl;
  cout<<endl<<endl;
}

void properPrefix(string s){
  int count = 0;
  cout<<"\n Proper prefix Combination are: "<<endl;

  string temp;
  for(int i = 0;i< s.length();i++){
    temp += s[i];
    if(i!=s.length()-1){
      cout<<temp<<endl;
      count++;
    }
  }
  cout<<"Number of ProperPrefix: "<<count<<endl;
  cout<<endl<<endl;

}
void properSuffix(string s){
  int count=0;
  cout<<"\n Proper Suffix combination are: "<<endl;

  string temp;
  for (int i=s.length() - 1; i>=0; i--){
    if(i!=s.length()-1){
    temp = s[i] + temp;
    cout<<temp<<endl;
    count++;
    }
  }
  cout<<"Number of Proper suffix: "<<count<<endl;
  cout<<endl<<endl;
}

void substring(string s){
  int count = 0;
  cout<<"\nSubstring combinations are: "<<endl;

  for(int i = 0;i<s.length();i++){
    string temp;
    for(int j = i;j<s.length();j++){
      temp+= s[j];
      cout<<temp<<endl;
      count++;
    }
  }
  cout<<"Number of substrings: "<<count<<endl;
  cout<<endl<<endl;
}

void subsequences(string s){
  int count = 0;
  cout<<"\nSubsequence combinations are: "<<endl;

  for(int i = 0; i < (1 << s.length()); i++){
    string temp;
    for(int j = 0; j < s.length(); j++){
      if(i & (1 << j)){
        temp += s[j];
      }
    }
    cout << temp << endl;
    count++;
  }
  cout<<"Number of subsequences: "<<count<<endl;
  cout<<endl<<endl;
}