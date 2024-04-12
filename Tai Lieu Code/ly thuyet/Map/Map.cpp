#include <bits/stdc++.h>

using namespace std;


int main() {
    
    map<string,int>d,mymap; 
    mymap["a"]=10;
  mymap["b"]=20;
  mymap["c"]=30;
  mymap["d"]=40;
  mymap["e"]=50;
  mymap["f"]=60;
// Xóa map 

 auto it=mymap.find("b");
  mymap.erase (it);                   // erasing by iterator
  mymap.erase ("c");                  // erasing by key

   it=mymap.find ("e");
    mymap.erase ( it, mymap.end() );    // erasing by range
  
    for (auto i : mymap) cout << i.first << ' ' << i.second <<endl;
    // xét có tồn tại ko 
    // d["abc"] = 2;
    // d.count("abc") == 1 nếu tồn tại trong map, == 0 nếu ko tồn tại
    return 0;
}
