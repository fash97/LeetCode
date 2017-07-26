class Solution {
  public:
    string complexNumberMultiply(string a, string b) {
      int real1 = 0, real2 = 0, fake1 = 0, fake2 = 0;
      bool positive1 = true, positive2 = true, positive3 = true, positive4 = true;
      int i;
      if(a[0] == '-') positive1 = false;
      if(positive1)   i = 0;
      else    i = 1;
      while(a[i] != '+'){
        real1 = real1*10 + (a[i++]-'0');
        cout << "real1: "  << real1 << endl;
      }
      if(a[i+1] == '-')   positive2 = false;
      if(positive2)   i=i+1;
      else    i=i+2;
      while(a[i] != 'i'){
        fake1 = fake1*10 + (a[i++]-'0');
      }
      if(b[0] == '-') positive3 = false;
      if(positive3)   i = 0;
      else    i = 1;
      while(b[i] != '+'){
        real2 = real2*10 + (b[i++]-'0');
      }
      if(b[i+1] == '-')   positive4 = false;
      if(positive4)   i=i+1;
      else    i=i+2;
      while(b[i] != 'i'){
        fake2 = fake2*10 + (b[i++]-'0');
      }
      if(!positive1)  real1 = -real1;
      if(!positive2)  fake1 = -fake1;
      if(!positive3)  real2 = -real2;
      if(!positive4)  fake2 = -fake2;
      return to_string(-(fake1*fake2)+real1*real2)+"+"+to_string(real1*fake2+real2*fake1)+"i";
    }
};
