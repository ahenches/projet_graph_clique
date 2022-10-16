#include <iostream>
#include <vector>

using namespace std;
  
// The vect here is a copy of vect in main()
void func(vector<double> vector) { vector.push_back(30); }
  
int main()
{
    vector<double> vect;
    vect.push_back(10);
    vect.push_back(20);
  
    func(vect);
  
    // vect remains unchanged after function
    // call
    for (int i = 0; i < vect.size(); i++)
        cout << vect[i] << " ";
  
    return 0;
}