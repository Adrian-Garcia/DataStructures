#include "Priority.h"

int main() {

	Priority container(true);

	container.push(1);
	container.push(5);
	container.push(2);
	container.push(8);
	container.push(7);
	container.push(9);
	container.push(10);
	container.push(3);
	container.push(6);
	container.push(4);

	if (container.empty()) {
		cout << "YES\n";
	}
	else {
		cout << "NO\n";
	}

	cout << container.top() << endl;

	container.print();

	return 0;
}
