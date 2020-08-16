#include <iostream>
#include <string>
#include <stack>
#include <list>
#include <map>


using namespace std;

bool IsBalanced(const string);

int main(int argc, char const *argv[]) {
	string s = "{[]((){{}[{{({}{}(((()))))}}]})}"; // it's balanced

	cout << IsBalanced(s);

	return 0;
}

bool IsBalanced(const string str) {
	typedef  map<char, string>    directions_map;
	typedef  map<char, char>    associations_map;
	typedef pair<char, string>  		    _pair;

	stack<_pair, list<_pair>> brace_stack;

	directions_map brace_direction = { make_pair('(', "left"),
									   make_pair('{', "left"),
									   make_pair('[', "left"),
									   make_pair(')', "right"),
									   make_pair('}', "right"),
									   make_pair(']', "right") };

	associations_map brace_associations = {  make_pair('(', ')'),
											 make_pair('{', '}'),
											 make_pair('[', ']') };

	bool is_balanced;

	brace_stack.push(make_pair(str[0], brace_direction[str[0]]));	 
	
	for (int i = 1; i < str.size(); ++i) {
		if ( brace_stack.top().second == brace_direction[str[i]] )
		{ //if they're co-directed
			 brace_stack.push(make_pair(str[i], brace_direction[str[i]]));
		}
		else if ( brace_associations[brace_stack.top().first]  == str[i] )
		{ //so, they have opposite direction & if the braces associated, then pop out of the stack
			brace_stack.pop();
			if ( brace_stack.empty() == true ) { is_balanced = true; }
		}
		else
		{ //and if they're not associated, then it's imposible to be balanced
			is_balanced = false;
			break;
		}
	}

	return is_balanced; 
}