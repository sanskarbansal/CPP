#include<iostream>
#include<climits>
#include<fstream>
using namespace std;

double long fact(int n){
  double long ans = 1;
  for(int i = 1; i <= n ; i++)
    ans = ans * i;
  return ans;
}

double long ncm(int n, int r){
  double long ans = fact(n)/(fact(r)*fact(n-r));
  return ans;
}


int main(){
  ofstream f("Binomial.html");
  f << "<html>\n<title>Binomial</title>\n<body>\n<p>";
  int t;
  cin >> t;
  for(int i = 0; i < t; i++){
    int n; cin >> n;
    string a,b; cin >> a >> b;
    for(int i = 0; i <= n; i++){
      f << "<sup>" << n << "</sup>C<sub>" << i << "</sub>" << "("<< a << ")" << "<sup>" << n - i << "</sup> ("<< b << ")"<< "<sup>" << i << "</sup>";
      if(i != n){
        f << "+";
      }
    }
    f << "</br>";
    for(int i = 0; i <= n; i++){
      f << ncm(n, i) << "("<< a << ")" << "<sup>" << n - i << "</sup> ("<< b << ")"<< "<sup>" << i << "</sup>";
      if(i != n){
        f << "+";
      }
    }

    f << "<br>";
  }
f << "\n</p></body>\n</html>";
f.close();
}
