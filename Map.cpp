// Map.cpp : Defines the entry point for the application.
//

#include "Map.h"

using namespace std;

void map(const string& filename, OutIter output) {
	ifstream infile(filename.c_str());
		while (infile.good()) {
			string line;
				getline(infile, line);
				regex word_re("(\\w+)");
				sregex_iterator iter(line.begin(), line.end(), word_re);
				sregex_iterator end;
				for (; iter != end; ++iter) {
					string word = iter­ > str();
						output = std::pair<string, int>(word, 1);
				}
		}
	infile.close();
}
};
