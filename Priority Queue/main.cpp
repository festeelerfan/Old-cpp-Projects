#include "pq_zero.h"
#include <string>
#include <iostream>

using namespace std;

int main() {

pq_zero<string> pqLine;
pqLine.push("steve",3.1);
pqLine.push("john",1);
pqLine.push("amy",3);
pqLine.push("phil",5);
pqLine.push("jen", 4);
pqLine.push("mel",1);
cout << "The current most important person is: " << pqLine.top() << endl;
pqLine.pop();
pqLine.push("joe",1);
pqLine.push("tony",6);
while(pqLine.empty() != true)
{
    cout << "The next important person is: " << pqLine.top() << endl;
    pqLine.pop();
}

return 0;
}