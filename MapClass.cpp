// Map Class defines map() method used to pasre through a text file and count each instance of an occuring word. 
// Stores word (key) and occuring number (value) in a dictionary like pair in a temporary text file. 

#include <iostream>
#include <fstream>
#include <map>
#include <string>

//typedef std::map<std::string, int> StrIntMap;

class MapClass {        
public: 

	//void export(string& word, int count) {}

	void map(const string& filename, string& line) { 
					
		regex word_re("(\\w+)");
		sregex_iterator iter(line.begin(), line.end(), word_re);
		sregex_iterator end;
		for (; iter != end; ++iter) {
			string word = iter­ > str();
			output = 
			output = std::pair<string, int>(word, 1);
			//export()
			std::cout << output;
		}
		
	}
};

int main() {
	
	ifstream infile(filename.c_str());
		while (infile.good()) {
			string line;
			getline(infile, line);
			MyMap obj;
			obj.map();
		}
	infile.close();

	return 0;
}
