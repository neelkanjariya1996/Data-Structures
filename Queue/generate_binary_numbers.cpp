#include <iostream>
#include <queue>

using namespace std;

void
generate_binary_numbers (int n)
{

	queue <string> q;

	q.push ("1");

	while (n--) {

		string s1 = q.front ();
		q.pop ();
		cout << s1 << endl;

		string s2 = s1;
		
		q.push (s1.append ("0"));
		q.push (s2.append ("1"));	
	}

}

int
main ()
{

	int n = 0;

	n = 10;
	generate_binary_numbers (n);

	return 0;

}
