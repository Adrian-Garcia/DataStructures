#include <sstream>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

struct valores {
	int valStack;
	int valQueue;
	int valPQueue;
};

int main () {

	string d,data;
	
	stack<int> stack;
	queue<int> queue;
	priority_queue<int, vector<int>, greater<int> > pqueue;

	int a, b;

	getline(cin, data);
	while (data != "#"){
		
		stringstream ss;
	  	ss << data;
		
		while (ss >> d){
			
			//Producto
			if (d == "*") {

				//Fila
				a = queue.front();
				queue.pop();
				b = queue.front();
				queue.pop();
				queue.push(a*b);
				
				//Pila
				a = stack.top();
                stack.pop();
                b = stack.top();
                stack.pop();
                stack.push(b*a);

                //Fila prioritaria
                a = pqueue.top();
                pqueue.pop();
                b = pqueue.top();
                pqueue.pop();
                pqueue.push(b*a);
			}

			//Suma
			else if (d == "+") {
				
				//Fila
				a = queue.front();
				queue.pop();
				b = queue.front();
				queue.pop();
				queue.push(a+b);
				
				//Pila
				a = stack.top();
                stack.pop();
                b = stack.top();
                stack.pop();
                stack.push(b+a);

                //Fila prioritaria
                a = pqueue.top();
                pqueue.pop();
                b = pqueue.top();
                pqueue.pop();
                pqueue.push(b+a);
			}

			//Resta
			else if (d == "-") {

				//Fila
				a = queue.front();
				queue.pop();
				b = queue.front();
				queue.pop();
				queue.push(b-a);
				
				//Pila
				a = stack.top();
                stack.pop();
                b = stack.top();
                stack.pop();
                stack.push(b-a);

                //Fila prioritaria
                a = pqueue.top();
                pqueue.pop();
                b = pqueue.top();
                pqueue.pop();
                pqueue.push(b-a);
			}

			else {

				stringstream test(d);
				test >> a;

				stack.push(a);
				queue.push(a);
				pqueue.push(a);
			}
		}


		cout << stack.top() << " ";
		cout << queue.front() << " ";
		cout << pqueue.top() << endl;
		stack.pop();
		queue.pop();
		pqueue.pop();
	  	getline(cin, data);	
	}
	
	return 0;
}
