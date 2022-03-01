#include <ctime>
#include <iostream>
#include <typeinfo>
using namespace std;
int main()
{
    time_t result = time(nullptr);
    cout << asctime(localtime(&result))
              << result << " seconds since the Epoch\n";
    cout<<"\n"<< typeid(result).name() << endl;   

    long int tp  = 322324;     
    cout<<"\n"<< typeid(tp).name() << endl;   

}
//  1 1 G 5
// 6 1 S 2 1 S 2 2 G 2 S 1 1 S 4 1 G 2
//5 1 S 2 1 G 2 S 3 2 G 2 G 3
//32 4 S 5 13 S 9 6 S 4 1 G 4 S 6 1 S 8 11 G 13 G 1 S 12 12 G 10 S 15 13 S 2 13 S 7 5 S 10 3 G 6 G 10 S 15 14 S 5 12 G 5 G 7 G 15 G 5 G 6 G 10 S 7 13 G 14 S 8 9 G 4 S 6 11 G 9 S 6 12 G 3
//1 -1 -1 -1 -1 3 12 5 14 12 -1 3 -1 -1 -1 -1 

