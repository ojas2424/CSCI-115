#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

class HashModule {
private:
	static const int arrLen = 4001;
	string count;
	float changeLen[arrLen];
	float costFunc[arrLen];
	string hashDictionary[arrLen];

public:
	HashModule();
	~HashModule();
	int hash_t(string count);
	void updateHashDictData(string data);

	int helperVar = 0;
	int p = 0;
	int getHashDictSize();
};

HashModule::HashModule() {
	for(helperVar =0;helperVar < arrLen;helperVar++){
		hashDictionary[helperVar] = "empty";
		changeLen[helperVar] = NULL;
		costFunc[helperVar] = NULL;
		helperVar++;
	}
}

HashModule::~HashModule() {}


int HashModule::hash_t(string count) {
	int add = 0;
	int idxNum;

	for (int i = 0; i < count.length(); i++) {
		add = add + (int)count[i];
	}

	idxNum = add % arrLen;
	return idxNum;
}

int HashModule::getHashDictSize() {
	int arrLen = 0;
	for (int i = 0; i < arrLen; i++) {
		if (hashDictionary[i] != "empty") {
			arrLen++;
		}
	}
	return arrLen;
}

void HashModule::updateHashDictData(string count) {
	string s;
	int idxNum = hash_t(count);
	if (hashDictionary[idxNum] == "empty") { 
		hashDictionary[idxNum] = count; 
		changeLen[idxNum] = 1; 
		costFunc[idxNum] = 1;
	}
	else {
		if (count != hashDictionary[idxNum]) {
			while ((hashDictionary[idxNum] != "empty") && (hashDictionary[idxNum] != count)) {
				idxNum++; 
				p++;
				if (idxNum == arrLen) { 
					idxNum = 0; 
				}
				costFunc[idxNum] = costFunc[idxNum]++; 
			}
		}
		else {
			costFunc[idxNum] = costFunc[idxNum]++; 
			p++;
		}
		changeLen[idxNum] = changeLen[idxNum]++;
		hashDictionary[idxNum] = count;
	}
}




int main() {
	HashModule h;

	ifstream file;
	file.open("RomeoAndJuliet.txt");
	string count;
	count.clear();  
	while (file >> count) {
		h.updateHashDictData(count);
		count.clear(); 
	}
	cout << "unique words:" << h.getHashDictSize() << endl;
	cout << endl;
}