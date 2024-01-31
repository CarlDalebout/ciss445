#include <iostream>
#include <string>
#include <vector>

#include <bits/stdc++.h> 
using namespace std; 
  
int towerOfHanoi(int n, char from_rod, char to_rod, 
                  char aux_rod) 
{ 
    if (n == 0) { 
        return 1; 
    } 
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod); 
    cout << "Move disk " << n << " from rod " << from_rod 
         << " to rod " << to_rod << endl; 
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod); 
}

int main()
{

    std::cout << std::isdigit('+') << '\n';

    return 0;
}